#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "e0a3ab8176b342a0a7c529202fcb2434";
char ssid[] = "amit";
char pass[] = "thakur123";
BlynkTimer timer;
const int trig = D1;
const int echo = D2;
unsigned long int  distance, duration;
void chart() {
  if (distance <= 10) {
    Blynk.tweet("its workinng");
    Blynk.email("kunalgarglibra@gmail.com", "work time", "go and collect dustbin of sector 29d chandigarh");
  }
  
}

void setup()
{ Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  timer.setInterval(3000L,chart);
  pinMode(moist, OUTPUT);
  pinMode(ir, INPUT);
  }

void loop()
{ Blynk.run();
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration / 58.2;
  Serial.println(distance);
  timer.run();
}
