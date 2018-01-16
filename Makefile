FILES=sort.c
OUT=normal-sort

main: build

build: $(FILES)
	gcc -o normal-sort $(FILES) -lm

debug: $(FILES)
	gcc -g -o $(OUT) $(FILES) -lm
	gdb $(OUT)

profile: $(FILES)
	gcc -pg -o $(OUT) $(FILES) -lm
	./$(OUT)
	gprof $(OUT)

clean:
	rm normal-sort
	rm *.out
