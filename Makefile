#Makefile borregs
IN=main.c
DEPS=global.h nplaying.h aplayer.h lector.h
LFLAGS=-lm -lncurses
CFLAGS=-t -std=c99
OUT=noisy

$(OUT) : $(IN) $(DEPS)
	gcc -o $@ $(CFLAGS) $^ $(LFLAGS) && sleep 2 &&echo "[...] Everithing is OK"

clean: 
	rm $(OUT)&&ls -l *.lst *.wav *.log &&echo "Data Files Were not Deleted"
	
#
