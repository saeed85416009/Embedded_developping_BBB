/*
 * this application has been written by Saeed Pourghasemy
 * this application could be run on Beagleboard
 * 		Version:	0.1
 * 		date   :	2019/03/31
 */

#include "main.h"

int main(int argc, char *argv[]) {

	if (argc != 4) {
		printf("you have to enter at least four arguments......\n\n ");
	}

	if (strcmp(argv[3], "int_led") == 0) {
		if (main_intled(argc, argv)) {
			printf("error in internal led program....\n\n");
		}
	}
	if (strcmp(argv[3], "lcd_text") == 0) {
			if (main_lcdText(argc, argv)) {
				printf("error in internal lcd text program....\n\n");
			}
	}
	if (strcmp(argv[3], "MPU6050") == 0) {       // Accelerometer - Gyroscope
				if(main_mpu6050()) {
					printf("error in internal MPU6050 program....\n\n");
				}
	}
	if (strcmp(argv[3], "7segment_4digit") == 0) {
		if (main_7segment_4digit(argc, argv)) {
			printf("error in internal 7segment 4 digit program....\n\n");
		}
	}
	if (strcmp(argv[3], "7segment_counter") == 0) {
		if (main_7segment_counter(argc, argv)) {
			printf("error in internal 7 segment counter program....\n\n");
		}
	}
	return 0;
}

