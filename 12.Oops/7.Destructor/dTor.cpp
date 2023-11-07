#include<iostream>
using namespace std;


/*   ------------
    | DESTRUCTOR |
     ------------
    
    -> Every class, function, variable has a life cycle.
    -> At then end of their work, they are all destroyed by ' DESTRUCTOR '.

    -> Syntax : 
        ~ class_name(){}

    Ques. What is the use of this destructor ?
    Ans. Every memory which has been initialised, has to be destroyed. Memory in stack is destroyed but what about the memory at heap?
         Heap memory needs to be destroyed, hence we need destructor to be defined if there is a heap memory being used in our class.

    # Note : If there is a heap memory used in a class and destructor is not defined to delete it, there will definetly be a memory leak as 'default destructor' will not be called!
*/

class Student{
    public: 
        string name;                                      
        int rollNumber; 
        int *heapMemory;                                           

    public:          
        // Default Constructor
        Student(){
            cout << "Default Constructor called!" << endl;
            this -> heapMemory = new int(10);
        }

        // Destructor
        ~ Student(){
            cout << "Destructor called!" << endl;
            delete heapMemory;
        }
        
};


int main(){
    Student s1;
    cout << "S1 made" << endl;

    {
        Student s2;
        cout << "s2 made" << endl;
    }

    return 0;
}