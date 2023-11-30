#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>
using namespace std;

volatile int counter = 0;
std::mutex mtx;

void *mutex_testing(int param)
{
        int i;
        for(i = 0; i < 5; i++) {
                std::unique_lock<std::mutex> lock(mtx);
                counter++;
                // std::cout << (int*)param << " " << counter << std::endl;
                printf("thread %d counter = %d\n", (int)param, counter);
        }
}

void *mutex_testing2(int param)
{
        int i;
        for(i = 0; i < 5; i++) {
                std::unique_lock<std::mutex> lock(mtx);
                counter++;
                usleep(1);
                printf("thread %d counter = %d\n", (int)param, counter);
        }
}

int main()
{
        int one = 1, two = 2, three = 3;
        std::thread thread1(mutex_testing, one);
        std::thread thread2(mutex_testing, two);
        std::thread thread3(mutex_testing, three);
        
        thread1.join();
        thread2.join();
        thread3.join();

        cout << endl; counter = 0;

        std::thread thread4(mutex_testing2, one);
        std::thread thread5(mutex_testing2, two);
        std::thread thread6(mutex_testing2, three);
        
        thread4.join();
        thread5.join();
        thread6.join();

        return 0;
}