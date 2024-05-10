#define LEDPIN_5 (uint8_t)(1<<PB1)
void setup() {
  // put your setup code here, to run once:
DDRB |= LEDPIN_5;
Serial.begin(9600);
init_pwm();
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<1024;++i)
  {
    OCR1A = i;
    _delay_ms(10);   //PORTB |= LEDPIN_5;
  }
  _delay_ms(1000);
  for(int i=1023;i>0;--i)
  {
    OCR1A = i;
        _delay_ms(10);

    //PORTB &= ~(LEDPIN_5);
  }
  _delay_ms(1000);

}

void init_pwm()
{
  //high frequesncy pwm
  TCCR1A |= (1<<WGM11) || (1<<WGM10);
  TCCR1B |= (1<<WGM12);
  TCCR1B &= ~(1<<WGM13);
  //set pwm mode
  TCCR1A |= (1<<COM1A1);
  TCCR1A &= ~(1<<COM1A0);

  //set the presscalaer of 250kz
  //16000000/250000 = 64 is prescalar

  TCCR1B |= (1<<CS10)|(1<<CS11);
  TCCR1B &= ~(1<<CS12);
}