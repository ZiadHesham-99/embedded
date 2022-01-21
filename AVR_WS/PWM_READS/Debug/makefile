################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/Timer/Debug/DIO_DRIVER/subdir.mk
-include MCAL/Timer/Debug/subdir.mk
-include MCAL/Timer/DIO_DRIVER/subdir.mk
-include MCAL/Timer/subdir.mk
-include MCAL/INTERRUPT/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/LCD_handler/subdir.mk
-include HAL/KEYPAD_handler/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
PWM_READS.lss \

FLASH_IMAGE += \
PWM_READS.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: PWM_READS.elf secondary-outputs

# Tool invocations
PWM_READS.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,PWM_READS.map -mmcu=atmega32 -o "PWM_READS.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

PWM_READS.lss: PWM_READS.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S PWM_READS.elf  >"PWM_READS.lss"
	@echo 'Finished building: $@'
	@echo ' '

PWM_READS.hex: PWM_READS.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex PWM_READS.elf  "PWM_READS.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: PWM_READS.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 PWM_READS.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) PWM_READS.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
