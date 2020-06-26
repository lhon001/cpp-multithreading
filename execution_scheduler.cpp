/**
 * This program shows the execution scheduler process
 * via two threads "chopping vegetables"
 */

#include <thread>
#include <chrono>
#include <iostream>
#include <string>

bool chopping = true;

void vegetable_chopper(const std::string name) {
    unsigned int vegetable_count = 0;
    while (chopping) {
        vegetable_count++;
    }
    std::cout << name << " chopped " << vegetable_count << " vegetables." << std::endl;
}

int main() {
    // create two threads to execute the vegetable_chopper function
    std::thread jack(vegetable_chopper, "Jack");
    std::thread olivia(vegetable_chopper, "Olivia");

    std::cout << "Jack and Olivia are chopping vegetables..." << std::endl;
    // after the thread are created, we pause main (the main execution thread for 1 sec)
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // setting chopping to false will stop while loop in both threads.
    chopping = false;
    jack.join();
    olivia.join();
    return 0;
}