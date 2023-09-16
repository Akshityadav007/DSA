#include<iostream>
using namespace std;

void sortCol2(vector<int> &nums){
    int low = 0, high = nums.size() - 1,i = 0;
    while(i <= high){
        if(nums[i] == 2){
            swap(nums[i],nums[high]);
            // the below code is the only CATCH
            high--; // no need to increase 'i' as we don't know if this is swapped with 0/1 from nums[high]
        }
        else if(nums[i] == 0){
            swap(nums[i],nums[low]);
            low++;i++;      
        }
        else{
            i++;
        }
    }
}

// mine(60 %) + love babbar's logic
// simple - easy < doesn't mean good >
void sortCol(vector<int> &v){
    // low - for 0 ; high - for 2
    // first loop for 0
    int low = 0,high = v.size() - 1;
    for(int i = 0;i < v.size();i++){
        if(v[i] == 0){
            swap(v[i],v[low]);
            low++;
        }
    }
    // second loop for 2
    for(int i = v.size() - 1;i >= 0;i--){
        if(v[i] == 2){
            swap(v[i],v[high]);
            high--;
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
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    cout << "Enter the array: " << endl;
    for(int i = 0;i < n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    cout << "Pre sort: " << endl;
    printVector(v);
    sortCol(v);
    cout << "Post sort: " << endl;
    printVector(v);
}