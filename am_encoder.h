#ifndef AM_ENKODER_H_
#define AM_ENKODER_H_
#include <avr/io.h>
#include <Arduino.h>

typedef enum
{
    STOP,
    ONE,
    TWO,
    THR
} QUARTED;

class AM_ENCODER
{

private:
    uint8_t nr_pinA;
    uint8_t nr_pinB;
    uint16_t resolution;
    float mm_per_step;
    long act_step;
    uint8_t port_enc_A;
    uint8_t port_enc_B;
    uint8_t pin_enc_A;
    uint8_t pin_enc_B;
    QUARTED cw;

public:
    void begin(uint8_t pinA = 0, uint8_t pinB = 0, uint16_t resol = 0, uint8_t mm_per_circle = 0);
    long read_step(void);
    String convert_to_mm(long pos);
};

#endif /* AM_ENKODER_H_ */