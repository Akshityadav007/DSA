#include<iostream>
using namespace std;

// Learn this after module 11

/*
    -> Also known as Dynamic Polymorphism.
    -> Function overriding.

    -> Suppose there is a class 'Animal'.
    -> It's child class 'dog'.

    -> If we make an object of dog class using a pointer of a class 'animal'.
    -> E.g.: Animal *animal = new Dog();


    -> If we call a function using this pointer, it will call the function of animal class (not of dog class).
    -> This happens because compiler compiles it as an object of animal class (Early/Static binding).

    -> This is a problem!

    -> To solve this, we have dynamic/runtime polymorphism.
    
    -> We'll use late binding (function overriding).
    -> Make the function of animal class 'virtual' (all including destructor.)
    -> Using 'override' keyword is optional but as a good programmer we'll use it.

    # Note : We use pointer to make object to use heap memory (runtime operation).
    # Note : If we don't make destructor virtual the heap memory allocated to 'animal' object won't be deleted.

*/

class Animal{
    public:
         virtual void sound(){
            cout << "Animal making sound!" << endl;
        }


        // destructor
        virtual ~Animal(){
            cout << "Animal dTor called!" << endl;
        }
};


class Dog: public Animal{
    public:
        void sound() 
        override                                        // gives warning on using this in my compiler
        {
            cout << "Dog barking!" << endl;
        }


         // destructor
        ~Dog(){
            cout << "Dog dTor called!" << endl;
        }
};


class Cat: public Animal{
    public:
        void sound() 
        override 
        {
            cout << "Cat meowing!" << endl;
        }

        // destructor
        ~Cat(){
            cout << "Cat dTor called!" << endl;
        }
};

class Parrot: public Animal{
    public:
        void sound() 
        override 
        {
            cout << "Parrot speaking!" << endl;
        }

        // destructor
        ~Parrot(){
            cout << "Parrot dTor called!" << endl;
        }
};



void sound(Animal *animal){
    animal -> sound();                  // polymorphic
    // animal -> sound(), is behaving as per required object allocated at runtime
}

int main(){

    Animal *a = new Dog();
    sound(a);

    a = new Cat();
    sound(a);

    a = new Parrot();
    sound(a);       

    delete a;

    return 0;
}