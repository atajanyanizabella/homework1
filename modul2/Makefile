all:	main

main:	main.o thread_pool.o
	g++ main.o thread_pool.o -o main

main.o:	main.cpp thread_pool.h
	g++ -c main.cpp -o main.o

thread_pool.o:	thread_pool.cpp pool_function_t.h
	g++ -c thread_pool.cpp -o thread_pool.o

clean:
	rm *.o main
