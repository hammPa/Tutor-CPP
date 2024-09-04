#include <iostream>
#include <string>
#include <memory>

class Car {
private:
    std::string name;
    std::string chasisNumber;
    int maxSpeed;
public:
    Car(const char *name, const char  *chasisNumber, int maxSpeed){
        this->name = name;
        this->chasisNumber = chasisNumber;
        this->maxSpeed = maxSpeed;
    }

    friend std::ostream& operator<<(std::ostream& os, const Car& obj){
        os << "Data : " << obj.name << "\n";
        os << "Data : " << obj.chasisNumber << "\n";
        os << "Data : " << obj.maxSpeed << "\n";
        return os;
    }
};


int main(){
    
    Car car1 = Car("BMW", "BA-123-EA", 300);
    std::cout << car1 << std::endl;

    return 0;
}
