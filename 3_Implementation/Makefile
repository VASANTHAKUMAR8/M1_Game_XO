# Name of the project
PROJECT_NAME = XO_game
# All source code files
SRC = main.c\
src/clinic_main.c
INC = inc
all.exe : $(SRC) 
	gcc $^ -I$(INC) -o $@

run : all.exe
	./all.exe

clean:
	del all.exe
