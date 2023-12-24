#include <DHT.h>

const int sensorPin=A0;
const float baselineTemp = 21;
DHT dht(sensorPin, DHT11);

int temp;
int humidity;

int state;

void setup() {
  // put your setup code here, to run once:
  dht.begin();

  Serial.begin(9600);
  for(int x=2;x<7;x++){
    pinMode(x, OUTPUT);
    digitalWrite(x, LOW);
  }
}

void loop() {
  delay(250);

  temp = dht.readTemperature();
  humidity = dht.readHumidity();

  // put your main code here, to run repeatedly:

  Serial.print(temp);
  Serial.println(" degrees C ");

  Serial.print(humidity);
  Serial.println(" Humidity H ");


  if(temp<=baselineTemp){
    state=3;
  }
  else if(temp<=baselineTemp+2 && temp>baselineTemp){
    state=4;
  }
  else if(temp<=baselineTemp+4 && temp>baselineTemp+2){
    state=5;
  }
  else if(temp>baselineTemp+4){
    state=6;
  }

  for(int x=2;x<=state;x++){
    digitalWrite(x, HIGH);
  }

}
