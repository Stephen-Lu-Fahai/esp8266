#define BLINKER_WIFI
#define BLINKER_DUEROS_MULTI_OUTLET

#include <Blinker.h>
 
char auth[] = "4f671feac515";
char ssid[] = "008";
char pswd[] = "996402893";

#define HOLE1 1
#define HOLE2 2
#define HOLE3 3
#define HOLE4 4

int GPIO1 = 12;
int GPIO2 = 13; 
int GPIO3 = 14;  
int GPIO4 = 16; 

BlinkerButton Button1("bathroom");
BlinkerButton Button2("bedroom");
BlinkerButton Button3("restroom");
BlinkerButton Button4("desklamp");

void button1_callback(const String & state) {
 BLINKER_LOG("get button state: ", state);
 digitalWrite(GPIO1, !digitalRead(GPIO1));
 Blinker.vibrate();
}

void button2_callback(const String & state) {
 BLINKER_LOG("get button state: ", state);
 digitalWrite(GPIO2, !digitalRead(GPIO2));
 Blinker.vibrate();
}

void button3_callback(const String & state) {
 BLINKER_LOG("get button state: ", state);
 digitalWrite(GPIO3, !digitalRead(GPIO3));
 Blinker.vibrate();
}

void button4_callback(const String & state) {
 BLINKER_LOG("get button state: ", state);
 digitalWrite(GPIO4, !digitalRead(GPIO4));
 Blinker.vibrate();
}

void duerPowerState(const String & state, uint8_t num)
{

 BLINKER_LOG("need set power state: ", state);

  switch(num)
  {
      case HOLE1:
      {
         if (state == "on") 
         {
            digitalWrite(GPIO1, !digitalRead(GPIO1));
            BlinkerDuerOS.powerState("on", num);
            BlinkerDuerOS.print();
         }
        else if (state == "off") 
        {
            digitalWrite(GPIO1, !digitalRead(GPIO1));
            BlinkerDuerOS.powerState("off", num);
            BlinkerDuerOS.print();
        }
        
         break;  
      }  

      case HOLE2:
      {
         if (state == "on") 
         {
            digitalWrite(GPIO2, !digitalRead(GPIO2));
            BlinkerDuerOS.powerState("on", num);
            BlinkerDuerOS.print();
         }
        else if (state == "off") 
        {
            digitalWrite(GPIO2, !digitalRead(GPIO2));
            BlinkerDuerOS.powerState("off", num);
            BlinkerDuerOS.print();
        }
         break;  
      }  

      case HOLE3:
      {
         if (state == "on") 
         {
            digitalWrite(GPIO3, !digitalRead(GPIO3));
            BlinkerDuerOS.powerState("on", num);
            BlinkerDuerOS.print();
         }
        else if (state == "off") 
        {
            digitalWrite(GPIO3, !digitalRead(GPIO3));
            BlinkerDuerOS.powerState("off", num);
            BlinkerDuerOS.print();
        }
         break;  
      }  

      case HOLE4:
      {
         if (state == "on") 
         {
            digitalWrite(GPIO4, !digitalRead(GPIO4));
            BlinkerDuerOS.powerState("on", num);
            BlinkerDuerOS.print();
         }
        else if (state == "off") 
        {
            digitalWrite(GPIO4, !digitalRead(GPIO4));
            BlinkerDuerOS.powerState("off", num);
            BlinkerDuerOS.print();
        }
         break;  
      }  
  }

}

void setup() {

 Serial.begin(115200); 
 BLINKER_DEBUG.stream(Serial);

 pinMode(GPIO1, OUTPUT);
 digitalWrite(GPIO1, LOW);
  pinMode(GPIO2, OUTPUT);
 digitalWrite(GPIO2, LOW);
  pinMode(GPIO3, OUTPUT);
 digitalWrite(GPIO3, LOW);
  pinMode(GPIO4, OUTPUT);
 digitalWrite(GPIO4, LOW);

 Blinker.begin(auth, ssid, pswd);
 Button1.attach(button1_callback);
 Button2.attach(button2_callback);
 Button3.attach(button3_callback);
 Button4.attach(button4_callback);

 BlinkerDuerOS.attachPowerState(duerPowerState);
}
void loop() {
 Blinker.run();
}
