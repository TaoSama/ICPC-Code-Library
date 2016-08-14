//
//  Created by TaoSama on 2016-08-12
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int a[N], b[N];
vector<int> src[N], des[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i <= n; ++i) src[i].clear(), des[i].clear();
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            src[a[i]].push_back(i);
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%d", b + i);
            des[b[i]].push_back(i);
        }

        bool ok = true;
        vector<int> pos(n + 1);
        for(int i = 0; i <= n && ok; ++i) {
            if(src[i].size() != des[i].size()) ok = false;
            for(int j = 0; j < src[i].size(); ++j)
                pos[src[i][j]] = des[i][j];
        }

        while(m--) {
            int x, y; scanf("%d%d", &x, &y);
            if(!ok) continue;
            sort(pos.begin() + x, pos.begin() + y + 1);
        }

        for(int i = 1; i <= n && ok; ++i) if(pos[i] != i) ok = false;

        puts(ok ? "Yes" : "No");
    }

    return 0;
}
