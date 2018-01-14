FILES=sort.c

main: build

build: $(FILES)
	gcc -o sort $(FILES)

clean: sort
	rm sort
