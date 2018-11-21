/*
 * Posílání dat na display Nextion
 * Verze z 20.11.2018
 */

int w = 0;
long randNumber;

void setup() {
  Serial.begin(9600);

   randomSeed(analogRead(0));

  Nextion("dims=80");
  
  Nextion("page 0");
  delay(2000);
  Nextion("page 1");
  delay(2000);
  Nextion("page 2");
  delay(2000);
  Nextion("page 3");
  delay(2000);
  Nextion("page 4");
  delay(2000);
  Nextion("page 5");
  delay(2000);
  Nextion("page 6");
  delay(2000);
  Nextion("page 7");
  delay(2000);
  
  }

void loop() {

  randNumber = random(2, 99);
  
  Nextion("t75.txt=\"Unknown...\""); //= změna obsahu pole

  Nextion("t76.txt=\"Nic...\""); //= změna obsahu pole

  Nextion("t77.txt=\"Hovno...\""); //= změna obsahu pole
  
  Nextion("t71.txt=\""+(String)randNumber+"\"");
  
  Serial.print("j70.val="); 
  Serial.print(randNumber);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);

  
  delay(1000);
 
  
  }

// Funkce která posílá data a příkazy pro Nextion
/*
 * Nextion("page 1"); = změna stránky
 * Nextion("t0.txt=\"Cas...\""); = změna obsahu pole
 * Nextion("t1.txt=\""+(String)w+"\""); = poslání proměnný
 * Nextion("dims=80"); = defaultní podsvícení 
 */
 
void Nextion(String data){
Serial.print(data);
Serial.write(0xff);
Serial.write(0xff);
Serial.write(0xff);
}
