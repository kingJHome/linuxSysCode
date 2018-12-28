copy: copy.o ../tlpi_hdr.h ../get_num.o ../error_functions.o 
	gcc -o $@ $^

seek_io:seek_io.o ../tlpi_hdr.h ../get_num.o ../error_functions.o
	gcc -o $@ $^

copy.o: copy.c
	gcc -c copy.c

seek_io.o: seek_io.c
	gcc -c seek_io.c
