//
//  Created by TaoSama on 2015-07-27
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
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char a[10][10][10];

struct P {
    int x, y, step;
    P() {}
    P(int x, int y, int step): x(x), y(y), step(step) {}
};

bool vis[10][10];
bool bfs() {
    queue<P> q;
    memset(vis, false, sizeof vis);
    vis[8][1] = true;
    q.push(P(8, 1, 0));
    while(q.size()) {
        P cur = q.front(), nxt; q.pop();
        if(cur.step > 8 || cur.x == 1 && cur.y == 8) return true;
        for(int i = -1; i <= 1; ++i) {
            for(int j = -1; j <= 1; ++j) {
                int nx = cur.x + i, ny = cur.y + j;
//                cout << nx << ' ' << ny << '\n';
//              pr(nx); pr(ny); prln(cur.step);
                if(nx < 1 || nx > 8 || ny < 1 || ny > 8) continue;
                if(cur.step <= 8 && a[cur.step][nx][ny] == 'S') continue;
                if(cur.step <= 7 && a[cur.step + 1][nx][ny] == 'S') continue;
                q.push(P(nx, ny, cur.step + 1));
            }
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> (a[0][1] + 1)) {
        for(int i = 2; i <= 8; ++i) cin >> (a[0][i] + 1);
        for(int t = 1; t <= 8; ++t) {
            for(int i = 8; i; --i) {
                for(int j = 1; j <= 8; ++j) {
                    a[t][i][j] = a[t - 1][i][j];
                    if(a[t - 1][i][j] == 'S') {
                        a[t][i][j] = '.';
                        if(i + 1 <= 8) a[t][i + 1][j] = 'S';
                    }
                }
            }
        }
        cout << (bfs() ? "WIN" : "LOSE") << '\n';



//        for(int t = 0; t <= 8; ++t) {
//            for(int i = 1; i <= 8; ++i) {
//                for(int j = 1; j <= 8; ++j)
//                    cout << a[t][i][j];
//                cout << endl;
//            }
//            cout << endl;
//        }
//       return 0;
    }
    return 0;
}
