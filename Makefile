.PHONY: all clean test
default: all

LIB_NAME = Hermes
LIBRARY = lib$(LIB_NAME).so

$(LIBRARY) : ./src/*.c
	@echo
	@echo Compile library:
	@echo

	-gcc -Os -std=c11 -pedantic -Wall -Wextra ./src/*.c -shared -o $(LIBRARY)

	@echo

test :
	@echo test

clean :
	-rm -f $(LIBRARY)

all : test $(LIBRARY)
	@echo all
