/*
Problem: 
- how to count the frequency of each character
- how to do shuffling like how to put the characters forward whose frequency is more
- sort string based on frequency
- build answer string

* Method 1: using bucket sort
* method 2: HashMap + Sorting
* Method 3: Heap(Priority Queue)

- The comparator doesn't define an order for equal frequencies, which can violate the strict ordering expected by sort.


*/

#include<iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin>>s;
    unordered_map<char, int> freq;
    //Count frequency
    for(char ch: s){
        freq[ch]++;
    }

    //Sort based on frequency
    /*Safer comparator is: 
    sort(s.begin(), s.end(), [&](char a, char b){
        if(freq[a]==freq[b]) return a<b;

        return freq[a]>freq[b];
    });

    this gives a consistent order when frequencies are equal. Even though problem allows any order, this avoids comparator issues
    t ->1
    r ->1
    e ->2

    now t vs r
    1==1 -> alphabetically r<t -> r first  -> eert


    */
    sort(s.begin(), s.end(), [&](char a, char b){
        if(freq[a]==freq[b]) return a<b;

        return freq[a]>freq[b];
    });

    cout<<s<<endl;

    return 0;
}