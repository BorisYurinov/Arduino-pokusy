//master
//Maximalni cislo co umi poslat je 32750


#include <Wire.h>

int hodnota; 
byte mb[2]; 

void setup(){ 
  Wire.begin(); 
  Serial.begin(9600); 
  }


void loop(){
   Wire.requestFrom(100, 2);
   while(Wire.available() > 0){
    mb[0] = Wire.read(); //nižší byte
     mb[1] = Wire.read(); //vyšší byte
      //nyní hodnoty opět spojíme dohromady
       hodnota = mb[0] + mb[1]*256;
        Serial.println(hodnota);
   }
   delay(1000);
}
