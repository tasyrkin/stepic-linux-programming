
all: exe lib

exe: main.c lib
	gcc main.c -fPIC -ldl -o hello

lib: hello.c
	gcc hello.c -shared -fPIC -o libHello.so

clean:
#- before rm tells make to ignore the operation
	-rm -f hello libHello.so *.o
