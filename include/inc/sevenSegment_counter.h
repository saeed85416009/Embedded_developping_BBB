
#ifndef __SEVENSEGMENT_4DIGIT_H
#define __SEVENSEGMENT_4DIGIT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>


/*==================================================================================
BBB_expansion_header_P8_pins           GPIO number            7Seg Display segment
===================================================================================
P8.7                                   GPIO_66                     a
P8.8                                   GPIO_67                     b
P8.9                                   GPIO_69                     c
P8.10                                  GPIO_68                     h //decimal point
P8.11                                  GPIO_45                     d
P8.12                                  GPIO_44                     e
P8.14                                  GPIO_26                     f
P8.16                                  GPIO_46                     g
=================================================================================== */


#define GPIO_66     66
#define GPIO_67     67
#define GPIO_69     69
#define GPIO_68     68
#define GPIO_45     45
#define GPIO_44     44
#define GPIO_26     26
#define GPIO_46     46


#define GPIO_66_P8_7_SEGA       GPIO_66
#define GPIO_67_P8_8_SEGB       GPIO_67
#define GPIO_69_P8_9_SEGC       GPIO_69
#define GPIO_68_P8_10_DP        GPIO_68
#define GPIO_45_P8_11_SEGD      GPIO_45
#define GPIO_44_P8_12_SEGE      GPIO_44
#define GPIO_26_P8_14_SEGF      GPIO_26
#define GPIO_46_P8_16_SEGG      GPIO_46



#define HIGH_VALUE  		1
#define LOW_VALUE   		0

#define GPIO_DIR_OUT        HIGH_VALUE
#define GPIO_DIR_IN         LOW_VALUE

#define GPIO_LOW_VALUE      LOW_VALUE
#define GPIO_HIGH_VALUE     HIGH_VALUE

#define SEGMENT_ON          HIGH_VALUE
#define SEGMENT_OFF         LOW_VALUE


/* This is the path corresponds to GPIOs in the 'sys' directory */
#define SYS_GPIO_PATH 		"/sys/class/gpio"

#define SOME_BYTES 			100



// prototypes

/*  GPIO configure direction*  dir_value : 1 means 'out' , 0 means "in"*/
int gpio_configure_dir(uint32_t gpio_num, uint8_t dir_value);

/*
 *  GPIO write value *  out_value : can be either 0 or 1 */
int gpio_write_value(uint32_t gpio_num, uint8_t out_value);

/**  GPIO read value*/
int gpio_read_value(uint32_t gpio_num);


/*
 *  GPIO configure the edge of trigger
 *  *  edge : rising, falling , none*/
int gpio_configure_edge(uint32_t gpio_num, char *edge);

/**  Open the sys fs file corresponding to gpio number*/
int gpio_file_open(uint32_t gpio_num);

/* *  close a file*/
int gpio_file_close(int fd);



int initialize_all_gpios(void);

/* *  GPIO export pin*/
int gpio_export(uint32_t gpio_num);

/* This function displays number on the 7segment display */
void Write_number_to_7segdisplay(uint8_t numberToDisplay);

/* implements the up counting from 0 to 9 */
void start_upcounting(int delay_value_ms);

/* implements the down counting from 9 to 0 */
void start_downcounting(int delay_value_ms);

int main_7segment_counter(int argc, char *argv[]);





#endif
