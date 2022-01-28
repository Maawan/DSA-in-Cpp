#include<iostream>
#include<vector>
using namespace std;
class Vehicle {
    protected:
    int wheels;
    public:
    Vehicle(){
        wheels = 4;
    }
    virtual void move() = 0;
    virtual void brake() = 0;
};
class FrontWheelDriven : protected Vehicle {
    string carName;
    public:
    FrontWheelDriven(string name){
        this->carName = name;
    }
    void move(){
        cout << carName << " is moving with its Front Tyres " << endl;
    }
    void brake(){
        cout << carName << " is braking with its Back Tyres " << endl;
    }
    int getWheels(){
        return wheels;
    }
};
class BackWheelDriven : protected Vehicle {
    string carName;
    public:
    BackWheelDriven(string name){
        this->carName = name;
    }
    void move(){
        cout << carName << " is moving with its Back Tyres " << endl;
    }
    void brake(){
        cout << carName << " is braking with its Front Tyres " << endl;
    }
    int getWheels(){
        return wheels;
    }
};
class AllWheelDriven : protected Vehicle {
    string carName;
    public:
    AllWheelDriven(string carName){
        this->carName = carName;
    }
    void move(){
        cout << carName << " is moving with its All Four Tyres " << endl;
    }
    void brake(){
        cout << carName << " is braking with its All 4 Tyres " << endl;
    }
    int getWheels(){
        return wheels;
    }
};
class Maruti : public FrontWheelDriven {
    int power;
    public:
    Maruti():FrontWheelDriven{"Hello"}{
        this->power = 100;
    }

};
int main(){
    AllWheelDriven merceredes("GLA");
    merceredes.move();
    cout << "No of Wheels " << merceredes.getWheels() << endl;
    Maruti m;
    m.move();
    m.brake();
    return 0;
}