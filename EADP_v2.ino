const int potentiometerPin = A0;
const int redLED = 11;
const int greenLED = 3;

int ledState = LOW;

float sensorValue = 0;

float y = 0;
float y_prev = 0;
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
int runDuration = 0;
int runCount = 0;

unsigned long tempVar1 = 0;
unsigned long tempVar2 = 0;
int tempVar3 = 0;
int tempVar4 = 0;

void setup() {
  Serial.begin(115200);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(potentiometerPin, INPUT);
}

void debugOutputs(){
  if (y != y_prev){
    y_prev = y;
    Serial.print(y);
    Serial.print(" , ");
    Serial.print(bpm);
    Serial.print(", ");
    Serial.print(blinkDelay);
    Serial.print(", ");
    Serial.print(runCount);
    Serial.println("");
    }
}

void minuteNotify(){
  if (minuteFlag == 0){
    minuteFlag = 1;
    minuteStart = millis();
  }
  else if (minuteFlag == 1){
    minuteEnd = millis();
    runDuration = minuteEnd - minuteStart;
    if (runDuration == 60){
      minuteFlag = 0;
      runCount += 1;
    }
  }
}

/*

void preliminaryChecks(){
  if (blinkCount == 60){
    ledStatus == 1;
    blinkCount == 0;
  }
  if (ledStatus == 1){
    digitalWrite(greenLED, HIGH);
  }
}

*/

void inputProcess(){
  sensorValue = analogRead(potentiometerPin);
  y = map(sensorValue, 0, 1023, 0, 130);

  bpm = (float)y + 10;
  blinkDelay = ((60.0 / bpm) * 1000) / 2;
}

void lightActions(){
  if (instanceCount == 0){
    instanceCount += 1;
    startTime = millis();
    digitalWrite(redLED, ledState);
  }
  else if(instanceCount == 1){
    endTime = millis();
    timeDifference = endTime - startTime;
    if (timeDifference >= blinkDelay){
      if (ledState == LOW){
        ledState = HIGH;
      }
      else{
        ledState = LOW;
      }
      startTime = endTime;
      digitalWrite(redLED, ledState);
      Serial.println(2*timeDifference);
      if (tempVar3 == 0){
        tempVar3 = 1;
        tempVar1 = millis();
      }
      if (tempVar3 == 1){
        tempVar2 = millis();
        tempVar4 = tempVar2 - tempVar1;
        if (tempVar4 >= blinkDelay){
          tempVar1 = tempVar2;
          instanceCount = 0;
          }
        }
    }
  }
}

void loop(){
  // preliminaryChecks();
  // minuteNotify();
  inputProcess();
  lightActions();
  debugOutputs();
}
