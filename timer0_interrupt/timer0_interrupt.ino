
void setup() {
  // put your setup code here, to run once:
  DDRB |= (1<<PB5);
  Serial.begin(9600);
sei();
TIMSK1 |= (1<<TOIE1);

 TCCR1A &= (~(1<<WGM10)) & (~(1<<WGM11));
 TCCR1B &= (~(1<< WGM12)) & (~(1<< WGM13));
 TCCR1B |= (1<<CS12) | (1<<CS10);
 TCCR1B &= (~(1<<CS11));
 TCNT1 = 49535;
}
ISR(TIMER1_OVF_vect)
{
  PORTB ^= (1<<PB5);
  Serial.println("in isr");
  TCNT1 = 49535;
}
void loop() {
  // put your main code here, to run repeatedly:

}
