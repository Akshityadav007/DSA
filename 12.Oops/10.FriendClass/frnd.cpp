#include<iostream>
using namespace std;

/*
    -> Friend is a keyword in C++ that is used to share the information of a class that was previously hidden (private).
    -> For example, the private members of a class are hidden from every other class and cannot be modified except through getters or setters. 
    -> Similarly, the protected members are hidden from all classes other than its children classes.

*/

class A{
    private:
        int x;

    public:
        A(int _val) : x(_val){}

        int getX() const { return x; }

        void setX(int _val){ x = _val; }

        friend class B;
};

class B{
    public:
        void print(const A &a){
            // cout << a.getX() << endl;

            // what if i want to access 'x' without getter
            cout << a.x << endl;                                    // for this we need to declare class 'B' as friend in class 'A'
        }
};



// Similarly we can make friend functions too.
// Although in real world, we avoid using this concept.

int main(){


    return 0;
}   