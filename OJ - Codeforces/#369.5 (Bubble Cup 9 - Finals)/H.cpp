//
//  Created by TaoSama on 2016-09-12
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

int n, m;
vector<int> lists[N];
vector<pair<int, int> > hate;
int conf[N * 10], team[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        hate.push_back({u, v});
    }

    int T = -INF;
    for(int i = 1; i <= n; ++i) {
        int k; scanf("%d", &k);
        while(k--) {
            int x; scanf("%d", &x);
            lists[i].push_back(x);
            T = max(T, x);
        }
    }

    srand(12345);
    int ok = false;
    while(!ok) {
        for(int i = 1; i <= T; ++i) conf[i] = rand() & 1;
        for(int i = 1; i <= n; ++i) team[i] = lists[i][rand() % lists[i].size()];

        int hatred = 0;
        for(int i = 0; i < m && !ok; ++i) {
            int u, v; tie(u, v) = hate[i];
            hatred += conf[team[u]] ^ conf[team[v]];
            if(hatred * 2 >= m) ok = true;
        }
    }
    for(int i = 1; i <= n; ++i) printf("%d%c", team[i], " \n"[i == n]);
    for(int i = 1; i <= T; ++i) printf("%d%c", conf[i] + 1, " \n"[i == T]);

    return 0;
}
