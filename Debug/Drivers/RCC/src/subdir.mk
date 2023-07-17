################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/RCC/src/rcc.c 

OBJS += \
./Drivers/RCC/src/rcc.o 

C_DEPS += \
./Drivers/RCC/src/rcc.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/RCC/src/%.o Drivers/RCC/src/%.su Drivers/RCC/src/%.cyclo: ../Drivers/RCC/src/%.c Drivers/RCC/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I"E:/ENG PRo/Embedded/stm_project/NUCLEO-F446RE/Inc" -I"E:/ENG PRo/Embedded/stm_project/NUCLEO-F446RE/Drivers/GPTIIM/inc" -I"E:/ENG PRo/Embedded/stm_project/NUCLEO-F446RE/Drivers/EXTI/inc" -I"E:/ENG PRo/Embedded/stm_project/NUCLEO-F446RE/Drivers/CPU/inc" -I"E:/ENG PRo/Embedded/stm_project/NUCLEO-F446RE/Drivers/GPIO/inc" -I"E:/ENG PRo/Embedded/stm_project/NUCLEO-F446RE/Drivers/RCC/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-RCC-2f-src

clean-Drivers-2f-RCC-2f-src:
	-$(RM) ./Drivers/RCC/src/rcc.cyclo ./Drivers/RCC/src/rcc.d ./Drivers/RCC/src/rcc.o ./Drivers/RCC/src/rcc.su

.PHONY: clean-Drivers-2f-RCC-2f-src

