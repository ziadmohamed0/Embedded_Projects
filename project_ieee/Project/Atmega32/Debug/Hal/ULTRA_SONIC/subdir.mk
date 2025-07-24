################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hal/ULTRA_SONIC/ULTRA_SONIC.c 

OBJS += \
./Hal/ULTRA_SONIC/ULTRA_SONIC.o 

C_DEPS += \
./Hal/ULTRA_SONIC/ULTRA_SONIC.d 


# Each subdirectory must supply rules for building sources it contributes
Hal/ULTRA_SONIC/%.o: ../Hal/ULTRA_SONIC/%.c Hal/ULTRA_SONIC/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


