FILES=sort.c

main: build

build: $(FILES)
	gcc -g -o sort $(FILES) -lm

clean: sort
	rm sort
