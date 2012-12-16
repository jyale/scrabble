################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Scrabble.cpp \
../board.cpp \
../boardobserver.cpp \
../dictionary.cpp \
../gamestate.cpp \
../gamestateobserver.cpp \
../inputcontroller.cpp \
../letters.cpp \
../player.cpp \
../playerobserver.cpp \
../playround.cpp \
../tools.cpp 

OBJS += \
./Scrabble.o \
./board.o \
./boardobserver.o \
./dictionary.o \
./gamestate.o \
./gamestateobserver.o \
./inputcontroller.o \
./letters.o \
./player.o \
./playerobserver.o \
./playround.o \
./tools.o 

CPP_DEPS += \
./Scrabble.d \
./board.d \
./boardobserver.d \
./dictionary.d \
./gamestate.d \
./gamestateobserver.d \
./inputcontroller.d \
./letters.d \
./player.d \
./playerobserver.d \
./playround.d \
./tools.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


