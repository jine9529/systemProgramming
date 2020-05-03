CC = gcc
CFLAGS = -03 -Wall
OBJS = one.o two.o ten.o

morph:	$(OBJS)
	$(CC) -o three $(CFLAG) $(OBJS)
clean:
	rm -f $(OBJS)
	rm -f three
.c.o:
	@echo "compiling " $*.c "..."
	@echo "compiling " $< "..."
	$(CC) $(CFLAG) -c $*.c
