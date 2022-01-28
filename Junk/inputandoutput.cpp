#include<iostream>
#include<fstream>
using namespace std;
int main(){
    fstream obj1;
    obj1.open("C:\Users\Maawan Ahmad\Desktop\C Programs\oopsPracticals\abc.txt");
    if(!obj1){
        cout << "Error";
    }
    obj1 << "Hello";
    obj1 << "Hi";
    string s;
    obj1 << s;
    cout << s;
    return 0;
}