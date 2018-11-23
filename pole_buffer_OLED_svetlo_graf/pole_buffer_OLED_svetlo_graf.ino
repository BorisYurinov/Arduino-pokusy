/*
 * Nacteme pole z analog in, nacpeme je do pole o poctu 120 prvků
 * posuneme pole o jedna a pridame a udelame sexy graf :-p
 * Nevypada to spatne ;-) :-)
 * Verze z 23.11.2018
 */



#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4 // not used / nicht genutzt bei diesem Display
Adafruit_SSD1306 display(OLED_RESET);

//Pole 
 int pole[120] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; 
 int i = 0;
 
 int grafy = 0;
 

const int analogPin = A0; //na pinu 0 se bude načítat hodnota
int novecislo = 0;


void setup()   {  
  Serial.begin(9600);              

  // initialize with the I2C addr 0x3C / mit I2C-Adresse 0x3c initialisieren
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  
}



void loop() {

  
  
  //Vlozeni dat ze stareho pole do noveho, ale bez nejstarsiho prvku na zacatku
   for (i=0; i<120; i++) {
       pole[i]=pole[(i+1)];
      }

   
 
 //Vlozeni dalsi hodnoty do stareho pole
  novecislo=analogRead(analogPin);
  Serial.println(novecislo);
  pole[120]=novecislo;


  
 
  display.clearDisplay();
 
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.setTextSize(1); // Vyska textu je 15px
  display.println(novecislo);


//Ze by graf?
    for(int k=0; k<=120; k++){
    grafy = map(pole[k], 0, 1024, 62, 10);
    display.drawLine(k, grafy, k, 62, WHITE);
    //        odkud  x   y   kam x y
    }

  //        odkud  x   y   kam x y
   


  
  
  display.display();
  

  delay(1000);
  Serial.println();
  Serial.println();
 
 
 
}
