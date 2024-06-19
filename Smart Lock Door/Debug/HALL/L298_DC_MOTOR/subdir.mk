################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HALL/L298_DC_MOTOR/L298_DC_MOTOR_config.c \
../HALL/L298_DC_MOTOR/L298_DC_MOTOR_prog.c 

OBJS += \
./HALL/L298_DC_MOTOR/L298_DC_MOTOR_config.o \
./HALL/L298_DC_MOTOR/L298_DC_MOTOR_prog.o 

C_DEPS += \
./HALL/L298_DC_MOTOR/L298_DC_MOTOR_config.d \
./HALL/L298_DC_MOTOR/L298_DC_MOTOR_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HALL/L298_DC_MOTOR/%.o: ../HALL/L298_DC_MOTOR/%.c HALL/L298_DC_MOTOR/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


