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
void setup() {
  // put your setup code here, to run once:
DDRB |= (LEDPIN_1) |(LEDPIN_2) |(LEDPIN_3) |(LEDPIN_4) |(LEDPIN_5) |(LEDPIN_6);
DDRD |= (LEDPIN_7) |(LEDPIN_8) |(LEDPIN_9) |(LEDPIN_10);
DDRD &= ~(1<<PD2); // set port pin as input

}

void loop() {
  // put your main code here, to run repeatedly:
  _delay_ms(1000);pattern_A();
  _delay_ms(1000);pattern_2();
 _delay_ms(1000); pattern_3();
 _delay_ms(1000);pattern_c();
 _delay_ms(1000);pattern_e();
 _delay_ms(1000);pattern_f();
 _delay_ms(1000); pattern_g();
 _delay_ms(1000);pattern_k();
 _delay_ms(1000);pattern_p();
 _delay_ms(1000);pattern_s();
 _delay_ms(1000);pattern_4();
 _delay_ms(1000);pattern_6();
 _delay_ms(1000);pattern_7();
 _delay_ms(1000);pattern_9();
}
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
  ledOn(PORTD,LEDPIN_7);ledOff(PORTD,LEDPIN_8);ledOn(PORTD,LEDPIN_9);ledOn(PORTD,LEDPIN_10);

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