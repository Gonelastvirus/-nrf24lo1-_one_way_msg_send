#include<nRF24L01.h>
#include<SPI.h>
#include<RF24.h>
RF24 radio(7,8);//CE, CSN
const byte address[6]="00001";
/*
//Transmeter

void setup() {
radio.begin();
radio.openWritingPipe(address);//we set the address of the receiver to which we will send data
radio.setPALevel(RF24_PA_MIN);//we set the Power Amplifier level, in our case I will set it to minimum as my modules are very close to each other.
//Note that if using a higher level it is recommended to use a bypass capacitors across GND and 3.3V of the modules so that they have more stable voltage while operating.

radio.stopListening();//sets module as transmitter, and on the other side, we have the radio.startListening() function which sets the module as receiver.
}

void loop() {
const char text[]="hello world";
radio.write(&text,sizeof(text));
delay(1000);

}*/
//receiver
void setup(){
Serial.begin(9600);
radio.begin();
radio.openReadingPipe(0,address);
radio.setPALevel(RF24_PA_MIN);
radio.startListening();
}
void loop(){
if(radio.available()){
char text[32]="";
radio.read(&text,sizeof(text));
Serial.print(text);
Serial.print("\n");
}

}
