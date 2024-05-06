uint8_t count = 0;

void setup() {
  // put your setup code here, to run once:
DDRD &= ~(1<<PD2); // set port pin as input
DDRB |= (1<<PB5); //set port pin as output
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(PIND & (1<<PIND2)) // set pind2 to logic 1 and check for logic high
{
  
}
else
{
  count++; //when switch is pressed
}
if(count <200 )
{
  Serial.println(count);
  PORTB |= (1<<PB5);
  
}
else if (count>200)
{
  Serial.println(count);
  PORTB &= ~(1<<PB5);
}
}
