#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

#define LED 2
#define GOMB 3

unsigned long previousMillis = millis();
const long kozte = 500;

bool ledallapot = LOW;
bool villog = true;
bool hosszan = false;
unsigned long nyomaskezdet = 0;
bool gombelozo = HIGH;

void setup()
{
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(GOMB, INPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:

  int gomb = digitalRead(GOMB);

  if (gomb == LOW && gombelozo == HIGH)
  {
    nyomaskezdet = millis();
  }

  if (gomb == HIGH && gombelozo == LOW)
  {
    unsigned long nyomasIdo = millis() - nyomaskezdet;

    if (nyomasIdo >= 500)
    {
      hosszan = true;
      villog = false;
      digitalWrite(LED, HIGH);
    }
    else
    {
      if (hosszan)
      {
        hosszan = false;
        villog = true;
        ledallapot = LOW;
        digitalWrite(LED, ledallapot);
      }
      else 
      {
          villog = !villog; 
          if (!villog) {
              digitalWrite(LED, LOW);
          }
      }
    }
  }

  gombelozo = gomb;

  if (villog)
  {
    villogas();
  }
  

}

void villogas()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= kozte)
  {
    previousMillis = currentMillis;

    ledallapot = !ledallapot;
    digitalWrite(LED, ledallapot);
  }
}
