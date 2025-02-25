################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Terminal/Terminal.c 

C_DEPS += \
./Terminal/Terminal.d 

OBJS += \
./Terminal/Terminal.o 


# Each subdirectory must supply rules for building sources it contributes
Terminal/%.o: ../Terminal/%.c Terminal/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Terminal

clean-Terminal:
	-$(RM) ./Terminal/Terminal.d ./Terminal/Terminal.o

.PHONY: clean-Terminal

