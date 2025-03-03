################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hall/UltraSonic/UltraSonic_Config.c \
../Hall/UltraSonic/UltraSonic_Prog.c 

OBJS += \
./Hall/UltraSonic/UltraSonic_Config.o \
./Hall/UltraSonic/UltraSonic_Prog.o 

C_DEPS += \
./Hall/UltraSonic/UltraSonic_Config.d \
./Hall/UltraSonic/UltraSonic_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
Hall/UltraSonic/%.o: ../Hall/UltraSonic/%.c Hall/UltraSonic/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


