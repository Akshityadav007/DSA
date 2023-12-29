#include<iostream>
#include<unordered_map>
using namespace std;

// Theory
/*   ------
    | Maps |
     ------
    
    -> It is a type of data structure which stores data in form of key, value pairs.

    1) Map STL (C++):
        - https://en.cppreference.com/w/cpp/container/map . 
        - Two types of hashmaps:
            i) ordered_map :
                - Implemented using balanced BST.
                - Key is present in sorted manner.
                - Insertion, searching, deletion, T.C. = O(logn)
                - Syntax : map<data_type1, data_type2> map;
            ii) unorder_map : 
                - Implemented using array/hashtable/bucket array.
                - Insertion, searching, deletion, T.C. = O(1) (nearly).
                - Syntax : unordered_map<data_type1, data_type2> map;
                - 'count' keyword when applied on a key returns 1 if it exists in the map, else returns 0
                - 'find' keyword return an iterator.

                * When we try to access values of map using 'mapp['key]', if the key exists it will return they value of it, else it will create the mapping and return 0(the value of that mapping);
    
    2) 
        -> Hash function is used to store the data given to a hashtable.
        -> The hash function comprises of two things:
            i) Hash code - converts input to int(output sum of hash code).
            ii) Compression function - places the hash code to it's compressed place.
        -> Collision is a situation which occurs when the 'output sum of hashcode' of two hash inputs come same.
        -> Collisions must be handled.

    3)
        Collision - Handling Techniques:
            i) Open Hashing
                - At the point of collision we store a pointer to a linked list which stores the inputs having collision.
            ii) Closed Hashing
                - Search for next free space linearly. (Linear profing).
                or
                - Search for next squared index for free space. (Quadractic profing).
            
    4)
        Load factor = no. of elements / free boxes
            - If load factor < 0.7, then has function is a very good hash function.
*/


int main(){
    unordered_map <string, int> mapping;

    // INSERTION

    // create pair
    pair<string, int> p = make_pair("Akshit", 1);
    pair<string, int> q("Yadav", 2);
    pair<string, int> r;
    r.first = "Boy";
    r.second = 3;

    // insert into map
    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);

    // insert
    mapping["girl"] = 4;

    cout << "Size of map: " << mapping.size() << endl;

    // ACCESS
    cout << mapping.at("Yadav") << endl;
    cout << mapping["Akshit"] << endl;

    // SEARCHING
    // "count" keyword on a key
    cout << mapping.count("Joy") << endl;

    // best approach to search
    if(mapping.find("Yadav") == mapping.end())
        cout << "Not found" << endl;
    else
        cout << "Found" << endl;
    
    
    
    cout << "Size of map: " << mapping.size() << endl;          // size before '[]' call
    cout << mapping["Yoda"] << endl;                            // will return 0 after creating "['Yoda] = 0" mapping
    cout << "Size of map: " << mapping.size() << endl;          // size will change here as "Yoda" has been created

    return 0;
}