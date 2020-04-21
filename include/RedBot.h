/*
*/
#ifndef RedBot_h
#define RedBot_h

#include <Arduino.h>

// Pin aliases for the motor controller.
#define    L_CTRL_1   2
#define    L_CTRL_2   4
#define    PWM_L      5

#define    R_CTRL_1   7
#define    R_CTRL_2   8
#define    PWM_R      6

// PCINT functionality aliases. Each PCINT has a value set up when the
//  class member gets created, and the PCINT service routine will handle
//  the choosing the appropriate response to the interrupt.

#define NOT_IN_USE    0
#define WHISKER       1
#define LENCODER      2
#define RENCODER      3
#define SW_SERIAL     4

#define PCINT_A0      0
#define PCINT_A1      1
#define PCINT_A2      2
#define PCINT_A3      3
#define PCINT_A4      4
#define PCINT_A5      5
#define PCINT_3       6
#define PCINT_9       7
#define PCINT_10      8
#define PCINT_11      9

enum WHEEL {LEFT, RIGHT, BOTH}; // Variable for which wheel you're interested in
                  //  when you do things in the encoder class.

// These three functions need to work from within multiple classes, so we keep
//  them separate and add them as friend functions where appropriate.
void setPinChangeInterrupt(int pin, byte role); // The "role" of each pin is
                  //  stored in an array which is accessed in the interrupt
                  //  handler to determine what should be done on a falling edge
                  //  PC interrupt.
void pinFunctionHandler(byte pinIndex); // This is the function which actually
                  //  handles the legwork after the interrupt has identified
                  //  which pin caught the interrupt.
void brake(void); // Globally accessible motor brake. I couldn't figure out how
                  //  to set a function pointer to the RedBotMotors class
                  //  function, and it's a small function, so I just made a
                  //  global in the library.
void PC0Handler(byte PBTemp);
void PC1Handler(byte PCTemp);
void PC2Handler(byte PDTemp);


class RedBotMotors
{
  public:
    RedBotMotors() {}
    void drive(int speed) {}
    void drive(int speed, int duration) {}
    void pivot(int speed) {}
    void pivot(int speed, int duration) {}

    void rightMotor(int speed) {}
    void leftMotor(int speed) {} 

    void rightMotor(int speed, int duration) {}
	void leftMotor(int speed, int duration) {} 

    void rightDrive(int speed) {}
	void leftDrive(int speed) {}

    void stop() {}
    void coast() {}
    void brake() {}

    void rightStop() {}
    void leftStop() {}

    void rightCoast() {}
    void leftCoast() {}

    void leftBrake() {}       // Quick-stop left motor, as with brake().
    void rightBrake() {}      // Quick-stop right motor, as with brake().
};

class RedBotMotorsMock : public RedBotMotors {
    public:
        MOCK_METHOD1(drive, void(int speed));
        MOCK_METHOD0(stop, void());
};

RedBotMotorsMock* redbotMotorInstance();
void releaseRedbotMock();

#endif 
