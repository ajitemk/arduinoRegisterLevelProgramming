volatile uint8_t basems_flag;
unsigned int counter;
void setup()
{
  DDRB=1<<PB5;
  timer1_init();
  Serial.begin(9600);
}
void loop()
{
  basems_wait();
  userDefinedTask_for_Timer1();
}
void timer1_init(void)
{
  TIMSK1 |= (1<<TOIE1);
  TCCR1B |=(1<<CS12)|(1<<CS10); // 1024 prescale value
  TCCR1B &= (~(1<<CS11));
  TCCR1A=0x00;           //no wave generation mode
  TCNT1 = 65520;
}
ISR(TIMER1_OVF_vect)
{
  noInterrupts();
  basems_flag=1;
  TCNT1=65520;// due to prescaler value may be differ
  interrupts();
}
void basems_wait()
{
  //this function has an 1ms execution time
  basems_flag=0;
  counter++;  
  while(basems_flag == 0);

}
void userDefinedTask_for_Timer1()
{
  if(counter>1000)
  {
    PORTB ^= 1<<PB5;
    Serial.println(millis());
    
  }
  counter =0;

}