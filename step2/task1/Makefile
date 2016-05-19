
all: lib

test: test.c lib
	gcc test.c -fPIC -lsolution -L. -o test

lib: solution.c
	gcc solution.c -shared -fPIC -o libsolution.so

clean:
#- before rm tells make to ignore the operation
	-rm -f test libsolution.so *.o
