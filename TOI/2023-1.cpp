#include<bits/stdc++.h>
using namespace std;

#define RE(v, s, e) for(long long v = s; v < e; v++)
#define P pair<long long, long long>
#define PP pair<P, long long>

int main(){
    long long n, m;
    cin >> n >> m;
    vector<P> ml(m, P(0, 0));
    vector<pair<P, long long>> nl(n, pair<P, long long>(P(0, 0), 0));
    RE(i, 0, n){
        cin >> nl[i].first.first >> nl[i].first.second >> nl[i].second;
    }
    RE(i, 0, m){
        cin >> ml[i].first >> ml[i].second;
    }
    priority_queue<PP, vector<PP>, greater<PP>> ans;
    RE(a, 0, n){
        auto i = nl[a];
        PP like;
        like.second = a;
        like.first = P(LLONG_MAX, LLONG_MAX);
        for(auto j : ml){
            long long dx = i.first.first - j.first;
            long long dy = i.first.second - j.second;
            like.first.first = min(like.first.first, dx * dx + dy * dy);
            like.first.second = i.second;
        }
        ans.push(like);
    }
    RE(i, 0, n){
        cout << ans.top().second+1 << '\n';
        ans.pop();
    }
    return 0;
}