#include <EEPROM.h>
#include <SoftwareSerial.h>
SoftwareSerial BT_Serial(0,1); 

int Whisky=2;
int Vodka=3;
int SucDePortocale=4;
int Redbull=5;
int CocaCola=6;
int cv1=7;
int cv2=8;
int cv3=9;

int TimpDeAmestecare=500;
char bt_data; 

void setup()
{
 
Serial.begin(9600);
BT_Serial.begin(9600); 
pinMode(2, OUTPUT); 
pinMode(3, OUTPUT); 
pinMode(4, OUTPUT); 
pinMode(5, OUTPUT); 
pinMode(6, OUTPUT); 
pinMode(7, OUTPUT); 
pinMode(8, OUTPUT); 
pinMode(9, OUTPUT); 

digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
 
}

 void loop()
{
if(BT_Serial.available()>0)
{
  bt_data=BT_Serial.read();
 }

  if (bt_data=='A') 
  {
    Mix(1000,0,0,0,0);//whisky;
  }
  if (bt_data=='B') 
  {
    Mix(0,0,0,0,5000);//cola
  }
  if (bt_data=='C') 
  {
    Mix(0,0,5000,0,0);//suc portocale
  }
  if (bt_data=='D') 
  {
    Mix(0,0,0,5000,0);//rebull
  }
  if (bt_data=='E') 
  {
    Mix(0,1000,0,0,0);//vodka
  }
  if (bt_data=='F') 
  {
    Mix(2000,0,0,5000,0); //whisky cola
  }
  if (bt_data=='G') 
  {
    Mix(2000,0,0,0,5000); //whisky red bull
  }
  if (bt_data=='H') 
  {
    Mix(0,2000,5000,0,0); //orange vodka
  }
  if (bt_data=='a') 
  {
    Mix(0,2000,0,5000,0); //vodka cola
  }
  if (bt_data=='b') 
  {
    Mix(0,2000,0,0,5000); //redbull vodka
  }
  if (bt_data=='c') 
  {
    Mix(0,0,5000,0,1660); //redbull orange
  }
  if (bt_data=='d') 
  {
    Mix(1000,0,2000,4660,0); //orange burst
  }
  if (bt_data=='e') 
  {
    Mix(0,1000,2000,4660,0); //screwdriver
  }
  if (bt_data=='T') 
  {
    Mix(1000,1000,1000,1000,1000); //test
  }
}

void Mix(int TimpWhisky, int TimpVodka, int TimpSucDePortocale, int TimpRedbull, int TimpCocaCola) 
{
bt_data='0';
delay(800);
digitalWrite(Whisky, LOW);   
delay(TimpWhisky);            
digitalWrite(Whisky, HIGH); 
delay(TimpDeAmestecare);    

digitalWrite(Vodka, LOW);   
delay(TimpVodka);            
digitalWrite(Vodka, HIGH); 
delay(TimpDeAmestecare);   

digitalWrite(SucDePortocale, LOW);   
delay(TimpSucDePortocale);            
digitalWrite(SucDePortocale, HIGH); 
delay(TimpDeAmestecare);     

digitalWrite(Redbull, LOW);   
delay(TimpRedbull);            
digitalWrite(Redbull, HIGH); 
delay(TimpDeAmestecare);   

digitalWrite(CocaCola, LOW);   
delay(TimpCocaCola);            
digitalWrite(CocaCola, HIGH); 
delay(TimpDeAmestecare);    
  
bt_data='0';
}