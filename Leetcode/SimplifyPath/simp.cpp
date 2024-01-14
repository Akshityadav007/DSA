#include<iostream>
#include<stack>
using namespace std;

// Problem || Leetcode : 71
/*
    -> Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.
    -> In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. 
    -> For this problem, any other format of periods such as '...' are treated as file/directory names.
    -> The canonical path should have the following format:
        - The path starts with a single slash '/'.
        - Any two directories are separated by a single slash '/'.
        - The path does not end with a trailing '/'.
        - The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
        - Return the simplified canonical path.
*/


// Solution
/*
    -> Just follow the instructions.
*/

class Solution {
public:
    string simplifyPath(string path) {
        string ans = "";
        stack <string> st;

        int i = 0;

        while(i < path.size()){
            if(path[i] == '/'){
                ++i;
                continue;
            }
            else if(path[i] == '.'){
                int periodCount = 0;
                string currFile = "";
                while(i < path.size() && path[i] != '/'){
                    currFile += path[i];
                    if(path[i] == '.')
                        ++periodCount;
                    ++i;
                }
                
                if(periodCount == 2 && currFile.size() == 2){
                    if(!st.empty())
                        st.pop();
                }
                else if(periodCount == 1 && currFile.size() == 1)
                    ++i;
                else
                    st.push(currFile);
            }
            else {
                // letter, digit or _
                string currPath = "";
                while(i < path.size() && path[i] != '/'){
                    currPath += path[i];
                    ++i;
                }

                st.push(currPath);
            }
        }        

        // fill the answer string
        while(!st.empty()){
            string temp = "/" + st.top();
            ans = temp + ans;
            st.pop();
        }

        // empty string
        if(ans.size() == 0)
            ans = "/";

        return ans;
    }
};

int main(){

    return 0;
}