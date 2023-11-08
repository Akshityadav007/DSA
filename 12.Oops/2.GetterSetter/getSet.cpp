#include<iostream>
using namespace std;


// Getter Setters can also be used for public variables too. But usually we use them for private.

class Student{
    private:
        string gf;
    public: 
        string name;                                      
        int rollNumber;                                           

    public:          
        // Default Constructor
        Student(){
            cout << "Default Constructor called!" << endl;
        }

        // Parameterized
        Student(string _name, int _rN){
            name = _name;
            rollNumber = _rN;
        }

        // getter
        string getGf(){
            return gf;
        }

        // setter
        void setGf(string gf){
            this -> gf = gf;
        }
        
};


int main(){
    Student s1("Naruto", 34);
    s1.setGf("Hinata");
    cout << s1.name << "'s gf is " << s1.getGf() << endl;

    return 0;
}