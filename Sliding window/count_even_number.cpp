// 1. Count of even numbers in every window

#include <iostream>
using namespace std;

int main() {
    // k=window size
    int k=3;
    int arr[]= {2,5,3,6,8,4,7,9};
    int count=0;
    int n=sizeof(arr)/sizeof(arr[0]);
    //for 1st window
    for(int i=0; i<k; i++){
        if(arr[i]%2==0){
            count++;
        }
    }
    cout<<count<<" ";
    //slide window
    for(int i=k; i<n; i++){
        if(arr[i-k]%2==0){
            count--;
        }
        //if incoming element is even
        if(arr[i]%2==0){
            count++;
        }
        cout<<count<<" ";
    }

    return 0;
}