#include <iostream>
#include <algorithm>

class MyClass {
private:
    int* data;
    size_t size;

public:
    // Constructor
    MyClass(size_t size) : size(size), data(new int[size]) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = i;  // Initialize array with values 0, 1, 2, ...
        }
        std::cout << "Constructor called for object of size " << size << "\n";
    }

    // Destructor
    ~MyClass() {
        delete[] data;
        std::cout << "Destructor called for object of size " << size << "\n";
    }

    // Copy Constructor
    MyClass(const MyClass& other) : size(other.size), data(new int[other.size]) {
        std::copy(other.data, other.data + other.size, data);
        std::cout << "Copy constructor called for object of size " << size << "\n";
    }

    // Copy Assignment Operator
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {   // Avoid self-assignment
            delete[] data;       // Free existing resource
            size = other.size;
            data = new int[size];
            std::copy(other.data, other.data + other.size, data);
            std::cout << "Copy assignment operator called for object of size " << size << "\n";
        }
        return *this;
    }

    // Method to display the data
    void display() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }
};

// Main function to demonstrate the Rule of Three
int main() {
    // Create an object
    MyClass obj1(5);
    obj1.display();

    // Use copy constructor
    MyClass obj2 = obj1;  // This will invoke the copy constructor
    obj2.display();

    // Modify obj2 to show they are independent
    obj2 = MyClass(3);  // Assignment operator with a temporary object of size 3
    obj2.display();

    // Use copy assignment operator
    obj2 = obj1;  // Now obj2 is assigned obj1's values
    obj2.display();

    // End of main: destructors for obj1 and obj2 will be automatically called
    return 0;
}
