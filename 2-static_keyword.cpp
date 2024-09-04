#include <iostream>
using namespace std;

// dalam fungsi
void exampleFunction() {
    static int count = 0;
    count++;
    std::cout << "Count: " << count << std::endl;
}

// luar fungsi
static int globalVariable = 42; // hanya dapat diakses di file main.cpp

// fungsi static
static void localStaticFunction() { // hanya dapat diakses di file main.cpp
    // ...
}


// method dalam class 
class MyClass {
public:
    static void staticMethod() {
        // Jika suatu metode di dalam kelas dideklaras sebagai static, 
        // itu berarti metode tersebut terkait dengan kelas itu sendiri, bukan dengan instance objek kelas.
        cout << "Oi" << endl;
    }
};



// variabel dalam class
class MyClass2 {
public:
    static int sharedVariable;
    // Semua objek MyClass akan menggunakan salinan bersama dari sharedVariable.
};

int MyClass2::sharedVariable = 0;



int main(){
    
    exampleFunction();
    exampleFunction();
    exampleFunction();

    MyClass::staticMethod();

    MyClass2 child1, child2;
    cout << child1.sharedVariable << endl;

    child1.sharedVariable = 100;

    cout << child2.sharedVariable << endl;

    return 0;
}
