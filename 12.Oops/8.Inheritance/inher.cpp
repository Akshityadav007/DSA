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

*/

/*        - Mode of inheritance:

         -----------------------------------------------------------
        | Base class        |          Mode of Inheritance          |
        | access modifiers  | Public     |   Protected   | Private  |
        |-------------------|------------|---------------|----------|
        | Public            | Public     |   Protected   | Private  |
        | Protected         | Proctected |   Protected   | Private  |
        | Private           | N/A        |   N/A         | N/A      |
         -----------------------------------------------------------

        N/A : Not Accessible

*/

/*   ----------------------
    | Types Of Inheritance |
     ----------------------

    1. Single Inheritance : Parent_class -> Child_class

    2. Multi - level Inheritance : 
        - Parent_class -> Child_class -> grand_child_class.
        - E.g. Fruit -> Mango -> Alphonso.
    
    3. Hierarchichal Inheritance : 
        - Parent_class -> Child_class
                |     ↳    Child_class   
                ↳  Child_class

    4. Multiple Inheritance (Important for interviews) :
        - Child class inherits from more than one parent classes.
        - E.g. Teacher -> Professor
                             ↑
                          Researcher

        # Multiple Inheritance is not possible in Java.

            

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
        // constructor
        Sparrow(int age, int weight, int noOfLegs, string color){
            this -> age = age;
            this -> weight = weight;
            this -> noOfLegs = noOfLegs;
            this -> color = color;
        }

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

// child class
class Parrot : public Bird{
    public:
        void speaking(){
            cout << "Parrot is speaking!" << endl;
        }
};

int main(){
    Sparrow sp(1, 1, 2, "Brown");
    Pigeon pg;
    Parrot pa;

    sp.eat();
    sp.grassing();
    cout << sp.color << endl;

    pg.eat();
    pg.guttering();

    pa.eat();
    pa.speaking();
    

    return 0;
}