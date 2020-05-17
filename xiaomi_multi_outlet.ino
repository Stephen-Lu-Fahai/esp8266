#define BLINKER_WIFI
#define BLINKER_MIOT_MULTI_OUTLET

#include <Blinker.h>

char auth[] = "4f671feac515";
char ssid[] = "holdmoral";
char pswd[] = "Hdm2017!@@";

bool oState[5] = { false };

#define HOLE1 1
#define HOLE2 2
#define HOLE3 3
#define HOLE4 4

int GPIO1 = 4;
int GPIO2 = 5; 
int GPIO3 = 12;  
int GPIO4 = 14; 

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



void miotPowerState(const String & state, uint8_t num)
{
    BLINKER_LOG("need set outlet: ", num, ", power state: ", state);

    switch(num)
  {
      case HOLE1:
      {
         if (state == "on") 
         {
            digitalWrite(GPIO1, !digitalRead(GPIO1));
            BlinkerMIOT.powerState("on", num);
            BlinkerMIOT.print();
         }
        else if (state == "off") 
        {
            digitalWrite(GPIO1, !digitalRead(GPIO1));
            BlinkerMIOT.powerState("off", num);
            BlinkerMIOT.print();
        }
        
         break;  
      }  

      case HOLE2:
      {
         if (state == "on") 
         {
            digitalWrite(GPIO2, !digitalRead(GPIO2));
            BlinkerMIOT.powerState("on", num);
            BlinkerMIOT.print();
         }
        else if (state == "off") 
        {
            digitalWrite(GPIO2, !digitalRead(GPIO2));
            BlinkerMIOT.powerState("off", num);
            BlinkerMIOT.print();
        }
         break;  
      }  

      case HOLE3:
      {
         if (state == "on") 
         {
            digitalWrite(GPIO3, !digitalRead(GPIO3));
            BlinkerMIOT.powerState("on", num);
            BlinkerMIOT.print();
         }
        else if (state == "off") 
        {
            digitalWrite(GPIO3, !digitalRead(GPIO3));
            BlinkerMIOT.powerState("off", num);
            BlinkerMIOT.print();
        }
         break;  
      }  

      case HOLE4:
      {
         if (state == "on") 
         {
            digitalWrite(GPIO4, !digitalRead(GPIO4));
            BlinkerMIOT.powerState("on", num);
            BlinkerMIOT.print();
         }
        else if (state == "off") 
        {
            digitalWrite(GPIO4, !digitalRead(GPIO4));
            BlinkerMIOT.powerState("off", num);
            BlinkerMIOT.print();
        }
         break;  
      }  
  }
//    if (state == BLINKER_CMD_ON) {
//        digitalWrite(LED_BUILTIN, HIGH);
//
//        BlinkerMIOT.powerState("on", num);
//        BlinkerMIOT.print();
//
//        oState[num] = true;
//    }
//    else if (state == BLINKER_CMD_OFF) {
//        digitalWrite(LED_BUILTIN, LOW);
//
//        BlinkerMIOT.powerState("off", num);
//        BlinkerMIOT.print();
//
//        oState[num] = false;
//
//        if (num == 0)
//        {
//            for (uint8_t o_num = 0; o_num < 5; o_num++)
//            {
//                oState[o_num] = false;
//            }
//        }
//    }
}

void miotQuery(int32_t queryCode, uint8_t num)
{
    BLINKER_LOG("AliGenie Query outlet: ", num,", codes: ", queryCode);

    switch (queryCode)
    {
        case BLINKER_CMD_QUERY_ALL_NUMBER :
            BLINKER_LOG("MIOT Query All");
            BlinkerMIOT.powerState(oState[num] ? "on" : "off", num);
            BlinkerMIOT.print();
            break;
        case BLINKER_CMD_QUERY_POWERSTATE_NUMBER :
            BLINKER_LOG("MIOT Query Power State");
            BlinkerMIOT.powerState(oState[num] ? "on" : "off", num);
            BlinkerMIOT.print();
            break;
        default :
            BlinkerMIOT.powerState(oState[num] ? "on" : "off", num);
            BlinkerMIOT.print();
            break;
    }
}

void dataRead(const String & data)
{
    BLINKER_LOG("Blinker readString: ", data);

    Blinker.vibrate();
    
    uint32_t BlinkerTime = millis();
    
    Blinker.print("millis", BlinkerTime);
}

void setup()
{
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
    Blinker.attachData(dataRead);
   Button1.attach(button1_callback);
   Button2.attach(button2_callback);
   Button3.attach(button3_callback);
   Button4.attach(button4_callback);
    
    BlinkerMIOT.attachPowerState(miotPowerState);
    BlinkerMIOT.attachQuery(miotQuery);
}

void loop()
{
    Blinker.run();
}
