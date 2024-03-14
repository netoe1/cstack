cstack.o:./src/cstack.c ./include/cstack.h
	gcc -c ./src/cstack.c -o ./bin/cstack.o
main.o: ./src/main.c
	gcc -o ./bin/main.o ./src/main.c ./bin/cstack.o
all:
	make cstack.o main.o
run:
	./bin/main.o
clean:
	rm -rf ./bin/*.*
