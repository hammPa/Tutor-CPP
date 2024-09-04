#include <iostream>
#include <string>


// virtual di gunakan sebagai tanda bahwa class turunan harus mendefinisikan methodnya sendiri, terbagi 2 yaitu

// virtual function
class virtualClass {
protected: // protected agar bisa di akses class turunan
    std::string nama;
public:
    virtualClass(std::string nama) : nama(nama) {}
    virtual void showNama(){
        std::cout << this->nama << " dari parent" << std::endl;
    }
};

class derivedVirtualClass: public virtualClass {
public:
    // harus memanggil constructor class parent, jadi input dari class child di kirimm ke parent
    derivedVirtualClass(std::string nama): virtualClass(nama){}
    void showNama() override {
        std::cout << nama << " dari child" << std::endl;
    }
};

// pure virtual function
class pureVirtualClass {
protected:
    std::string nama;
public:
    pureVirtualClass(std::string nama) : nama(nama) {}
    virtual void showNama() = 0;
};

class derivedPureVirtualClass: public pureVirtualClass {
public:
    derivedPureVirtualClass(std::string nama) : pureVirtualClass(nama) {}
    void showNama() override {
        std::cout << nama << " dari child" << std::endl;
    }
};


int main(){

    // virtual
    virtualClass vclass = virtualClass("vclass");
    vclass.showNama();

    derivedVirtualClass dvclass = derivedVirtualClass("dvclass");
    dvclass.showNama();




    // pure virtual
    // pureVirtualClass pvclass; tidak bisa tampil karna methodnya baru ada di turunannya
    derivedPureVirtualClass dpvclass("dpvclass");
    dpvclass.showNama();

    return 0;
}
