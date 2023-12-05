#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <iostream>
#include <string>

using namespace boost::interprocess; // For notational convenience.

int main()
{
    // Remove shared memory on construction and destruction.
    struct shm_remove
    {
        shm_remove()
        {
            shared_memory_object::remove("MySharedMemory");
        }
        ~shm_remove()
        {
            shared_memory_object::remove("MySharedMemory");
        }
    } remover;

    // Create a shared memory object.
    shared_memory_object shm(create_only, "MySharedMemory", read_write);

    // Set the size of the shared memory object. We only need to hold an int.
    shm.truncate(sizeof(int));

    // Map the whole shared memory in this process.
    mapped_region region(shm, read_write);

    // Get the address of the mapped region.
    void* addr = region.get_address();

    // Construct the shared structure in memory.
    int* shared_data = new (addr) int;

    // Write data to the shared memory.
    *shared_data = 123;

    std::cout << "Data written to shared memory: " << *shared_data << std::endl;

    // Wait for specific user input before exiting.
    std::string input;
    std::cout << "Enter 'exit' to finish: ";
    while (input != "exit")
    {
        std::getline(std::cin, input);
    }

    return 0;
}