#include <iostream>
#include <vector>

#include "Item.h"
#include "Currency.h"

using namespace std;

template<typename Type>
class smart_ptr
{
   Type* ptr;
public:
   smart_ptr(Type* arg_ptr = NULL) : ptr(arg_ptr)
   {}
 
   ~smart_ptr()
   {
     // if(ptr) // Deleting a null-pointer is safe
     delete ptr;
   }

   Type& operator*() 
    {
       return *ptr;
    }

    const Type& operator*() const
    {
       return *ptr;
    }
};

// Assume it implemented ABOVE main
void show_ptr(const smart_ptr<int>& intptr)
{
   cout << "Value is now:" << *intptr; // Const
}

int main()
{
   smart_ptr<int> intptr(new int);
   *intptr = 10; // Non-const
 
   show_ptr(intptr);
}
