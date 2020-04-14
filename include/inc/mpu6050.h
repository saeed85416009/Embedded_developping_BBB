#ifndef __MPU6050_H
#define __MPU6050_H

/*================================================
BBB_expansion_header_P9_pins     MPU6050 pins
===================================================
P9_19                              SCL
P9_20                              SDA
P9_3                               VCC 3.3v
P9_1                               GND
==================================================== */

/*
 * Datasheet refs
 * 1. MPU-6000 and MPU-6050 Product Specification Revision 3.4
 * 2. MPU-6000 and MPU-6050 Register Map and Descriptions Revision 4.2
 */


#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>

/*MPU6050 register addresses */

#define MPU6050_REG_POWER               0x6B
#define MPU6050_REG_ACCEL_CONFIG        0x1C
#define MPU6050_REG_GYRO_CONFIG         0x1B

/*These are the addresses of mpu6050 from which you will fetch accelerometer x,y,z high and low values */
#define MPU6050_REG_ACC_X_HIGH          0x3B
#define MPU6050_REG_ACC_X_LOW           0x3C
#define MPU6050_REG_ACC_Y_HIGH          0x3D
#define MPU6050_REG_ACC_Y_LOW           0x3E
#define MPU6050_REG_ACC_Z_HIGH          0x3F
#define MPU6050_REG_ACC_Z_LOW           0x40

/*These are the addresses of mpu6050 from which you will fetch gyro x,y,z high and low values */
#define MPU6050_REG_GYRO_X_HIGH          0x43
#define MPU6050_REG_GYRO_X_LOW           0x44
#define MPU6050_REG_GYRO_Y_HIGH          0x45
#define MPU6050_REG_GYRO_Y_LOW           0x46
#define MPU6050_REG_GYRO_Z_HIGH          0x47
#define MPU6050_REG_GYRO_Z_LOW           0x48

/*
 * Different full scale ranges for acc and gyro
 * refer table 6.2 and 6.3 in the document MPU-6000 and MPU-6050 Product Specification Revision 3.4
 *
 */
#define ACC_FS_SENSITIVITY_0					16384
#define ACC_FS_SENSITIVITY_1		            8192
#define ACC_FS_SENSITIVITY_2		            4096
#define ACC_FS_SENSITIVITY_3		            2048

#define GYR_FS_SENSITIVITY_0					 131
#define GYR_FS_SENSITIVITY_1					 65.5
#define GYR_FS_SENSITIVITY_2					 32.8
#define GYR_FS_SENSITIVITY_3				 	 16.4


/* This is the I2C slave address of mpu6050 sensor */
#define MPU6050_SLAVE_ADDR 0x68

#define MAX_VALUE 50

/* This is the linux OS device file for hte I2C3 controller of the SOC */
#define I2C_DEVICE_FILE   "/dev/i2c-2"

int main_mpu6050(void);

#endif
