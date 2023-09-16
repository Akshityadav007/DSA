#include<iostream>
#include<vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        // first find the sum of 'k' elements in array
        double sum = 0;
        for(int i = 0;i < k;i++)
            sum+=nums[i];
        // get the average
        double maxAvg = sum / k;
        
        // two pointer approach for sliding window
        int low = 0;
        for(int i = k;i < n;i++){
            sum -= nums[low];
            sum += nums[i];
            double tempAvg = sum / k;
            cout << tempAvg << endl;
            maxAvg = max(maxAvg,tempAvg);
            low++;
        }

        return maxAvg;
}
    double max(double a,double b){
        if(a > b)
        return a;
        else
        return b;
}

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(12);
    v.push_back(-5);
    v.push_back(-6);
    v.push_back(50);
    v.push_back(3);
    int k = 4;
    double ans = findMaxAverage(v,k);
    cout << ans << endl;
}