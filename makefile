SRC = clientAPI.c labyrinthAPI.c main1.c Laby.c
OBJ = $(SRC:.c=.o)
CC = gcc 
CFLAGS = -Wall -Wextra

all: main1

.c.o:
	$(CC) $(CFLAGS) -c $<
	
main1: $(OBJ)
	$(CC) -o $@ $(OBJ)

clean:
	rm main1 *.o
