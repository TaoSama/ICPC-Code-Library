
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char s[55][55];
int d[][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, m; 
    while(cin >> n >> m) {
        int sx = -1, sy = -1;
        for(int i = 1; i <= n; ++i) {
            cin >> (s[i] + 1);
            for(int j = 1; j <= m; ++j) {
                if(s[i][j] == 'S') sx = i, sy = j;
            }
        }
        string str; cin >> str;
        int c[4] = {0, 1, 2, 3};
        int ans = 0;
        do {
           bool ok = false;
           int nx = sx, ny = sy;
           for(char x : str) {
                int idx = c[x - '0'];
                nx += d[idx][0];
                ny += d[idx][1];
                if(nx < 1 || nx > n || ny < 1 || ny > m || s[nx][ny] == '#') break;
                if(s[nx][ny] == 'E') {ok = true; break;}
           }
           ans += ok;
        }while(next_permutation(c, c + 4));
        cout << ans << endl;
    }
    return 0;
}
