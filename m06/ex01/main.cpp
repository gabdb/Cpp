
#include "Serializer.hpp"

int main()
{
    Data original;
    original.nb = 42;
    original.info = "Hello serialization!";

    std::cout << "Original Data address: " << &original << std::endl;

    // Serialize the pointer
    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "Serialized value (raw uintptr_t): " << raw << std::endl;

    // Deserialize it back
    Data* deserialized = Serializer::deserialize(raw);

    std::cout << "Deserialized Data address: " << deserialized << std::endl;
    std::cout << "Deserialized values -> nb: " << deserialized->nb << ", info: " << deserialized->info << std::endl;

    // Verify pointer equality
    if (deserialized == &original)
        std::cout << "Success" << std::endl;
    else
        std::cout << "Error" << std::endl;

    return 0;
}
