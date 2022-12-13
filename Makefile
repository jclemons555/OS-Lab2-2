signal: signal.c
	gcc signal.c -o signal

timer: timer.c
	gcc timer.c -o timer

all: signal timer

clean:
	rm signal timer