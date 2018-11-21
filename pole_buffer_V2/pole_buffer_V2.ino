 /*
  * Prace s polem, neco jako posun pole o jednu pozici na ulozeni nekolika poslednich hodnot
  * Nejjednodussi verze posunu pole o jednu hodnotu
  * Verze z 21.11.2017
  */
 
 
 //Pole 
 int pole[6] = {21,82,23,104,75,88}; 
      

 int i = 0;
 int j = 0;
 
 int novyprvek = 666;
  
 int poledata = 0;  



void setup() {
  // put your setup code here, to run once:

   Serial.begin(9600);

//Vlozeni dat ze stareho pole do noveho, ale bez nejstarsiho prvku na zacatku
   for (i=1; i<6; i++) {
       pole[j]=pole[(j+1)];
        }
   
   j=0;
   i=0;



      
//Vlozeni dalsi hodnoty do stareho pole
pole[6]=novyprvek;


//Tak a tady uz je pole komplet s novou hodnotou :-) 


//Vypis stareho pole s nvou hodnotou na konci 
   for (j=0; j<7; j++) {
       
       Serial.print(pole[i]); Serial.print(", ");
       i=(i+1);  
          
      }

   j=0;
   i=0;

}

void loop() {
  // put your main code here, to run repeatedly:

}
