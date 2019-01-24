files=../error_functions.o ../get_num.o

displayEnv: display_env.o $(files)
	gcc -o $@ $^

modifyEnv: modify_env.o $(files)
	gcc -o $@ $^

t_fork: t_fork.o $(files)
	gcc -o $@ $^

forkFileShare: fork_file_sharing.o $(files)
	gcc -o $@ $^

t_execve: t_execve.o $(files)
	gcc -o $@ $^

envargs: envargs.o $(files)
	gcc -o $@ $^

display_env.o: display_env.c
	gcc -c $^

modify_env.o: modify_env.c
	gcc -c $^

t_fork.o: t_fork.c
	gcc -c $^

fork_file_sharing.o: fork_file_sharing.c
	gcc -c $^

t_execve.o: t_execve.c
	gcc -c $^

envargs.o: envargs.c
	gcc -c $^
