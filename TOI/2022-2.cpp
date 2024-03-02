#include<bits/stdc++.h>

using namespace std;
#define REP(var, start, end) for(int var = start; var < end; var++)

vector<string> keyb = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
vector<vector<int>> dis;

void init(){
    REP(i0, 0, 3)REP(j0, 0, keyb[i0].size())REP(i1, 0, 3)REP(j1, 0, keyb[i1].size()){
        int Td;
        if(i0 > i1 && j0 > j1 || i1 > i0 && j1 > j0){
            Td = max(abs(i0 - i1), abs(j0 - j1));
        }else{
            Td = abs(i0 - i1) + abs(j0 - j1);
        }
        dis[dis[i0][j0] - 'A'][dis[i1][j1] - 'A'] = Td;
    }
}

int main() {
    init();
    string in;
    int dl = 'F' - 'A', dr = 'J' - 'A', ans = 0;
    cin >> in;
    for(int i = 0; i < in.size(); i++){
        in[i] -= 'A';
    }
    vector<vector<vector<int>>> dp(in.size()+1, vector<vector<int>>(26, vector<int>(26)));
    REP(i, 0, in.size()+1)REP(j, 0, 26)REP(k, 0, 26){
        dp[i][j][k] = -1;
    }
    dp[0][dl][dr] = 0;
    REP(i, 0, in.size())REP(L, 0, 26)REP(R, 0, 26){
        int C = in[i];
        if(dp[i][L][R] != -1){
            dp[i+1][L][C] = min(dp[i+1][L][C], dp[i][L][R] + dis[R][C]);
            dp[i+1][C][R] = min(dp[i+1][C][R], dp[i][L][R] + dis[L][C]);
        }
    }

}
