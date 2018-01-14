FILES=sort.c

main: build

build: $(FILES)
	gcc -o sort $(FILES) -lm

clean: sort
	rm sort
