//This example shows how to use the Mux Shield for analog inputs

#include <MuxShield.h>

//Initialize the Mux Shield
MuxShield muxShield;
int threshold = 300;


// Define the number of samples to keep track of.  The higher the number,
// the more the readings will be smoothed, but the slower the output will
// respond to the input.  Using a constant rather than a normal variable lets
// use this value to determine the size of the readings array.
const int numReadings = 10;
const int sensorCount = 48;
int readings[numReadings][sensorCount];      // the readings from the analog input
int index= 0;                  // the index of the current reading
int total[sensorCount];// = 0;                  // the running total
int average[sensorCount];// = 0;                // the average


void setup()
{
  //Set I/O 1, I/O 2, and I/O 3 as analog inputs
  muxShield.setMode(1,ANALOG_IN);
  muxShield.setMode(2,ANALOG_IN);
  muxShield.setMode(3,ANALOG_IN);

  Serial.begin(115200);//28800
  for (int thisReading = 0; thisReading < numReadings; thisReading++){
    for(int sensorNum = 0;sensorNum<sensorCount;sensorNum++){
      readings[thisReading][sensorNum] = 0;  
    }
  }
}

//Arrays to store analog values after recieving them
int IO1AnalogVals[16];
int IO2AnalogVals[16];
int IO3AnalogVals[16];

void loop()
{



  for (int i=0; i<16; i++)
  {
    //Analog read on all 16 inputs on IO1, IO2, and IO3
    IO1AnalogVals[i] = muxShield.analogReadMS(1,i);
    IO2AnalogVals[i] = muxShield.analogReadMS(2,i);
    IO3AnalogVals[i] = muxShield.analogReadMS(3,i);
  }
  /*
  //Print IO1 values for inspection
   //Serial.print("ch1:");
   for (int i=0; i<16; i++)
   {
   if(IO1AnalogVals[i] > threshold){
   Serial.print('1');
   Serial.print('\t');
   } else{
   Serial.print('0');
   Serial.print('\t');
   }
   //  Serial.print(IO1AnalogVals[i]);
   //Serial.print('\t');
   }
   
   */

  /*
  //Serial.println();
   //Print IO1 values for inspection
   //Serial.print("ch2:");
   for (int i=0; i<16; i++)
   {
   Serial.print(IO2AnalogVals[i]);
   Serial.print('\t');
   }
   // Serial.println();
   //Print IO1 values for inspection
   // Serial.print("ch3:");
   for (int i=0; i<16; i++)
   {
   Serial.print(IO3AnalogVals[i]);
   Serial.print('\t');
   }
   // Serial.println();
   
   Serial.println();
   delay(30);
   
   */

  Serial.print("Array 1");
  Serial.print('\t');
  for(int sensorNum = 0;sensorNum<sensorCount/3;sensorNum++){
    // subtract the last reading:
    total[sensorNum] = total[sensorNum] - readings[index][sensorNum];         
    // read from the sensor:  
    readings[index][sensorNum] = IO1AnalogVals[sensorNum];//analogRead(inputPin); 
    // add the reading to the total:
    total[sensorNum] = total[sensorNum] + readings[index][sensorNum];       
    // advance to the next position in the array:  
    index = index + 1;                    

    // if we're at the end of the array...
    if (index >= numReadings)              
      // ...wrap around to the beginning: 
      index = 0;                           

    // calculate the average:
    average[sensorNum] = total[sensorNum] / numReadings;         
    // send it to the computer as ASCII digits
    Serial.print(average[sensorNum]);   
    Serial.print('\t');
    delay(1);        // delay in between reads for stability  
  }
  Serial.println();


  ///---------
  //Sensors 16-31
  ///---------
  Serial.print("Array 2");
  Serial.print('\t');
  for(int sensorNum = sensorCount/3;sensorNum< (sensorCount/3)*2;sensorNum++){
    // subtract the last reading:
    total[sensorNum] = total[sensorNum] - readings[index][sensorNum];         
    // read from the sensor:  
    readings[index][sensorNum] = IO1AnalogVals[sensorNum];//analogRead(inputPin); 
    // add the reading to the total:
    total[sensorNum] = total[sensorNum] + readings[index][sensorNum];       
    // advance to the next position in the array:  
    index = index + 1;                    

    // if we're at the end of the array...
    if (index >= numReadings)              
      // ...wrap around to the beginning: 
      index = 0;                           

    // calculate the average:
    average[sensorNum] = total[sensorNum] / numReadings;         
    // send it to the computer as ASCII digits
    Serial.print(average[sensorNum]);   
    Serial.print('\t');
    delay(1);        // delay in between reads for stability  
  }
    Serial.println();

  ///---------
  //Sensors 32-47
  ///---------
  Serial.print("Array 3");
  Serial.print('\t');
  for(int sensorNum = (sensorCount/3)*2; sensorNum< sensorCount;sensorNum++){
    // subtract the last reading:
    total[sensorNum] = total[sensorNum] - readings[index][sensorNum];         
    // read from the sensor:  
    readings[index][sensorNum] = IO1AnalogVals[sensorNum];//analogRead(inputPin); 
    // add the reading to the total:
    total[sensorNum] = total[sensorNum] + readings[index][sensorNum];       
    // advance to the next position in the array:  
    index = index + 1;                    

    // if we're at the end of the array...
    if (index >= numReadings)              
      // ...wrap around to the beginning: 
      index = 0;                           

    // calculate the average:
    average[sensorNum] = total[sensorNum] / numReadings;         
    // send it to the computer as ASCII digits
    Serial.print(average[sensorNum]);   
    Serial.print('\t');
    delay(1);        // delay in between reads for stability  
  }
    Serial.println();


  //Serial.println(IO1AnalogVals[0]);

}




