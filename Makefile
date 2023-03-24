build:
	gcc -o ./bin/main ./src/main.c

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
