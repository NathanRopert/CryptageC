cibles=$(patsubst %.c, %, $(wildcard *.c))

all: $(cibles)

$(cibles): %: %.c
	gcc -o $@ $<

clean:
	rm $(cibles)
