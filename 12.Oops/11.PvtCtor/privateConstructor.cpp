#include<iostream>
using namespace std;

/*
    Ques. Can constructors be made private ?
    Ans. Yes.

    -> This is use case of friend class.
    -> Suppose if we want that user shouldn't directly make an object of the given class, instead it can be made using another class(friend).
*/

class Box{
    private:
        int width;

        Box(int _val) : width(_val){}
    
    public:

        int getWidth(){ return width; }

        void setWidth(int _val){ width = _val; }

        friend class BoxFactory;                        // declare another class as friend
};


class BoxFactory{
    public:
        Box getABox(int _w){
            return Box(_w);                     // here we can make it's object, as this class is it's friend
        }
};

int main(){

    // Box b(12);                      // this will give an error

    // Hence we need to make this object explicitly using object of 'BoxFactory' class

    BoxFactory bxFact;
    Box bxObj = bxFact.getABox(12);                 // returns object of 'box' class

    cout << bxObj.getWidth() << endl;

    return 0;
}