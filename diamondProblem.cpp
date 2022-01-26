#include<iostream>
#include<vector>
using namespace std;
class Super {
    public:
    void sample1(){
        cout << "Super Sample 1 " << endl;
    }
    void sample2(){
        cout << "Super Sample 2 " << endl;
    }
    void sample3(){
        cout << "Super Sample 3 " << endl;
    }
};
class Base1 : public Super {
    public:
    void sample1(){
        cout << "Base 1  Sample 1 " << endl;
    }
    void sample2(){
        cout << "Base 1 Sample 2 " << endl;
    }
    void sample3(){
        cout << "Base 1 Sample 3 " << endl;
    }
    
};
class Base2 : public Super {
    public:
    void sample1(){
        cout << "Base 2 Sample 1 " << endl;
    }
    void sample2(){
        cout << "Base 2 Sample 2 " << endl;
    }
    void sample3(){
        cout << "Base 2 Sample 3 " << endl;
    }
    
};
class Child : public Base1 , public Base2{

};
int main(){
    Child obj;
    obj.sample2();
    return 0;
}