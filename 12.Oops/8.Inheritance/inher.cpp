#include<iostream>
using namespace std;

/*   -------------
    | INHERITANCE |
     -------------

    -> Two classes : 
        1. Parent class / Super class / Base class
        2. Child class / Sub class / Derived class
    -> All public/protected members/functions are inherited by child class from parent class.

    -> Syntax:
        - class child_class_name : mode_of_inheritance parent_class_name {};
        - Mode of inheritance:
            1. Public : All public members will be inherited.
            2. Protected : All protected members will be inherited.
            3. Private : All private members will be inherited.

*/

// Parent class
class Bird{
    public:
        int age, weight, noOfLegs;;
        string color;

        void eat(){
            cout << "Bird is eating!" << endl;
        }

        void fly(){
            cout << "Bird is flying!" << endl;
        }
};

// child class
class Sparrow : public Bird{
    public:
        void grassing(){
            cout << "Sparrow is grassing!" << endl;
        }
};

// child class
class Pigeon : public Bird{
    public:
        void guttering(){
            cout << "Sparrow is guttering!" << endl;
        }
};

int main(){
    Sparrow sp;
    Pigeon pg;

    

    return 0;
}