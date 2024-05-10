#define LEDPIN_6 (uint8_t)(1<<PB0)
unsigned int captured=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
timer1_inputCapture_init();
DDRB |= ~(LEDPIN_6);
DDRB |= (1<<PB1);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(captured>0)
  {
    PORTB |= (1<<PB1);

  }

}
void timer1_inputCapture_init()
{
  //enable the global interrupt
  sei();      
//set input captured interrupt enable bit in t1msk1 register
  TIMSK1 |= (1<<ICIE1);
  //set mode of the timer, we use normal mode
  TCCR1A &= ~(1<<WGM10) & ~(1<<WGM11);
  TCCR1B &= ~(1<<WGM13) & ~(1<<WGM12); // normal mode
  //set the prescalar for the timer
  TCCR1B |= (1<<CS10) | (1<<CS12);
  TCCR1B &= ~(1<<CS11);
  //start the timer with initial value
  TCNT1 = 0;
  //select the edge for capturing
  TCCR1B |= (1<<ICES1);
 }
  ISR(TIMER1_CAPT_vect)
 {
  TCNT1=0;
  captured = ICR1;
  Serial.println(captured);
 }