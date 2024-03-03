#include<bits/stdc++.h>

using namespace std;

#define REP(var, start, end) for(int var = start; var < end; var++)
#define P pair<int, int>

vector<int> sts;
vector<vector<P>> rd;
int n, k;

pair<int, int> dfs(int cur, int p, int pr){
    int up = sts[cur] - k;
    int total = 0;
    for(P i : rd[cur]){
        if(i.first == p)continue;
        P temp = dfs(i.first, cur, i.second);
        total += temp.second;
        up += temp.first;
    }
    total += abs(up * pr);
    return P(up, total);
}

int main(){
    cin >> n >> k;
    sts.resize(n+1);
    REP(i, 1, n+1){
        cin >> sts[i];
    }
    rd.resize(n+1);
    int c, a, b;
    while(cin >> a >> b >> c){
        rd[a].push_back(P(b, c));
        rd[b].push_back(P(a, c)); 
    }
    auto temp = dfs(1, -1, 0);
    cout << temp.second;
    
}