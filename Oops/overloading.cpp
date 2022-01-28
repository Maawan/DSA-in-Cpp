#include<iostream>
using namespace std;
class A{
    int a ;
    int b;
    public:
    A(int a , int b){
        this->a = a;
        this->b = b;
    }
    void getResults(){
        cout << a << " " << b << endl;
        
    }
    friend A operator ++ (A& onj );
};
A operator ++ (A& onj){
    int sum = 0;
    onj.a = onj.a + 2;
    onj.b = onj.b + 2;
    return onj;
}
int main(){
    A a(12,23) , b(34 , 56);
    a++;
    a.getResults();
    return 0;
}