#include<iostream>
using namespace std;

/* 

     Multiple Inheritance (Important for interviews) :
        - Child class inherits from more than one parent classes.
        - E.g. Teacher -> Professor
                                ↑
                            Researcher

        # Multiple Inheritance is not possible in Java.

*/


// Parent class
class Teacher{
   public:
        void teach(){
            cout << "Teaching.." << endl;
        }
};

// Parent class
class Researcher{
    public:
        void research(){
            cout << "Researching.." << endl;
        }
};


// Child class
class Professor : public Teacher, public Researcher{
    public:
        void bore(){
            cout << "Boring.." << endl;
        }
};

int main(){
    

    return 0;
}