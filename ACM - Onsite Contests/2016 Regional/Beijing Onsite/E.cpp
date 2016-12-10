//
//  Created by TaoSama on 2016-11-13
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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

int d[N][4][3];

struct Sta {
    int x, a, b;
};

int s[5];
void decode(int x) {
    for(int i = 0; i < 5; ++i) {
        s[5 - i - 1] = x % 10;
        x /= 10;
    }
}

int encode() {
    int x = 0;
    for(int i = 0; i < 5; ++i) x = x * 10 + s[i];
    return x;
}

void update(Sta& u, Sta& v, queue<Sta>& q) {
    if(d[v.x][v.a][v.b] == INF) {
        d[v.x][v.a][v.b] = d[u.x][u.a][u.b] + 1;
        q.push(v);
    }
}


void bfs() {
    memset(d, 0x3f, sizeof d);
    queue<Sta> q; q.push({12345, 0, 0});
    d[12345][0][0] = 0;
    decode(12345);
//    for(int i = 0; i < 5; ++i) printf("%d ", s[i]); puts("");
    while(q.size()) {
        Sta u = q.front(), v; q.pop();
        decode(u.x);
        for(int i = 0; i < 5; ++i) {
            if(i + 1 < 5) {
                swap(s[i], s[i + 1]);
                v = u; v.x = encode();
//                printf("%d\n", v.x);
                update(u, v, q);
                swap(s[i], s[i + 1]);
            }
            int o = s[i];
            if(u.a < 3) {
                v = u;  ++v.a;
                if((++s[i]) >= 10) s[i] -= 10;
                v.x = encode();
//               printf("%d\n", v.x);
                update(u, v, q);
                s[i] = o;
            }
            if(u.b < 2) {
                v = u; ++v.b;
                if((s[i] *= 2) >= 10) s[i] -= 10;
                v.x = encode();
//               printf("%d\n", v.x);
                update(u, v, q);
                s[i] = o;
            }
        }
//        break;
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int x; bfs();
    while(scanf("%d", &x) == 1) {
        int ans = INF;
        for(int i = 0; i <= 3; ++i)
            for(int j = 0; j <= 2; ++j)
                ans = min(ans, d[x][i][j]);
        if(ans == INF) ans = -1;
        printf("%d\n", ans);
    }

    return 0;
}
