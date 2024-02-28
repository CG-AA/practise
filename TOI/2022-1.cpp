//goal O(nr^2)
#include<bits/stdc++.h>

using namespace std;

unordered_map<int, unordered_map<int, int>> umap;
int n, r;

int des(int x, int y, int xp, int yp){
    return pow(x - xp, 2)+pow(y - yp, 2);
}

void mapping(int x, int y){
    for(int i = x-r; i <= x+r; i++){
        for(int j = 0; des(x, y, i, y+j) <= r*r; j++){
            if(j >0)
                umap[i][y+j]++;
            umap[i][y-j]++;
        }
    }
}

int main(){
    int ans = 0;
    cin >> n >> r;
    for(int i = 0; i < n; i++){
        pair<int, int> temp;
        cin >> temp.first >> temp.second;
        mapping(temp.first, temp.second);
    }
    for(auto i : umap){
        for(auto j : i.second){
            if(j.second % 2)
                ans++;
        }
    }

    cout << ans;
}