################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal/Timer1/Timer1_prog.c 

OBJS += \
./Mcal/Timer1/Timer1_prog.o 

C_DEPS += \
./Mcal/Timer1/Timer1_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Mcal/Timer1/%.o: ../Mcal/Timer1/%.c Mcal/Timer1/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


