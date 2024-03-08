#include<bits/stdc++.h>
using namespace std;

#define R(v, s, e) for(int v = s; v < e; v++)
#define P pair<int, int>

bool cmp(P a, P b){
    if(a.second == 1) a.first*=2;
    if(b.second == 1) b.first*=2;
    return (a.first) > (b.first);
}

int main(){
    vector<int> w;
    vector<P> dn;
    int n, k;
    cin >> n >> k;
    w.resize(n);
    R(i, 0, n){
        cin >> w[i];
    }
    R(i, 0, n){
        dn.push_back(P(w[i], 1));
        R(j, i+1, n){
            dn.push_back(P(w[i] + w[j], 2));
        }
    }
    sort(dn.begin(), dn.end(), cmp);
    P ans = dn[k-1];
    if(!(ans.first % ans.second)){
        ans.first = ans.first / ans.second;
        ans.second = 1;
    }
    cout << ans.first << '\n' << ans.second;
    return 0;
}