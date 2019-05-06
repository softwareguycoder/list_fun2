################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../file.c \
../list_fun2.c \
../point.c \
../stdafx.c 

OBJS += \
./file.o \
./list_fun2.o \
./point.o \
./stdafx.o 

C_DEPS += \
./file.d \
./list_fun2.d \
./point.d \
./stdafx.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/bhart/git/list_core/list_core" -I"/home/bhart/git/common_core/common_core" -I"/home/bhart/git/api_core/api_core" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


