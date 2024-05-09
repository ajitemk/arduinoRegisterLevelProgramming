volatile uint8_t basems_flag;

void setup() {
  // put your setup code here, to run once:
  init_timer_1_output_compare_mode();
  DDRB |= (1<<PB1);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //DDRB |= (1<<PB1);
  basems_wait_for_1ms();
}

void init_timer_1_output_compare_mode()
{
  sei();
  TIMSK1 |= (1<<OCIE1A); //enable the required timer1 interrupt
  TCCR1A &= ~(1<<WGM10) & ~(1<<WGM11);
  TCCR1B &= ~(1<<WGM12) & ~(1<<WGM13);
  TCCR1A |= (1<<COM1A0);
  TCCR1A &= ~(1<<COM1A0);
  TCCR1B |= (1<<CS12) | (1<<CS10);
  TCCR1B &= ~(1<<CS11);
  TCNT1=0;
  OCR1A = 15635;
}
ISR(TIMER1_COMPA_vect)
{
  TCNT1 =0;
  OCR1A = 15625;
  basems_flag=1;
  Serial.println("PB1 pin will toggle dont neeed to write code for that");
}
void basems_wait_for_1ms()
{
  basems_flag=0;
  counter++;
  while(basems_flag ==0);
}