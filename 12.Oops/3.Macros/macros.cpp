#include<iostream>
using namespace std;

/*   --------
    | MACROS |
     --------
    
    1. In C++, macros are preprocessor directives that allow you to define constants, functions, or code snippets that can be used throughout your code. 
       They are typically defined using the #define directive and are evaluated by the preprocessor before the code is compiled.
    2. Macros can be used for a variety of purposes, such as defining constants or creating shorthand for commonly used expressions.
    3. Macros do not take any space in memory.
    4. They are used to improve code - readability.
    
    # While compilation, compiler simply puts whatever is in macro at it's rightful place (nothing much!).
*/

#define pi 3.141592653589793238462643383279502884197
#define maxx(x, y) (x > y ? x : y)

double circleArea(double radius){
    return pi * radius * radius;
}

double circlePerimeter(double radius){
    return 2 * pi * radius;
}

void testFun(){
    int a = 5;
    int b = 6;
    int c = maxx(a, b);
}

int main(){
    cout << circleArea(65.4) << endl;   
    cout << circlePerimeter(65.4) << endl;

    return 0;
}