#include<iostream>
using namespace std;

/*
    -> We'll add two vectors (class 11, 12) using '+' operator.
    -> V1 = [ x1 ]
            [ y1 ] 
    -> V2 = [ x2 ]
            [ y2 ]  

    -> V1 + V2 = [ x1 + x2 ]
                 [ y1 + y2 ]

    # Note : These are not C++ vectors, these are vectors which we studied in class 11 and 12.

*/


class Vector{
    int x, y;
    public:
        // init list            -- new way of constructor which we learnt!
        Vector(int x, int y) : x(x), y(y) {}

        void display(){
            cout << "x : " << x << endl;
            cout << "y : " << y << endl;
        }

        // add  - to do operator overloading write 'operator operator_name' .. this is syntax
        void operator + (const Vector &src){
            // src would be v2
            // 'this' pointer would point to v1

            this -> x = this -> x + src.x;
            this -> y = this -> y + src.y;
        }

};

int main(){
    Vector v1(1, 2);
    Vector v2(3, 4);

    // Problem : Add V1, V2 and store it in V1
    v1 + v2;
    v1.display();

    return 0;
}

//   # Homework : Know all operators which can be overloaded. (I used chat gpt)

/*

    -> In C++, you can overload several operators to customize their behavior for user-defined types. Here is a list of operators that can be overloaded:

    1. Arithmetic Operators:
    - `+` (addition)
    - `-` (subtraction)
    - `*` (multiplication)
    - `/` (division)
    - `%` (modulo)

    2. Comparison Operators:
    - `==` (equality)
    - `!=` (inequality)
    - `<` (less than)
    - `>` (greater than)
    - `<=` (less than or equal to)
    - `>=` (greater than or equal to)

    3. Logical Operators:
    - `!` (logical NOT)
    - `&&` (logical AND)
    - `||` (logical OR)

    4. Bitwise Operators:
    - `&` (bitwise AND)
    - `|` (bitwise OR)
    - `^` (bitwise XOR)
    - `~` (bitwise NOT)
    - `<<` (left shift)
    - `>>` (right shift)

    5. Assignment Operators:
    - `=` (assignment)
    - `+=` (addition assignment)
    - `-=` (subtraction assignment)
    - `*=` (multiplication assignment)
    - `/=` (division assignment)
    - `%=` (modulo assignment)
    - `&=` (bitwise AND assignment)
    - `|=` (bitwise OR assignment)
    - `^=` (bitwise XOR assignment)
    - `<<=` (left shift assignment)
    - `>>=` (right shift assignment)

    6. Increment and Decrement Operators:
    - `++` (prefix and postfix)
    - `--` (prefix and postfix)

    7. Subscript Operator: `[]`

    8. Function Call Operator: `()`

    9. Member Access Operators:
    - `->` (member access through pointer)
    - `.` (member access through object)

    10. Address-of Operator: `&`

    11. Dereference Operator: `*`

    12. Comma Operator: `,`

    13. Conditional Operator (Ternary Operator): `? :`

    14. New and Delete Operators:
    - `new`
    - `delete`
    - `new[]`
    - `delete[]`

    15. Type Conversion Operators:
    - `type()`, where `type` is the type you want to convert to (e.g., `int()` for converting to an integer type)

    -> Please note that not all operators can be overloaded for all types, and some operators have certain restrictions on their overloading. 
    -> For example, the conditional operator `? :` and the comma operator `,` have specific rules for overloading. 
    -> Overloading operators should be done with care to ensure that the resulting code remains clear and intuitive for other developers.

*/