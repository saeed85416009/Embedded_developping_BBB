################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../scr/main.c 

OBJS += \
./scr/main.o 

C_DEPS += \
./scr/main.d 


# Each subdirectory must supply rules for building sources it contributes
scr/%.o: ../scr/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -I"D:\Users\Saeed\eclipse-workspace\BBB-Saeed-1\include\inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


