################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/EXTI/src/exti.c 

OBJS += \
./Drivers/EXTI/src/exti.o 

C_DEPS += \
./Drivers/EXTI/src/exti.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/EXTI/src/%.o Drivers/EXTI/src/%.su Drivers/EXTI/src/%.cyclo: ../Drivers/EXTI/src/%.c Drivers/EXTI/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I"E:/ENG PRo/Embedded/stm_project/NUCLEO-F446RE/Inc" -I"E:/ENG PRo/Embedded/stm_project/NUCLEO-F446RE/Drivers/GPTIIM/inc" -I"E:/ENG PRo/Embedded/stm_project/NUCLEO-F446RE/Drivers/EXTI/inc" -I"E:/ENG PRo/Embedded/stm_project/NUCLEO-F446RE/Drivers/CPU/inc" -I"E:/ENG PRo/Embedded/stm_project/NUCLEO-F446RE/Drivers/GPIO/inc" -I"E:/ENG PRo/Embedded/stm_project/NUCLEO-F446RE/Drivers/RCC/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-EXTI-2f-src

clean-Drivers-2f-EXTI-2f-src:
	-$(RM) ./Drivers/EXTI/src/exti.cyclo ./Drivers/EXTI/src/exti.d ./Drivers/EXTI/src/exti.o ./Drivers/EXTI/src/exti.su

.PHONY: clean-Drivers-2f-EXTI-2f-src

