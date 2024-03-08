#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nl;
    int temp, n = 0;
    while(cin >> temp){
        nl.push_back(temp);
        n++;
    }
    n--;
    nl.pop_back();
    sort(nl.begin(), nl.end());
    if(n % 2){
        cout << nl[(n-1)/2];
    }else{
        cout << nl[n/2];
    }
    return 0;
}