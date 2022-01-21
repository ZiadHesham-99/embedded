################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/KEYPAD_handler/KEYPAD.c \
../HAL/KEYPAD_handler/KEYPAD_cfg.c 

OBJS += \
./HAL/KEYPAD_handler/KEYPAD.o \
./HAL/KEYPAD_handler/KEYPAD_cfg.o 

C_DEPS += \
./HAL/KEYPAD_handler/KEYPAD.d \
./HAL/KEYPAD_handler/KEYPAD_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/KEYPAD_handler/%.o: ../HAL/KEYPAD_handler/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


