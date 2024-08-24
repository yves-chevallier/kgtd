CC?=gcc
CFLAGS=-std=c17 -O3 -Wall -Werror -pedantic -mfpmath=sse -msse -mmmx -ffast-math
LDFLAGS=-lSDL -lGL -lm
EXEC=main
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

all: $(EXEC)

-include $(OBJS:.o=.d)

$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) -MMD -MP

clean:
	$(RM) -f $(OBJS) $(EXEC) $(OBJS:.o=.d)

.PHONY: all clean
