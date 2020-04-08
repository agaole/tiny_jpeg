all:
	gcc -std=c99 -lm main.c -o jpegenc 
clean:
	-rm jpegenc
