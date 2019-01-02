displayEnv: display_env.o ../error_functions.o ../get_num.o
	gcc -o $@ $^

modifyEnv: modify_env.o ../error_functions.o ../get_num.o
	gcc -o $@ $^

display_env.o: display_env.c
	gcc -c $^

modify_env.o: modify_env.c
	gcc -c $^
