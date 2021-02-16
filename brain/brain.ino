#include <SoftwareSerial.h>

// Utilized I/O Pins 
int PIN_RX = 12;
int PIN_TX = 11;
int PIN_HC = 13;
int PIN_AT = 10;

// Set up the software serial port
SoftwareSerial softSerial(PIN_RX, PIN_TX);

boolean BT_CONNECTED = false;

long BAUD_TERMINAL = 9600;
long BAUD_AT = 38400;
long BAUD_DEF = 57600;

const char ADDRESS [13] = "81,f9,2a5bb8";
long TIME_OUT = 25000;

// Program Modes - AT_MODE := Start Program in AT, FORCE_NEW_CONNECTION := Automatically Run AT-Commands
boolean AT_MODE = true;
boolean FORCE_NEW_CONNECTION = false;

// checksum variables
byte generatedChecksum = 0;
byte checksum = 0; 
int payloadLength = 0;
byte payloadData[64] = {0};
byte poorQuality = 0;
byte attention = 0;
byte meditation = 0;

int ByteRead;

// system variables
long lastReceivedPacket = 0;
boolean bigPacket = false;

void setup() {
  
    // Initiate Terminal Connection
    Serial.begin(BAUD_TERMINAL);
    Serial.println(F("Program Initiated"));
    delay(100);

    // If AT-Mode Enabled on startup
    if (AT_MODE == true) {
      Serial.println(F("- Initializing in AT Mode -"));
      softSerial.begin(BAUD_AT);

      // Enable 5V on AT-Pin
      pinMode(PIN_AT, OUTPUT);
      digitalWrite(PIN_AT, HIGH);
      delay(500);
      
    } else {
      Serial.println(F("- Initializing in Data Mode -"));
      softSerial.begin(BAUD_DEF);
    }

    // Turns on HC-05
    Serial.println(F("- Powering Bluetooth Module -"));
    pinMode(PIN_HC, OUTPUT);
    digitalWrite(PIN_HC, HIGH);
    delay(2000);

    // Starts AT-Mode if Enabled
    if (AT_MODE == true) {
      // Automatically Attempt to Set AT-Parameters
      if (FORCE_NEW_CONNECTION == true) {
        auto_force_pair();
      } else {
        manual_force_pair();
      }
    }
}

void manual_force_pair() {
  Serial.println(F("- Order of operations for pairing HC05: "));
  Serial.println(F("AT+RMAAD"));
  Serial.println(F("AT+ROLE=1"));
  Serial.println(F("AT+RESET"));
  Serial.println(F("AT+CMODE=0"));
  Serial.println(F("AT+INQM=0,5,9"));
  Serial.println(F("AT+INIT"));
  Serial.println(F("AT+PAIR=xxxx,xx,xxxxxx,tt"));
  Serial.println(F("AT+BIND=xxxx,xx,xxxxxx"));
  Serial.println(F("AT+CMODE=1"));
  Serial.println(F("AT+LINK=xxxx,xx,xxxxxx"));
}

void auto_force_pair() {
  Serial.println(F("\r\n- Attempting Forced Auto-Pair of Headset: "));
  
  softSerial.write("AT+RMAAD\r\n");
  checkCommand();

  softSerial.write("AT+ROLE=1\r\n");
  checkCommand();
  
  softSerial.write("AT+RESET\r\n");
  checkCommand();
  delay(1000);
  
  softSerial.write("AT+CMODE=0\r\n");
  checkCommand();  
  
  softSerial.write("AT+INQM=0,5,9\r\n");
  checkCommand();  
  
  softSerial.write("AT+INIT\r\n");
  checkCommand();  
  
  softSerial.write("AT+INQ\r\n");
  checkCommand();  
  checkCommand();  
  
  softSerial.write("AT+PAIR=");
  softSerial.write(ADDRESS);
  softSerial.write(",20\r\n");
  checkCommand();  
  
  softSerial.write("AT+BIND=");
  softSerial.write(ADDRESS);
  softSerial.write("\r\n");
  checkCommand();  
  
  softSerial.write("AT+CMODE=1\r\n");
  checkCommand();  

  softSerial.write("AT+LINK=");
  softSerial.write(ADDRESS);
  softSerial.write("\r\n");
  checkCommand();  

  digitalWrite(PIN_AT, LOW);
  softSerial.write("AT+RESET\r\n");
  AT_MODE = false;
  checkCommand();
  Serial.println(F("\r\n- Rebooting in Data-Mode -"));
  
  softSerial.flush();
  softSerial.begin(BAUD_DEF);
  while(Serial.available()) {
    Serial.read();
  }

  Serial.println(F("- Data-Mode -"));

}

void checkCommand() {

  unsigned long startTime = millis();

   while (!softSerial.available()) {
     
     if (millis() - startTime > TIME_OUT) {
       break;
     }
     Serial.print('.');
     delay(500);
   }

  if (softSerial.available()) {
    while(softSerial.available()) {
      Serial.print((char)softSerial.read());
    }
  } else {
    Serial.println(F("Timed out!"));
  }

}

byte ReadOneByte() {

  if(softSerial.available()) {
    ByteRead = softSerial.read();
    return ByteRead;
  } else {
    return 0;
  }
}

void loop() {

  if (AT_MODE == true) {

    // From Bluetooth to Terminal
    if (softSerial.available()) {
        Serial.print((char)softSerial.read());
    }

    // From Terminal to Bluetooth
    if (Serial.available()) {
      softSerial.write(Serial.read());
    }  
    
  } else {
    
    delay(100);
    
    // Look for sync bytes
    if(ReadOneByte() == 170) {
      Serial.println(F("- Found Sync Byte -"));
      if (BT_CONNECTED == false) {
        Serial.println("Bluetooth Connected");
        BT_CONNECTED = true;
      }
      if(ReadOneByte() == 170) {
  
        payloadLength = ReadOneByte();
        if(payloadLength > 169)                      //Payload length can not be greater than 169
            return;
  
        generatedChecksum = 0;        
        for(int i = 0; i < payloadLength; i++) {  
          payloadData[i] = ReadOneByte();            //Read payload into memory
          generatedChecksum += payloadData[i];
        }   
  
        checksum = ReadOneByte();                      //Read checksum byte from stream      
        generatedChecksum = 255 - generatedChecksum;   //Take one's compliment of generated checksum
  
          if(checksum == generatedChecksum) {    
  
          poorQuality = 200;
          attention = 0;
          meditation = 0;
  
          for(int i = 0; i < payloadLength; i++) {    // Parse the payload
            switch (payloadData[i]) {
            case 2:
              i++;            
              poorQuality = payloadData[i];
              bigPacket = true;            
              break;
            case 4:
              i++;
              attention = payloadData[i];                        
              break;
            case 5:
              i++;
              meditation = payloadData[i];
              break;
            case 0x80:
              i = i + 3;
              break;
            case 0x83:
              i = i + 25;      
              break;
            default:
              break;
            } // switch
          } // for loop
  
    Serial.println(poorQuality);
    Serial.println(attention);
    Serial.println(' ');
  
        } 
      }
    } else {
      delay(100);
    }
  }
}
