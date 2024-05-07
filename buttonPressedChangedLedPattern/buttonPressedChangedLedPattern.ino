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
 enum patternState{
  ALL_LED_OFF,
  PATTERN_A ,
  PATTERN_2 ,
  PATTERN_3,
  PATTERN_c,
  PATTERN_e,
  PATTERN_f,
  PATTERN_g,
  PATTERN_k,
  PATTERN_p,
  PATTERN_s,
  PATTERN_4,
  PATTERN_6,
  PATTERN_7,
  PATTERN_9
 }patternValue;
 unsigned char ledpinB[6]={LEDPIN_1,LEDPIN_2,LEDPIN_3,LEDPIN_4,LEDPIN_5,LEDPIN_6};
unsigned char ledpinD[4]={LEDPIN_7,LEDPIN_8,LEDPIN_9,LEDPIN_10};
bool currentState,lastState=LOW;  bool state=LOW;
uint8_t count=0;
uint8_t ledState=0;
void setup() {
  // put your setup code here, to run once:
DDRB |= (LEDPIN_1) |(LEDPIN_2) |(LEDPIN_3) |(LEDPIN_4) |(LEDPIN_5) |(LEDPIN_6);
DDRD |= (LEDPIN_7) |(LEDPIN_8) |(LEDPIN_9) |(LEDPIN_10);
DDRD &= ~(1<<PD2); // set port pin as input

}

void loop() {
  // put your main code here, to run repeatedly:
   currentState =  isButtonPressed() ;
   _delay_ms(85);
 ledState = getLedState();
 lastState = currentState;
 switch(ledState)
 {
  case PATTERN_A:pattern_A();break;
  case PATTERN_2:pattern_2();break;
  case PATTERN_3:pattern_3();break;
  case PATTERN_c:pattern_c();break;
  case PATTERN_e:pattern_e();break;
  case PATTERN_f:pattern_f();break;
  case PATTERN_g:pattern_g();break;
  case PATTERN_k:pattern_k();break;
  case PATTERN_p:pattern_p();break;
  case PATTERN_s:pattern_s();break;
  case PATTERN_4:pattern_4();break;
  case PATTERN_6:pattern_6();break;
  case PATTERN_7:pattern_7();break;
  case PATTERN_9:pattern_9();break;
  
  default:allLedOff();break;
 }
//   _delay_ms(1000);pattern_A();
//   _delay_ms(1000);pattern_2();
//  _delay_ms(1000); pattern_3();
//  _delay_ms(1000);pattern_c();
//  _delay_ms(1000);pattern_e();
//  _delay_ms(1000);pattern_f();
//  _delay_ms(1000); pattern_g();
//  _delay_ms(1000);pattern_k();
//  _delay_ms(1000);pattern_p();
//  _delay_ms(1000);pattern_s();
//  _delay_ms(1000);pattern_4();
//  _delay_ms(1000);pattern_6();
//  _delay_ms(1000);pattern_7();
//  _delay_ms(1000);pattern_9();
}
/**********************************PATTERN STARTED******************************/
void pattern_A()
{
  ledOn(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOn(PORTB,LEDPIN_3);ledOn(PORTB,LEDPIN_4);
  ledOn(PORTB,LEDPIN_5);ledOn(PORTB,LEDPIN_6);
  ledOn(PORTD,LEDPIN_7);ledOn(PORTD,LEDPIN_8);ledOn(PORTD,LEDPIN_9);ledOn(PORTD,LEDPIN_10);
}
void pattern_2()
{
  ledOn(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOn(PORTB,LEDPIN_3);ledOff(PORTB,LEDPIN_4);ledOff(PORTB,LEDPIN_5);
  ledOn(PORTB,LEDPIN_6);ledOn(PORTD,LEDPIN_8);ledOn(PORTD,LEDPIN_9);ledOff(PORTD,LEDPIN_7);ledOff(PORTD,LEDPIN_10);

}
void pattern_3()
{
  ledOn(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOn(PORTB,LEDPIN_3);ledOff(PORTB,LEDPIN_4);ledOff(PORTB,LEDPIN_5);ledOn(PORTB,LEDPIN_6);
  
  ledOn(PORTD,LEDPIN_7);ledOff(PORTD,LEDPIN_8);ledOn(PORTD,LEDPIN_10);ledOn(PORTD,LEDPIN_9);
}
void pattern_c()
{
  ledOn(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOff(PORTB,LEDPIN_3);ledOn(PORTB,LEDPIN_4);ledOff(PORTB,LEDPIN_5);
  ledOn(PORTB,LEDPIN_6);
  ledOff(PORTD,LEDPIN_7);ledOn(PORTD,LEDPIN_8);ledOn(PORTD,LEDPIN_10);ledOn(PORTD,LEDPIN_9);
}
void pattern_e()
{
  ledOn(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOn(PORTB,LEDPIN_4);ledOff(PORTB,LEDPIN_3);
  ledOn(PORTB,LEDPIN_6);ledOn(PORTB,LEDPIN_5);
  ledOn(PORTD,LEDPIN_8);ledOn(PORTD,LEDPIN_10);ledOn(PORTD,LEDPIN_9);ledOff(PORTD,LEDPIN_7);
}
void pattern_f()
{
  ledOn(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOn(PORTB,LEDPIN_4);ledOff(PORTB,LEDPIN_3);
  ledOn(PORTB,LEDPIN_6);ledOn(PORTB,LEDPIN_5);
  ledOn(PORTD,LEDPIN_8);ledOn(PORTD,LEDPIN_10);ledOff(PORTD,LEDPIN_7);ledOff(PORTD,LEDPIN_9);
}
void pattern_g()
{
  ledOn(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOn(PORTB,LEDPIN_4);ledOff(PORTB,LEDPIN_3);ledOff(PORTB,LEDPIN_5);
  ledOn(PORTB,LEDPIN_6);
  ledOn(PORTD,LEDPIN_8);ledOn(PORTD,LEDPIN_7);ledOn(PORTD,LEDPIN_9);
  ledOn(PORTD,LEDPIN_10);
}
void pattern_k()
{
  ledOn(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOn(PORTB,LEDPIN_4);ledOff(PORTB,LEDPIN_3);ledOff(PORTB,LEDPIN_5);
  ledOn(PORTB,LEDPIN_6);
  ledOn(PORTD,LEDPIN_8);ledOn(PORTD,LEDPIN_9);ledOff(PORTD,LEDPIN_7);
  ledOn(PORTD,LEDPIN_10);
}

void pattern_p()
{
  ledOn(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOn(PORTB,LEDPIN_3);ledOn(PORTB,LEDPIN_4);
  ledOn(PORTB,LEDPIN_6); ledOff(PORTB,LEDPIN_5);
  ledOn(PORTD,LEDPIN_8);ledOff(PORTD,LEDPIN_7);ledOff(PORTD,LEDPIN_9);
  ledOn(PORTD,LEDPIN_10);
}
void pattern_s()
{
  ledOn(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOn(PORTB,LEDPIN_4);ledOff(PORTB,LEDPIN_3);
  ledOn(PORTB,LEDPIN_6);ledOn(PORTD,LEDPIN_10);
  ledOn(PORTD,LEDPIN_7);
  ledOn(PORTD,LEDPIN_9);
}
void pattern_4()
{
  ledOff(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOff(PORTB,LEDPIN_3);ledOn(PORTB,LEDPIN_4);
  ledOn(PORTB,LEDPIN_5);ledOn(PORTB,LEDPIN_6);
  ledOn(PORTD,LEDPIN_7);ledOff(PORTD,LEDPIN_8);ledOn(PORTD,LEDPIN_9);ledOff(PORTD,LEDPIN_10);

}
void pattern_6()
{
  ledOff(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOff(PORTB,LEDPIN_3);ledOn(PORTB,LEDPIN_4);
  ledOn(PORTB,LEDPIN_5);ledOn(PORTB,LEDPIN_6);
  ledOn(PORTD,LEDPIN_7);ledOn(PORTD,LEDPIN_8);ledOn(PORTD,LEDPIN_9);ledOn(PORTD,LEDPIN_10);

}
void pattern_7()
{
  ledOn(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOn(PORTB,LEDPIN_3);ledOff(PORTB,LEDPIN_4);
  ledOn(PORTB,LEDPIN_5);ledOff(PORTB,LEDPIN_6);
  ledOn(PORTD,LEDPIN_7);ledOff(PORTD,LEDPIN_8);ledOn(PORTD,LEDPIN_9);ledOff(PORTD,LEDPIN_10);

}

void pattern_9()
{
  ledOn(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOn(PORTB,LEDPIN_3);ledOn(PORTB,LEDPIN_4);
  ledOn(PORTB,LEDPIN_5);ledOff(PORTB,LEDPIN_6);
  ledOn(PORTD,LEDPIN_7);ledOff(PORTD,LEDPIN_8);ledOn(PORTD,LEDPIN_9);ledOff(PORTD,LEDPIN_10);

}
void blink(volatile uint8_t &port, volatile uint8_t pin)
{
  Serial.println(port);
  port |=pin;
  _delay_ms(400);
  port &= ~pin;
  _delay_ms(400);
}
void ledOn(volatile uint8_t &port,uint8_t pin)
{
  port|=pin;
}
void ledOff(volatile uint8_t &port,uint8_t pin)
{
  port &= (~(pin));
}
void allLedOff()
{
  for(uint8_t i = 0 ; i < 6;++i)
  {
    ledOff(PORTB,ledpinB[i]);
  }
    for(uint8_t i = 0 ; i < 4;++i)
  {
    ledOff(PORTD,ledpinD[i]);
  }
 // PORTB &= (~(LEDPIN_1)) & (~(LEDPIN_2)) & (~(LEDPIN_3)) & (~(LEDPIN_4)) & (~(LEDPIN_5)) & (~(LEDPIN_6));
  //PORTD &= (~(LEDPIN_7)) & (~(LEDPIN_8)) & (~(LEDPIN_9)) & (~(LEDPIN_10)); 
}
/***********************************PATTERNENDED***************************************/
/********************************SWITCH CODE STARTED ***********************************/

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
uint8_t getLedState()
{
 //   bool state=LOW; this statement coause led chaser to run one time only

if(currentState == HIGH && lastState == LOW)
 {
  count++;
  /*****below line of code give status of state*****/
  switch(count)
  {
    case 1:patternValue=PATTERN_A;break;
    case 2:patternValue=PATTERN_2;break;
    case 3:patternValue=PATTERN_3;break;
    case 4:patternValue=PATTERN_c;break;
    case 5:patternValue=PATTERN_e;break;
    case 6:patternValue=PATTERN_f;break;
    case 7:patternValue=PATTERN_g;break;
    case 8:patternValue=PATTERN_k;break;
    case 9:patternValue=PATTERN_p;break;
    case 10:patternValue=PATTERN_s;break;
    case 11:patternValue=PATTERN_4;break;
    case 12:patternValue=PATTERN_6;break;
    case 13:patternValue=PATTERN_7;break;
    case 14:patternValue=PATTERN_9;break;
 
    default:patternValue=ALL_LED_OFF;count=0;break;//count =0 becoz after completion of all pattern, counter will going to increase
  }
  
 }
 return patternValue;
}
