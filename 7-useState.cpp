#include <iostream>
#include <memory>
#include <tuple>
#include <functional>
#include <ostream>

template <typename Type>
class Data {
private:
    Type data;
public:
    void setData(Type data){
        this->data = data;
    }

    Type getData() const {
        return this->data;
    }

    friend std::ostream& operator<<(std::ostream& os, const Data<Type>& temp){
        os << temp.getData();
        return os;
    }
};

template <typename Type>
std::tuple<Data<Type>&, std::function<void(Type)>> useState(Type data){
    static Data<Type> val;
    val.setData(data);

    std::function<void(Type)> setVal = [&val](Type newData){
        val.setData(newData);
    };

    return std::make_tuple(std::ref(val), setVal);
}

int main(){

    auto [angka, setAngka] = useState(0);
    std::cout << angka << "\n";

    setAngka(30);

    std::cout << angka << "\n";

    return 0;
}
