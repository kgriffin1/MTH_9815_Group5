#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <iostream>

using namespace boost::interprocess; // For notational convenience.

int main()
{
    // Open the shared memory object.
    shared_memory_object shm(open_only, "MySharedMemory", read_only);

    // Map the whole shared memory in this process.
    mapped_region region(shm, read_only);

    // Get the address of the mapped region.
    const void* addr = region.get_address();

    // Obtain the shared data.
    const int* shared_data = static_cast<const int*>(addr);

    // Print the data from the shared memory.
    std::cout << "Data read from shared memory: " << *shared_data << std::endl;

    return 0;
}