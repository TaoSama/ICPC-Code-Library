//
//  Created by TaoSama on 2016-03-31
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

int n, m;
vector<pair<int, string> > G[N / 10];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        char name[100]; int x, y; scanf("%s%d%d", name, &x, &y);
        G[x].push_back({ -y, name});
    }
    for(int i = 1; i <= m; ++i) sort(G[i].begin(), G[i].end());
    for(int i = 1; i <= m; ++i) {
        if(G[i].size() > 2 && G[i][2].first == G[i][1].first) puts("?");
        else printf("%s %s\n", G[i][0].second.c_str(), G[i][1].second.c_str());
    }
    return 0;
}
