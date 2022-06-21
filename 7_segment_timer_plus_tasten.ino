int pin_a = 6;
int pin_b = 7;
int pin_c = 8;
int pin_d = 9;
int pin_e = 10;
int pin_f = 11;
int pin_g = 12;
int gnd_4 = 4;

int pin_taste_1 = 2;
byte taste_1_zustand = 0;
int pin_taste_2 = 3;
byte taste_2_zustand = 0;
int pin_taste_3 = 5;
byte taste_3_zustand = 0;

byte zahlen[10] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};
byte number;

void setup(){
  pinMode(pin_a, OUTPUT);
  pinMode(pin_b, OUTPUT);
  pinMode(pin_c, OUTPUT);
  pinMode(pin_d, OUTPUT);
  pinMode(pin_e, OUTPUT);
  pinMode(pin_f, OUTPUT);
  pinMode(pin_g, OUTPUT);
  pinMode(gnd_4, OUTPUT);
  pinMode(pin_taste_1, INPUT_PULLUP);
  pinMode(pin_taste_2, INPUT_PULLUP);
  pinMode(pin_taste_3, INPUT_PULLUP);
  Serial.begin(9600);
}
 
void loop(){
  int zahl = 0b01001001;
  for (int i = 0; i < 7; ++i) {
    boolean enableSegment = bitRead(zahl, i);
    digitalWrite(i + 6, enableSegment);
  }
  delay(10);

  //Taste 1
  if (digitalRead(pin_taste_1) == LOW & !taste_1_zustand) {
    taste_1_zustand = 1;
    Serial.println("Taste 1");
    for (int j = 0; j <= 9; j++) {
      int zahl = zahlen[j];
      for (int i = 0; i < 7; ++i) {
        boolean enableSegment = bitRead(zahl, i);
        digitalWrite(i + 6, enableSegment);
      }
      delay(1000);
      if (digitalRead(pin_taste_1) == HIGH & taste_1_zustand) {
        taste_1_zustand = 0;
        break;
      }
    }
  } 
  delay(10);
  

  // Taste 2
  if (digitalRead(pin_taste_2) == LOW & !taste_2_zustand) {
    taste_2_zustand = 1;
    Serial.println("Taste 2");
    for (int j = 9; j >= 0; j--) {
      int zahl = zahlen[j];
      for (int i = 0; i < 7; ++i) {
        boolean enableSegment = bitRead(zahl, i);
        digitalWrite(i + 6, enableSegment);
      }
      delay(1000);
      if (digitalRead(pin_taste_2) == HIGH & taste_2_zustand) {
        taste_2_zustand = 0;
        break;
      }
    }
  } 
  delay(10);

  //Taste 3
  if (digitalRead(pin_taste_3) == LOW & !taste_3_zustand) {
    taste_3_zustand = 1;
    Serial.println("Taste 3");
    for (int j = 9; j >= 0; j--) {
      int zahl = zahlen[j];
      for (int i = 0; i < 7; ++i) {
        boolean enableSegment = bitRead(zahl, i);
        digitalWrite(i + 6, enableSegment);
      }
      delay(1000);
    }
  }
}
