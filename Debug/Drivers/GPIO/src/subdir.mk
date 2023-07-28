################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/GPIO/src/gpio.c 

OBJS += \
./Drivers/GPIO/src/gpio.o 

C_DEPS += \
./Drivers/GPIO/src/gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/GPIO/src/%.o Drivers/GPIO/src/%.su Drivers/GPIO/src/%.cyclo: ../Drivers/GPIO/src/%.c Drivers/GPIO/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I"E:/ENG PRo/Embedded/stm_project/NUCLEO-F446RE/Inc" -I"E:/ENG PRo/Embedded/stm_project/NUCLEO-F446RE/Drivers/UART/inc" -I"E:/ENG PRo/Embedded/stm_project/NUCLEO-F446RE/Drivers/GPTIIM/inc" -I"E:/ENG PRo/Embedded/stm_project/NUCLEO-F446RE/Drivers/EXTI/inc" -I"E:/ENG PRo/Embedded/stm_project/NUCLEO-F446RE/Drivers/CPU/inc" -I"E:/ENG PRo/Embedded/stm_project/NUCLEO-F446RE/Drivers/GPIO/inc" -I"E:/ENG PRo/Embedded/stm_project/NUCLEO-F446RE/Drivers/RCC/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-GPIO-2f-src

clean-Drivers-2f-GPIO-2f-src:
	-$(RM) ./Drivers/GPIO/src/gpio.cyclo ./Drivers/GPIO/src/gpio.d ./Drivers/GPIO/src/gpio.o ./Drivers/GPIO/src/gpio.su

.PHONY: clean-Drivers-2f-GPIO-2f-src

