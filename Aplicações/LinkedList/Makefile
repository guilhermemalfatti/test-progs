INPUT_SIZE=2048

llist: gen_input.c llist.c llist.h main.c
	gcc -o gen_input gen_input.c
	gcc -DDEBUG -static -O3 -o llist llist.c main.c
clean:
	rm -rf llist llist.o gen_input
