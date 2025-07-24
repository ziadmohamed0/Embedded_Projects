################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hal/DC_MOTOR/DC_MOTOR.c 

OBJS += \
./Hal/DC_MOTOR/DC_MOTOR.o 

C_DEPS += \
./Hal/DC_MOTOR/DC_MOTOR.d 


# Each subdirectory must supply rules for building sources it contributes
Hal/DC_MOTOR/%.o: ../Hal/DC_MOTOR/%.c Hal/DC_MOTOR/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


