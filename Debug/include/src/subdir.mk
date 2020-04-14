################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../include/src/gpio_driver_lcd.c \
../include/src/lcd_driver.c \
../include/src/lcd_text.c \
../include/src/led.c \
../include/src/mpu6050.c \
../include/src/sevenSegment_4digit.c \
../include/src/sevenSegment_counter.c \
../include/src/test.c 

OBJS += \
./include/src/gpio_driver_lcd.o \
./include/src/lcd_driver.o \
./include/src/lcd_text.o \
./include/src/led.o \
./include/src/mpu6050.o \
./include/src/sevenSegment_4digit.o \
./include/src/sevenSegment_counter.o \
./include/src/test.o 

C_DEPS += \
./include/src/gpio_driver_lcd.d \
./include/src/lcd_driver.d \
./include/src/lcd_text.d \
./include/src/led.d \
./include/src/mpu6050.d \
./include/src/sevenSegment_4digit.d \
./include/src/sevenSegment_counter.d \
./include/src/test.d 


# Each subdirectory must supply rules for building sources it contributes
include/src/%.o: ../include/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -I"D:\Users\Saeed\eclipse-workspace\BBB-Saeed-1\include\inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


