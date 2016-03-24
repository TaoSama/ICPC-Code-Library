//
//  Created by TaoSama on 2015-10-12
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

int n, k, sx;
char a[5][105];
typedef pair<int, int> P;

bool bfs(int sx) {
    queue<P> q; q.push(P(sx, 1));
    while(q.size()) {
        int x = q.front().first, y = q.front().second; q.pop();
        if(isalpha(a[x][++y])) continue;
        if(y >= n) return true;
        for(int i = -1; i <= 1; ++i) {
            int nx = x + i;
            if(nx < 1 || nx > 3) continue;
            if(isalpha(a[nx][y]) || isalpha(a[nx][y + 1])
                    || isalpha(a[nx][y + 2]) || a[nx][y + 2] == 1) continue;
            int ny = y + 2;
//            pr(nx); prln(ny);
            if(ny >= n) return true;
            a[nx][ny] = 1;
            q.push(P(nx, ny));
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        memset(a, 0, sizeof a);
        for(int i = 1; i <= 3; ++i) {
            scanf("%s", a[i] + 1);
            if(a[i][1] == 's') sx = i;
        }
        puts(bfs(sx) ? "YES" : "NO");
    }
    return 0;
}
