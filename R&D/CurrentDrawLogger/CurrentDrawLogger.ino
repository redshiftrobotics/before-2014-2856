#include <SPI.h>
#include <SD.h>

const int chipSelect = 10;

int VRaw; //This will store our raw ADC data
int IRaw;

float VFinal; //This will store the converted data
float IFinal;


void setup()
{
  Serial.begin(9600);
//make chipselect pin output
  pinMode(10, OUTPUT);

  // check for errors
  if (!SD.begin(chipSelect)) {
    Serial.println("Failed to communicate with SD card");
  }
  Serial.println("Initialized");
}

void loop()
{
  // make a string for assembling the data
  String dataString = "";

  // read sensors for voltage and current

      //Measurement
  VRaw = analogRead(A0);
  IRaw = analogRead(A1);
  
  //Conversion
  VFinal = VRaw/49.44; //45 Amp board
  IFinal = IRaw/14.9; //45 Amp board
  
   //add data to string
   dataString += String(VFinal);
   //add a tab for easier excel importing
   dataString += "\t";
   
      //add data to string
   dataString += String(IFinal);
   //add a tab for easier excel importing
   dataString += "\t";
  

  // open the file
  File dataFile = SD.open("log.txt", FILE_WRITE);

  //write to file
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // To serial for testing
    Serial.println(dataString);
  }
  // if file fails to open, print error
  else {
    Serial.println("Error: failed to open file...");
  }
  
  //Wait 1 seconds before logging the next data point.
  delay(1000);
}


