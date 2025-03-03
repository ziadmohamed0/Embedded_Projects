################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hall/DC_Motor/Dc_Motor_Config.c \
../Hall/DC_Motor/Dc_Motor_Prog.c 

OBJS += \
./Hall/DC_Motor/Dc_Motor_Config.o \
./Hall/DC_Motor/Dc_Motor_Prog.o 

C_DEPS += \
./Hall/DC_Motor/Dc_Motor_Config.d \
./Hall/DC_Motor/Dc_Motor_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
Hall/DC_Motor/%.o: ../Hall/DC_Motor/%.c Hall/DC_Motor/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


