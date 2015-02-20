run: rect
	gcc -g -o rect *.c
	./rect
compile: 
	gcc -g -o rect *.c
clean:
	rm -f rect