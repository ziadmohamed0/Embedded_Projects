################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Card/Card.c 

C_DEPS += \
./Card/Card.d 

OBJS += \
./Card/Card.o 


# Each subdirectory must supply rules for building sources it contributes
Card/%.o: ../Card/%.c Card/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Card

clean-Card:
	-$(RM) ./Card/Card.d ./Card/Card.o

.PHONY: clean-Card

