all:
	gcc src/sfile.c -o bin/sfile
	gcc src/sdir.c -o bin/sdir

clean:
	rm -r bin
	mkdir bin
