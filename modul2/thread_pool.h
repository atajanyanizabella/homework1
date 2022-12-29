#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <queue>
#include <pthread.h>
#include "pool_function_t.h"

class parallel_scheduler{
private:
	std::queue<pool_function_t>* queue;
	std::size_t capacity;
	pthread_mutex_t* lock;
	pthread_cond_t* is_not_empty;
	pthread_t* threads;

	static void* thread_function(void* argument);

public:
	parallel_scheduler(std::size_t capacity);
	void initialize();
	void run(pool_function_t pool_function);
	~parallel_scheduler();
};

#endif

