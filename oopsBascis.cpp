#include<iostream>
#include<vector>
using namespace std;
class A { 
    int health;
    public:
    A(){
        cout << "Default Constructor Called" << endl;
    }
    A(int health){
        this->health = health;

    }
    A(A& obj){
        this->health = obj.health;
    }
};
int main(){
    A obj;
    A* ptr = new A();
}

