#include "Serialize.hpp"
#include <iostream>

int main() {
    // 1. Create Data object
    Data* original = new Data;
    original->id = 42;
    original->tag = "test";
    
    std::cout << "Original address: " << original << std::endl;
    std::cout << "Original values: id=" << original->id 
              << ", tag=" << original->tag << std::endl;
    
    // 2. Serialize
    uintptr_t raw = Serializer::serialize(original);
    std::cout << "Serialized value: " << raw << std::endl;
    
    // 3. Deserialize
    Data* restored = Serializer::deserialize(raw);
    std::cout << "Restored address: " << restored << std::endl;
    std::cout << "Restored values: id=" << restored->id 
              << ", tag=" << restored->tag << std::endl;
    
    // 4. Verify
    if (original == restored) {
        std::cout << "✓ SUCCESS: Pointers match!" << std::endl;
    } else {
        std::cout << "✗ FAIL: Pointers don't match!" << std::endl;
    }
    
    // 5. Cleanup
    delete original;
    
    return 0;
}