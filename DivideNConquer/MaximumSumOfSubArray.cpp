// Maximum subarray problem: Here suppose we have stock prices going up and down.
// and we need to find when to buy and sell stocks for maximum profit.
// This problem can be transformed by calculating the daily changes in the stock prices
// and computing the maximum sum of a part of the list. That will be our answer.

#include <iostream>
#include <limits>
#include <tuple> // for making tuples to return multiple values from a function

using namespace std; 

tuple<int, int, int> findMaxCrossingSubArray(int a[], int low, int  mid, int high){
    int maxleft;
    int maxright;
    
    int leftsum=numeric_limits<int>::min();
    int sum = 0;
    for(int i=mid;i>=low;i--){
        sum=sum+a[i];
        if(sum>leftsum){
            leftsum=sum;
            maxleft=i;
        }

    }
    int rightsum=numeric_limits<int>::min();
    sum = 0;
    for(int i=mid+1;i<=high;i++){
        sum=sum+a[i];
        if(sum>rightsum){
            rightsum=sum;
            maxright=i;
        }

    }
    if(leftsum==numeric_limits<int>::min()){
        leftsum=0;
    }
    if(rightsum==numeric_limits<int>::min()){
        rightsum=0;
    }
    return make_tuple(maxleft,maxright,leftsum+rightsum);
}

tuple<int, int, int> findMaxSubArray(int a[], int low, int high){
    if(high==low)
    {
        return make_tuple(low, high, a[low]);
    }
        
    else
    {
       //int leftlow,leftsum,lefthigh,rightlow,righthigh,rightsum,crosslow,crosshigh,crosssum;
        int mid = (low+high)/2;
        auto [leftlow, lefthigh, leftsum] = findMaxSubArray(a,low,mid);
        auto [rightlow, righthigh, rightsum] = findMaxSubArray(a,mid+1,high);
        auto [crosslow, crosshigh,crosssum] = findMaxCrossingSubArray(a,low,mid,high);
        
        if(leftsum>=rightsum && leftsum>=crosssum){
            return make_tuple(leftlow, lefthigh,leftsum);
        }
        else if( rightsum>=leftsum && rightsum>=crosssum){
            return make_tuple(rightlow, righthigh,rightsum);
        }
        else{
            return make_tuple(crosslow, crosshigh, crosssum);
        }
    }
}

int main(){
    int a[16]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    // int a2,b,c;
    auto [a2,b,c] = findMaxSubArray(a,0,15);
    cout<<a2<<endl<<b<<endl<<c<<endl;
}