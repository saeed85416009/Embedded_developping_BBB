#ifndef __LED_H
#define __LED_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

/* This is the path corresponds to USER LEDS in the 'sys' directory */
#define  SYS_FS_LEDS_PATH "/sys/class/leds"

/* This is the path corresponds to USER LED 3 in the 'sys' directory */
//#define SYS_FS_ "/sys/class/leds/beaglebone:green:usr3"

#define USR_LED_NUMBER 3
#define SOME_BYTES 100

/* * function prototypes  */


int write_trigger_values(uint8_t led_no, char *value);
int write_brightness_values(uint8_t led_no, int value);
void process_trigger_values( char *value);
void process_brightness_values( int value);
int main_intled( int argc, char *argv[] );





#endif
