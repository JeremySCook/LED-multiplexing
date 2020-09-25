int xValue[] = {5, 6, 7};
int yValue[] = {2, 3, 4};

void setup() {
  for (int z = 0; z < 3; z++){
pinMode(xValue[z], OUTPUT);
pinMode(yValue[z], OUTPUT);
  }
}

void loop() {
  for (int x = 0; x < 3; x++){
    digitalWrite(xValue[x], LOW);
    for (int y = 0; y < 3; y++){
      digitalWrite(yValue[y], HIGH);
      delay(500);
      }
        for (int z = 0; z < 3; z++){
          digitalWrite(xValue[z], HIGH);
          digitalWrite(yValue[z], LOW);
    }
  }
}
