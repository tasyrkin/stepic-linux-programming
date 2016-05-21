
all: exe

test_lib: test_lib.c
	gcc test_lib.c -shared -fPIC -o test_lib

exe: solution.c
	gcc solution.c -ldl -o solution

clean:
#- before rm tells make to ignore the operation
	-rm -f test libsolution.so *.o
