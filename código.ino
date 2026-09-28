#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);

float celsius;
int LM35;
int ledG = 13;
int ledY = 12;
int ledR = 11;
int buzzer = 10;

void setup (){
  lcd.begin(16,2);
  lcd.clear();
  pinMode(ledG, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(A0, INPUT);  
}

void loop (){
  LM35=analogRead(A0);
  celsius = map(((LM35 - 20) * 3.04), 0, 1023, -40, 125);
  
  if (celsius < 30){
    digitalWrite(ledG, 1);
    digitalWrite(ledY, 0);
    digitalWrite(ledR, 0);
    digitalWrite(buzzer, 0);
    lcd.setCursor(0,0);
    lcd.print("Acesso Liberado  ");
    lcd.setCursor(0,1);
    lcd.print("Temp:            ");
    lcd.setCursor(6,1);
    lcd.print(celsius);
  }
  
  else if(celsius >= 30 && celsius <= 50){
    digitalWrite(ledG, 0);
    digitalWrite(ledY, 1);
    digitalWrite(ledR, 0);
    digitalWrite(buzzer, 1);
    delay(500);
    digitalWrite(buzzer, 0);
    delay(700);
    lcd.setCursor(0,0);
    lcd.print("Acesso BLOQUEADO ");
    lcd.setCursor(0,1);
    lcd.print("Temp:            ");
    lcd.setCursor(6,1);
    lcd.print(celsius);
  }    
  
  else if(celsius > 50){
    digitalWrite(ledG, 0);
    digitalWrite(ledY, 0);
    digitalWrite(ledR, 1);
    digitalWrite(buzzer, 1);
    lcd.setCursor(0,0);
    lcd.print("PERIGO           ");
    lcd.setCursor(0,1);
    lcd.print("Temp:            ");
    lcd.setCursor(6,1);
    lcd.print(celsius);
  }  
  
  else {
    lcd.setCursor(0,0);
    lcd.print("INICIANDO SISTEMA");
    lcd.setCursor(0,1);
    lcd.print("AGUARDE");
  }
}