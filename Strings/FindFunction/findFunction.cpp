#include<iostream>
using namespace std;

// T.C. - O(n * p), where p is position

int find(string st,string part){
    for(int i = 0;i < st.length();i++){
        int j = 0;
        if(st[i] == part[j]){
            while((i + j) < st.length() && j < part.length() && st[i + j] == part[j]){
                j++;
            }
            if(j == part.length())
                return i;
        }
    }
    return -1;
}

int main(){
    string s = "I am a good boy!";
    string search = "am";

    cout << find(s,search) << endl;
}