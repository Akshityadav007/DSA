#include<iostream>
using namespace std;

/*
    -> In a class, any member function will have a hidden parameter being passed to it, i.e. 'this' pointer which belongs to an object of that class.
    -> 'this' pointer of obj1 is different from 'obj2'. This helps C++ in distinguishing parameters of individual objects.

    -> Static data member: 
        - That variable is going to share memory with all of the class instances.
        - Basically these do not belong to a particular object (class instance), instead they are common to all objects (class instances).
        - All instances of that class will share same copy of this data member.
        - Used using  - class_name :: static_member_name

    -> Static member function: 
        - There is no instance of that class being passed into that method.
        - They do not have any hidden 'this' pointer to them as they are shared among all objects as a common copy. That is why always use only static members inside these functions.
        - Used using  - class_name :: static_function_name.
*/

// 1.
class Test{
    public:
        int a,b;

        // constructor
        Test(int _a,int _b){
            a = _a;
            b = _b;
        }

        void print() const{
            cout << this -> a << " " << this -> b << endl;
        }
};


// 2.
class TestStatic{
    public:
        static int x, y;

        void print(){
            cout << x << " " << y << endl;
        }
};

// This is the way to declare static data members
int TestStatic :: x;            // data_type class_name :: member_name
int TestStatic :: y;            //                      ↑↑ - used to define scope


// 3.
class TestStaticFunc{
    public:
        static int x, y;

        static void print(){
            // can access only static data members
            cout << x << " " << y << endl;
        }
};

int TestStaticFunc :: x;
int TestStaticFunc :: y;



int main(){
    
    // 1. Working of normal class members
    Test obj1(1, 2);
    Test obj2(4, 5);

    obj1.print();               // 1 2
    obj2.print();               // 4 5

    

    // 2. let's check out static data members
    TestStatic objS1;
    TestStatic objS2;

    objS1.x = 10;               // set 'x' of object 1 to 10
    objS1.y = 20;               // set 'y' of object 1 to 20

    objS2.x = 30;               // set 'x' of object 2 to 30
    objS2.y = 40;               // set 'y' of object 2 to 40

    objS1.print();              // 30 40
    objS2.print();              // 30 40

    // both printed same value because all objects share same copy of static data members, hence object2 changed 'x' of object 2 also.



    // 3. let's explore static functions
    TestStaticFunc :: x = 100;              // another way of accessing static data member
    TestStaticFunc :: y = 102;
    TestStaticFunc :: print();              // way to access static function

    return 0;
}