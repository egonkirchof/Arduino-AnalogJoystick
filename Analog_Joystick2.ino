// this is a modified program from a Elegoo kit to read an analog joystick
// since my joystick would not give the same reading even when I hold it still
// I add some delta to x and y so I consider two reading to be the same 
// If they are within the delta

// You can choose the pins you want but remember X and Y must be analog pins
const int SW_pin = 2; // digital 
const int X_pin = 0; // analog
const int Y_pin = 1; // analog

struct data {
  int sw;
  int x;
  int y;  
} previous,now;

#define Dy 1 // if the joystick keeps changing value even if you are holding it still
#define Dx 1 // you can adjust these deltas and treat a small difference compared to the
             // previous reading as the same reading
             

void setup() {
  pinMode(SW_pin, INPUT_PULLUP);
  Serial.begin(9600);
  previous.x = 313;
}

bool different(data a,data b) {
  return !(a.sw==b.sw and ( abs(a.x-b.x)<=Dx) and ( abs(a.y-b.y)<=Dy));
}

void loop() {
  now.sw = digitalRead(SW_pin);
  now.x = analogRead(X_pin);
  now.y = analogRead(Y_pin);
  if( different(previous,now)) {
    Serial.println(String(now.sw)+": "+ String(now.x) + " , "+ String(now.y));
  }
  previous = now;
}
