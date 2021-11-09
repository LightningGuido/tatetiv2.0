################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/casillero.cpp \
../src/main.cpp \
../src/tablero.cpp 

OBJS += \
./src/casillero.o \
./src/main.o \
./src/tablero.o 

CPP_DEPS += \
./src/casillero.d \
./src/main.d \
./src/tablero.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


