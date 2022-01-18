#include<iostream>
#include<cstring>
using namespace std;
class A{
    public:
    int val;
    char *st;
    A(int a , char ch[]){
        this->val = a;
        st = new char(100);
        strcpy(st , ch);
    }
    // Comment this Copy Constuctor for Shallow Copy
    A(A& newObj){
        this->st = new char(100);
        strcpy(this->st , newObj.st);
        this->val = newObj.val;
    }
    void display(){
        cout << val << " " << st << endl;
    }
};
int main(){
    char ch[] = {'B','a','b','b','e','r','\0'};
    A one(786 , ch);
    A second(one);
    second.st[0] = 'M';
    one.display();
    second.display();
    return 0;
}