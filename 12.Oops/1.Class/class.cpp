#include<iostream>
using namespace std;

/*

    -> Class is a user - defined data type.
    -> An empty class will have 1 byte of memory, as smallest memory that can be allocated/readable is 1 byte.
    -> A non empty class will have memory of the sum of size of all it's attributes(not variables of method inside it).

    

    ->
            ______________________
            | STRUCTURE OF CLASS |
            ----------------------

            class class_name {
                attributes;                             // by default, private

                methods;                               // by default, private
            };

    ->
            ------------------
            | OBJECT OF CLASS |
            ------------------

            class_name object_name;                 // in main function

    -> Access modifiers -   They define scope of access.
        1) Public: Accessible outside class

        2) Private: Accessible only in class.

        3) Protected:

    -> Constructor : 
        - It constructs an instance of class.
        - Used to take input while making the object of the class. 
        - It is the only function which has no return type (not even void).
        - It is public.
        - Syntax:
            // default constructor
            class_name(){

            }

    -> Polymorphism :same function many forms
        - This is shown in below 'Student' class having multiple constructors.
    
    -> In C++, there is a hidden pointer 'this' added by compiler privately. (class_name *this)

    -> We use ' . ' to access methods of class stored on stack.
    -> We use ' -> ' to access methods of class stored on heap.(We can also use de - referencing operator i.e. (*obj_name).method_name)
    -> In case of heap memory allocation, make sure to delete() to check memory leak.

*/

class Student{

    // Attributes
    private:
        string gf;
    public: 
        string name;                                        // attribute
        string section;                                     // attribute
        int rollNumber;                                     // attribute
        int age;                                            // attribute

    
    // Methods
    public:                                             // by default, methods of C++ class are private
        // Constructor 
        // Default Constructor (called even if we don't write this) - assigns garbage value to attributes
        Student(){
            cout << "Default Constructor called!" << endl;
        }

        // paramterized - constructor
        Student(int _rollNo, int _age, string _name, string _section, string _gf){
            rollNumber = _rollNo;
            this -> name = _name;
            this -> age = _age;
            this -> section = _section;
            this ->gf = _gf;
        }

        // constr for a student with no gf
        Student(int _rollNo, int _age, string _name, string _section){
            rollNumber = _rollNo;
            this -> name = _name;
            this -> age = _age;
            this -> section = _section;
        }


        void study(){
            cout << name << " is studying!" << endl;
        }
        
};

class Padding1 {
    int age;
    int number;
    bool active;                                        // attribute     
    // Although bool takes 1 byte memory, compiler here gives additional 3 bytes (padding) from it own side to the 
    // bus (used to shift memory) to make it shift faster as other 'int' have 4 bytes which makes it easier to pick up. 
    // And to shift to 1 byte pick up will take more time. This increases the size of class.
};

class Padding2{
    double num1;
    double num2;
    char c;
    bool active;

    // Compiler makes it to the next nearest multiple of greatest size of variable
    /*
        -> Here, double has 8 bytes.
        -> Hence total size of the class should be 8 + 8 + 1 + 1 = 18.
        -> Next multiple of 8 is 24, so it will make it 24 bytes. ( Of course, 6 bytes padding)
    */
};

class Padding3{
    int n1;
    int n2;
    string name;                        // takes 24 bytes of memory
    bool active;
    int n3;

    /*
        -> Here, string takes 24 bytes,
        -> So, compiler will take the memory in multiples of 24.
        -> Real memory of this class = 4 + 4 + 24 + 1 + 4 = 37 bytes.
        -> But the next multiple of 24 is 48 (37 < 48). Hence, the memory of this class will be 48 Bytes.
    */
};



int main(){
    Student s1(1, 21, "Naruto", "Jonin - B", "Hinata");                 // object of the class  - Object is an instance of a class
    s1.study();

    Student s2;

    Student noGf(2, 23, "Choji", "Jonin - B");
    noGf.study();

    return 0;
}