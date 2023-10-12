#include<iostream>
using namespace std;

// love babbar's logic < easy - simple >
void shift2(vector<int> &v){
    int j = 0;
    for(int i = 0;i < v.size();i++){
        if(v[i] < 0){
            swap(v[i],v[j]);
            j++;
        }
    }
}

// my logic < complex >
void shift(vector<int> &v){
    int low = 0,high = v.size() - 1;
    while(low < high){
        if(v[high] < 0){
            if(v[low] >= 0){
                swap(v[low],v[high]);
                low++;high--;
            }
            else{
                low++;
            }
        }
        else{
            if(v[low] >= 0){
                high--;
            }
            else{
                low++;high--;
            }
        }
    }
}

void printVector(vector<int> v){
    for(int i = 0;i < v.size();i++)
    cout << v[i] << " ";
    cout << endl;
}
int main(){
    vector<int> v;
    cout << "Enter the size of array:" << endl;
    int n;
    cin >> n;
    cout << "Enter the array:" << endl;
    for(int i = 0;i < n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    cout << "Pre shift: " << endl;
    printVector(v);
    shift(v);
    cout << "Post shift: " << endl;
    printVector(v);

    return 0;
}