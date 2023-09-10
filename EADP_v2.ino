const int potentiometerPin = A0;
const int redLED = 11;

const int buttonPin = 2;

int ledState = LOW;
int buttonState1 = 0;
int buttonState0 = 0;

float sensorValue = 0;

float y = 0;
float y_prev = 0;

// bpm : number of times chest or abdomen rises over the course of one minute
float bpm = 0;

float blinkDelay = 0;
int instanceCount = 0;

unsigned long startTime = 0;
unsigned long endTime = 0;
int timeDifference = 0 ;
int blinkCount = 0;
int ledStatus = 0;

int minuteFlag = 0;
unsigned long minuteStart = 0;
unsigned long minuteEnd = 0;

int brightness = 0;
int fadeAmount = 5;

int lightJump = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(redLED, OUTPUT);
  // pinMode(potentiometerPin, INPUT);
  pinMode(buttonPin, INPUT);
}

void debugOutputs()
{
  if (y != y_prev){
    y_prev = y;
    Serial.print(y);
    Serial.print(" , ");
    Serial.print(bpm);
    Serial.print(", ");
    Serial.print(blinkDelay);
    Serial.print(", ");
    Serial.print(buttonState1);
    Serial.println("");
    }
}

void inputProcess()
{  
  // sensorValue = analogRead(potentiometerPin);
  // y = map(sensorValue, 0, 1023, 0, 130);

  y = 10;

  bpm = (float)y + 10;
  blinkDelay = ((60.0 / bpm) * 1000) / 2;
}

void lightActions()
{
  buttonState1 = digitalRead(buttonPin);
  if ((buttonState1 != buttonState0) && (buttonState1 == HIGH))
  {
    lightJump = 1;
    buttonState0 = buttonState1;
  }

  if (lightJump == 0)
  {
    if (instanceCount == 0)
    {
      startTime = millis();
      digitalWrite(redLED, ledState);
      instanceCount += 1;
    }
    else if(instanceCount >= 1)
    {
      endTime = millis();
      timeDifference = endTime - startTime;
      if (timeDifference >= blinkDelay)
      {
        if (instanceCount == 2)
        {
          instanceCount = 0;
        }
        if (ledState == LOW)
        {
          ledState = HIGH;
        }
        else
        {
          ledState = LOW;
        }
        startTime = endTime;
        instanceCount += 1;
        digitalWrite(redLED, ledState);
      }
    }
  }
  else if (lightJump == 1)
  {
    if (ledState != HIGH)
    {
      ledState = HIGH;
      digitalWrite(redLED, ledState);
      startTime = millis();
    }
    
    if ((int)millis() - startTime >= blinkDelay)
    {
      digitalWrite(redLED, LOW);
      lightJump = 0;
      instanceCount = 0;
    }
  }
}

void loop()
{
  inputProcess();
  lightActions();
  debugOutputs();
}
