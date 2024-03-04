#include<bits/stdc++.h>
using namespace std;

#define RE(var, sta, end) for(int var = sta; i < end; i++)
bool m11(vector<int> n){
    int odd = 0, even = 0;
    for(int i = 0; i < n.size(); i += 2){
        even += n[i];
    }
    for(int i = 1; i < n.size(); i += 2){
        odd += n[i];
    }
    if(((odd - even) % 11))
    return 0;
    return 1;
}


int main(){
    int n0, n2;
    cin >> n0 >> n2;
    vector<int> n(n0+n2);
    RE(i, 0, n0) n[i] = 0;
    RE(i, n0, n2+n0) n[i] = 2;
    while(!m11(n)){
        
    }
}