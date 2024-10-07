################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app/hw/hw.c 

OBJS += \
./app/hw/hw.o 

C_DEPS += \
./app/hw/hw.d 


# Each subdirectory must supply rules for building sources it contributes
app/hw/%.o app/hw/%.su app/hw/%.cyclo: ../app/hw/%.c app/hw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/DATA/SOC_workspace/stm32/STM32F411_Layer/app" -I"C:/DATA/SOC_workspace/stm32/STM32F411_Layer/app/common" -I"C:/DATA/SOC_workspace/stm32/STM32F411_Layer/app/hw" -I"C:/DATA/SOC_workspace/stm32/STM32F411_Layer/app/hw/driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-app-2f-hw

clean-app-2f-hw:
	-$(RM) ./app/hw/hw.cyclo ./app/hw/hw.d ./app/hw/hw.o ./app/hw/hw.su

.PHONY: clean-app-2f-hw

