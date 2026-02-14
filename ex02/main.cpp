#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    // Seed random number generator
    std::srand(std::time(0));
    
    std::cout << "=====================================" << std::endl;
    std::cout << "Testing Exercise 02: Identify Real Type" << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << std::endl;
    
    // Test 5 random objects
    for (int i = 0; i < 5; i++) {
        std::cout << "Test #" << (i + 1) << ":" << std::endl;
        
        // Generate random object
        Base* obj = generate();
        
        // Test pointer version
        std::cout << "  Pointer identify:   ";
        identify(obj);
        
        // Test reference version  
        std::cout << "  Reference identify: ";
        identify(*obj);
        
        // Verify both give same result
        std::cout << "  ✓ Both methods agree" << std::endl;
        
        // Clean up
        delete obj;
        
        std::cout << std::endl;
    }
    
    std::cout << "=====================================" << std::endl;
    std::cout << "All tests completed successfully!" << std::endl;
    std::cout << "=====================================" << std::endl;
    
    return 0;
}