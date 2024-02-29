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
    int cul = 'F' - 'A', cur = 'J' - 'A', ans = 0;
    cin >> in;
    for(int i = 0; i < in.size(); i++){
        in[i] -= 'A';
    }
}
/*This block of code is the core part of the dynamic programming solution in the `work()` function.

Here's a breakdown of what it does:

1. It iterates over all possible states `dp[i][j][k]` where `i` is the current character in the string, `j` is the position of the left finger, and `k` is the position of the right finger. 

2. If the current state `dp[i][j][k]` is not `INF` (which means it's reachable), it tries to transition to the next state.

3. The next character to type is `nxt = in[i+1]`.

4. It considers two possible transitions:

   - Move the left finger from `j` to `nxt` and keep the right finger at `k`. The distance for this move is `dp[i][j][k] + dis[j][nxt]`. If this is less than the current minimum distance to reach `dp[i+1][nxt][k]`, it updates the minimum distance.
   
   - Move the right finger from `k` to `nxt` and keep the left finger at `j`. The distance for this move is `dp[i][j][k] + dis[k][nxt]`. If this is less than the current minimum distance to reach `dp[i+1][j][nxt]`, it updates the minimum distance.

This way, it calculates the minimum distance to type each character in the string, considering all possible positions of the left and right fingers.*/