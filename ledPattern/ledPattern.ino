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
 // pattern_A();
 // pattern_2();
 // pattern_3();
 //pattern_c();
 //pattern_e();
 //pattern_f();
 // pattern_g();
 //pattern_k();
 //pattern_p();
 //pattern_s();
 //pattern_4();
 //pattern_6();
 //pattern_7();
 pattern_9();
}
void pattern_A()
{
  ledOn(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOn(PORTB,LEDPIN_3);ledOn(PORTB,LEDPIN_4);
  ledOn(PORTB,LEDPIN_5);ledOn(PORTB,LEDPIN_6);
  ledOn(PORTD,LEDPIN_7);ledOn(PORTD,LEDPIN_8);ledOn(PORTD,LEDPIN_9);ledOn(PORTD,LEDPIN_10);
}
void pattern_2()
{
  ledOn(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOn(PORTB,LEDPIN_3);
  ledOn(PORTB,LEDPIN_6);ledOn(PORTD,LEDPIN_8);ledOn(PORTD,LEDPIN_9);
}
void pattern_3()
{
  ledOn(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOn(PORTB,LEDPIN_3);ledOn(PORTB,LEDPIN_6);
  
  ledOn(PORTD,LEDPIN_7);ledOn(PORTD,LEDPIN_10);ledOn(PORTD,LEDPIN_9);ledOn(PORTD,LEDPIN_10);
}
void pattern_c()
{
  ledOn(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOn(PORTB,LEDPIN_4);
  ledOn(PORTB,LEDPIN_6);
  ledOn(PORTD,LEDPIN_8);ledOn(PORTD,LEDPIN_10);ledOn(PORTD,LEDPIN_9);
}
void pattern_e()
{
  ledOn(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOn(PORTB,LEDPIN_4);
  ledOn(PORTB,LEDPIN_6);ledOn(PORTB,LEDPIN_5);
  ledOn(PORTD,LEDPIN_8);ledOn(PORTD,LEDPIN_10);ledOn(PORTD,LEDPIN_9);
}
void pattern_f()
{
  ledOn(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOn(PORTB,LEDPIN_4);
  ledOn(PORTB,LEDPIN_6);ledOn(PORTB,LEDPIN_5);
  ledOn(PORTD,LEDPIN_8);ledOn(PORTD,LEDPIN_10);
}
void pattern_g()
{
  ledOn(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOn(PORTB,LEDPIN_4);
  ledOn(PORTB,LEDPIN_6);
  ledOn(PORTD,LEDPIN_8);ledOn(PORTD,LEDPIN_7);ledOn(PORTD,LEDPIN_9);
  ledOn(PORTD,LEDPIN_10);
}
void pattern_k()
{
  ledOn(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOn(PORTB,LEDPIN_4);
  ledOn(PORTB,LEDPIN_6);
  ledOn(PORTD,LEDPIN_8);ledOn(PORTD,LEDPIN_9);
  ledOn(PORTD,LEDPIN_10);
}

void pattern_p()
{
  ledOn(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOn(PORTB,LEDPIN_4);
  ledOn(PORTB,LEDPIN_6);ledOn(PORTB,LEDPIN_3);
  ledOn(PORTD,LEDPIN_8);
  ledOn(PORTD,LEDPIN_10);
}
void pattern_s()
{
  ledOn(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOn(PORTB,LEDPIN_4);//ledOn(PORTB,LEDPIN_3);
  ledOn(PORTB,LEDPIN_6);ledOn(PORTD,LEDPIN_10);
  ledOn(PORTD,LEDPIN_7);
  ledOn(PORTD,LEDPIN_9);
}
void pattern_4()
{
  /*ledOn(PORTB,LEDPIN_1);*/ledOn(PORTB,LEDPIN_2);/*ledOn(PORTB,LEDPIN_3);*/ledOn(PORTB,LEDPIN_4);
  ledOn(PORTB,LEDPIN_5);ledOn(PORTB,LEDPIN_6);
  ledOn(PORTD,LEDPIN_7);/*ledOn(PORTD,LEDPIN_8);*/ledOn(PORTD,LEDPIN_9);/*ledOn(PORTD,LEDPIN_10);*/

}
void pattern_6()
{
  /*ledOn(PORTB,LEDPIN_1);*/ledOn(PORTB,LEDPIN_2);/*ledOn(PORTB,LEDPIN_3);*/ledOn(PORTB,LEDPIN_4);
  ledOn(PORTB,LEDPIN_5);ledOn(PORTB,LEDPIN_6);
  ledOn(PORTD,LEDPIN_7);ledOn(PORTD,LEDPIN_8);ledOn(PORTD,LEDPIN_9);ledOn(PORTD,LEDPIN_10);

}
void pattern_7()
{
  ledOn(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOn(PORTB,LEDPIN_3);/*ledOn(PORTB,LEDPIN_4);*/
  ledOn(PORTB,LEDPIN_5);/*ledOn(PORTB,LEDPIN_6);*/
  ledOn(PORTD,LEDPIN_7);/*ledOn(PORTD,LEDPIN_8);*/ledOn(PORTD,LEDPIN_9);/*ledOn(PORTD,LEDPIN_10);*/

}

void pattern_9()
{
  ledOn(PORTB,LEDPIN_1);ledOn(PORTB,LEDPIN_2);ledOn(PORTB,LEDPIN_3);ledOn(PORTB,LEDPIN_4);
  ledOn(PORTB,LEDPIN_5);/*ledOn(PORTB,LEDPIN_6);*/
  ledOn(PORTD,LEDPIN_7);/*ledOn(PORTD,LEDPIN_8);*/ledOn(PORTD,LEDPIN_9);/*ledOn(PORTD,LEDPIN_10);*/

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