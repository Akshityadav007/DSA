#include<iostream>
using namespace std;

/*   ------------------
    | COPY Constructor |
     ------------------

    1. Copy Constructors are used to copy one object to another.
    2. It is not necessary to create copy object (compiler will add it), but it is always a good practice to have them.

    Ques. Why do we need a COPY constructor ?
    Ans. -> This is used in ' Deep copying '.
    
    3. In parameter of COPY constructor, it is necessary to pass by value because if not done so, it will make a copy of the object.
       And we haven't yet created the COPY constructor, hence this is wrong!
    4. Also it is declared 'const', so that it's values aren't changed by intruders (hackers).
*/

class Student{
    private:
        string gf;
    public: 
        string name;                                       
        string section;                                   
        int rollNumber;                                    
        int age;                                           

    public:          
        // Default Constructor
        Student(){
            cout << "Default Constructor called!" << endl;
        }

        // paramterized - constructor
        Student(int _rollNo, int _age, string _name, string _section, string _gf){
            cout << "Paramterized Constructor called!" << endl;
            rollNumber = _rollNo;
            this -> name = _name;
            this -> age = _age;
            this -> section = _section;
            this ->gf = _gf;
        }

        // Copy Constructor
        Student(const Student &srcObj){
            cout << "Copy constructor called!" << endl;
            this -> name = srcObj.name;
            this -> section = srcObj.section;
            this -> rollNumber = srcObj.rollNumber;
            this -> age = srcObj.age;
            this -> gf = srcObj.gf;
        }

        
};


int main(){
    Student s1(1, 21, "Naruto", "Jonin - B", "Hinata");        // object of the class  - Object is an instance of a class
    
    Student s2 = s1;                                           // # Method 1
    // Student s2(s1);                                         // # Method 2

    cout << s1.name << endl;
    cout << s2.name << endl;

    // # Note : COPY Constructor will not be called in this case ↓
    Student s3;
    s3 = s1;


    return 0;
}