#include <iostream>
using namespace std;

class Box {
	int* ptr;
    int size;
	
public:
	Box(int size) {
        this->size = size;
		ptr = new int[size];
	}
	
	Box(const Box& box) {	// Copy Constructor
		ptr = new int(*box.ptr);
	}
	
	~Box() {	// Destructor
		delete ptr;
        ptr = nullptr;
	}
	
	Box& operator=(const Box& otherBox) {
		if(this == &otherBox)
			return *this;
		
		delete ptr;
		ptr = new int(*otherBox.ptr);
		
		return *this;
	}

    int getSize() {
        return size;
    }

    void setSize(int size) {
        this->size = size;
    }

    int* getPointer() const {
        return ptr;
    }

    void setPointer(int* p) {
        ptr = p;
    }
};

int main() {
    
    // Showcasing Deep Copy
    Box box1(3);
    cout << "Box1 size: " << box1.getSize() << endl;

    Box box2 = box1;
    cout << "Box2 size: " << box2.getSize() << endl;

    box2.setSize(5);

    cout << "Now Box1 size: " << box1.getSize() << endl;

    // Showcasing Shallow Copy
    Box box3(30);
    Box box4(13);
    box4.setPointer(box3.getPointer());

    box4.setSize(50);  // It will change value in box3 too

    std::cout << "box3 value: " << box3.getSize() << endl;
    std::cout << "box4 value: " << box4.getSize() << endl;
    
    return 0;
}
