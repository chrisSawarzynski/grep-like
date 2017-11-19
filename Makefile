# config:

COMPILER=gcc
DEPS_FLAGS=-c -g -Wall -Werror
MAIN_FLAGS=-g -Wall -Werror
default: main

# deps for build targets

READ_O=build/read_file.o
MAIN_O=build/grep-like

# build targets

$(READ_O): src/read_file/read_file.c
	$(COMPILER) src/read_file/read_file.c $(DEPS_FLAGS) -o $(READ_O)

main: $(READ_O)
	gcc $(READ_FILE) src/main.c $(MAIN_FLAGS) -o $(MAIN_O)

clean:
	rm ./build/*
