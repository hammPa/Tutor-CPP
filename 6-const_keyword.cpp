#include <iostream>

int main(){

    // variabel konstan : nilai tidak bisa di ubah
    const float pi = 3.14f;

    // pointer ke data konstan : nilai tidak bisa di ubah melalui pointer tapi bisa melalui variabel aslo
    int value = 5;
    const int *ptrVal = &value;

    // pointer konstan : alamat tidak bisa di ganti
    int value2 = 10;
    int *const ptrval2 = &value2;

    // reference konstan :
    int value3 = 30;
    const int &refValue = value3;

    // metode anggota konstan : metode ini tidak akan mengubah anggota data non-static dari objek class
    class contoh {
    private:
        int data;
    public:
        int getData() const { return data; }
    };


    // parameter konstan : Ini berarti nilai value yang dilewatkan ke fungsi tidak akan diubah di dalam fungsi tersebut. 
    void print(const int value);

    return 0;
}
