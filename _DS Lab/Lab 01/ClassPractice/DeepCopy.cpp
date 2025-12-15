/**
 * Destructor is still necessary for if you only want to use shallow copy in your program
 * For DeepCopy both Destructor & CopyConstructor/AssignmentMethod are needed
 */

#include <iostream>
using namespace std;

class Box {
public:
    int* size;

    Box(int size) {
        this->size = new int(size);
    }

    Box(const Box& st) {
        /**
         * These two forms are completely equivalent:
         *  const Box& param;  // Style 1: const before type
         *  Box const& param;  // Style 2: const after type
         * Both mean exactly the same thing: "a reference to a Box object that cannot be modified."
         * This equivalence stems from C++'s type declaration grammar, where const modifies the type to its left (unless there's nothing to the left, then it modifies the type to its right).
         * This becomes more interesting with pointers:
         *  const int* p;      // Pointer to a constant integer
         *  int const* p;      // Same as above (pointer to a constant integer)
         *  int* const p;      // Constant pointer to an integer (different meaning!)
         */
        
        /**
         * The ampersand (&) creates a reference parameter rather than a value parameter.
         * This is critical for two key reasons:
         *  Efficiency: Without the &, C++ would make a complete copy of the object to pass it to the constructor, which would be inefficient, especially for large objects.
         *  Avoiding Infinite Recursion: Without the reference, calling the copy constructor would require making a copy of the parameter, which would call the copy constructor again, creating an infinite loop.
         */

        size = new int(*st.size);   // Create a new memory block & copy data there (Deep Copy)
    }

    // Destructor
    ~Box() {
        cout << "\n Destructing Box of size " << *size << " ......\n";
        delete size;
    }
};

int main() {
    
    Box box1(10);
    Box box2 = box1;    // Shallow copy (box1 & box2 pointing to same memory location)
    
    Box box3(20);
    Box box4 = box3;    // Deep copy
    
    return 0;
}
