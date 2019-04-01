CC=gcc
BINARIES=main wc map

main: main.c
	${CC} -g -o main main.c

wc: wc.c
	${CC} -g -o wc wc.c

map: map.c
	${CC} -g -o map map.c

clean:
	rm -f ${BINARIES} *.o
	echo "clean complete"
