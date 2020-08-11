CC	?=	gcc
SRC	= $(wildcard lib/*.c lib/*/*.c)
OBJ	=	$(SRC:.c=.o)
CFLAGS	=	-Wall -g

test.bin: $(OBJ) test/test_suite.o
	$(CC) $(CFLAGS) -o $@ $^

my.a: $(OBJ)
	ar rs my.a $(OBJ)
