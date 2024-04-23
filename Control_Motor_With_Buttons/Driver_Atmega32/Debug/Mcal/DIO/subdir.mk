################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal/DIO/dio_Prog.c 

OBJS += \
./Mcal/DIO/dio_Prog.o 

C_DEPS += \
./Mcal/DIO/dio_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
Mcal/DIO/%.o: ../Mcal/DIO/%.c Mcal/DIO/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


