#define ENCA1 19
#define ENCB1 16
#define PWM1 22
#define IN1 23

#define ENCA2 32
#define ENCB2 33
#define PWM2 25
#define IN2 26

int pos1 = 0;
int pos2 = 0;
void setup() {
  Serial.begin(9600);
  pinMode(ENCA1,INPUT);
  pinMode(ENCB1,INPUT);
  pinMode(ENCA2,INPUT);
  pinMode(ENCB2,INPUT);
  pinMode(PWM1,INPUT);
  pinMode(IN1,INPUT);
  pinMode(PWM2,INPUT);
  pinMode(IN2,INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA1),readEncoder1,RISING);
  attachInterrupt(digitalPinToInterrupt(ENCA2),readEncoder2,RISING);
}

void loop() {
  setMotor(1, 255, PWM1, IN1);
  setMotor(1, 255, PWM2,IN2);
  delay(5000);
  Serial.print("pos1\t");
  Serial.print(pos1);
  Serial.print("pos2\t");
  Serial.println(pos2);
  setMotor(-1, 255, PWM1, IN1);
  setMotor(-1, 255, PWM2,IN2);
  delay(5000);
  Serial.print("pos1\t");
  Serial.print(pos1);
  Serial.print("pos2\t");
  Serial.println(pos2);
  setMotor(0, 0, PWM1, IN1);
   setMotor(0, 0, PWM2,IN2);
  delay(1000);
  Serial.print("pos1\t");
  Serial.print(pos1);
  Serial.print("pos2\t");
  Serial.println(pos2);
}

void setMotor(int dir, int pwmVal, int pwm, int in1){
  analogWrite(pwm,pwmVal);
  if(dir == 1){
    digitalWrite(in1,HIGH);
  }
  else if(dir == -1){
    digitalWrite(in1,LOW);
  }
  else{
    digitalWrite(in1,LOW);
  }
}

void readEncoder1(){
  int b = digitalRead(ENCB1);
  if(b > 0){
    pos1++;
  }
  else{
    pos1--;
  }
}
void readEncoder2(){
  int b = digitalRead(ENCB2);
  if(b > 0){
    pos2++;
  }
  else{
    pos2--;
  }
}