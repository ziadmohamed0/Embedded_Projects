################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Server/Server.c 

C_DEPS += \
./Server/Server.d 

OBJS += \
./Server/Server.o 


# Each subdirectory must supply rules for building sources it contributes
Server/%.o: ../Server/%.c Server/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Server

clean-Server:
	-$(RM) ./Server/Server.d ./Server/Server.o

.PHONY: clean-Server

