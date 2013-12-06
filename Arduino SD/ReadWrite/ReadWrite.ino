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

File myFile1;

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
  myFile1 = SD.open("HS_Humid.txt", FILE_WRITE);
  
  // if the file opened okay, write to it:
  if (myFile1) {
    Serial.print("Writing to HS_Humid.txt...");
    myFile1.println("Here is the Data for humidity");
	// close the file:
    myFile1.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening HS_Humid.txt");
  }
  
  // re-open the file for reading:
  myFile1 = SD.open("HS_Humid.txt");
  if (myFile1) {
    Serial.println("HS_Humid.txt:");
    
    // read from the file until there's nothing else in it:
    while (myFile1.available()) {
    	Serial.write(myFile1.read());
    }
    // close the file:
    myFile1.close();
  } else {
  	// if the file didn't open, print an error:
    Serial.println("error opening HS_Humid.txt");
  }
}

void loop()
{
	// nothing happens after setup
}

