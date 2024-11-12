# Tutor-CPP

1. Function Pointer
Function pointer adalah variabel yang berfungsi menyimpan fungsi yang sebelumnya sudah di buat, lebih tepatnya menyimpan alamat dari sebuah fungsi yang sudah exist. Atau jika teman teman sebeumnya pernah menggunakan bahasa yang dynamically typed language, maka teman teman mungkin familiar dengan konsep function expression pada javascript. Misal kita punya fungsi :

void display(){
    cout << "Hello World" << endl;
}

void tampilkanHalo(){
    cout << "Hello HOF" << endl;
}

void HigherOrderFunction(void(*func)()){
    func();
}
Misal kita tampilkan dengan cout dama fungsinya, maka akan menampilkan alamat, sama seperti bila kita menampilkan dengan menggunakan ampersand (&). 
Lebih jelasnya : 
  
![image](https://github.com/user-attachments/assets/028d430a-4728-43cb-9dbc-e342123624a2)
Ini akan menampilkan 1 karena belumdi casting, jjika ingin melihat alamatnya maka harus di cating sesuai tipe datanya, di kasus ini casting dengan tipe void *, maka akan menghasilkan :
  
![image](https://github.com/user-attachments/assets/f994371e-6a1d-4442-b0e5-6b7adcb8472f)

Lalu jika kita ingin memasukkan fungsinya ke variabel, maka kita harus menggunakan tipe data yang sesuai dengan tipe data fungsi pada rvalue. Pada kasus kita, terdapat fungsi void yang tidak memiliki parameter, maka pada deklarasi variabel juga tidak ada parameter, contoh implementasinya :

void(*varDisplay)() = display;
Disini, kita menggunakan * karena display pada rvalue adalah sebuah alamat memori, dan menggunakan tipe void karena tipe dari rvalue juga adalah void.
Maka kita bisa memanggialnya seperti fungsi biasa :

varDisplay();

Kita bisa juga diubah menjadi tipe data dengan typedef :

typedef void(*tipedata)();
tipedata fungsi = display;
fungsi();

Jadi di sini, nama variabel yang di berikan typedef sekarang adalah tipe dari variabel yang akan menyimpan function, atau simpelnya, anggap saja seperti tipe data custom. Nah, fungsi pointer seperti ini juga bisa di terapkan ke fungsi lain, kalau di js misalnya higher order function, contoh : 

HigherOrderFunction(tampilkanHalo);

Atau bisa langsung di isi apa yang mau ditampilkan ke dalam argumen tanpa perlu fungsi diluar main, caranya dengan menggunakna lambda function ( ini hanya bisa di lakukan di c++ dan tidak  berlaku di c) :
  
HigherOrderFunction([](){ cout << "Hello HOF dengan lambda function" << endl; });

___
