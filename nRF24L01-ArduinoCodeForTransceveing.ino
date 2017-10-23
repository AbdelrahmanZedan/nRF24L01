//////////////////////////////////////////////////////
//communication libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//////////////////////////////////////////////////////
//CE & CSN pins
#define ce 9
#define csn 10

bool listeningIndicator=true;
char go;
char come;

const uint64_t p1 = 0xA2A2A2A2B4LL;
const uint64_t p2 = 0xE5E5E5E5E5LL;

RF24 radio(ce,csn);
///////////////////////////////////////////////////////

void setup() {  
  Serial.begin(9600);
  //radio setup:
  radio.begin();
  radio.setPALevel(RF24_PA_MIN); 
  radio.enableAckPayload();
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(p1);
  radio.openReadingPipe(1,p2);
  radio.startListening();
}

void loop (){
  if(Serial.available()>0){
    go=Serial.read();
    trans(go);
    Serial.print("Sending: ");
    Serial.println(go);
  }
  come = rec();
  if(come != ' '){
    Serial.print("Receiving: ");
    Serial.println(come);
    come=' ';
  }
}

void trans (char n){
  if(listeningIndicator==true){
    radio.stopListening();
    listeningIndicator=false;
  }
  radio.write(&n,sizeof(n));  
  /*bool done=false;
  while(!done){
    done= radio.write(&n,sizeof(n));
  }*/
}

char rec (){
  char n=' ';
  if(listeningIndicator==false){
    radio.startListening();
    listeningIndicator=true;
  }
  if(radio.available()){
    bool done=false;
    while(!done){
      done=radio.read(&n,sizeof(n));
    }
    return n;
  }
  else if(!radio.available()) {
    return ' ';
  }
}
