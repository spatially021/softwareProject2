#define PIN_LED 9

int bright=0;
int fade=5;

void setup() {
  // put your setup code here, to run once:

  pinMode(PIN_LED,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  analogWrite(PIN_LED,bright);

  bright+=fade;

  if(bright<=0||bright>=255){
    fade=-fade;
  }

  delay(30);
  
}
