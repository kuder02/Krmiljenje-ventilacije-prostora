int potenciometer = A0;
int motor = 9;
int temperatura = A2;
float vrednost;

void setup() {
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(motor,OUTPUT);
  pinMode(temperatura,INPUT);
}


void loop() {
  if(digitalRead(3)==0){
    if(digitalRead(4)==0){
      digitalWrite(motor,LOW);
      digitalWrite(5,HIGH);
      vrednost = analogRead(potenciometer);
      vrednost = vrednost * 0.2492668622;
      analogWrite(motor,vrednost);
      Serial.println(vrednost);
    }
    else if(digitalRead(4)==1){
      digitalWrite(motor,LOW);
       digitalWrite(6,HIGH);
       digitalWrite(5,LOW);
      temperatura = analogRead(temperatura);
      temperatura = temperatura * 0.2492668622;
      Serial.println(temperatura);
      analogWrite(motor, temperatura);       
    }
      }
    else if(digitalRead(3)==1){
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(motor,HIGH);  
    }
}


