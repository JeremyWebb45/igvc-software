#ifndef WHEEL_ENCODERS_HPP_
#define WHEEL_ENCODERS_HPP_

#include "WProgram.h"
#include "SPI.hpp"

/* MOTOR ENCODER DEFINITIONS */
#define COUNTER_SCALER			(64)
#define F_CPU 16000000
#define COUNTER_RATE			(F_CPU/COUNTER_SCALER)
#define TOTAL_ENCODER_TICKS 		((double)512)
#define RAD_PER_ENCODER_TICK		((double)(2*M_PI)/TOTAL_ENCODER_TICKS)
#define LEFT_MOTOR_ENCODER_DIRECTION 	1
#define RIGHT_MOTOR_ENCODER_DIRECTION 	0

/* ROBOT PHYSICAL DEFINITIONS */  /*TODO: determine these values */
#define MOTOR_RATIO		((double)20)
#define WHEEL_RADIUS		((double)5 / (double)MOTOR_RATIO)
#define WHEEL_BASE		((double)28)

/* PIN DEFINITIONS */
/** SPI **/
#define SPI_MOSI 				/*13*/
#define SPI_MISO				7/*12*/
#define SPI_CLK					6/*11*/
#define SPI_SS_LEFT_MOTOR_ENCODER		5/*10*/
#define SPI_SS_RIGHT_MOTOR_ENCODER		4/*9*/
#define BITBANG_SPI 1

struct motorEncoderData{
	int leftMotorTick;
	int rightMotorTick;
	unsigned int time; //this should be made an int, if possible
};

void calcDelta(struct motorEncoderData current, struct motorEncoderData previous, int *dl, int *dr, long *dt);
void readMotorEncoders(struct motorEncoderData *data);
int delta(int p2, int p1, int maxDiff, int maxVal, int dir);
int convertMotorEncoderFormat(unsigned int data);

#endif
