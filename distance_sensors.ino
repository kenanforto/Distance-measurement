//definisanje pinova na arduinu
const int trigPin=10;
const int echoPin=9;
long trajanje;
int udaljenost;
int ucitanjeir=A0;
int i;
void upaliU() //funckija uključivanja slova U na sedmosegmentnom displayu
{
 digitalWrite(2, 1);
 digitalWrite(3, 0);
 digitalWrite(4, 0);
 digitalWrite(5, 0);
 digitalWrite(6, 0);
 digitalWrite(7, 0);
 digitalWrite(8, 1);
}
void upaliI() //funckija uključivanja slova I na sedmosegmentnom displayu
{
 digitalWrite(2, 1);
 digitalWrite(3, 0);
 digitalWrite(4, 0);
 digitalWrite(5, 1);
 digitalWrite(6, 1);
 digitalWrite(7, 1);
 digitalWrite(8, 1);
}
void setup() {
 Serial.begin(9600);
//konfigurisanje izlaza/ulaza arduina
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 for(i=2;i<9;i++)
 {
 pinMode(i, OUTPUT);
 }
}
void loop() {
 digitalWrite(trigPin, 0);
 delayMicroseconds(2);
 digitalWrite(trigPin, 1);
 delayMicroseconds(10);
 digitalWrite(trigPin, 0);
 trajanje=pulseIn(echoPin, 1); //očitavanje vrijednosti ultrazvučnog senzora
 udaljenost=trajanje*0.034/2; //izraz za dobijanje vrijednosti udaljenosti ultrazvucnog senzora
 Serial.print("Ultrazvucni senzor je izmjerio udaljenost "); //ispisivanje na displayu
 Serial.println(udaljenost); //ispisivanje na displayu uz novi red
 int ocitanje=analogRead(ucitanjeir); //očitavanje vrijednosti infracrvenog senzora
 float napon=ocitanje*5/1024.0;
 float udaljenost1=29.988*pow(napon, -1.173); //izraz za dobijanje vrijednosti udaljenosti ir senzora
 Serial.print("IC senzor je izmjerio udaljenost "); //ispisivanje na displayu
 Serial.println(udaljenost1); //ispisivanje na displayu uz novi red
 if(udaljenost1<udaljenost) //upoređivanje dobijenih vrijednosti udaljenosti uz uslov
 {
 upaliI(); //pozivanje funkcije upaliI
 }
 else
 {
 upaliU(); //pozivanje funkcije upaliU
 }
 delay(1000); //ponavljanje postupka svakih 1000ms
}
