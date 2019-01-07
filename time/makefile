files=../error_functions.o ../get_num.o

calendar: calendar_time.o $(files)
	gcc -o $@ $^

showTime: show_time.o $(files)
	gcc -o $@ $^

calendar_time.o: calendar_time.c
	gcc -c $^

show_time.o: show_time.c
	gcc -c show_time.c
