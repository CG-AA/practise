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