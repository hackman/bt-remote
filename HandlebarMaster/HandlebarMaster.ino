#define Vx A0 // Define / Equate "Vx" with A0, the pin where Vx is connected
#define Vy A1 // Define / Equate "Vy" with A1, the pin where Vy is connected
#define Button A2 // Define / Equate Button with A2, the pin where the button is connected
#define DATA_PIN_2 2 //  left LED flash handlebar
#define DATA_PIN_3 3//  right LED flash handlebar
#define DATA_PIN_4 4//  up LED flash handlebar
#define DATA_PIN_5 5//  down LED flash handlebar
#define DATA_PIN_6 6//  joystick push button LED flash handlebar
#define DATA_PIN_7 7//  buzzer LED flash handlebar
char state;
int t=0;

void setup() {

  pinMode(Vx, INPUT); // Configure Vx (A0) as an Input
  pinMode(Vy, INPUT); // Configure Vy (A1) as an Input
  pinMode(Button, INPUT_PULLUP); // Configure Button (A2) as an Input, internally "pulled-up" to 5v
  pinMode(DATA_PIN_2, OUTPUT);
  pinMode(DATA_PIN_3, OUTPUT);
  pinMode(DATA_PIN_4, OUTPUT);
  pinMode(DATA_PIN_5, OUTPUT);
  pinMode(DATA_PIN_6, OUTPUT);
  Serial.begin(38400); 

}

void loop() {
  
  
  if (analogRead(Vx) <= 100) { // X-Axis Left
    Serial.write('L');
  }
  if (analogRead(Vx) >= 900) { // X-Axis Right
    Serial.write('R');
  }
  if (analogRead(Vy) <= 100) { // Y-Axis Up
    Serial.write('U');
  }
  if (analogRead(Vy) >= 900) { // Y-Axis Down
    Serial.write('D');
  }
  if (digitalRead(Button) == 0) { // Clear / Reset
    Serial.write('N');
  }
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read();
  }
    if (state == 'A') { // X-Axis Left
    LeftArrowFB();
  }
  if (state == 'D') { // X-Axis Right
    RightArrowFB();
  }
  if (state == 'W') { // Y-Axis Up
    ThumbsBadFB();
  }
  if (state == 'S') { // Y-Axis Down
    ThumbsUpFB();
  }
  if (state == 'C') { // Clear / Reset
    ClearFB();
  }
}

void LeftArrowFB() {
  
  while (state == 'A') {
  digitalWrite(DATA_PIN_2, LOW);
  digitalWrite(DATA_PIN_3, LOW);
  digitalWrite(DATA_PIN_4, LOW);
  digitalWrite(DATA_PIN_5, LOW);
  digitalWrite(DATA_PIN_6, LOW);
  digitalWrite(DATA_PIN_2, HIGH);
  delay(1000);
  digitalWrite(DATA_PIN_2, LOW);
  delay(1000); 
  }
}

void RightArrowFB() {

  while (state == 'D') {
  digitalWrite(DATA_PIN_2, LOW);
  digitalWrite(DATA_PIN_3, LOW);
  digitalWrite(DATA_PIN_4, LOW);
  digitalWrite(DATA_PIN_5, LOW);
  digitalWrite(DATA_PIN_6, LOW);
  digitalWrite(DATA_PIN_3, HIGH);
    delay(1000);
  digitalWrite(DATA_PIN_3, LOW);
  delay(1000); 
  }
}

void ThumbsBadFB() {

  while (state == 'W') {
  digitalWrite(DATA_PIN_2, LOW);
  digitalWrite(DATA_PIN_3, LOW);
  digitalWrite(DATA_PIN_4, LOW);
  digitalWrite(DATA_PIN_5, LOW);
  digitalWrite(DATA_PIN_6, LOW);
  digitalWrite(DATA_PIN_4, HIGH);
    delay(1000);
  digitalWrite(DATA_PIN_4, LOW);
  delay(1000); 
  }
}

void ThumbsUpFB() {

  while (state == 'S') {
  digitalWrite(DATA_PIN_2, LOW);
  digitalWrite(DATA_PIN_3, LOW);
  digitalWrite(DATA_PIN_4, LOW);
  digitalWrite(DATA_PIN_5, LOW);
  digitalWrite(DATA_PIN_6, LOW);
  digitalWrite(DATA_PIN_5, HIGH);
    delay(1000);
  digitalWrite(DATA_PIN_5, LOW);
  delay(1000); 
  }
}

void ClearFB() {

  while (state == 'C') {
  digitalWrite(DATA_PIN_2, LOW);
  digitalWrite(DATA_PIN_3, LOW);
  digitalWrite(DATA_PIN_4, LOW);
  digitalWrite(DATA_PIN_5, LOW);
  digitalWrite(DATA_PIN_6, LOW);
  digitalWrite(DATA_PIN_6, HIGH);
    delay(1000);
  digitalWrite(DATA_PIN_6, LOW);
  delay(1000); 
  }
}
