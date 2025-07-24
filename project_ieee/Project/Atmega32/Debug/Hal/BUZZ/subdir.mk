################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hal/BUZZ/BUZZ.c 

OBJS += \
./Hal/BUZZ/BUZZ.o 

C_DEPS += \
./Hal/BUZZ/BUZZ.d 


# Each subdirectory must supply rules for building sources it contributes
Hal/BUZZ/%.o: ../Hal/BUZZ/%.c Hal/BUZZ/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


