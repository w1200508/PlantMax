#include <CapacitiveSensor.h>
const int LED = 13;
const int GSR = A2;
int threshold = 0;
int sensorValue;

CapacitiveSensor   cs_1 = CapacitiveSensor(23, 22);      // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_2 = CapacitiveSensor(25, 24);       // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_3 = CapacitiveSensor(29, 28);
CapacitiveSensor   cs_4 = CapacitiveSensor(33, 32);
CapacitiveSensor   cs_5 = CapacitiveSensor(37, 36);
CapacitiveSensor   cs_6 = CapacitiveSensor(41, 40);
CapacitiveSensor   cs_7 = CapacitiveSensor(45, 44);
CapacitiveSensor   cs_8 = CapacitiveSensor(49, 48);
CapacitiveSensor   cs_9 = CapacitiveSensor(53, 52);

void setup()
{
  long sum = 0;
  cs_1.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  cs_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  cs_3.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  cs_4.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  cs_5.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  cs_6.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  cs_7.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  cs_8.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  cs_9.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);


  /*for (int i = 0; i < 500; i++)
    {
    sensorValue = analogRead(GSR);
    sum += sensorValue;
    delay(5);
    }
    threshold = sum / 500;
    //Serial.print("threshold =");
    //Serial.println(threshold);*/
}


void loop()
{
  long start = millis();
  long total1 =  cs_1.capacitiveSensor(30);
  long total2 =  cs_2.capacitiveSensor(30);
  long total3 =  cs_3.capacitiveSensor(30);
  long total4 =  cs_4.capacitiveSensor(30);
  long total5 =  cs_5.capacitiveSensor(30);
  long total6 =  cs_6.capacitiveSensor(30);
  long total7 =  cs_7.capacitiveSensor(30);
  long total8 =  cs_8.capacitiveSensor(30);
  long total9 =  cs_9.capacitiveSensor(30);

  sensorValue = analogRead(GSR);
  Serial.print(sensorValue);
  Serial.print("\t");
  Serial.print(total1);                  // print sensor output 1
  Serial.print("\t");
  Serial.print(total2);
  Serial.print("\t");
  Serial.print(total3);
  Serial.print("\t");
  Serial.print(total4);
  Serial.print("\t");
  Serial.print(total5);
  Serial.print("\t");
  Serial.print(total6);
  Serial.print("\t");
  Serial.print(total7);
  Serial.print("\t");
  Serial.print(total8);
  Serial.print("\t");
  Serial.print(total9);
  Serial.println();

  delay(100);                             // arbitrary delay to limit data to serial port
}
