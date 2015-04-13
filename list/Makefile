CC=gcc

CPPFLAGS=
CFLAGS= -Wall -Wextra -Werror -std=c99 -O3
LDFLAGS=
LDLIBS=

SRC= main.c
OBJ= ${SRC:.c=.o}

all: main list

list: list.c
	${CFLAGS} list.c

main: ${OBJ}

clean:
	rm -f *~ *.o

# END
