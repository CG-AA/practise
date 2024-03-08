#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    float m = n*1.8+32, k = m - (int)m;
    if(k < 0.5){
        cout << (int)m;
        return 0;
    }
    cout << (int)m + 1;
    return 0;
}