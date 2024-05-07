 #define LEDPIN_1 (uint8_t)(1<<PB5)
 #define LEDPIN_2 (uint8_t)(1<<PB4)
 #define LEDPIN_3 (uint8_t)(1<<PB3)
 #define LEDPIN_4 (uint8_t)(1<<PB2)
 #define LEDPIN_5 (uint8_t)(1<<PB1)
 #define LEDPIN_6 (uint8_t)(1<<PB0)
 #define LEDPIN_7 (uint8_t)(1<<PD7)
 #define LEDPIN_8 (uint8_t)(1<<PD6)
 #define LEDPIN_9 (uint8_t)(1<<PD5)
 #define LEDPIN_10 (uint8_t)(1<<PD4)

unsigned char ledpinB[6]={LEDPIN_1,LEDPIN_2,LEDPIN_3,LEDPIN_4,LEDPIN_5,LEDPIN_6};
unsigned char ledpinD[4]={LEDPIN_7,LEDPIN_8,LEDPIN_9,LEDPIN_10};
// #define PORT_ON(port,uint8_t pin) port|=(pin)
// #define PORT_OFF(port,uint8_t pin) port &=(~(pin))
// #define PORT_TOGGLE(port,uint8_t pin)port ^=(pin)

bool currentState,lastState=LOW,ledState=LOW;  bool state=LOW;

uint8_t count=0;
void setup() {
  // put your setup code here, to run once:
DDRB |= (LEDPIN_1) |(LEDPIN_2) |(LEDPIN_3) |(LEDPIN_4) |(LEDPIN_5) |(LEDPIN_6);
DDRD |= (LEDPIN_7) |(LEDPIN_8) |(LEDPIN_9) |(LEDPIN_10);

DDRD &= ~(1<<PD2); // set port pin as input

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 currentState =  isButtonPressed() ;
 _delay_ms(85);
 ledState = getLedState();
 
 lastState = currentState;
 Serial.println(ledState);
 if(ledState == HIGH)
 {
  //led chased code
    ledChaser();
 }
 else
 {
  //off the chaser
 // ledOff();
 //allLedOff();
 }
}//end of loop
bool getLedState()
{
 //   bool state=LOW; this statement coause led chaser to run one time only

if(currentState == HIGH && lastState == LOW)
 {
  count++;
  if(ledState == LOW)
  {
    state =  HIGH;
    // ledState = HIGH;
  }
  else if (ledState == HIGH)
  {
    state = LOW;
    //ledState = LOW;
  }
  Serial.println("in getLedState = ");
  Serial.print(state);
 }
 return state;
}
void blink(volatile uint8_t &port, volatile uint8_t pin)
{
  Serial.println(port);
  port |=pin;
  _delay_ms(400);
  port &= ~pin;
  _delay_ms(400);
}

void ledChaser()
{
for(uint8_t i=0;i<6;i++)
  {
    blink(PORTB,ledpinB[i]);
  }
  for(uint8_t i=0;i<4;i++)
  {
    blink(PORTD,ledpinD[i]);
  }
}

bool isButtonPressed()
{
  if(PIND & (1<<PIND2)) //when button is pressed
  {
    return LOW;
  }
  else
  {
    return HIGH;
  }
}
void allLedOff()
{
  for(uint8_t i = 0 ; i < 6;++i)
  {
    ledOff(PORTB,ledPinB[i]);
  }
    for(uint8_t i = 0 ; i < 4;++i)
  {
    ledOff(PORTD,ledPinD[i]);
  }
 // PORTB &= (~(LEDPIN_1)) & (~(LEDPIN_2)) & (~(LEDPIN_3)) & (~(LEDPIN_4)) & (~(LEDPIN_5)) & (~(LEDPIN_6));
  //PORTD &= (~(LEDPIN_7)) & (~(LEDPIN_8)) & (~(LEDPIN_9)) & (~(LEDPIN_10)); 
}
void ledOff(volatile uint8_t &port,uint8_t pin)
{
  port &= (~(pin));
}