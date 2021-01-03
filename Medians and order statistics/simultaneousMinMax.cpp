#include <iostream>

using namespace std;

int c=0;

void min_max(int a[], int s){
    int max;
    int min;
    if(s%2==0){
        if(a[0]>a[1]){
            c++;
            max=a[0];
            min=a[1];
        }
        else{
            c++;
            max=a[1];
            min=a[0];
        }
        for(int i=2;i<=s-2;i+=2){
            if(a[i]>a[i+1]){
                c++;
                c++;
                if(a[i+1]<min){
                    min=a[i+1];
                }
                    c++;
                if(a[i]>max){
                    max=a[i];
                }
            }
            else
            {
                c++;
                c++;
                if(a[i]<min){
                    min=a[i];
                }
                    c++;
                if(a[i+1]>max){
                    max=a[i+1];
                }
            }
        }
    }
    else{
        min=max=a[0];
        for(int i=1;i<=s-2;i+=2){
            if(a[i]>a[i+1]){
                c++;
                c++;
                if(a[i+1]<min){
                    min=a[i+1];
                }
                    c++;
                if(a[i]>max){
                    max=a[i];
                }
            }
            else
            {
                c++;
                c++;
                if(a[i]<min){
                    
                    min=a[i];
                }
                c++;
                if(a[i+1]>max){
                    
                    max=a[i+1];
                }
            }
        }
    }
    cout<<"min: "<<min<<"  "<<"max: "<<max<<"  "<<"comparisons:"<<c;
}   

int main(){
    int a[10] = {52,6,2,-2,46,43,1,654,1,3};
    min_max(a,10);
}