#define BLINKER_WIFI
#define BLINKER_MIOT_LIGHT

#include <Blinker.h>
 
char auth[] = "331585465827";
char ssid[] = "XFYJ";
char pswd[] = "www.0825.com";
 
int GPIO = 0; 
 

BlinkerButton Button1("btn-abc");
 
void button1_callback(const String & state) {
 BLINKER_LOG("get button state: ", state);
 digitalWrite(GPIO, !digitalRead(GPIO));
 Blinker.vibrate();
}
 
void miotPowerState(const String & state)
{
 BLINKER_LOG("need set power state: ", state);
 if (state == "on") {
 digitalWrite(GPIO, LOW);
 BlinkerMIOT.powerState("on");
 BlinkerMIOT.print();
 }
 else if (state == "off") {
 digitalWrite(GPIO, HIGH);
 BlinkerMIOT.powerState("off");
 BlinkerMIOT.print();
 }
}
 
void setup() {

 Serial.begin(115200); 
 BLINKER_DEBUG.stream(Serial);

 pinMode(GPIO, OUTPUT);
 digitalWrite(GPIO, HIGH);
 

 Blinker.begin(auth, ssid, pswd);
 Button1.attach(button1_callback);

 BlinkerMIOT.attachPowerState(miotPowerState);
}
void loop() {
 Blinker.run();
}
