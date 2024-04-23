################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hall/BCD/bcd_Config.c \
../Hall/BCD/bcd_Prog.c 

OBJS += \
./Hall/BCD/bcd_Config.o \
./Hall/BCD/bcd_Prog.o 

C_DEPS += \
./Hall/BCD/bcd_Config.d \
./Hall/BCD/bcd_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
Hall/BCD/%.o: ../Hall/BCD/%.c Hall/BCD/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


