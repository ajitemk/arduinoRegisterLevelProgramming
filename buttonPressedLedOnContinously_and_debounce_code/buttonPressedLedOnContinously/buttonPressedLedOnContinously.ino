//in this code debounce concept is explain
uint8_t count = 0;
bool currentState;bool ledState=LOW;bool lastState=LOW;
void setup() {
  // put your setup code here, to run once:
DDRD &= ~(1<<PD2); // set port pin as input
DDRB |= (1<<PB5); //set port pin as output
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(PIND & (1<<PIND2)) //when button is not pressed
{
  currentState=LOW;
  Serial.println("in if");
}
else                  //when button is pressed isko pressed karne do uske baad main dekh lenge
{
  Serial.println("in else");
  currentState=HIGH;
}
    _delay_ms(85); //delay for settling bouncing effect of switch

Serial.print("currentState = ");
Serial.println(currentState);


Serial.print("ledState = ");
Serial.println(ledState);
if(currentState == HIGH && lastState == LOW)  // if lastState variable is not their then button press is not working properly
{
    Serial.println("codition is true and led will change its state ");
  count++;
  if(ledState == LOW && count==5)
  {
    Serial.println("Count is 5 when led is low ");
    ledState=HIGH;
    count = 0;
  }
  else if(ledState == HIGH && count == 5)
  {
    Serial.println("Count is 5 when led is high");
    ledState = LOW;
    count = 0;
  }
  
}
else
{
  Serial.print("lastState = ");
  Serial.println(lastState);
  Serial.println("codition is false and led will remain in same state ");
  
}
  lastState = currentState; //assign currentState to lastState to make above codition false
Serial.println(count);
if(ledState == HIGH )
  {
    PORTB |= (1<<PB5);      
  }
else 
  {
    PORTB &= (~(1<<PB5));
  }


}
