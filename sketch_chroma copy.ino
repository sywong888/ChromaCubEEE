//-----ChromaCubEEE-----//

int g1LED = 13;
int g2LED = 10;
int g3LED = 5;
int g4LED = 3;

int y1LED = 9;
int y2LED = 8;
int y3LED = 7;
int y4LED = 6;

int r1LED = 12;
int r2LED = 11;
int r3LED = 4;
int r4LED = 2;

int received = 0;
int light_state = 0;

unsigned long previousMillis = 0;
unsigned long currentMillis = 0;

int happened = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(g1LED, OUTPUT);
  pinMode(g2LED, OUTPUT);
  pinMode(g3LED, OUTPUT);
  pinMode(g4LED, OUTPUT);
  
  pinMode(y1LED, OUTPUT);
  pinMode(y2LED, OUTPUT);
  pinMode(y3LED, OUTPUT);
  pinMode(y4LED, OUTPUT);
  
  pinMode(r1LED, OUTPUT);
  pinMode(r2LED, OUTPUT);
  pinMode(r3LED, OUTPUT); 
  pinMode(r4LED, OUTPUT);
}

void loop() {

  if (happened == 4) {
    light_state = 0; 
    happened = 0;
    received = 3;
  } 

  if (Serial.available() > 0) {
    received = Serial.read();
  }
  
  if (received == '2') {
    light_state = 0; //off
    happened = 0;
    received = 3;
  }

  if (received == '1' && happened == 0 && light_state == 0) {
    light_state = 1; //on
    happened = 1; //1 means start button was pressed
    previousMillis = millis(); //starting timer
  }

  currentMillis = millis();

  if ((happened == 1 || happened == 2 || happened == 3) && light_state == 1 && currentMillis - previousMillis >= 30000) {
   
    if (happened == 1) {
      for (int i = 0; i < 20; i++) {
        digitalWrite(g1LED, HIGH);
        digitalWrite(g2LED, HIGH);
        digitalWrite(g3LED, HIGH);
        digitalWrite(g4LED, HIGH);
        delay(100);
        digitalWrite(g1LED, LOW);
        digitalWrite(g2LED, LOW);
        digitalWrite(g3LED, LOW);
        digitalWrite(g4LED, LOW);
        delay(100);
      }
      happened = 2;
      
      previousMillis = currentMillis;
    }
    
    else if (happened == 2) {
      for (int i = 0; i < 20; i++) {
        digitalWrite(y1LED, HIGH);
        digitalWrite(y2LED, HIGH);
        digitalWrite(y3LED, HIGH);
        digitalWrite(y4LED, HIGH);
        delay(100);
        digitalWrite(y1LED, LOW);
        digitalWrite(y2LED, LOW);
        digitalWrite(y3LED, LOW);
        digitalWrite(y4LED, LOW);
        delay(100);
      }
      happened = 3;
      
      previousMillis = currentMillis;
    }
    
    else if (happened == 3) {
      for (int i = 0; i < 20; i++) {
        digitalWrite(r1LED, HIGH);
        digitalWrite(r2LED, HIGH);
        digitalWrite(r3LED, HIGH);
        digitalWrite(r4LED, HIGH);
        delay(100);
        digitalWrite(r1LED, LOW);
        digitalWrite(r2LED, LOW);
        digitalWrite(r3LED, LOW);
        digitalWrite(r4LED, LOW);
        delay(100);
      }
      happened = 4;
      previousMillis = currentMillis;
    }
  }
}
