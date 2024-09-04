#include <iostream>
using namespace std;

// misal kita punya fungsi ini
void display(){
    cout << "Hello World" << endl;
}

void tampilkanHalo(){
    cout << "Hello HOF" << endl;
}

void HigherOrderFunction(void(*func)()){
    func();
}

int main(){
    
    // jika kita cout nama fungsi, maka akan menampilkan pointer dari fungsinya : 
    cout << "display : " << display << endl;
    cout << "&display : " << &display << endl;

    // lalu kita ingin memasukkan fungsi nya ke variabel, maka bisa begini :
    auto varDisplayAuto = display;

    // maka jika kita panggil varDisplayAuto() sama artinya dengan display()
    varDisplayAuto();

    // jika kita lihat auto dengan mengarahkan cursor, akan di lihatkan tipe data dari auto nya :
    // void(*varDisplayAuto)()

    // maka bisa juga di buat :
    void(*varDisplay)() = display;
    varDisplay();

    // bisa juga diubah menjadi tipe data dengan typedef :
    typedef void(*tipedata)();
    tipedata fungsi = display;
    fungsi();


    cout << endl << endl << endl;
    // nah, fungsi pointer seperti ini juga bisa di terapkan ke fungsi lain
    // kalau di js, higher order function
    // contoh : 

    HigherOrderFunction(tampilkanHalo);

    // atau bisa langsung di isi apa yang mau ditampilkan ke dalam argumen tanpa perlu fungsi diluar main
    // caranya dengan menggunakna lambda function :
    HigherOrderFunction([](){ cout << "Hello HOF dengan lambda function" << endl; });

    return 0;
}
