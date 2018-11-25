//Slave
//Maximalni cislo co umi poslat je 32750


#include <Wire.h>

int data = 33749; //Maximalni cislo co umi poslat je 32750
byte mb[2];

void setup(){
    Wire.begin(100);
    Wire.onRequest(odeslatData);
}

void loop(){
    delay(100);
}

void odeslatData(){
  
  data = (data+250);
  
  //kolik celých 256 se vejde do naměřené hodnoty
  mb[1] = (data-(data%256))/256; //byte s vyšší hodnotou
  //jaký je zbytek po dělení 256
  mb[0] = data%256; //byte s nižší hodnotou - 
  Wire.write(mb, 2);
}
