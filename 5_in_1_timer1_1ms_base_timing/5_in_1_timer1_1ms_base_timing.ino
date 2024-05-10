 #define LEDPIN_1 (uint8_t)(1<<PB5)
 #define LEDPIN_2 (uint8_t)(1<<PB4)
 #define LEDPIN_3 (uint8_t)(1<<PB3) // pwm pin
 #define LEDPIN_4 (uint8_t)(1<<PB2)
 #define LEDPIN_5 (uint8_t)(1<<PB1)
 #define LEDPIN_6 (uint8_t)(1<<PB0)
 #define LEDPIN_7 (uint8_t)(1<<PD7)
 #define LEDPIN_8 (uint8_t)(1<<PD6)
 #define LEDPIN_9 (uint8_t)(1<<PD5)
 #define LEDPIN_10 (uint8_t)(1<<PD4)
#define SWITCH_2 (uint8_t)(1<<PD2)

volatile uint8_t basems_flag;
volatile unsigned int counter,counter1,counter2,counter3,counter4,counter5,
                      counter_for_reading_switch_PD2_state,counter_for_timer2_pwm;
uint8_t count=0,ledState=0,pwm_Status=0;
bool currentState,lastState=LOW;  bool state=LOW;
unsigned char ledpinB[6]={LEDPIN_1,LEDPIN_2,LEDPIN_3,LEDPIN_4,LEDPIN_5,LEDPIN_6};
unsigned char ledpinD[4]={LEDPIN_7,LEDPIN_8,LEDPIN_9,LEDPIN_10};

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

void setup() {
  // put your setup code here, to run once:
 DDRB |= (LEDPIN_1) |(LEDPIN_2) |(LEDPIN_3) |(LEDPIN_4) |(LEDPIN_5) |(LEDPIN_6);
DDRD |= (LEDPIN_7) |(LEDPIN_8) |(LEDPIN_9) |(LEDPIN_10);
DDRD &= ~(SWITCH_2); // set port pin as input
  timer1_init();
  init_timer2_pwm();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 basems_wait_for_1ms();
//  userDefinedTask_for_Timer1();
 
 //Serial.print("currentState = ");
 //Serial.println(currentState);
}
/***************TIMEER 1 INIT***********************************************/

void timer1_init(void)
{
  
  sei(); // enable global interrupt
  TIMSK1 |= (1<<TOIE1);  // timer1 overflow interrupt enable,menas notify to cpu about overflow of time
  TCCR1B |=(1<<CS12)|(1<<CS10); // 1024 prescale value
  TCCR1B &= (~(1<<CS11));// prescalar to decrease cpu frequency
  TCCR1A=0x00;           //no wave generation mode
  TCNT1 = 65520;		  //loading the step count from where it has to start to reach max value(65535)
}
ISR(TIMER1_OVF_vect)
{
  noInterrupts();
  basems_flag=1;
  //counter=counter+1;   // no need for arithmetic operation
  TCNT1=65520;// due to prescaler value may be differ
        //Serial.println("IN ISR====================================================");

  interrupts();
}
/****************************TIMER 2 PWM init******************************************/
void init_timer2_pwm()
{
  //high frequesncy pwm
//  TCCR1A |= (1<<WGM11) || (1<<WGM10);
  //TCCR1B |= (1<<WGM12);
  //TCCR1B &= ~(1<<WGM13);
  //wgm = 3 Waveform Generation Mode Bit Description
    TCCR2A |= (1<<WGM21)|(1<<WGM20);
    TCCR2B &= ~(1<<WGM22);

    //set pwm mode 
  TCCR2A |= (1<<COM2A1);
  TCCR2A |= (1<<COM2A0); //inverting mode

  //set the presscalaer of 250kz
  //16000000/250000 = 64 is prescalar

  TCCR2B |= (1<<CS22);
  TCCR2B &= ~(1<<CS21) & ~(1<<CS20);
  //TCNT2 = 0;
}
/*******************************delay of 1ms******************************/
void delay_ms(unsigned int delay)
{
  while(delay)
  {
    basems_wait_for_1ms();
    delay--;
  }
}
/*****************************TIMER 1 BASE TIME of 1ms *********************/
void basems_wait_for_1ms()
{

  //this function has an 1ms execution time
  basems_flag=0;
  counter++;
  counter1++;
  counter2++;
  counter3++;
  counter4++;
  counter5++;  
  counter_for_reading_switch_PD2_state++;
  counter_for_timer2_pwm++;
  //Serial.println(counter_for_reading_switch_PD2_state);
  userDefinedTask_for_Timer1(); // this has to be here only because, this function is working as delay also
  while(basems_flag == 0);
  //Serial.println(millis());

}
/***************************USER DEFINE TASK ********************************/
void userDefinedTask_for_Timer1()
{
     // Serial.println(counter);
  //Serial.println(counter);
  if(counter_for_timer2_pwm == 1000)
  {
    counter_for_timer2_pwm=0;
    pwm_Status = 1;
    //Serial.println("=============================================");
    if(pwm_Status)
{
  pwm_Status=0;
  //Serial.println("***********************************************************************");
      
  for(int i=0;i<256;++i)
    {
      OCR2A = i;
     // delay_ms(2);
    }
  //delay_ms(1000);
  for(int i=255;i>0;--i)
    {
      OCR2A = i;
      //delay_ms(2);
    }
  //delay_ms(1000);
}

  }

  if(counter_for_reading_switch_PD2_state == 10)
  {
    Serial.println(millis());

    currentState=isButtonPressed();
    delay_ms(85);
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

  counter_for_reading_switch_PD2_state=0;
  //blink(PORTB,LEDPIN_1);
}

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
  //Serial.println(port);
  port |=pin;
  delay_ms(400);
  port &= ~pin;
  delay_ms(400);
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
//Serial.println("==================================");
if(currentState == HIGH && lastState == LOW) // lastState is important
 {
  count++; // when button is pressed this count variable will increased
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
