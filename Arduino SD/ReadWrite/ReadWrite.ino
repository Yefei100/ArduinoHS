/*
  SD card read/write
 
 This example shows how to read and write data to and from an SD card file 	
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4
 
 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 
 This example code is in the public domain.
 	 
 */
 
#include <SD.h>
#include <SPI.h>

const int featureNum = 3;
File myFile[featureNum];

void setup()
{
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin 
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output 
  // or the SD library functions will not work. 
   pinMode(10, OUTPUT);
   
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile[0] = SD.open("HS_Humid.txt", FILE_WRITE);
  
  // if the file opened okay, write to it:
  if (myFile[0]) {
    Serial.print("Writing to HS_Humid.txt...");
    myFile[0].println("Here is the Data for humidity");
	// close the file:
    myFile[0].close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening HS_Humid.txt");
  }
  
  // re-open the file for reading:
  myFile[0] = SD.open("HS_Humid.txt");
  if (myFile[0]) {
    Serial.println("HS_Humid.txt:");
    
    // read from the file until there's nothing else in it:
    while (myFile[0].available()) {
    	Serial.write(myFile[0].read());
    }
    // close the file:
    myFile[0].close();
  } else {
  	// if the file didn't open, print an error:
    Serial.println("error opening HS_Humid.txt");
  }
    
    myFile[1] = SD.open("HS_Temp.txt", FILE_WRITE);
  
  // if the file opened okay, write to it:
  if (myFile[1]) {
    Serial.print("Writing to HS_Temp.txt...");
    myFile[1].println("Here is the Data for temperature");
	// close the file:
    myFile[1].close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening HS_Temp.txt");
  }
  
  // re-open the file for reading:
  myFile[1] = SD.open("HS_Temp.txt");
  if (myFile[1]) {
    Serial.println("HS_Temp.txt:");
    
    // read from the file until there's nothing else in it:
    while (myFile[1].available()) {
    	Serial.write(myFile[1].read());
    }
    // close the file:
    myFile[1].close();
  } else {
  	// if the file didn't open, print an error:
    Serial.println("error opening HS_Temp.txt");
  }
}

void loop()
{
	// nothing happens after setup
}

