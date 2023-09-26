#include<iostream>
using namespace std;


string substr(string s,int from,int to){
    string ans = "";
    for(int i = from;i < to && i < s.length();i++){
        ans+=s[i];
    }
    return ans;
}

// Method 1 - O(n + n)
void erase1(string &s,int from,int step){
    s = (substr(s,0,from) + substr(s,from + step,s.length()));
}

// Method 2 - O(n)
void erase2(string &s,int from,int step){
    string s1;
    for(int i = 0;i < s.length();i++){
        if(i == from && (from + step) < s.length()){
            i = from + step;
        }
        s1+=s[i];
    }
    s = s1;     // shallow copying
}

// Method 3 - O(n)
void erase3(string &s,int from,int step){
    int i = from, j = from + step;
    while(s[j] != '\0'){
        s[i] = s[j];
        i++;j++;
    }
    for(;i < s.length();i++){
        s[i] = '\0';
    }
}

int main(){
    string s = "Funny is he";
    //erase1(s,2,3);
    //erase2(s,2,3);
    erase3(s,2,5);
    cout << s << endl;

    return 0;
}