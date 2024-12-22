all:
	gcc src/sfile.c -o bin/sfile
	gcc src/sdir.c -o bin/sdir
	gcc src/slist.c -o bin/slist

clean:
	rm -r bin
	mkdir bin
