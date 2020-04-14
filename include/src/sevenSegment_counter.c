#include "sevenSegment_counter.h"


/*
 *  GPIO configure direction
 *  dir_value : 1 means 'out' , 0 means "in"
 */
int gpio_configure_dir(uint32_t gpio_num, uint8_t dir_value)
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
int gpio_write_value(uint32_t gpio_num, uint8_t out_value)
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
int gpio_read_value(uint32_t gpio_num)
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
 *  edge : rising, falling , none
 */
int gpio_configure_edge(uint32_t gpio_num, char *edge)
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
int gpio_file_open(uint32_t gpio_num)
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
int gpio_file_close(int fd)
{
    return close(fd);
}



int initialize_all_gpios(void)
{
	/*  we are driving the leds , so,
	 * 1. first make the gpio which drives the led to output mode , that means set the direction as "out"
	 * 2. then write the value "0" to turn off all the leds or segments.
	 */
			gpio_export(GPIO_66_P8_7_SEGA);
	        gpio_export(GPIO_67_P8_8_SEGB);
	        gpio_export(GPIO_69_P8_9_SEGC);
	        gpio_export(GPIO_68_P8_10_DP);
	        gpio_export(GPIO_45_P8_11_SEGD);
	        gpio_export(GPIO_44_P8_12_SEGE);
	        gpio_export(GPIO_26_P8_14_SEGF);
	        gpio_export(GPIO_46_P8_16_SEGG);

    gpio_configure_dir(GPIO_66,GPIO_DIR_OUT);
    gpio_write_value(GPIO_66, GPIO_LOW_VALUE );

    gpio_configure_dir(GPIO_67,GPIO_DIR_OUT);
    gpio_write_value(GPIO_67, GPIO_LOW_VALUE );

    gpio_configure_dir(GPIO_69,GPIO_DIR_OUT);
    gpio_write_value(GPIO_69, GPIO_LOW_VALUE );

    gpio_configure_dir(GPIO_68,GPIO_DIR_OUT);
    gpio_write_value(GPIO_68, GPIO_LOW_VALUE );

    gpio_configure_dir(GPIO_45,GPIO_DIR_OUT);
    gpio_write_value(GPIO_45, GPIO_LOW_VALUE );

    gpio_configure_dir(GPIO_44,GPIO_DIR_OUT);
    gpio_write_value(GPIO_44, GPIO_LOW_VALUE );

    gpio_configure_dir(GPIO_26,GPIO_DIR_OUT);
    gpio_write_value(GPIO_26, GPIO_LOW_VALUE );

    gpio_configure_dir(GPIO_46,GPIO_DIR_OUT);
    gpio_write_value(GPIO_46, GPIO_LOW_VALUE );

    return 0;

}

/*
 *  GPIO export pin
 *
 */
int gpio_export(uint32_t gpio_num)
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

/* This function displays number on the 7segment display */
void Write_number_to_7segdisplay(uint8_t numberToDisplay)
{

    switch (numberToDisplay){

    case 0:
        gpio_write_value(GPIO_66_P8_7_SEGA, SEGMENT_ON);
        gpio_write_value(GPIO_67_P8_8_SEGB, SEGMENT_ON);
        gpio_write_value(GPIO_69_P8_9_SEGC, SEGMENT_ON);
        gpio_write_value(GPIO_45_P8_11_SEGD, SEGMENT_ON);
        gpio_write_value(GPIO_44_P8_12_SEGE, SEGMENT_ON);
        gpio_write_value(GPIO_26_P8_14_SEGF, SEGMENT_ON);
        gpio_write_value(GPIO_46_P8_16_SEGG, SEGMENT_OFF);
    break;

    case 1:
        gpio_write_value(GPIO_66_P8_7_SEGA, SEGMENT_OFF);
        gpio_write_value(GPIO_67_P8_8_SEGB, SEGMENT_ON);
        gpio_write_value(GPIO_69_P8_9_SEGC, SEGMENT_ON);
        gpio_write_value(GPIO_45_P8_11_SEGD, SEGMENT_OFF);
        gpio_write_value(GPIO_44_P8_12_SEGE, SEGMENT_OFF);
        gpio_write_value(GPIO_26_P8_14_SEGF, SEGMENT_OFF);
        gpio_write_value(GPIO_46_P8_16_SEGG, SEGMENT_OFF);
    break;

    case 2:
        gpio_write_value(GPIO_66_P8_7_SEGA, SEGMENT_ON);
        gpio_write_value(GPIO_67_P8_8_SEGB, SEGMENT_ON);
        gpio_write_value(GPIO_69_P8_9_SEGC, SEGMENT_OFF);
        gpio_write_value(GPIO_45_P8_11_SEGD, SEGMENT_ON);
        gpio_write_value(GPIO_44_P8_12_SEGE, SEGMENT_ON);
        gpio_write_value(GPIO_26_P8_14_SEGF, SEGMENT_OFF);
        gpio_write_value(GPIO_46_P8_16_SEGG, SEGMENT_ON);
    break;

    case 3:
        gpio_write_value(GPIO_66_P8_7_SEGA, SEGMENT_ON);
        gpio_write_value(GPIO_67_P8_8_SEGB, SEGMENT_ON);
        gpio_write_value(GPIO_69_P8_9_SEGC, SEGMENT_ON);
        gpio_write_value(GPIO_45_P8_11_SEGD, SEGMENT_ON);
        gpio_write_value(GPIO_44_P8_12_SEGE, SEGMENT_OFF);
        gpio_write_value(GPIO_26_P8_14_SEGF, SEGMENT_OFF);
        gpio_write_value(GPIO_46_P8_16_SEGG, SEGMENT_ON);
    break;

    case 4:
        gpio_write_value(GPIO_66_P8_7_SEGA, SEGMENT_OFF);
        gpio_write_value(GPIO_67_P8_8_SEGB, SEGMENT_ON);
        gpio_write_value(GPIO_69_P8_9_SEGC, SEGMENT_ON);
        gpio_write_value(GPIO_45_P8_11_SEGD, SEGMENT_OFF);
        gpio_write_value(GPIO_44_P8_12_SEGE, SEGMENT_OFF);
        gpio_write_value(GPIO_26_P8_14_SEGF, SEGMENT_ON);
        gpio_write_value(GPIO_46_P8_16_SEGG, SEGMENT_ON);
    break;

    case 5:
        gpio_write_value(GPIO_66_P8_7_SEGA, SEGMENT_ON);
        gpio_write_value(GPIO_67_P8_8_SEGB, SEGMENT_OFF);
        gpio_write_value(GPIO_69_P8_9_SEGC, SEGMENT_ON);
        gpio_write_value(GPIO_45_P8_11_SEGD, SEGMENT_ON);
        gpio_write_value(GPIO_44_P8_12_SEGE, SEGMENT_OFF);
        gpio_write_value(GPIO_26_P8_14_SEGF, SEGMENT_ON);
        gpio_write_value(GPIO_46_P8_16_SEGG, SEGMENT_ON);
    break;

    case 6:
        gpio_write_value(GPIO_66_P8_7_SEGA, SEGMENT_ON);
        gpio_write_value(GPIO_67_P8_8_SEGB, SEGMENT_OFF);
        gpio_write_value(GPIO_69_P8_9_SEGC, SEGMENT_ON);
        gpio_write_value(GPIO_45_P8_11_SEGD, SEGMENT_ON);
        gpio_write_value(GPIO_44_P8_12_SEGE, SEGMENT_ON);
        gpio_write_value(GPIO_26_P8_14_SEGF, SEGMENT_ON);
        gpio_write_value(GPIO_46_P8_16_SEGG, SEGMENT_ON);
    break;

    case 7:
        gpio_write_value(GPIO_66_P8_7_SEGA, SEGMENT_ON);
        gpio_write_value(GPIO_67_P8_8_SEGB, SEGMENT_ON);
        gpio_write_value(GPIO_69_P8_9_SEGC, SEGMENT_ON);
        gpio_write_value(GPIO_45_P8_11_SEGD, SEGMENT_OFF);
        gpio_write_value(GPIO_44_P8_12_SEGE, SEGMENT_OFF);
        gpio_write_value(GPIO_26_P8_14_SEGF, SEGMENT_OFF);
        gpio_write_value(GPIO_46_P8_16_SEGG, SEGMENT_OFF);
    break;

    case 8:
        gpio_write_value(GPIO_66_P8_7_SEGA, SEGMENT_ON);
        gpio_write_value(GPIO_67_P8_8_SEGB, SEGMENT_ON);
        gpio_write_value(GPIO_69_P8_9_SEGC, SEGMENT_ON);
        gpio_write_value(GPIO_45_P8_11_SEGD, SEGMENT_ON);
        gpio_write_value(GPIO_44_P8_12_SEGE, SEGMENT_ON);
        gpio_write_value(GPIO_26_P8_14_SEGF, SEGMENT_ON);
        gpio_write_value(GPIO_46_P8_16_SEGG, SEGMENT_ON);
    break;

    case 9:
        gpio_write_value(GPIO_66_P8_7_SEGA, SEGMENT_ON);
        gpio_write_value(GPIO_67_P8_8_SEGB, SEGMENT_ON);
        gpio_write_value(GPIO_69_P8_9_SEGC, SEGMENT_ON);
        gpio_write_value(GPIO_45_P8_11_SEGD, SEGMENT_ON);
        gpio_write_value(GPIO_44_P8_12_SEGE, SEGMENT_OFF);
        gpio_write_value(GPIO_26_P8_14_SEGF, SEGMENT_ON);
        gpio_write_value(GPIO_46_P8_16_SEGG, SEGMENT_ON);
    break;

    case 10:
        gpio_write_value(GPIO_66_P8_7_SEGA, SEGMENT_OFF);
        gpio_write_value(GPIO_67_P8_8_SEGB, SEGMENT_OFF);
        gpio_write_value(GPIO_69_P8_9_SEGC, SEGMENT_OFF);
        gpio_write_value(GPIO_45_P8_11_SEGD, SEGMENT_OFF);
        gpio_write_value(GPIO_44_P8_12_SEGE, SEGMENT_OFF);
        gpio_write_value(GPIO_26_P8_14_SEGF, SEGMENT_OFF);
        gpio_write_value(GPIO_46_P8_16_SEGG, SEGMENT_OFF);
    break;
    }



}

/* implements the up counting from 0 to 9 */
void start_upcounting(int delay_value_ms)
{
    uint8_t i =0;

    if ( initialize_all_gpios() < 0)
    {
        printf("Error: GPIO init failed !\n");
    }
    else
    {
        printf("UP COUNTING.......\n");
        while(1)
       {

            for(i=0;i<10;i++)
            {
                Write_number_to_7segdisplay(i);
                /*suspend execution for microsecond intervals*/
                usleep(delay_value_ms * 1000); //converting ms to micro
            }

       }

    }

}

/* implements the down counting from 9 to 0 */
void start_downcounting(int delay_value_ms)
{
    int i=9;
    if ( initialize_all_gpios() < 0)
    {
        printf("Error: GPIO init failed !\n");
    }
    else
    {
        printf("DOWN COUNTING.......\n");
        while(1)
       {
            for(i=9;i >= 0 ;i--)
            {
                Write_number_to_7segdisplay(i);
                /*suspend execution for microsecond intervals*/
                usleep(delay_value_ms * 1000); //converting ms to micro
            }
       }
    }
}


int main_7segment_counter(int argc, char *argv[]) {

    printf("Application for up/down/random counter on 7 seg display\n");

    if ( argc != 4 ) /* argc should be 3 for correct execution */
    {

        printf( "usage: %s <direction> <delay>\n", argv[0] );
        printf( "valid direction : up, down, updown, random\n");
        printf ("recommended delay range in ms : 0 to 1000\n");
    }
    else
    {
    	/* convert the 'delay' value , which argv[2]  in to integer */
        int delay_value = atoi(argv[2]);

        /* argc is correct , lets check argv */
        if (! strcmp(argv[1], "up") )
        {
            start_upcounting(delay_value);
        }
        else if (strcmp(argv[1], "down") == 0)
        {
            start_downcounting(delay_value);
        }
        else /* default: */
        {
            printf("Invalid direction values\n");
            printf( "valid direction values : up, down,updown,random\n");
        }
    }
    return 0;
}


