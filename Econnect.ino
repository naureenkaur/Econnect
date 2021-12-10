/* This circuit is designed for plants that require an automatic 
watering. A temperature sensor is used as a moisture sensor due
to unavaliablity. The BJT N-P-N transistor is used as a switch to
turn on and off the DC motor pump. The LCD screen is also implemented
as a way of getting feedbacks of the moisture levels in real time.
Two LEDs are also used which are to show when the plant is being
watered or not.
*/

#include <LiquidCrystal.h>


const int MoistureSensor = A0;
const int LED1 = 12;
const int LED2 = 11;
int MoistureValue;

const int capteur_D = 8;
const int capteur_A = A3;
int val_analogique;

int sensorValue = 0;

LiquidCrystal lcd(2,3,4,5,6,7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Auto Waterer");
  lcd.setCursor(0,1);
  lcd.print("Starting");

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  delay(2000);
  lcd.clear();
  lcd.print("Moisture");
  lcd.setCursor(0,1);
  lcd.print("System = ");
  
  pinMode(A1, INPUT);
  Serial.begin(9600);

  pinMode(9, OUTPUT);

  pinMode(capteur_D, INPUT);
  pinMode(capteur_A, INPUT);
  Serial.begin(9600);
 
}

void loop() {

  MoistureValue = analogRead(MoistureSensor);
  lcd.setCursor(12,0);
  lcd.print(50);
  lcd.setCursor(14,0);
  lcd.print("%"); 
  
  if (MoistureValue < 160){
    lcd.setCursor(9,0);
    lcd.print("< "); 

    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
     lcd.setCursor(9,1);
    lcd.print("ON ");
  }
  else {
    lcd.setCursor(9,0);
    lcd.print(">=");

    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    lcd.setCursor(9,1);
    lcd.print("OFF");
  }

  Serial.println("Temp:");
  Serial.println(MoistureValue);
    sensorValue = analogRead(A1);
  // print the sensor reading so you know its range
  Serial.println(sensorValue);
  // map the sensor reading to a range for the LED
  analogWrite(9, map(sensorValue, 0, 1023, 0, 255));
  delay(100); // Wait for 100 millisecond(s)

  if(digitalRead(capteur_D) == LOW) 
  {
    Serial.println("Digital value : wet"); 
    delay(10); 
  }
else
  {
    Serial.println("Digital value : dry");
    delay(10); 
  }
val_analogique=analogRead(capteur_A); 
 Serial.print("Analog value : ");
 Serial.println(val_analogique); 
 Serial.println("");
  delay(1000);
   
}
