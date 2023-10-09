#include<iostream>
using namespace std;

/*
    ->
                                                    ↱      address of 'a'
                                    int* ptr    =   &a;
                                    ↓    ↳ pointer name
                                    pointer to integer data type

    -> '*' is de - referencing operator (returns the value to stored at the address stored in the pointer). Note: Only a pointer can be de-referenced.
    -> '&' is referencing operator (returns the address of the variable).

    -> In the below code,
        Box - |a| stores value of 10 and has address '0x13231'. -- Just a random address.
        Box - |ptr| stores address of 'a' i.e. 0x13231.

*/

// pointer with characters
void characterArray(){
    char ch[50] = "Akshit";
    char* cptr = ch;                 // only 'ch' and not '&ch'.
    cout << cptr << endl;            // unlike integer array where this would print the address of variable, this here would print entire array i.e. "Akshit"
    cout << *cptr << endl;           // this will act same, prints ch[0] i.e. 'A'.

    // Bascially in char arrays, the pointer begins from the address to which it is assigned and traverses till it gets '\0' i.e. null
    cout << cptr + 2 << endl;            // this will start it traversal from ch[2] and traverse till '\0' 

    // So, what if we try it with a single character and not char array?
    char c = 'A';
    char* cp = &c;
    cout << cp << endl;         // this will keep printing till it finds '\0' which means it will print characters after 'A' too... (can be anything!)



    // BAD practice
    char *cptrBad = "Akshit";
    // Why? Well we know pointers only store addresses. So, where will "Akshit" be stored ?
    // This is bad because "Akshit" is stored in a temporary storage and the address of temp storage is assigned to cptrBad, hence it is a bad practice
}

// void pointers
void voidPointers(){
    void* vPtr;
    int x = 10;
    vPtr = &x;

    // before using let's cast it to 'int'
    int* intPtr = static_cast<int*>(vPtr);          // static_cast operator is a compile time operator that tells compiler to consider vPtr as pointer to 'int' data type
    cout << *intPtr << endl;                        // this will print 10

}

// passing pointers
// Passed by value
void byValue(int* pValue){
    pValue = pValue + 1;              // this doesn't modify main() pointer, a new pointer 'pValue' with a different address is created.
}
// Passed by reference
void byReference(int* &pRef){
    pRef = pRef + 1;              // this modifies main() pointer
}

int main(){
    // 1)

    // declaration
    int a = 10;
    int* ptr = &a;      // right practice

    // dereferencing
    cout << *ptr << endl;

    // check what is stores in 'ptr'
    cout << ptr << endl;

    // verify with address of 'a'
    cout << &a << endl;

    // the box 'ptr' will also be occupying some space
    cout << &ptr << endl;



    // 2)       Declaration practice
    int *p;             // bad practice         --> This is a Wild pointer
    int *p1 = 0;        // better practice      --> create null pointer
        // or
    int *p2 = nullptr;  // 2nd way of null pointer



    //3)    Pointer storing same address
    int b = 3;
    int* p3 = &b;
    int* p4 = p3;       // -> here 'p4' will store the address of 'b' not 'p3'  i.e. value stored in p3.

    /*
        -> it will result in compilation error if we do - int* p4 = &p3;
        -> a value of type "int **" cannot be used to initialize an entity of type "int *". (we'll need pointer to pointer)
        -> Address of pointer can only be stored with a pointer to pointer.
    */

    // 4)   Pointer to pointer
    int c = 3;

    // declaration
    int* p5 = &c;
    int** p6 = &p5;              // -> This is pointer to pointer which stores address pointer p5.
    int*** p7 = &p6;             // -> Pointer to -> a pointer to -> a pointer          .. and so on... 
    /*
        -> p7 stores address of p6 pointer
        -> p6 stores address of p5 pointer
        -> p5 stores address of c variable
    */

    // dereferencing
    cout << p7 << endl;                             // p7 can be accessed with only p7
    cout << *p7 << p6 << endl;                      // p6 can be accessed with *p7 (value stored in p7) and p6
    cout << **p7 << *p6 << p5 << endl;              // p5 can be accessed with **p7 (value stored in *p7), *p6 (value stored in p6) and p5

    cout << ***p7 << **p6 << *p5 << c << endl;      // c is accessed here


    // Basically de - referencing is going to the address of stored value in the pointer and getting the stored value on that address


    // passing to function
    byValue(p5);
    cout << p5 << endl;             // p5 is not modified
    
    byReference(p5);
    cout << p5 << endl;             // p5 is modified


}