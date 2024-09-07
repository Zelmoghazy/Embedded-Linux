#include <iostream>
#include <mutex>
#include <ostream>
#include <thread>

// shared variable
int count = 0;

// Mutex
std::mutex mut;

void update_counter()
{
    for (int i = 0; i < 100000; i++) {
        count++;
    }
}

void update_counter_mutex()
{
    for (int i = 0; i < 100000; i++) {
        mut.lock();
        count++;
        mut.unlock();
    }
}

int main(void)
{
    std::thread t1(update_counter);
    std::thread t2(update_counter);

    t1.join();
    t2.join();

    std::cout << "count: " << count << std::endl;

    count = 0;

    std::thread t3(update_counter_mutex);
    std::thread t4(update_counter_mutex);

    t3.join();
    t4.join();

    std::cout << "count: " << count << std::endl;

    return 0;
}