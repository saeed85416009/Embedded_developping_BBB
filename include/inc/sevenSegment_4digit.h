
#ifndef __SEVENSEGMENT_4DIGIT_H
#define __SEVENSEGMENT_4DIGIT_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include<stdint.h>
#include <time.h>
#include <math.h>

/*==========================================================================================
BBB_expansion_header_P8_pins           GPIO number            4-digit 7seg Display pin number
=============================================================================================
P8.7                                   GPIO_66                     11   (SEG A)
P8.8                                   GPIO_67                     7    (SEG B)
P8.9                                   GPIO_69                     4	(SEG C)
P8.10                                  GPIO_68                     3	(DP)
P8.11                                  GPIO_45                     2	(SEG D)
P8.12                                  GPIO_44                     1	(SEG E)
P8.14                                  GPIO_26                     10	(SEG F)
P8.16                                  GPIO_46                     5	(SEG G)
============================================================================================ */


/*==========================================================================================
BBB_expansion_header_P9_pins           GPIO number            4-digit 7seg Dispaly pin number
=============================================================================================
P9.15                                   GPIO_48                     12   (DIGIT 1 )
P9.23                                   GPIO_49                      9	 (DIGIT 2 )
P9.30                                   GPIO_112                     8	 (DIGIT 3 )
P9.27                                   GPIO_115                     6	 (DIGIT 4 )
============================================================================================= */

/* un comment this macro only if you use COMMAN CATHODE display */
//#define COMMON_CATHODE

#define GPIO_66     66
#define GPIO_67     67
#define GPIO_69     69
#define GPIO_68     68
#define GPIO_45     45
#define GPIO_44     44
#define GPIO_26     26
#define GPIO_46     46

#define GPIO_48     48
#define GPIO_49     49
#define GPIO_112    112
#define GPIO_115    115


#define GPIO_66_P8_7_SEGA       GPIO_66       /*  display pin 11    */
#define GPIO_67_P8_8_SEGB       GPIO_67       /*  display pin 7     */
#define GPIO_69_P8_9_SEGC       GPIO_69       /*  display pin 4     */
#define GPIO_68_P8_10_DP        GPIO_68       /*  display pin 3     */
#define GPIO_45_P8_11_SEGD      GPIO_45       /*  display pin 2     */
#define GPIO_44_P8_12_SEGE      GPIO_44       /*  display pin 1     */
#define GPIO_26_P8_14_SEGF      GPIO_26       /*  display pin 10    */
#define GPIO_46_P8_16_SEGG      GPIO_46       /*  display pin 5     */

#define GPIO_48_P9_15_DIGIT1     GPIO_48       /*  display pin 12    */
#define GPIO_49_P9_23_DIGIT2     GPIO_49       /*  display pin 9     */
#define GPIO_117_P9_30_DIGIT3    GPIO_112      /*  display pin 8     */
#define GPIO_115_P9_27_DIGIT4    GPIO_115      /*  display pin 6     */



#define HIGH_VALUE          1
#define LOW_VALUE           0

#define GPIO_DIR_OUT        HIGH_VALUE
#define GPIO_DIR_IN         LOW_VALUE

#define GPIO_LOW_VALUE      LOW_VALUE
#define GPIO_HIGH_VALUE     HIGH_VALUE

#ifdef COMMON_CATHODE
	#define SEGMENT_ON          HIGH_VALUE
	#define SEGMENT_OFF         LOW_VALUE
#else
	#define SEGMENT_ON          LOW_VALUE
	#define SEGMENT_OFF         HIGH_VALUE
#endif


/* This is the path corresponds to GPIOs in the 'sys' directory */
#define SYS_GPIO_PATH       "/sys/class/gpio"

#define SOME_BYTES          100


/* * function prototypes  */
int gpio_export_4digit(uint32_t gpio_num);
int gpio_configure_dir_4digit(uint32_t gpio_num, uint8_t dir_value);
int gpio_write_value_4digit(uint32_t gpio_num, uint8_t out_value);
int gpio_read_value_4digit(uint32_t gpio_num);
int gpio_configure_edge_4digit(uint32_t gpio_num, char *edge);
int gpio_file_open_4digit(uint32_t gpio_num);
int gpio_file_close_4digit(int fd);
void Write_number_to_7segdisplay_4digit(uint8_t numberToDisplay);
void dispaly_numbers_4digit(uint32_t number);
void start_downcounting_4digit(int delay_value);
void start_upcounting_4digit(int delay_value);
int main_7segment_4digit(int argc, char *argv[]);
















#endif
