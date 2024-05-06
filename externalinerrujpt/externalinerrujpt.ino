const byte LED = 13;
const byte BUTTON = 2;
volatile byte state=LOW ;
// Interrupt Service Routine (ISR)
ISR(INT0_vect)
{
  state = !state; // to toogle the led 
}
void setup ()
{
  pinMode (LED, OUTPUT);  // so we can update the LED
  //digitalWrite (BUTTON, HIGH);  // internal pull-up resistor
//  attachInterrupt (digitalPinToInterrupt (BUTTON), switchPressed, CHANGE);  // attach interrupt handler
SREG |= (1<<7);      //enable gloval interrupt
EIMSK |= (1<<INT0);   //enable interrupt 0
EICRA |= (1<<ISC00) ; //select the mode, risin,falling,high low
EICRA &= (~(1<<ISC01));//select the mode 
}  // end of setup

void loop ()
{
  // loop doing nothing 
  digitalWrite(LED,state);
  delay(200);
     
} 