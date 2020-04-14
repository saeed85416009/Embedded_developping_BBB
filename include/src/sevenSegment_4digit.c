
#include "sevenSegment_4digit.h"


/*
 *  GPIO export pin
 *
 */
int gpio_export_4digit(uint32_t gpio_num)
{
	int fd, len;
	char buf[SOME_BYTES];

	fd = open(SYS_GPIO_PATH "/export", O_WRONLY);
	if (fd < 0) {
		perror(" error opening export file\n");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", gpio_num);
	write(fd, buf, len);
	close(fd);

	return 0;
}

/*
 *  GPIO configure direction
 *  dir_value : 1 means 'out' , 0 means "in"
 */
int gpio_configure_dir_4digit(uint32_t gpio_num, uint8_t dir_value)
{
    int fd;
    char buf[SOME_BYTES];

    snprintf(buf, sizeof(buf), SYS_GPIO_PATH "/gpio%d/direction", gpio_num);

    fd = open(buf, O_WRONLY);
    if (fd < 0) {
        perror("gpio direction configure\n");
        return fd;
    }

    if (dir_value)
        write(fd, "out", 4); //3+1  +1 for NULL character
    else
        write(fd, "in", 3);

    close(fd);
    return 0;
}

/*
 *  GPIO write value
 *  out_value : can be either 0 or 1
 */
int gpio_write_value_4digit(uint32_t gpio_num, uint8_t out_value)
{
    int fd;
    char buf[SOME_BYTES];

    snprintf(buf, sizeof(buf), SYS_GPIO_PATH "/gpio%d/value", gpio_num);

    fd = open(buf, O_WRONLY);
    if (fd < 0) {
        perror("gpio write value\n");
        return fd;
    }

    if (out_value)
        write(fd, "1", 2);
    else
        write(fd, "0", 2);

    close(fd);
    return 0;
}

/*
 *  GPIO read value
 */
int gpio_read_value_4digit(uint32_t gpio_num)
{
    int fd;
    uint8_t read_value=0;
    char buf[SOME_BYTES];

    snprintf(buf, sizeof(buf), SYS_GPIO_PATH "/gpio%d/value", gpio_num);

    fd = open(buf, O_WRONLY);
    if (fd < 0) {
        perror("gpio read value\n");
        return fd;
    }

    read(fd, &read_value, 1);

    close(fd);
    return read_value;
}


/*
 *  GPIO configure the edge of trigger
 *  edge : rising, falling
 */
int gpio_configure_edge_4digit(uint32_t gpio_num, char *edge)
{
    int fd;
    char buf[SOME_BYTES];

    snprintf(buf, sizeof(buf), SYS_GPIO_PATH "/gpio%d/edge", gpio_num);

    fd = open(buf, O_WRONLY);
    if (fd < 0) {
        perror("gpio configure edge\n");
        return fd;
    }

    write(fd, edge, strlen(edge) + 1);
    close(fd);
    return 0;
}

/*
 *  Open the sys fs file corresponding to gpio number
 */
int gpio_file_open_4digit(uint32_t gpio_num)
{
    int fd;
    char buf[SOME_BYTES];

    snprintf(buf, sizeof(buf), SYS_GPIO_PATH "/gpio%d/value", gpio_num);

    fd = open(buf, O_RDONLY | O_NONBLOCK );
    if (fd < 0) {
        perror("gpio file open\n");
    }
    return fd;
}

/*
 *  close a file
 */
int gpio_file_close_4digit(int fd)
{
    return close(fd);
}

/* This function displays number on the 7segment display */
void Write_number_to_7segdisplay_4digit(uint8_t numberToDisplay)
{

    switch (numberToDisplay){

    case 0:
        gpio_write_value_4digit(GPIO_66_P8_7_SEGA, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_67_P8_8_SEGB, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_69_P8_9_SEGC, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_45_P8_11_SEGD, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_44_P8_12_SEGE, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_26_P8_14_SEGF, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_46_P8_16_SEGG, SEGMENT_OFF);
    break;

    case 1:
        gpio_write_value_4digit(GPIO_66_P8_7_SEGA, SEGMENT_OFF);
        gpio_write_value_4digit(GPIO_67_P8_8_SEGB, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_69_P8_9_SEGC, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_45_P8_11_SEGD, SEGMENT_OFF);
        gpio_write_value_4digit(GPIO_44_P8_12_SEGE, SEGMENT_OFF);
        gpio_write_value_4digit(GPIO_26_P8_14_SEGF, SEGMENT_OFF);
        gpio_write_value_4digit(GPIO_46_P8_16_SEGG, SEGMENT_OFF);
    break;

    case 2:
        gpio_write_value_4digit(GPIO_66_P8_7_SEGA, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_67_P8_8_SEGB, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_69_P8_9_SEGC, SEGMENT_OFF);
        gpio_write_value_4digit(GPIO_45_P8_11_SEGD, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_44_P8_12_SEGE, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_26_P8_14_SEGF, SEGMENT_OFF);
        gpio_write_value_4digit(GPIO_46_P8_16_SEGG, SEGMENT_ON);
    break;

    case 3:
        gpio_write_value_4digit(GPIO_66_P8_7_SEGA, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_67_P8_8_SEGB, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_69_P8_9_SEGC, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_45_P8_11_SEGD, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_44_P8_12_SEGE, SEGMENT_OFF);
        gpio_write_value_4digit(GPIO_26_P8_14_SEGF, SEGMENT_OFF);
        gpio_write_value_4digit(GPIO_46_P8_16_SEGG, SEGMENT_ON);
    break;

    case 4:
        gpio_write_value_4digit(GPIO_66_P8_7_SEGA, SEGMENT_OFF);
        gpio_write_value_4digit(GPIO_67_P8_8_SEGB, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_69_P8_9_SEGC, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_45_P8_11_SEGD, SEGMENT_OFF);
        gpio_write_value_4digit(GPIO_44_P8_12_SEGE, SEGMENT_OFF);
        gpio_write_value_4digit(GPIO_26_P8_14_SEGF, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_46_P8_16_SEGG, SEGMENT_ON);
    break;

    case 5:
        gpio_write_value_4digit(GPIO_66_P8_7_SEGA, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_67_P8_8_SEGB, SEGMENT_OFF);
        gpio_write_value_4digit(GPIO_69_P8_9_SEGC, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_45_P8_11_SEGD, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_44_P8_12_SEGE, SEGMENT_OFF);
        gpio_write_value_4digit(GPIO_26_P8_14_SEGF, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_46_P8_16_SEGG, SEGMENT_ON);
    break;

    case 6:
        gpio_write_value_4digit(GPIO_66_P8_7_SEGA, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_67_P8_8_SEGB, SEGMENT_OFF);
        gpio_write_value_4digit(GPIO_69_P8_9_SEGC, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_45_P8_11_SEGD, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_44_P8_12_SEGE, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_26_P8_14_SEGF, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_46_P8_16_SEGG, SEGMENT_ON);
    break;

    case 7:
        gpio_write_value_4digit(GPIO_66_P8_7_SEGA, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_67_P8_8_SEGB, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_69_P8_9_SEGC, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_45_P8_11_SEGD, SEGMENT_OFF);
        gpio_write_value_4digit(GPIO_44_P8_12_SEGE, SEGMENT_OFF);
        gpio_write_value_4digit(GPIO_26_P8_14_SEGF, SEGMENT_OFF);
        gpio_write_value_4digit(GPIO_46_P8_16_SEGG, SEGMENT_OFF);
    break;

    case 8:
        gpio_write_value_4digit(GPIO_66_P8_7_SEGA, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_67_P8_8_SEGB, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_69_P8_9_SEGC, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_45_P8_11_SEGD, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_44_P8_12_SEGE, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_26_P8_14_SEGF, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_46_P8_16_SEGG, SEGMENT_ON);
    break;

    case 9:
        gpio_write_value_4digit(GPIO_66_P8_7_SEGA, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_67_P8_8_SEGB, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_69_P8_9_SEGC, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_45_P8_11_SEGD, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_44_P8_12_SEGE, SEGMENT_OFF);
        gpio_write_value_4digit(GPIO_26_P8_14_SEGF, SEGMENT_ON);
        gpio_write_value_4digit(GPIO_46_P8_16_SEGG, SEGMENT_ON);
    break;

    case 10:
    	/* This will turn off all segments */
        gpio_write_value_4digit(GPIO_66_P8_7_SEGA, SEGMENT_OFF);
        gpio_write_value_4digit(GPIO_67_P8_8_SEGB, SEGMENT_OFF);
        gpio_write_value_4digit(GPIO_69_P8_9_SEGC, SEGMENT_OFF);
        gpio_write_value_4digit(GPIO_45_P8_11_SEGD, SEGMENT_OFF);
        gpio_write_value_4digit(GPIO_44_P8_12_SEGE, SEGMENT_OFF);
        gpio_write_value_4digit(GPIO_26_P8_14_SEGF, SEGMENT_OFF);
        gpio_write_value_4digit(GPIO_46_P8_16_SEGG, SEGMENT_OFF);
    break;
    }



}

/*
 * This function implements the logic to write numbers on the 4 digit LED display
 * we turn on and display a number on each digit for a very small amount of time that is 10 micro seconds,then we move to
 * next digit.
 * if u do this very fast enough , then it gives the illusion that , we are writing to all digits simultaneously
 */
void dispaly_numbers_4digit(uint32_t number)
{
	/* we have 4 digits , so loop of 4 */
    for(int digit = 4 ; digit > 0 ; digit--)
    {
    	/*
    	 * start with the 4th digit(right most )
    	 * Turn on each digit for a small amount of time and display the number
    	 * */
        switch(digit)
        {
            case 1:
                gpio_write_value_4digit(GPIO_48_P9_15_DIGIT1,GPIO_HIGH_VALUE);
              break;

            case 2:
                gpio_write_value_4digit(GPIO_49_P9_23_DIGIT2,GPIO_HIGH_VALUE);
              break;
            case 3:
                gpio_write_value_4digit(GPIO_117_P9_30_DIGIT3,GPIO_HIGH_VALUE);
              break;
            case 4:
                gpio_write_value_4digit(GPIO_115_P9_27_DIGIT4,GPIO_HIGH_VALUE);
              break;
        }

        Write_number_to_7segdisplay_4digit(number % 10);
        number /= 10;

       /* display each digit only for 10 micro seconds */
       usleep(10);

       /* Turn of all segments */
       Write_number_to_7segdisplay_4digit(10);

        //Turn off all digits
        gpio_write_value_4digit(GPIO_48_P9_15_DIGIT1, GPIO_LOW_VALUE);
        gpio_write_value_4digit(GPIO_49_P9_23_DIGIT2, GPIO_LOW_VALUE);
        gpio_write_value_4digit(GPIO_117_P9_30_DIGIT3, GPIO_LOW_VALUE);
        gpio_write_value_4digit(GPIO_115_P9_27_DIGIT4, GPIO_LOW_VALUE);


    }



}

/*
 * this function down counts
 * 'delay_value' controls the speed of down counting (given by user through command line )
 */
void start_downcounting_4digit(int delay_value)
{
	uint32_t i=0,number=9999;
	printf("DOWN COUNTING.......\n");

	while(1)
	{
		/*we dont increment the number to display until 'delay_value' */
		for ( i =0 ; i < delay_value ; i++)
		{
			dispaly_numbers_4digit(number);
		}
		number--;
	}


}

/*
 * this function up counts
 * 'delay_value' controls the speed of up counting (given by user through command line )
 */
void start_upcounting_4digit(int delay_value)
{
	uint32_t i=0,number=0;
	printf("UP COUNTING.......\n");

	while(1)
	{
		/*we dont increment the number to display until 'delay_value' */
		for ( i =0 ; i < delay_value ; i++)
		{
			dispaly_numbers_4digit(number);
		}
		number++;
	}

}





int main_7segment_4digit(int argc, char *argv[])
 {
    printf("4 digit 7seg LED up/down/random counter application\n");

    if ( argc != 4 ) /* argc should be 3 for correct execution */
    {

        printf( "usage: %s <direction> <delay>\n", argv[0] );
        printf( "valid direction : up, down, updown,random\n");
        printf ("recommended delay range : 0  to 1000 \n");
    }
    else
    {
        int value = atoi(argv[2]);

        /*first lets export all required gpios */
        gpio_export_4digit(GPIO_66_P8_7_SEGA);
        gpio_export_4digit(GPIO_67_P8_8_SEGB);
        gpio_export_4digit(GPIO_69_P8_9_SEGC);
        gpio_export_4digit(GPIO_68_P8_10_DP);
        gpio_export_4digit(GPIO_45_P8_11_SEGD);
        gpio_export_4digit(GPIO_44_P8_12_SEGE);
        gpio_export_4digit(GPIO_26_P8_14_SEGF);
        gpio_export_4digit(GPIO_46_P8_16_SEGG);

        gpio_export_4digit(GPIO_48_P9_15_DIGIT1);
        gpio_export_4digit(GPIO_49_P9_23_DIGIT2);
        gpio_export_4digit(GPIO_117_P9_30_DIGIT3);
        gpio_export_4digit(GPIO_115_P9_27_DIGIT4);

        /*first configure the direction for segments */

        gpio_configure_dir_4digit(GPIO_66_P8_7_SEGA,GPIO_DIR_OUT);
        gpio_configure_dir_4digit(GPIO_67_P8_8_SEGB,GPIO_DIR_OUT);
        gpio_configure_dir_4digit(GPIO_69_P8_9_SEGC,GPIO_DIR_OUT);
        gpio_configure_dir_4digit(GPIO_68_P8_10_DP,GPIO_DIR_OUT);
        gpio_configure_dir_4digit(GPIO_45_P8_11_SEGD,GPIO_DIR_OUT);
        gpio_configure_dir_4digit(GPIO_44_P8_12_SEGE,GPIO_DIR_OUT);
        gpio_configure_dir_4digit(GPIO_26_P8_14_SEGF,GPIO_DIR_OUT);
        gpio_configure_dir_4digit(GPIO_46_P8_16_SEGG,GPIO_DIR_OUT);

        /*configure the direction for digit control */
        gpio_configure_dir_4digit(GPIO_48_P9_15_DIGIT1,GPIO_DIR_OUT);
        gpio_configure_dir_4digit(GPIO_49_P9_23_DIGIT2,GPIO_DIR_OUT);
        gpio_configure_dir_4digit(GPIO_117_P9_30_DIGIT3,GPIO_DIR_OUT);
        gpio_configure_dir_4digit(GPIO_115_P9_27_DIGIT4,GPIO_DIR_OUT);

        /* make all segments low */
        gpio_write_value_4digit(GPIO_66_P8_7_SEGA,GPIO_LOW_VALUE);
        gpio_write_value_4digit(GPIO_67_P8_8_SEGB,GPIO_LOW_VALUE);
        gpio_write_value_4digit(GPIO_69_P8_9_SEGC,GPIO_LOW_VALUE);
        gpio_write_value_4digit(GPIO_68_P8_10_DP,GPIO_LOW_VALUE);
        gpio_write_value_4digit(GPIO_45_P8_11_SEGD,GPIO_LOW_VALUE);
        gpio_write_value_4digit(GPIO_44_P8_12_SEGE,GPIO_LOW_VALUE);
        gpio_write_value_4digit(GPIO_26_P8_14_SEGF,GPIO_LOW_VALUE);
        gpio_write_value_4digit(GPIO_46_P8_16_SEGG,GPIO_LOW_VALUE);

        /*MAKE ALL DIGITS OFF */
        gpio_write_value_4digit(GPIO_48_P9_15_DIGIT1,GPIO_LOW_VALUE);
        gpio_write_value_4digit(GPIO_49_P9_23_DIGIT2,GPIO_LOW_VALUE);
        gpio_write_value_4digit(GPIO_117_P9_30_DIGIT3,GPIO_LOW_VALUE);
        gpio_write_value_4digit(GPIO_115_P9_27_DIGIT4,GPIO_LOW_VALUE);

        /* argc is correct , lets check argv */
        if (strcmp(argv[1], "up") == 0)
        {
            start_upcounting_4digit(value);
        }
        else if (strcmp(argv[1], "down") == 0)
        {
            start_downcounting_4digit(value);
        }

        else /* default: */
        {
            printf("Invalid direction values\n");
            printf( "valid direction values : up, down,updown,random\n");
            return 1;
        }
    }
    return 0;
}


