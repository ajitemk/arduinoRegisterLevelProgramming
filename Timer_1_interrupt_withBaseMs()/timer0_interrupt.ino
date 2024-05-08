volatile uint8_t basems_flag;
volatile unsigned int counter,counter1,counter2,counter3,counter4,counter5;
void setup()
{
  DDRB |= 1<<PB5;
  DDRB |= 1<<PB4;
  DDRB |= 1<<PB3;
  DDRB |= 1<<PB2;
  DDRB |= 1<<PB1;
  DDRB |= 1<<PB0;
  DDRD |= 1<<PD7;
  DDRD |= 1<<PD6;
  DDRD |= 1<<PD5;
  DDRD |= 1<<PD4;
  
  
  
  timer1_init();
  Serial.begin(9600);
}
void loop()
{
  basems_wait_for_1ms();
  userDefinedTask_for_Timer1();
}
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
  while(basems_flag == 0);

}
void userDefinedTask_for_Timer1()
{
     // Serial.println(counter);
  //Serial.println(counter);
  if(counter==1000)
  {
    PORTB ^= (1<<PB5);
     counter =0; 
      //Serial.println(millis());

  }
  //Serial.println(counter2);
  if(counter2 == 500) 
  {
    //counter =0;
    PORTB ^=(1<<PB3);
        //  Serial.println("===================================================================================");
    counter2=0;
  }
  if(counter == 250)
  {
    //PORTB ^= (1<<PB1);
  }
  if(counter5 == 200)
  {
   // PORTB ^= (1<<PB2);
  }
  if(counter3 == 125)
  {
    PORTB ^= (1<<PB1);
    counter3=0;
  }
  if(counter3 == 1)
  {
    //PORTB ^= (1<<PB0);
  }
  if(counter2 == 75)
  {
     PORTD ^= (1<<PD7);
    // counter2=0;
  }
   if(counter1 == 35)
  {
    PORTD ^= (1<<PD5);
    counter1=0;
  }
  

}