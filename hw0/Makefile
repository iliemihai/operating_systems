all: hello_world 

hello_world: hello_world.c
	gcc hello_world.c -Wall -Wextra -pedantic -o hello_world

arguments: arguments.c
	gcc arguments.c -Wall -Wextra -pedantic -o arguments

main: main.c
	gcc main.c -Wall -Wextra -pedantic -o main

wc: wc.c
	gcc wc.c -Wall -Wextra -pedantic -o wc

map: map.c
	gcc map.c -Wall -Wextra -pedantic -o map

clean:
	rm -f hello_world arguments main wc map
