// this finds ith order statistic Because this is randomized algorithm it has a linear expected running time.
#include <iostream>

using namespace std;

int partition(int a[], int p, int r)
{
    int x = a[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++)
    {
        if (a[j] <= x)
        {
            i += 1;
            //swap a[i] and a[j]
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    //swap a[i+1] and a[r]
    int t = a[i + 1];
    a[i + 1] = a[r];
    a[r] = t;
    return i + 1;
}

int randomizedPartition(int a[], int p, int r)
{   
    int i = p + rand() % (r - p + 1);
    
    int t = a[r];
    a[r] = a[i];
    a[i] = t;
    
    return partition(a, p, r);
}

int randomizedSelect(int a[], int p, int r, int i){
    if(p==r)
        return a[p];
    int q=randomizedPartition(a,p,r);
    int k=q-p+1;
    if(i==k)
        return a[q];
    else if(i<k)
        return randomizedSelect(a,p,q-1,i);
    else
        return randomizedSelect(a,q+1,r,i-k);
                                                                                                                
}

int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    cout<<randomizedSelect(a,0,9,2);
}