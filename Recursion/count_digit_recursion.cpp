// count digits of number using recursion
#include <iostream>
using namespace std;

int print(int n){
    if(n==0){
        return 0;
    }
    return 1+print(n/10);
    
}

int main() {
    int num=956374;
    cout<<print(num);

    return 0;
}