//
//  Created by TaoSama on 2015-09-12
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

int n, m, c;
char a[5005][5005];
typedef pair<int, int> P;
vector<P> p;
int sx, sy, tx, ty;
map<P, int> dp;

int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};
set<P> in;

int spfa() {
    queue<P> q; q.push(P(sx, sy));
    dp.clear();  in.clear();
    dp[P(sx, sy)] = 0;
    in.insert(P(sx, sy));
    while(q.size()) {
        P cur = q.front(), nxt; q.pop();
        in.erase(cur);
        for(int i = 0; i < 4; ++i) {
            int nx = cur.first + d[i][0], ny = cur.second + d[i][1];
            if(nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == '#') continue;
            nxt = make_pair(nx, ny);
            if(!dp.count(nxt)) dp[nxt] = INF;
            if(dp[nxt] > dp[cur] + (a[nx][ny] == '*' ? c : 0)) {
                dp[nxt] = dp[cur] + (a[nx][ny] == '*' ? c : 0);
                if(!in.count(nxt)) in.insert(nxt), q.push(nxt);
            }
        }
        if(a[cur.first][cur.second] != 'P') continue;
        for(int i = 0; i < p.size(); ++i) {
            nxt = p[i];
            if(nxt == cur) continue;
            if(!dp.count(nxt)) dp[nxt] = INF;
            if(dp[nxt] > dp[cur]) {
                dp[nxt] = dp[cur];
                if(!in.count(nxt)) in.insert(nxt), q.push(nxt);
            }
        }
    }
    P t = make_pair(tx, ty);
    return dp.count(t) ? dp[t] : -1;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &m, &c) == 3) {
        p.clear();
        for(int i = 1; i <= n; ++i) {
            scanf("%s", a[i] + 1);
            for(int j = 1; j <= m; ++j)
                if(a[i][j] == 'P') p.push_back(P(i, j));
                else if(a[i][j] == 'Y') sx = i, sy = j;
                else if(a[i][j] == 'C') tx = i, ty = j;
        }
//        printf("sx: %d sy: %d\n", sx, sy);
//        printf("tx: %d ty: %d\n", tx, ty);
        int ans = spfa();
        if(ans == -1) puts("Damn teoy!");
        else printf("%d\n", ans);
    }
    return 0;
}
