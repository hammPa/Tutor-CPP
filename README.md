# Tutor-CPP

# 1. Function Pointer
Function pointer adalah variabel yang berfungsi menyimpan fungsi yang sebelumnya sudah di buat, lebih tepatnya menyimpan alamat dari sebuah fungsi yang sudah exist. Atau jika teman teman sebelumnya pernah menggunakan bahasa yang dynamically typed language, maka teman teman mungkin familiar dengan konsep function expression pada javascript. Misal kita punya fungsi :

```cpp
void display(){
    cout << "Hello World" << endl;
}

void tampilkanHalo(){
    cout << "Hello HOF" << endl;
}

void HigherOrderFunction(void(*func)()){
    func();
}
```
Misal kita tampilkan dengan cout nama fungsinya, maka akan menampilkan alamat, sama seperti bila kita menampilkan dengan menggunakan ampersand (&). 
Lebih jelasnya : 
  
![image](https://github.com/user-attachments/assets/028d430a-4728-43cb-9dbc-e342123624a2)

Ini akan menampilkan 1 karena belum di casting, jika ingin melihat alamatnya maka harus di cating sesuai tipe datanya, di kasus ini casting dengan tipe void *, maka akan menghasilkan :
  
![image](https://github.com/user-attachments/assets/f994371e-6a1d-4442-b0e5-6b7adcb8472f)

Lalu jika kita ingin memasukkan fungsinya ke variabel, maka kita harus menggunakan tipe data yang sesuai dengan tipe data fungsi pada rvalue. Pada kasus kita, terdapat fungsi void yang tidak memiliki parameter, maka pada deklarasi variabel juga tidak ada parameter, contoh implementasinya :

```cpp
void(*varDisplay)() = display;
```
Disini, kita menggunakan * karena display pada rvalue adalah sebuah alamat memori, dan menggunakan tipe void karena tipe dari rvalue juga adalah void.
Maka kita bisa memanggialnya seperti fungsi biasa :

```cpp
varDisplay();
```

Kita bisa juga diubah menjadi tipe data dengan typedef :

```cpp
typedef void(*tipedata)();
tipedata fungsi = display;
fungsi();
```

Jadi di sini, nama variabel yang di berikan typedef sekarang adalah tipe dari variabel yang akan menyimpan function, atau simpelnya, anggap saja seperti tipe data custom. Nah, fungsi pointer seperti ini juga bisa di terapkan ke fungsi lain, kalau di js misalnya higher order function, contoh : 

```cpp
HigherOrderFunction(tampilkanHalo);
```

Atau bisa langsung di isi apa yang mau ditampilkan ke dalam argumen tanpa perlu fungsi diluar main, caranya dengan menggunakna lambda function ( ini hanya bisa di lakukan di c++ dan tidak  berlaku di c) :

```cpp
HigherOrderFunction([](){ cout << "Hello HOF dengan lambda function" << endl; });
```

Kita juga bisa mengubah function yang di tunjuk oleh sebuah variabel dengan callback pada parameter function pengubah, ribet ? YOII. Contoh :
```cpp
void displayHalo(){ std::cout << "tampilkan halo\n"; }
void displayAhihihi(){ std::cout << "tampilkan ahihihi\n"; }

void changeFunc(void (**callback)(), void (*newFunc)(){
    *callback = newFunc;
}

int main(){

    void (*myfunc)() = displayHalo;
    myfunc();

    changeFunc(&myfunc, displayAhihihi);

    myfunc();

    return 0;
}
```

Hasilnya :

![image](https://github.com/user-attachments/assets/9d8ac2dc-70e2-40e0-bc60-e05501107a67)


Lanjut..... 
Bang bang kalau di KING C++ gmn bg 🗣️🗣️ ?
Makin Gampang Cuy, pakai reference (&) aja, gni loh :

```cpp
void changeFuncCpp(void (*&callback)(), void (*newFunc)()) {
    callback = newFunc;
}

int main() {
    void (*callback)() = displayHalo;
    callback();

    changeFuncCpp(callback, displayAhihihi);

    callback();

    return 0;
}
```

Dan hasilnya tetap bakalan sama kayak yang di atas tadi :D

# 2. 

# 3. Overloading Operator
Overloading operator adalah konsep menambahkan fungsi pada operator default yang telah ada di cpp sebelumnya, ribet ? Iya sih ehek.
Syntax begini :
```cpp
friend/* optional */ tipe_data operator operator_yang_akan_dipakai(tipe_data parameter){
} 
```
Tapi kita singkat saja, misal kita punya array (tidak usah hiraukan tipe datanya dulu, ini pakai style STL bawaan cpp) : 
```cpp
array<int, 3> arr = {1, 2, 3};
```

Nah, untuk menampilkan ini harus pakai looping kan, jadi setiap ingin menamppilkan data harus di looping, atau bisa juga menggunakan function saja, jadi setiap ingin melihat data dalam array, maka tinggal panggil nama fungsi, tapi ada cara lain yaitu dengan overloading operator dan friend function, berikut caranya :
```cpp
kita include dulu headernya, yaitu ostream, maka :

#include <ostream>

// lalu kita buat sebuah friend function
friend std::ostream& operator<<(std::ostream& os, array& arr){
    std::cout << "[ ";
    for(size_t i = 0; i < arr.size(); i++){
        os << arr[i];
    }
    std::cout << "]";
    return os;
}

// memanggil operator overload << :
std::cout << arr << "\n";
```

Maka di sini akan menampilkan semua element array. Contoh operator lain :
```cpp
class array {
private:
    int data[3];
public:
    int operator[](size_t index) { return data[index]; }    
};

// misal kita punya array ukuran 3 tipe data int, maka
array arr = {1, 2, 3}; // abaikan dulu bagaimana caranya nilai  ini bisa masuk, yang penting kita bahas overloadingnya

// awalnya untuk mengakseskita harus menulis ini :
std::cout << arr.data[0] << "\n";
// maka saat kita tulis syntax ini akan bisa tidak akan error:
std::cout << arr[0] << "\n";
std::cout << arr[1] << "\n";
std::cout << arr[2] << "\n";
```
Hasilnya akan menampilkan semua element array hanya dengan cout pada bagian nama variabelnya.
