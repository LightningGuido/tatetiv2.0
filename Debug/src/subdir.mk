################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Nodo.cpp \
../src/NodoPila.cpp \
../src/Tateti.cpp \
../src/cartas.cpp \
../src/casillero.cpp \
../src/cola.cpp \
../src/juego.cpp \
../src/jugador.cpp \
../src/main.cpp \
../src/pila.cpp \
../src/tablero.cpp 

OBJS += \
./src/Nodo.o \
./src/NodoPila.o \
./src/Tateti.o \
./src/cartas.o \
./src/casillero.o \
./src/cola.o \
./src/juego.o \
./src/jugador.o \
./src/main.o \
./src/pila.o \
./src/tablero.o 

CPP_DEPS += \
./src/Nodo.d \
./src/NodoPila.d \
./src/Tateti.d \
./src/cartas.d \
./src/casillero.d \
./src/cola.d \
./src/juego.d \
./src/jugador.d \
./src/main.d \
./src/pila.d \
./src/tablero.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


