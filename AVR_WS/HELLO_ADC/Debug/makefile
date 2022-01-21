################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIMER/subdir.mk
-include MCAL/INTERRUPT/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/LCD_handler/subdir.mk
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
HELLO_ADC.lss \

FLASH_IMAGE += \
HELLO_ADC.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: HELLO_ADC.elf secondary-outputs

# Tool invocations
HELLO_ADC.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,HELLO_ADC.map -mmcu=atmega32 -o "HELLO_ADC.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

HELLO_ADC.lss: HELLO_ADC.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S HELLO_ADC.elf  >"HELLO_ADC.lss"
	@echo 'Finished building: $@'
	@echo ' '

HELLO_ADC.hex: HELLO_ADC.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex HELLO_ADC.elf  "HELLO_ADC.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: HELLO_ADC.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 HELLO_ADC.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) HELLO_ADC.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
