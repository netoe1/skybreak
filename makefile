skybreak:
	gcc -o ./bin/skybreak.o ./src/skybreak.c -lncurses
clean:
	rm -rf ./bin/*.*
run:	
	./bin/skybreak.o
