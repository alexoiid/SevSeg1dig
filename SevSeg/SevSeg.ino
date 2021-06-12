#include <SevSeg.h>
SevSeg sevseg; 
  int i; //for the for loop
void setup(){
    byte konfiguracija = COMMON_CATHODE; //Configuration of the segment display
    byte brojCifara = 1; //Number of digits
    byte digitPins[] = {}; // For segment display with 4 digits define the ground pins
    byte segmentPinovi[] = {6, 5, 2, 3, 4, 7, 8, 9}; //Segment Pins A B C D E F G DP
    bool otpornik = true; // Series current limiting resistor 

  
    sevseg.begin(konfiguracija, brojCifara, digitPins, segmentPinovi, otpornik); // setup the segment display
    sevseg.setBrightness(90);
}

void loop(){
               for (i=0;i<10;i++) // For loop which increases the number displayed on the segment display
               {
                 sevseg.setNumber(i, i%2); // i%2 important for the dp without it the counter doesn't work
                  delay(1000);
                sevseg.refreshDisplay(); 
               }
}
