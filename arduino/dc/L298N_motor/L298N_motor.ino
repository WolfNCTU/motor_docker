const int motorIN1 = 5;
const int motorIN2 = 6;
const int motorIN3 = 10;
const int motorIN4 = 11;

const int TIME = 3000;
const int PAUSE = 1000;

void setup(){
  pinMode(motorIN1, OUTPUT);
  pinMode(motorIN2, OUTPUT);
  pinMode(motorIN3, OUTPUT);
  pinMode(motorIN4, OUTPUT);
}

void STOP(){
  digitalWrite(motorIN1, LOW);
  digitalWrite(motorIN2, LOW);
  digitalWrite(motorIN3, LOW);
  digitalWrite(motorIN4, LOW);
}

void CWturn(){
  digitalWrite(motorIN1, HIGH);
  digitalWrite(motorIN2, LOW);
  digitalWrite(motorIN3, LOW);
  digitalWrite(motorIN4, LOW);
}

void CCWturn(){
  digitalWrite(motorIN1, LOW);
  digitalWrite(motorIN2, HIGH);
  digitalWrite(motorIN3, LOW);
  digitalWrite(motorIN4, LOW);
}

void selfTest(){
  CWturn();
  delay(TIME);
  STOP();
  delay(PAUSE);
  CCWturn();
  delay(TIME);
  STOP();
  delay(PAUSE);
}

void loop(){
  selfTest();
}
