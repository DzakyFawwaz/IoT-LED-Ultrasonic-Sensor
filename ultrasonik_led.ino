#define led1 4
#define led2 2
#define led3 3

//define ultrasonik
#define echo 7
#define trigger 6

//define buzzer
#define buzz 5
int sound = 250;

void setup(){
  Serial.begin(9000);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  //pin LED
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(buzz, OUTPUT);
}

void loop(){
  long duration, distance;
  digitalWrite(trigger, LOW);
  delayMicroseconds(5); 
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigger, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 29.1;

  
//
//  if (distance <= 30) {
//    digitalWrite(led1, HIGH);
//    sound = 250;
//}
//  else {
//    digitalWrite(led1,LOW);
//  }
//  if (distance < 20) {
//      digitalWrite(led3, HIGH);
//      sound = 260;
//}
//  else {
//      digitalWrite(led3, LOW);
//  }
//  if (distance < 10) {
//      digitalWrite(led2, HIGH);
//      sound = 270;
//} 
//  else {
//    digitalWrite(led2, LOW);
//  }
//  
//
//  if (distance > 30 || distance <= 0){
//    Serial.println("Out of range");
//    noTone(buzz);
//  }
//  else {
//    Serial.print(distance);
//    Serial.println(" cm");
//    tone(buzz, sound);
//
//  }
//  delay(500);
//}

  if(distance <= 15){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  
  if(distance < 10){
    digitalWrite(led3, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led1, LOW);
    
  }

  if(distance < 5){
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
    digitalWrite(led3, LOW);
   
  }

  delay(500);

  if(distance < 15){
    digitalWrite(buzz, LOW);
  }

  if(distance < 10){
    digitalWrite(buzz, LOW);
  }

  if(distance < 5){
    digitalWrite(buzz, HIGH);
  }
}
