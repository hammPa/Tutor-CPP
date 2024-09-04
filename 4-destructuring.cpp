#include <iostream>
#include <vector>
#include <iterator>
using namespace std;


class Contoh {
public:
    int x;
    string y;
    vector<int> z;
};

void function(int (&arr)[3]){
    auto [x, y, z] = arr;
    cout << x << " " << y << " " << z << endl;
}

int main(){
    
    int a[] = {10, 20, 30};


    void(*func)(int (&)[3]) = function;
    func(a);


    Contoh contoh = {90, "hello world", {10,20}};

    auto [x, m, l] = contoh;

    cout << x << " " << m << " ";
    for(int i: l){
        cout << i << " ";
    }
    cout << endl;





    return 0;
}
