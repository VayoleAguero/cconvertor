CC=gcc
FLAGS= -Wall -Werror -Wextra
BO=bit_operations
NC=number_convertor
TARGET=../build/convertor
MAIN=util

all: convertor

clean: rm -rf $(BO).o $(NC).o $(TARGET)

rebuild: clean all

convertor:$(BO).o $(NC).o $(MAIN).o
	$(CC) $(FLAGS) $(BO).o $(NC).o $(MAIN).o -o $(TARGET)

$(BO).o:
	$(CC) $(FLAGS) -c bit_opers.c -o $(BO).o 


$(NC).o: 
	$(CC) $(FLAGS) -c numbr_convertation.c -o $(NC).o 

$(MAIN).o: main.c
	$(CC) $(FLAGS) -c main.c -o $(MAIN).o