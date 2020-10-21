const int buttonPin = A0; // Mic input 
const int led=3; //LED OUTPUT /relay output
int buttonState = 0; //button state orignal state
int lastButtonState = 0; //button status

int counter = 0;

void setup()
{
  pinMode(buttonPin, INPUT_PULLUP); // Push Button with pull-up
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState)
  {
    if (buttonState == HIGH)
    {
      if(counter==1) {
        counter=0;
      }else {
        counter++;
      Serial.println("Hi !");
      Serial.print("Number of button pushes:  ");
      Serial.println(counter);
      }
    }
    else 
    {
      Serial.println("Button off");
    }
    delay(50); // Delay a little bit to avoid bouncing
  }
  lastButtonState = buttonState;
  switch(counter) {
    case 0:
    digitalWrite(led,HIGH);
    break;

    case 1:
digitalWrite(led,LOW);
    break;
  }
}
