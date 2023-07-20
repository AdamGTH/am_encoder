## am_encoder

# basic code:

```cpp
#include <Arduino.h>
#include <am_encoder.h>

#define ENC_PIN_A 10          // OUTPUT ENCODER A
#define ENC_PIN_B 11          // OUTPUT ENCODER B
#define NUMBER_OF_STEPS 225   // OPTIONAL HOW MANY STEPS HAS ENCODER
#define VALUE_MM_PER_CIRCLE 6 // OPTIONAL VALUE IN milimeters THAT NEED TO MEASURE OF ROAD

long poz = 0, poz_old = 0;
AM_ENCODER enc; // VARIABLE TYPE OF AM_ENCODER

void setup()
{
  // LOAD THE VALUE FOR WORK OUR ENCODER, BUT TWO LAST VALUE ARE OPTIONAL
  enc.begin(ENC_PIN_A, ENC_PIN_B, NUMBER_OF_STEPS, VALUE_MM_PER_CIRCLE);
  Serial.begin(9600);
}

void loop()
{

  poz = enc.read_step(); // READ THE ACTUAL STEP

  if (poz != poz_old)
  {
    Serial.print(enc.convert_to_mm(poz)); // using method convert_to_mm() have returned the value in millimeters converted to string
    Serial.println(" mm");
    poz_old = poz;
  }
}

```

## Methods:

1. begin(arg1, arg2, arg3, arg4)
   arg 1 - encoder output pin A
   arg 2 - encoder output pin B
   arg 3 - number of steps of encoder (optional - we use this when we need to compute a linear displacement)
   arg 4 - millimeter value after turning the shaft (optional - we use this when we need to compute a linear displacement)
2. read_step() - returned actual number of step
3. convert_to_mm(arg1) - this method compute a value in millimeters, and returned in string value
   arg1 - actual value of step.
