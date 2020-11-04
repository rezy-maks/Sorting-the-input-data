all: bin/Sorting-the-input-data format

bin/Sorting-the-input-data: build/src/main.o build/src/sorts.o
	gcc -Wall -Werror build/src/main.o build/src/sorts.o -o bin/Sorting-the-input-data

build/src/main.o: src/main.c src/sorts.h
	gcc -Wall -Werror -c src/main.c -o build/src/main.o

build/src/sorts.o: src/sorts.c src/sorts.h
	gcc -Wall -Werror -c src/sorts.c -o build/src/sorts.o

clear:

	rm -rf build/src/*.o bin/Sorting-the-input-data

format:

	clang-format -i src/main.c

