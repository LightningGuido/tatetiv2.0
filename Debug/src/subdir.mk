################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/cartas.cpp \
../src/casillero.cpp \
../src/jugador.cpp \
../src/main.cpp \
../src/tablero.cpp 

OBJS += \
./src/cartas.o \
./src/casillero.o \
./src/jugador.o \
./src/main.o \
./src/tablero.o 

CPP_DEPS += \
./src/cartas.d \
./src/casillero.d \
./src/jugador.d \
./src/main.d \
./src/tablero.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


