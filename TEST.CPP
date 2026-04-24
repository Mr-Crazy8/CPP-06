// C++ Program to demonstrate 
// static_cast in inheritance
#include <iostream>
using namespace std;
class Base 
{
  public:
    void f_b()
    {
      std::cout << "Base" ;
    };
};

class Derived : public Base 
{
    int x;  // Derived-specific member
public:
    void f()
    {
        std::cout << "Derived: " << x;  // ACCESSES this->x
    }
};


// Driver code
int main()
{
  Base d1;
  
  // Implicit cast allowed
 // Derived* b1 = (Derived*)(&d1);
  
  Derived* b2 = static_cast<Derived*>(&d1);

  b2->f_b();
  b2->f();
  return 0;
}