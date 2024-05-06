
#define BITMASK 0x01
int priorstate=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
DDRB &= ~(1<<PD2); // 
DDRB |= (1<<PB5);


}

void loop() {
  // put your main code here, to run repeatedly:
int state;
state = PIND  & BITMASK;
 // Serial.println(state);

if(state != priorstate)
{
  Serial.println(state);
  priorstate=state;
}  
}
