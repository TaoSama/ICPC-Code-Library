//
//  Created by TaoSama on 2015-07-25
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 105, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, k;
int token[N], send[N][N], recv[N][N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(cin >> n && n) {
        memset(send, 0, sizeof send);
        memset(recv, 0, sizeof recv);
        for(int i = 1; i <= n; ++i) cin >> token[i];
        cin >> m;
        for(int i = 1; i <= m; ++i) {
            int x;
            while(cin >> x && x) {
                if(x < 0) send[i][-x]++;
                else recv[i][x]++;
            }
        }

//      for(int i = 1; i <= m; ++i){
//          for(int j = 1; j <= n; ++j){
//              printf("send[%d][%d] = %d", i, j, send[i][j]); cout << endl;
//              printf("recv[%d][%d] = %d", i, j, recv[i][j]); cout << endl;
//          }
//      }

        //transition
        cin >> k;
        bool live = true;
        int cnt = 0;
        while(live) {
            //each transition
            live = false;
            for(int i = 1; i <= m; ++i) {
                bool can = true;
                for(int j = 1; j <= n; ++j) { //check validation
                    if(token[j] < send[i][j]) {
                        can = false;
                        break;
                    }
                }
                if(can) {
                    live = true;
                    for(int j = 1; j <= n; ++j) { //transiting
//                      pr(send[i][j]); prln(recv[i][j]);
                        token[j] -= send[i][j];
                        token[j] += recv[i][j];
                    }
//                  prln(i);
//                  for(int j = 1; j <= n; ++j) cout << token[j] << ' '; cout << endl;
                    break;
                }
            }
            if(live && ++cnt >= k) break;
        }

        cout << "Case " << ++kase << ": ";
        if(cnt >= k) cout << "still live after " << k << " transitions\n";
        else cout << "dead after " << cnt << " transitions\n";
        cout << "Places with tokens:";
        for(int i = 1; i <= n; ++i)
            if(token[i]) cout << " " << i << " (" << token[i] << ")";
        cout << "\n\n";
    }
    return 0;
}
