files=../error_functions.o ../get_num.o

tSysconf: t_sysconf.o $(files)
	gcc -o $@ $^

tFpathconf: t_fpathconf.o $(files)
	gcc -o $@ $^

t_sysconf.o: t_sysconf.c
	gcc -c $^

t_fpathconf.o: t_fpathconf.c
	gcc -c $^
