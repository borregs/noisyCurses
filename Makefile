CC=gcc
CFLAGS=-std=c99 -t
LFLAGS=-lncurses -lm
OUT=noisy

$(OUT): main.c
	$(CC) -o $@ $^ $(CFLAGS) $(LFLAGS)

clean:
rm *.o *~ $(OUT)
