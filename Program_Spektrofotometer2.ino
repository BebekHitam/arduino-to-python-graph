int RPM;
unsigned long time;
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4); 
const int analogInPin = A1;
float sensorValue = 0;  
float sensorValue2 = 0;
float absorbansi=0;
int aPin      = 10; 
int bPin      = 11; 
int aPrimePin = 12; 
int bPrimePin = 13; 
float degrees = 0;
String inString = "";
int delay1 = 2;    
int delay2 = 200;  
int count  = 0;    

int numberOfRotations = 0; 
#include <Keypad.h>
int v1 = 0;
int v2 = 0;
int l =0;
const byte ROWS = 4; 
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};


byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2}; 

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void setup() {
   lcd.init();
       lcd.backlight();
  lcd.clear();     
  pinMode(aPin,      OUTPUT);
  pinMode(bPin,      OUTPUT);
  pinMode(aPrimePin, OUTPUT);
  pinMode(bPrimePin, OUTPUT);


  // Start with all coils off
  digitalWrite(aPin,      LOW);
  digitalWrite(bPin,      LOW);
  digitalWrite(aPrimePin, LOW);
  digitalWrite(bPrimePin, LOW);
   Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(analogInPin);
    
    
  if (l==0) {
      lcd.setCursor(0, 0);
    lcd.print("Spektrofotometer");
  }
  else {
    switch(l) {
    lcd.clear();
    break;
    }
  }
    char key = kpd.getKey();
  if(key)  
  {
    switch (key)
    {
      case 'A':
        numberOfRotations =  1 ;
        break;
      case 'B':
      l=2;
      if (v2==0) {
       numberOfRotations =  2 ; 
       }
        break;
        case 'C':
        l=2;
        if (numberOfRotations ==  3){
          numberOfRotations =  2 ;
          break;
        }
        else if (v2==720){
          break;
        }
        else{
         numberOfRotations =  3 ;
        lcd.clear();
        lcd.setCursor(0, 0);
       lcd.print("input nilai= ");
       v1 = GetNumber(); }
    //   
      default:
 lcd.clear();
  lcd.print("salah input");

    }
  }
 if ((numberOfRotations) ==  3 ) {



    if (degrees == v1) {
   digitalWrite(aPin,      LOW);
  digitalWrite(bPin,      LOW);
  digitalWrite(aPrimePin, LOW);
  digitalWrite(bPrimePin, LOW);
}
else
{
    aPin      = 10;
    bPin      = 11;
    aPrimePin = 12;
    bPrimePin = 13;
    
 digitalWrite(aPin,      HIGH);
  digitalWrite(bPin,      LOW);
  digitalWrite(aPrimePin, LOW);
  digitalWrite(bPrimePin, LOW);
  delay(delay1); 

  digitalWrite(aPin,      HIGH);
  digitalWrite(bPin,      HIGH);
  digitalWrite(aPrimePin, LOW);
  digitalWrite(bPrimePin, LOW);
  delay(delay1); 

  digitalWrite(aPin,      LOW);
  digitalWrite(bPin,      HIGH);
  digitalWrite(aPrimePin, LOW);
  digitalWrite(bPrimePin, LOW);
  delay(delay1); 

  digitalWrite(aPin,      LOW);
  digitalWrite(bPin,      HIGH);
  digitalWrite(aPrimePin, HIGH);
  digitalWrite(bPrimePin, LOW);
  delay(delay1);

  digitalWrite(aPin,      LOW);
  digitalWrite(bPin,      LOW);
  digitalWrite(aPrimePin, HIGH);
  digitalWrite(bPrimePin, LOW);
  delay(delay1);

  digitalWrite(aPin,      LOW);
  digitalWrite(bPin,      LOW);
  digitalWrite(aPrimePin, HIGH);
  digitalWrite(bPrimePin, HIGH);
  delay(delay1); 

  digitalWrite(aPin,      LOW);
  digitalWrite(bPin,      LOW);
  digitalWrite(aPrimePin, LOW);
  digitalWrite(bPrimePin, HIGH);
  delay(delay1); 

  digitalWrite(aPin,      HIGH);
  digitalWrite(bPin,      LOW);
  digitalWrite(aPrimePin, LOW);
  digitalWrite(bPrimePin, HIGH);
  delay(delay1); 

  count = count + 8;
  degrees = (720.0 * (count / 8192.0));
   
    lcd.setCursor(0, 0);    
    lcd.print("merah - ungu =");
    lcd.print("  ");          
    lcd.print(degrees);    
    lcd.print((char)223);   
    lcd.print(" ");          
 // sensorValue = analogRead(analogInPin);
  //sensorValue2 = analogRead(analogInPin2);
  //absorbansi=sensorValue-sensorValue2;
  lcd.setCursor(0,1);
  lcd.print("Intensitas 1 = ");
  lcd.print(sensorValue);
  
//  delay(500);

  if (count == 8192) {
    time = millis();
    if ( time > 55000 && time < 65000) { 
      RPM = numberOfRotations + 1;
    }
    delay(delay2); 
    count = 0; 
    v2=720;
  }  
}

 }
if ((numberOfRotations) == 2) {
     // lcd.clear();
  if (v2==0) {
       // inString = "";
    aPin      = 10;
    bPin      = 11;
    aPrimePin = 12;
    bPrimePin = 13;

  digitalWrite(aPin,      HIGH);
  digitalWrite(bPin,      LOW);
  digitalWrite(aPrimePin, LOW);
  digitalWrite(bPrimePin, LOW);
  delay(delay1); 

  digitalWrite(aPin,      HIGH);
  digitalWrite(bPin,      HIGH);
  digitalWrite(aPrimePin, LOW);
  digitalWrite(bPrimePin, LOW);
  delay(delay1); 

  digitalWrite(aPin,      LOW);
  digitalWrite(bPin,      HIGH);
  digitalWrite(aPrimePin, LOW);
  digitalWrite(bPrimePin, LOW);
  delay(delay1); 

  digitalWrite(aPin,      LOW);
  digitalWrite(bPin,      HIGH);
  digitalWrite(aPrimePin, HIGH);
  digitalWrite(bPrimePin, LOW);
  delay(delay1); 

  digitalWrite(aPin,      LOW);
  digitalWrite(bPin,      LOW);
  digitalWrite(aPrimePin, HIGH);
  digitalWrite(bPrimePin, LOW);
  delay(delay1); 

  digitalWrite(aPin,      LOW);
  digitalWrite(bPin,      LOW);
  digitalWrite(aPrimePin, HIGH);
  digitalWrite(bPrimePin, HIGH);
  delay(delay1); 

  digitalWrite(aPin,      LOW);
  digitalWrite(bPin,      LOW);
  digitalWrite(aPrimePin, LOW);
  digitalWrite(bPrimePin, HIGH);
  delay(delay1); 

  digitalWrite(aPin,      HIGH);
  digitalWrite(bPin,      LOW);
  digitalWrite(aPrimePin, LOW);
  digitalWrite(bPrimePin, HIGH);
  delay(delay1); 

  count = count + 8;
  degrees = (720.0 * (count / 8192.0));
  
  if ((numberOfRotations == 2)) { 

    lcd.setCursor(0, 0);   
    lcd.print("Merah ke Ungu = ");
    lcd.print(degrees);       
    lcd.print((char)223); 
    Serial.print(degrees);
    Serial.print(" , ");
    Serial.println(sensorValue);    
//  sensorValue = analogRead(analogInPin);
 // sensorValue2 = analogRead(analogInPin2);
  //absorbansi=sensorValue-sensorValue2;
 lcd.setCursor(0,1);
 lcd.print("Intensitas 1 = ");
 lcd.print(sensorValue);

 // delay(200);
  }
  if (count == 8192) {
    time = millis();
    if ( time > 55000 && time < 65000) { 
         numberOfRotations = 0;
      RPM = numberOfRotations + 1;

    }
    delay(delay2);
    count = 0; 
 v2 =720;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("tekan A untuk");
      lcd.setCursor(0,1);
      lcd.print("kembali posisi 0"); 
  }
    }
}

if ((numberOfRotations) ==1 ) {

if (v2==720) {
  
    aPin      = 13;
    bPin      = 12;
    aPrimePin = 11;
    bPrimePin = 10;  

  digitalWrite(aPin,      HIGH);
  digitalWrite(bPin,      LOW);
  digitalWrite(aPrimePin, LOW);
  digitalWrite(bPrimePin, LOW);
  delay(delay1); 

  digitalWrite(aPin,      HIGH);
  digitalWrite(bPin,      HIGH);
  digitalWrite(aPrimePin, LOW);
  digitalWrite(bPrimePin, LOW);
  delay(delay1); 

  digitalWrite(aPin,      LOW);
  digitalWrite(bPin,      HIGH);
  digitalWrite(aPrimePin, LOW);
  digitalWrite(bPrimePin, LOW);
  delay(delay1); 

  digitalWrite(aPin,      LOW);
  digitalWrite(bPin,      HIGH);
  digitalWrite(aPrimePin, HIGH);
  digitalWrite(bPrimePin, LOW);
  delay(delay1);

  digitalWrite(aPin,      LOW);
  digitalWrite(bPin,      LOW);
  digitalWrite(aPrimePin, HIGH);
  digitalWrite(bPrimePin, LOW);

  delay(delay1); 

  digitalWrite(aPin,      LOW);
  digitalWrite(bPin,      LOW);
  digitalWrite(aPrimePin, HIGH);
  digitalWrite(bPrimePin, HIGH);
  delay(delay1); 

  digitalWrite(aPin,      LOW);
  digitalWrite(bPin,      LOW);
  digitalWrite(aPrimePin, LOW);
  digitalWrite(bPrimePin, HIGH);
  delay(delay1); 
  digitalWrite(aPin,      HIGH);
  digitalWrite(bPin,      LOW);
  digitalWrite(aPrimePin, LOW);
  digitalWrite(bPrimePin, HIGH);
  delay(delay1); 

  count = count + 8;
  degrees = (720.0 * (count / 8192.0));
    
    lcd.setCursor(0, 0);      
    lcd.print("Ungu ke merah = ");
    degrees = 720 - degrees;
    lcd.print(" -");         
    lcd.print(degrees);       
    lcd.print((char)223);     
  //sensorValue = analogRead(analogInPin);
  //sensorValue2 = analogRead(analogInPin2);
  //absorbansi=sensorValue-sensorValue2;
  lcd.setCursor(0,1);
  lcd.print("Intensitas 1 = ");
  lcd.print(sensorValue);

  
 // delay(200);
  if (count == 8192) {
    time = millis();
    if ( time > 55000 && time < 65000) {
      RPM = numberOfRotations + 1;

    }
    delay(delay2); 
    count = 0; 
  numberOfRotations = 0;
    v1=0;
    v2=0;
  }
}
else if (degrees > 0 && degrees<720) {
    numberOfRotations = 2;
}

}
  //void loop
  }

  int GetNumber()
{
   
   int num = 0;
   char key = kpd.getKey();

   while(key != '#')
   {
      switch (key)
      {
         case NO_KEY:
            break;

         case '0': case '1': case '2': case '3': case '4':
         case '5': case '6': case '7': case '8': case '9':
 
          //  lcd.print(key);
          
            num = num * 10 + (key - '0');
            break;

         case '*':
            num = 0;
           // lcd.clear();
            break;
      }

      key = kpd.getKey();
   }

   return num;
   

}




 
