#include "thread_pool.h"
#include <iostream>

parallel_scheduler::parallel_scheduler(std::size_t capacity) : capacity(capacity) {
	this->queue = new std::queue<pool_function_t>;
	this->lock = new pthread_mutex_t;
	pthread_mutex_init(this->lock, NULL);
	this->is_not_empty = new pthread_cond_t;
	pthread_cond_init(this->is_not_empty, NULL);
	this->threads = new pthread_t[capacity];
}

void* parallel_scheduler::thread_function(void* argument){
	parallel_scheduler* pool = (parallel_scheduler*) argument;

	while(true){
		pthread_mutex_lock(pool->lock);
		while(pool->queue->size() == 0){
			pthread_cond_wait(pool->is_not_empty, pool->lock);
		}

		pool_function_t next_function = pool->queue->front();
		pool->queue->pop();
		std::cout << "Executing function" << std::endl;
		pthread_mutex_unlock(pool->lock);
	}
	delete pool;
	return NULL;
}

void parallel_scheduler::initialize(){
	for(int i = 0; i < this->capacity; ++i){
		int result = pthread_create(&(this->threads[i]), NULL, thread_function, this);
		if(result < 0)
			exit(result);
	}
}

void parallel_scheduler::run(pool_function_t pool_function){
	pthread_mutex_lock(this->lock);
	this->queue->push(pool_function);
	std::cout << "Adding function to queue" << std::endl;
	pthread_mutex_unlock(this->lock);

	pthread_cond_signal(this->is_not_empty);
}

parallel_scheduler::~parallel_scheduler(){
	delete this->queue;
	pthread_mutex_destroy(this->lock);
	delete this->lock;
	pthread_cond_destroy(this->is_not_empty);
	delete is_not_empty;
	delete [] threads;
}

