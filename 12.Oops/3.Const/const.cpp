#include<iostream>
using namespace std;

/*   -----------------
    | CONST - Keyword |
     -----------------
    1. The const keyword is used to declare that a variable, function, or object is immutable, 
       i.e., its value cannot be changed after initialisation.
    2. E.g., if you declare a variable as 'const int x= 5;', you cannot modify the value of x later in the program. 
       Any attempt to modify the value will result in a compilation error.
    3. You can declare a function as const, which means that it does not modify the state of the object it is called on.
    4. Compiler may be able to store const variables in read-only memory, which can result in faster access.
    5. Constructor is only called while creating an object.

    # CONST is like real - world promise 
    (can be by - passed using 'mutable' keyword. But used only for de - bugging purposes. Good programers avoid it!)

    -> lvalue - variables having memory location. E.g. int x = 5;
    -> rvalue - variables having no memory location. E.g. int &a = x;,  here a is 'rvalue'.
*/

/*   ---------------------
    | CONST with POINTERS |
     ---------------------

    -> There are three types of intialisation with pointers:
        1. CONSTANT data, pointer non - constant.
        2. CONSTANT pointer, data non - constant.
        3. CONSTANT pointer, data CONSTANT.
    
    -> 1. CONSTANT data, pointer non - constant:
          - Can be initialised in two ways,
            a) const int *x = new int(2);          
            b) int const *b = new int(2);
          - Both the initialisations mean same.

    -> 2. CONSTANT pointer, data non - constant.
          - Can be initialised like:
                int *const p = new int(2);
            
    -> 3. CONSTANT pointer, data CONSTANT.
          - Can be initialised like:
                const int *const p = new int(2);

*/

/*   ---------------------------
    | CONST with CLASS/FUNCTION |
     ---------------------------
    
    -> A CONST method/function can never change any of the member variable.
    -> Default argument - Arguments given by default while parameterization. 
                        - This is done usually for optional variables.
                        - MAKE SURE TO PLACE THEM AT RIGHTMOST PLACE.
*/

/*   --------------------
    | INTIALIZATION LIST |
     --------------------
    
    -> This is a new method of parameterized constructor.
    -> It works same as the old way.
    -> Basic use of this is, we can assign value to a 'const' variable using this. In old way, we can't do this.

*/


class Test{
    int x;
    // mutable int x;               // Avoid using mutable
    int *y;
    int z;

    public:
        // default constructor - (necessary to declare if parameterized constructor is declared (if a non parameterized object is needed to be created))
        Test(){
            x = 0;
            y = new int(0);
        }

        // Parameterized constructor
        Test(int _x, int _y, int _z = 0){       // here '_z' is the default argument (optional to pass) - placed at RIGHTMOST place
            x = _x;
            y = new int(_y);
            z = _z;
        }

        // new way of 'Parameterized constructor' - Initialization list
        Test(int _x, int _y, int _z = 0) : x(_x), y(new int(_y)), z(_z){}
        //                               : variable_name(to_be_intialized_with)                  // only difference

        // getters  -   set them as 'const' as they must not be used to modify member variables
        int getX() const {
            return x;
        }
        int getY() const {
            return *y;
        }
        int getZ() const {
            return z;
        }


        // setters
        void setX(int _a){
            x = _a;
        }
        void setY(int _b){
            *y = _b;
        }
        void setZ(int _c){
            z = _c;
        }
};

void PrintTest(const Test &t){
    // as this function object (t) is 'const', only 'const' function can be called using 't'
    cout << t.getX() << t.getY() << t.getZ() << endl;
}

int main(){
    // 1. CONST
    const int a = 5;        // a can't be modified further
    // a = 6;                  // invalid command


    // 2. CONST with POINTERS
        // a) CONSTANT data, pointer non - constant.
            const int *x = new int(2);          // data CONSTANT, pointer non - constant.
            int const *b = new int(2);          // can also be initialised like this.       - both are same (above intialisation and this)
        
            int y = 6;
            // *a = y;                           // invalid step - data can't be modified
            x = &y;                             // valid step - pointer can be modified


        // b) CONSTANT pointer, data non - constant.
            int *const p = new int(2);

            int m = 3;
            *p = m;                            // valid step - data can be modified
            //p = &m;                         // invalid step - pointer can't be modified.

        // c) CONSTANT pointer, data CONSTANT.
            const int *const q = new int(2);

            int n = 3;
            // *q = n;                         // invalid step - data can't be modified
            //q = &n;                         // invalid step - pointer can't be modified.

    // 3. CONST with CLASS/FUNCTIONS
    Test t;
    t.getX();
    t.getY();

    Test t2(1,2);
    PrintTest(t2);


    return 0;
}