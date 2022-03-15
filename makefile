LINK_TARGET = ex1
CC = gcc
CFLAGS = -g -Wall -std=c99

OBJS = \
	prompts.o \
	logfile.o \
	args.o \
	test.o

REBUILDABLES = $(OBJS) $(LINK_TARGET)

all: $(LINK_TARGET)

clean:
	rm -f $(REBUILDABLES)

$(LINK_TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<
