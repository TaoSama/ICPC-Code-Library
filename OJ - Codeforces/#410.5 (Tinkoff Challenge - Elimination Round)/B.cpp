//
//  Created by TaoSama on 2017-04-24
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
char s[N][N];
bool f[N][N][4][3];

struct Node {
    int x, y, d, t;
};

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);

        bool ans = false;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(s[i][j] == 'S') {
                    queue<Node> q;
                    memset(f, 0, sizeof f);
                    for(int k = 0; k < 4; ++k) {
                        f[i][j][k][0] = 1;
                        q.push({i, j, k, 0});
                    }
                    while(q.size()) {
                        static const int dir[][2] = {
                            -1, 0, 0, -1, 1, 0, 0, 1
                        };
                        Node u = q.front(); q.pop();
                        if(s[u.x][u.y] == 'T' && u.t <= 2) {
                            ans = true;
                            break;
                        }
                        for(int k = 0; k < 4; ++k) {
                            Node v = u;
                            v.x += dir[k][0], v.y += dir[k][1];
                            if(v.x < 1 || v.x > n || v.y < 1 || v.y > m) continue;
                            if(s[v.x][v.y] == '*') continue;
                            v.d = k; v.t += u.d != k;
                            if(v.t <= 2 && !f[v.x][v.y][v.d][v.t]) {
                                f[v.x][v.y][v.d][v.t] = true;
                                q.push(v);
                            }
                        }
                    }
                }
            }
        }
        puts(ans ? "YES" : "NO");
    }

    return 0;
}
