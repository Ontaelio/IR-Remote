#include <IRLib.h>

#define RECV_PIN 10 //with PCI 0 = pin2, 1 = pin3
//IRrecv irrecv(RECV_PIN);
IRrecv  My_Receiver(RECV_PIN);
IRdecode My_Decoder;
uint32_t IRresult;

void setup() {
  // put your setup code here, to run once:
My_Receiver.enableIRIn();
Serial.begin(9600);
  while (!Serial);

}

void loop() {
  // put your main code here, to run repeatedly:
if (My_Receiver.GetResults(&My_Decoder)) 
    { digitalWrite (13,HIGH);
    My_Receiver.resume();
    My_Decoder.decode();
    if (My_Decoder.value!=0xFFFFFFFF) 
      {IRresult=My_Decoder.value;
    
    
       if (IRresult>0)
      {Serial.print("#define xxx 0x");
       Serial.println(IRresult, HEX);
      }
      }
    }
}
