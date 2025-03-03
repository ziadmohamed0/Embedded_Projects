################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HALL/INIT/INIT_Prog.c 

OBJS += \
./HALL/INIT/INIT_Prog.o 

C_DEPS += \
./HALL/INIT/INIT_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
HALL/INIT/%.o: ../HALL/INIT/%.c HALL/INIT/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


