#include <iostream>
#include <thread>
#include <semaphore.h>
using namespace std;

sem_t s;

void init () {
	cout << "starting here" << endl;
	sem_post(&s);
}

void printNumbers () {
	int i = 0;
	while (i < 5) {
		sem_wait(&s);
		cout << i << endl;
		i++;
		sem_post(&s);
	}
}

int main () {
	sem_init(&s, 0, 0);
	std::thread th1(init);
	std::thread th2(printNumbers);
	th1.join(); th2.join();
	sem_destroy(&s);
	return 0;
}