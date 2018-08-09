# Arduino-AnalogJoystick
Reading an analog joystick and dealing with different reading due to lack of precision of the joystick

My joystick would give me slightly differentreading for X and Y even when I hold it still 
So I dealt with this buy comparing to reading and deciding it is the same reading if the difference between them 
is not higher then a Delta (Dx and Dy) previously defined.
The code is based in a code from an Elegoo kit.
