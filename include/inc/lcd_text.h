

#ifndef LCD_TEXT_H_
#define LCD_TEXT_H_



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
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

#include "lcd_text.h"
#include "lcd_driver.h"
#include "gpio_driver_lcd.h"

int main_lcdText(int argc, char *argv[]);
#endif /* LCD_TEXT_H_ */
