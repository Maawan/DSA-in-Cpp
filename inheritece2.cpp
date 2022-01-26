#include<iostream>
#include<vector>
using namespace std;
class Super{
    public:
    virtual void display(){
        cout << "Displaying Super Function Display Part  " << endl;
    }
};
class Base : public Super {
    public:
    void display(){
        cout << "Displaying Base Function Display Part " << endl;
    }
};
class Child : public Base {
    public:
    void display(){
        cout << "Displaying Child Function Display Part " << endl;
    }
};
int main(){
    Child Obj;
    Super *ptr = &Obj;
    ptr->display();
    return 0;
}