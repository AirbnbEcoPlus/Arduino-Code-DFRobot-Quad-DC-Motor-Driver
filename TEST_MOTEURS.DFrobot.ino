
const int E1 = 3; ///vitesse moteur avant gauche MOTEUR1
const int E2 = 11;///vitesse moteur avant droit MOTEUR2
const int E3 = 5; ///vitesse moteur arrière gauche MOTEUR3
const int E4 = 6; ///vitesse moteur arrère droit MOTEUR4

const int M1 = 4; /// Direction du MOTEUR1 avance si "HIGH"___ recule si "LOW"
const int M2 = 12;///Direction du MOTEU R2 avance si "HIGH"___ recule si "LOW"
const int M3 = 8; ///Direction du MOTEUR3 avance si "HIGH"___ recule si "LOW"
const int M4 = 7; ///Direction du MOTEUR4 avance si "HIGH"___ recule si "LOW"

const int portPot = 0;

const int bpUp = 2;
const int bpDown = 9;


int initialSpeed=100; //permet de regler la vitesse 
int Speed;
int Speed2;

int valpot;
int etatBpUp;
int etatBpDown;



boolean isForward;
boolean isBackward;
void forward(){
digitalWrite(M1,HIGH);
 analogWrite(E1,initialSpeed);
 digitalWrite(M2,LOW);
 analogWrite(E2,initialSpeed);
 digitalWrite(M3,LOW);
 analogWrite(E3, initialSpeed);
 digitalWrite(M4,HIGH);
 analogWrite(E4,initialSpeed);
}
void backward(){
digitalWrite(M1,LOW);
 analogWrite(E1,initialSpeed);
 digitalWrite(M2,HIGH);
 analogWrite(E2,initialSpeed);
 digitalWrite(M3,HIGH);
 analogWrite(E3, initialSpeed);
 digitalWrite(M4,LOW);
 analogWrite(E4,initialSpeed);
}
void forwardAndTurn(int potar){
  //Tourner a droite
   if(potar < 512){
    Speed = map(valpot, 512, 0, initialSpeed, 255);
    Speed2 = map(valpot, 512, 0, initialSpeed, 0);
    digitalWrite(M1,HIGH);
    analogWrite(E1,Speed);
    digitalWrite(M2,LOW);
    analogWrite(E2,Speed);
    digitalWrite(M3,LOW);
    analogWrite(E3, Speed2);
    digitalWrite(M4,HIGH);
    analogWrite(E4, Speed2);
   }
   //Tourner a gauche
   if(potar > 512){
    Speed = map(valpot, 512, 1023, initialSpeed, 255);
    Speed2 = map(valpot, 512, 1023, initialSpeed, 0);
    digitalWrite(M1,HIGH);
    analogWrite(E1, Speed2);
    digitalWrite(M2,LOW);
    analogWrite(E2, Speed2);
    digitalWrite(M3,LOW);
    analogWrite(E3,Speed);
    digitalWrite(M4,HIGH);
    analogWrite(E4,Speed);
   }
}
void backwardAndTurn(int potar){
//Tourner a droite
   if(potar < 512){
    Speed = map(valpot, 512, 0, initialSpeed, 255);
    Speed2 = map(valpot, 512, 0, initialSpeed, 0);
    digitalWrite(M1,LOW);
    analogWrite(E1,Speed);
    digitalWrite(M2,HIGH);
    analogWrite(E2,Speed);
    digitalWrite(M3,HIGH);
    analogWrite(E3, Speed2);
    digitalWrite(M4,LOW);
    analogWrite(E4, Speed2);
   }
   //Tourner a gauche
   if(potar > 512){
    Speed = map(valpot, 512, 1023, initialSpeed, 255);
    Speed2 = map(valpot, 512, 1023, initialSpeed, 0);
    digitalWrite(M1,LOW);
    analogWrite(E1, Speed2);
    digitalWrite(M2,HIGH);
    analogWrite(E2, Speed2);
    digitalWrite(M3,HIGH);
    analogWrite(E3,Speed);
    digitalWrite(M4,LOW);
    analogWrite(E4,Speed);
   }
 
}
void rotate(int potar){
  //Tourner a droite
  if(potar < 512){
    Speed = map(valpot, 512, 0, 0, 255);
    Serial.print("DROITE/Speed is : ");
    Serial.println(Speed);
    digitalWrite(M1,HIGH);
    analogWrite(E1,Speed);
    digitalWrite(M2,LOW);
    analogWrite(E2,Speed);
    digitalWrite(M3,HIGH);
    analogWrite(E3,Speed);
    digitalWrite(M4,LOW);
    analogWrite(E4,Speed);
  }
  //Tourner a gauche
  if(potar > 512){
    Speed = map(valpot, 512, 1023, 0, 255);
    Serial.print("GAUCHE/Speed is : ");
    Serial.println(Speed);
    digitalWrite(M1,LOW);
    analogWrite(E1,Speed);
    digitalWrite(M2,HIGH);
    analogWrite(E2,Speed);
    digitalWrite(M3,LOW);
    analogWrite(E3,Speed);
    digitalWrite(M4,HIGH);
    analogWrite(E4,Speed);
  }
}
void setup() {
  Serial.begin(9600);
  // met les broches de 3 à 9 en sortie
  for(int i=3;i<9;i++)
    pinMode(i,OUTPUT);
    // met les broches de 11 à 13 en sortie
  for(int i=11;i<13;i++)
    pinMode(i,OUTPUT);

  
}

void loop() {
etatBpUp = digitalRead(bpUp);
etatBpUp = digitalRead(bpDown);

if(etatBpUp == 1){
  forward();
  isForward = true;
}else{
  isForward = false;
}

if(etatBpDown == 1){
  backward();
  isBackward = true;
}else{
  isBackward = false;
}



valpot = analogRead(portPot);
if(isForward == true && isBackward == false){
forwardAndTurn(valpot);
}
if(isBackward == true && isForward == false){
  backwardAndTurn(valpot);
}
if(isBackward == false && isForward == false){
  rotate(valpot);
}




}
