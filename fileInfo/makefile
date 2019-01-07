files=../error_functions.o ../get_num.o

tStat: t_stat.o $(files)
	gcc -o $@ $^

tUmask: t_umask.c file_perms.c $(files)
	gcc -o $@ $^

t_stat.o: t_stat.c
	gcc -c $^
