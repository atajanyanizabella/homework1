#include "thread_pool.h"
#include <iostream>
#include <pthread.h>
#include <unistd.h>

void* print(void* argument){
	int* number = (int*) argument;
	std::cout << "printing " << *number << std::endl;
	//delete number;
	return NULL;
}

int main(){
	parallel_scheduler pool(10);
	pool.initialize();
	for(int i = 0; i < 1000; ++i){
		int* number = new int{i};
		pool.run(pool_function_t(print, number));
	}

	sleep(100);
	return 0;
}
