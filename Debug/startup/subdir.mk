################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../startup/boot_multicore_slave.c \
../startup/startup_lpc55s69_cm33_core0.c 

OBJS += \
./startup/boot_multicore_slave.o \
./startup/startup_lpc55s69_cm33_core0.o 

C_DEPS += \
./startup/boot_multicore_slave.d \
./startup/startup_lpc55s69_cm33_core0.d 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.c startup/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DCPU_LPC55S69JBD100_cm33_core0 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSDK_OS_FREE_RTOS -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/home/david/Documents/MCUXpresso_11.5.0_7232/workspace/LPC55S69_M3C/board" -I"/home/david/Documents/MCUXpresso_11.5.0_7232/workspace/LPC55S69_M3C/source" -I"/home/david/Documents/MCUXpresso_11.5.0_7232/workspace/LPC55S69_M3C/freertos/freertos_kernel/portable/GCC/ARM_CM33_NTZ/non_secure" -I"/home/david/Documents/MCUXpresso_11.5.0_7232/workspace/LPC55S69_M3C/freertos/freertos_kernel/include" -I"/home/david/Documents/MCUXpresso_11.5.0_7232/workspace/LPC55S69_M3C/drivers" -I"/home/david/Documents/MCUXpresso_11.5.0_7232/workspace/LPC55S69_M3C/drivers/freertos" -I"/home/david/Documents/MCUXpresso_11.5.0_7232/workspace/LPC55S69_M3C/utilities" -I"/home/david/Documents/MCUXpresso_11.5.0_7232/workspace/LPC55S69_M3C/component/uart" -I"/home/david/Documents/MCUXpresso_11.5.0_7232/workspace/LPC55S69_M3C/component/serial_manager" -I"/home/david/Documents/MCUXpresso_11.5.0_7232/workspace/LPC55S69_M3C/component/lists" -I"/home/david/Documents/MCUXpresso_11.5.0_7232/workspace/LPC55S69_M3C/startup" -I"/home/david/Documents/MCUXpresso_11.5.0_7232/workspace/LPC55S69_M3C/CMSIS" -I"/home/david/Documents/MCUXpresso_11.5.0_7232/workspace/LPC55S69_M3C/device" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


