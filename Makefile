# config:

COMPILER=gcc
DEBUG=-g
DEPS_FLAGS=-c $(DEBUG)
MAIN_FLAGS=$(DEBUG)
default: main

# deps for build targets

READ_O=build/read_file.o
FIND_O=build/find_pattern.o
PRINT_O=build/print_result.o

MAIN_DEPS=$(READ_O) $(FIND_O) $(PRINT_O)
MAIN_O=build/grep-like

# build targets

$(READ_O): src/read_file/read_file.c
	$(COMPILER) src/read_file/read_file.c $(DEPS_FLAGS) -o $(READ_O)

$(FIND_O): src/find_pattern/find_pattern.c
	$(COMPILER) src/find_pattern/find_pattern.c $(DEPS_FLAGS) -o $(FIND_O)

$(PRINT_O): src/print_result/print_result.c
	$(COMPILER) src/print_result/print_result.c $(DEPS_FLAGS) -o $(PRINT_O)

main: $(MAIN_DEPS)
	gcc $(READ_FILE) $(MAIN_DEPS) src/main.c $(MAIN_FLAGS) -o $(MAIN_O)

clean:
	rm build/*
