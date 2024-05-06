void delay_1msec()
{
  TCNT0 = 85;
  TCCR0A = 0;
  TCCR0B = 0;
  TCCR0B |= (1<<CS02) | (1<<CS00);
  while((TIFR0 & (1<<TOV0))==0);
  TCCR0B=0;
  TIFR0 = (1<<TOV0);
  }
void delay_ms(unsigned int del)
{
  while(del)
  {
    delay_1msec();
    del--;
  }
}

void setup() {
  // put your setup code here, to run once:
delay_1msec();
DDRB = (1<<PB5);
}

void loop() {
  // put your main code here, to run repeatedly:
PORTB |= (1<<PB5);
delay_ms(10);
PORTB &= (~(1<<PB5));
delay_ms(10);
}
