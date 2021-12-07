#include "pitches.h"
String x;
String prev_key;
void all_off();
void all_on();
bool sound = true;
void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(13, OUTPUT);
  
}

void loop() {
  while (!Serial.available());
  x=Serial.readString();
  
  if (x=="f"){
    if (prev_key!=x){
    sound = true;
    }
    all_off();
    digitalWrite(22,0);
    digitalWrite(23,0);
    delay(300);
    if (sound == true){
    delay(300);
    tone(1);
    sound=false;
    }
    prev_key = x;
  }else if(x=="b"){
    if (prev_key!=x){
    sound = true;
    }
    all_off();
    digitalWrite(23,0);
    digitalWrite(24,0);
    delay(300);
    if (sound == true){
    tone(2);
    delay(500);
    tone(2);
    delay(500);
    sound=false;
    }   
    prev_key = x;
  }else if(x=="r"){
    if (prev_key!=x){
    sound = true;
    }
    all_off();
    digitalWrite(25,0);
    digitalWrite(13,1); 
    delay(300);
    if (sound == true){
    tone(3);
    delay(500);
    tone(3);
    delay(500);
    tone(3);
    delay(500);
    sound=false;
    }
    prev_key = x;
  }else if (x=="l"){
    if (prev_key!=x){
    sound = true;
    }
    all_off();
    digitalWrite(22,0);
    digitalWrite(25,0);
    delay(300);
    if (sound == true){
    tone(4);
    delay(500);
    tone(4);
    delay(500);
    tone(4);
    delay(500);
    tone(4);
    sound=false;
    }
    prev_key = x;
  }
}

void all_off() {
  digitalWrite(22,1);
  digitalWrite(23,1);
  digitalWrite(24,1);
  digitalWrite(25,1);
  digitalWrite(13,0);
  delay(300);
}
void all_on() {
  digitalWrite(22,0);
  digitalWrite(23,0);
  digitalWrite(24,0);
  digitalWrite(25,0);
  digitalWrite(13,1);
}

void tone(int n){
  if (n==1){
  tone(BDPIN_BUZZER,NOTE_C4,500);
  delay(500);
  }else if (n==2){
  tone(BDPIN_BUZZER,NOTE_G3,500);
  delay(500);
  }else if (n==3){
  tone(BDPIN_BUZZER,NOTE_A3,500);
  delay(500);
  }else if (n==4){
  tone(BDPIN_BUZZER,NOTE_B3,500);
  delay(500);
  }
}
