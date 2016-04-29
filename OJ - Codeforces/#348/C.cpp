//
//  Created by TaoSama on 2016-04-25
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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

int n, m, q;
int a[105][105];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &m, &q) == 3) {
        memset(a, 0, sizeof a);
        vector<pair<int, int> > qs;
        while(q--) {
            int op, x, y, z; scanf("%d%d", &op, &x);
            if(op != 3) qs.push_back({op, x});
            else {
                scanf("%d%d", &y, &z);
                for(auto iter = qs.rbegin(); iter != qs.rend(); ++iter) {
                    if(iter->first == 1 && iter->second == x) {
                        if(++y > m) y -= m;
                    } else if(iter->first == 2 && iter->second == y) {
                        if(++x > n) x -= n;
                    }
                }
                a[x][y] = z;
            }
        }
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                printf("%d%c", a[i][j], " \n"[j == m]);
    }
    return 0;
}