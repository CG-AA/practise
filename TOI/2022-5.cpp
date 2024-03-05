#include<bits/stdc++.h>
using namespace std;

int n, m, cnt;
pair<int, int> p(-1, -1), rn(0, 0);
vector<vector<bool>> t;
vector<pair<int, int>> ans;
pair<int, int> findnext(){
    for(int i = 0; i < n; i++){
        if(i == p.first) i++;
        for(int j = 0; j < m; j++){
            if(abs(i - p.first) == abs(j - p.second) || j == p.second || t[i][j])continue;
            return pair<int, int>(i, j);
        }
    }
    return pair<int, int>(-1, -1);
}

int main(){
    cin >> n >> m;
    cnt = n*m;
    t.resize(n, vector<bool>(m));
    while(cnt--){
        ans.push_back(rn);
        t[rn.first][rn.second] = 1;
        p = rn;
        rn.first = p.first + 1;
        rn.second = p.second + 2;
        if(rn.first >= n || rn.second >= m || t[rn.first][rn.second]){
            rn = findnext();
            if(rn.first == -1 && cnt){
                cout << "-1";
                return 0;
            }
        }
    }
    for(auto i : ans){
        cout << i.first << ' ' << i.second << endl;
    }
    cout << ans[0].first << ans[0].second;
    return 0;
}