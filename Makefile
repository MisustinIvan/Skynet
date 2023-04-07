build:
	gcc -lm -o ./bin/main ./src/main.c ./src/compute.c ./src/max.c ./src/init.c ./src/logging.c ./src/randrange.c ./src/sigmoid.c ./src/training.c ./src/data.c

run:
	./bin/main

clear:
	rm ./bin/main

build_debug:
	gcc -g -o ./bin/main_debug ./src/main.c

debug:
	gdb ./bin/main_debug

show_info:
	cat ./bin/network_info
