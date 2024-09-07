#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

// Shared resource
int sharedCounter = 0;

// Mutex for protecting sharedCounter
std::mutex mtx;

// Function using basic mutex locking
void incrementWithMutex() {
    for (int i = 0; i < 100; ++i) {
        mtx.lock();  // Lock the mutex
        ++sharedCounter;
        mtx.unlock();  // Unlock the mutex
    }
}

// Function using lock_guard
void incrementWithLockGuard() {
    for (int i = 0; i < 100; ++i) {
        std::lock_guard<std::mutex> lock(mtx);  // Mutex is locked when lock_guard is created
        ++sharedCounter;
        // Mutex is automatically unlocked when lock_guard goes out of scope
    }
}

// Function using unique_lock
void incrementWithUniqueLock() {
    for (int i = 0; i < 100; ++i) {
        std::unique_lock<std::mutex> lock(mtx);  // Mutex is locked when unique_lock is created
        ++sharedCounter;
        // You can manually unlock the mutex if needed
        lock.unlock();
    }
}

int main(void) 
{
    // Create threads
    std::thread t1(incrementWithMutex);
    std::thread t2(incrementWithLockGuard);
    std::thread t3(incrementWithUniqueLock);

    // Join threads
    t1.join();
    t2.join();
    t3.join();

    std::cout << "Final value of sharedCounter: " << sharedCounter << std::endl;

    return 0;
}
