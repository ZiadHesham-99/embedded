################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
HELLO_SPI.lss \

FLASH_IMAGE += \
HELLO_SPI.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: HELLO_SPI.elf secondary-outputs

# Tool invocations
HELLO_SPI.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,HELLO_SPI.map -mmcu=atmega32 -o "HELLO_SPI.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

HELLO_SPI.lss: HELLO_SPI.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S HELLO_SPI.elf  >"HELLO_SPI.lss"
	@echo 'Finished building: $@'
	@echo ' '

HELLO_SPI.hex: HELLO_SPI.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex HELLO_SPI.elf  "HELLO_SPI.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: HELLO_SPI.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 HELLO_SPI.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) HELLO_SPI.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
