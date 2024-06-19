################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PROJECTS/SMART_LOCK_DOOR/SMART_LOCK_DOOR_prog.c 

OBJS += \
./PROJECTS/SMART_LOCK_DOOR/SMART_LOCK_DOOR_prog.o 

C_DEPS += \
./PROJECTS/SMART_LOCK_DOOR/SMART_LOCK_DOOR_prog.d 


# Each subdirectory must supply rules for building sources it contributes
PROJECTS/SMART_LOCK_DOOR/%.o: ../PROJECTS/SMART_LOCK_DOOR/%.c PROJECTS/SMART_LOCK_DOOR/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


