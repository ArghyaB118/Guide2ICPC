#include <iostream>
#include "pthread.h"
#include <unistd.h> // for usleep
#include <algorithm> // for partial_sort
using namespace std;

#define max_thread 4

void* func (void* input) {
	cout << "this is a thread" << endl;
	pthread_exit(NULL); 
}

void* func2 (void* input) {
	int* thread_id = (int*) input;
	cout << "this is thread with id: " << *thread_id << endl;
	pthread_exit(NULL); 
}

void* func2a (void* input) {
	int* thread_id = (int*) input;
	usleep(*thread_id);
	cout << "this is thread with id: " << *thread_id << endl;
	pthread_exit(NULL); 
}

struct thread_data {
	int thread_id;
	vector<int> v;
	int thread_start; 
	int thread_end;

	thread_data(vector<int> &v_) {
		v = v_;
	}
};

void* func3 (void* input) {
	struct thread_data* args = (struct thread_data*) input;
	cout << args->thread_id << " " 
		<< args->thread_start << " "
		<< args->thread_end << endl;
	std::sort(args->v.begin() + args->thread_start, args->v.begin() + args->thread_end);
	pthread_exit(NULL);
}

struct thread_data2 {
	int thread_id;
	int thread_start; 
	int thread_end;
};

vector<int> v2 = {1, 15, 12, 27, 2, 8, 17, 11};
void* func4 (void* input) {
	struct thread_data2* args = (struct thread_data2*) input;
	cout << args->thread_id << " " 
		<< args->thread_start << " "
		<< args->thread_end << endl;
	std::sort(v2.begin() + args->thread_start, v2.begin() + args->thread_end);
	pthread_exit(NULL);
}

int main () {
	pthread_t thread[max_thread];
	for (int i = 0; i < max_thread; i++)
		pthread_create(&thread[i], NULL, &func, NULL);
	for (int i = 0; i < max_thread; i++)
		pthread_join(thread[i], NULL);
	
	vector<int> thread_id(max_thread, 0);
	for (int i = 0; i < max_thread; i++) {
		thread_id[i] = i + 1;
		pthread_create(&thread[i], NULL, &func2, &thread_id[i]);
	}
	for (int i = 0; i < max_thread; i++)
		pthread_join(thread[i], NULL);
	/* 
	Dummy output:
	this is thread with id: 1
	this is thread with id: 3
	this is thread with id: 2
	this is thread with id: 4
	*/

	for (int i = 0; i < max_thread; i++)
		pthread_create(&thread[i], NULL, &func2a, (void*) &thread_id[i]);
	for (int i = 0; i < max_thread; i++)
		pthread_join(thread[i], NULL);
	/* 
	Dummy output:
	this is thread with id: 1
	this is thread with id: 2
	this is thread with id: 3
	this is thread with id: 4
	*/

	/* A note to self:
	I can create specific constructors
	but as I am not returning the vector after partially sorting
	the progress is lost. So, need to access a global vector.*/

	vector<int> v = {1, 15, 12, 27, 2, 8, 17, 11};
	
	struct thread_data t(v);
	t.thread_id = 1;
	t.thread_start = 0;
	t.thread_end = 3;
	
	// for (int &i : v)
	//	t.v.push_back(i);
	struct thread_data u = t;
	u.thread_id++;
	u.thread_start = u.thread_end + 1;
	u.thread_end = 7;
	vector<thread_data> td = {t, u};
	for (int i = 0; i < max_thread / 2; i++)
		pthread_create(&thread[i], NULL, &func3, (void*) &td[i]);
	for (int i = 0; i < max_thread / 2; i++)
		pthread_join(thread[i], NULL);
	
	for (int &i : t.v)
		cout << i << " ";
	cout << endl;

	for (int &i : u.v)
		cout << i << " ";
	cout << endl;

	struct thread_data2 t2;
	t2.thread_id = 1;
	t2.thread_start = 0;
	t2.thread_end = 4;
	
	struct thread_data2 u2 = t2;
	u2.thread_id++;
	u2.thread_start = u2.thread_end;
	u2.thread_end = 8;
	vector<thread_data2> td2 = {t2, u2};
	for (int i = 0; i < max_thread / 2; i++)
		pthread_create(&thread[i], NULL, &func4, (void*) &td2[i]);
	for (int i = 0; i < max_thread / 2; i++)
		pthread_join(thread[i], NULL);
	
	for (int &i : v2)
		cout << i << " ";
	cout << endl;

	std::inplace_merge(v2.begin(), v2.begin() + 4, v2.end());
	for (int &i : v2)
		cout << i << " ";
	cout << endl;
	return 0;
}