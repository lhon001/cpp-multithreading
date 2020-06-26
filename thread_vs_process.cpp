/**
 * program to identify threads vs processes
 * shows that a process with multiple threads will have the same process id
 * with different thread ids
 */
#include <thread>
#include <chrono>
#include <unistd.h>
#include <iostream>

void cpu_waster() {
    std::cout << "cpu_waster() Process ID:" << getpid() << std::endl;
    std::cout << "cpu_waster() Thread ID:" << std::this_thread::get_id() << std::endl;

    // cpu_waster() infinite while loop to keep cpu_waster() thread alive
    while(true) { continue; }
}

int main() {
    std::cout << "main() Process ID:" << getpid() << std::endl;
    std::cout << "main() Thread ID:" << std::this_thread::get_id() << std::endl;

    std::thread thread1(cpu_waster);
    std::thread thread2(cpu_waster);

    // main() infinite while loop to keep main() thread alive
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }  
    
    return 0;
}