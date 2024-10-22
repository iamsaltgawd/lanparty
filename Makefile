
CC = gcc
CFLAGS = -Wall -g
OBJFILES = main.o essentials.o reqs.o
TARGET = lanParty

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

main.o: ./src/main.c ./src/essentials.h ./src/reqs.h
	$(CC) $(CFLAGS) -c ./src/main.c

essentials.o: ./src/essentials.c ./src/essentials.h
	$(CC) $(CFLAGS) -c ./src/essentials.c

reqs.o: ./src/reqs.c ./src/reqs.h
	$(CC) $(CFLAGS) -c ./src/reqs.c

clean:
	rm -f *.o $(TARGET)
