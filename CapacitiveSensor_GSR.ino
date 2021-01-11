#include <CapacitiveSensor.h>
const int LED = 13;
const int GSR = A2;
int threshold = 0;
int sensorValue;

CapacitiveSensor   cs_4_2 = CapacitiveSensor(42, 41);       // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
//CapacitiveSensor   cs_4_6 = CapacitiveSensor(8, 12);       // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
//CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil

void setup()
{
  long sum = 0;
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  delay(1000);

  for (int i = 0; i < 500; i++)
  {
    sensorValue = analogRead(GSR);
    sum += sensorValue;
    delay(5);
  }
  threshold = sum / 500;
  //Serial.print("threshold =");
  //Serial.println(threshold);
}


void loop()
{
  long start = millis();
  long total1 =  cs_4_2.capacitiveSensor(30);
  //long total2 =  cs_4_6.capacitiveSensor(30);
  int temp;
  sensorValue = analogRead(GSR);
  Serial.print(sensorValue);
  Serial.print("\t");
  Serial.print(total1);                  // print sensor output 1
  Serial.print("\t");
  //Serial.print(total2);
  Serial.println();

  delay(10);                             // arbitrary delay to limit data to serial port
}
