#include<iostream>
using namespace std;

/*   -----------------
    | Diamond Problem |
     -----------------

    ->                Person
                    ⇙        ⇘
            Teacher            Researcher
                   ⇘          ⇙
                     Professor

    -> Person is parent class of teacher and researcher. (a teacher and researcher both can walk).
    -> Teacher and researcher are inherited by professor. (a professor teaches and does research).

    -> But this creates ambiguity for the compiler as it gets confused between which walk for the professor (teacher's walk or researcher's walk).
*/

// Solution
/*
    -> Solution 1 : Scope resolution

    -> Solution 2 : Using Virtual
                    - Tell that both the walks are same.
                    - Mark both the mode of inheritance of class 'Person' as 'virtual'.
                    - 'Virtual' tells the class to resolve this inherited class at runtime and not compile time,
                       doing this makes the class share same copy of the 'Person' class.
                    - When they share same copy of 'Person' (parent) class, they won't create their own individual methods,
                        i.e. there won't be seperate walk() for Teacher and professor.
                    - Assinging 'virtual' to everywhere where it is inherited is necessary.
*/


// Parent class
class Person{
   public:
        void walk(){
            cout << "Walking.." << endl;
        }
};

// Parent class
class Teacher : virtual public Person{
   public:
        void teach(){
            cout << "Teaching.." << endl;
        }
};

// Parent class
class Researcher : virtual public Person{
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
    Professor p;
    // p.walk();            // this causes issue

    
    // Solution 1 : Scope Resolution
    // p.Teacher :: walk();                // Telling to use teacher's walk or
    // p.Researcher :: walk();             // telling to use researcher's walk


    // Solution 2 : Using Virtual
    p.walk();

    return 0;
}