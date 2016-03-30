//
//  Created by TaoSama on 2016-01-28
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

int n, a[N], b[N];
int to[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        for(int i = 1; i <= n; ++i) scanf("%d", b + i);
        for(int i = 1; i <= n; ++i) to[b[i]] = i;

        int ans = 0;
        vector<pair<int, int> > path;
        for(int i = n; i; --i) {
            int pos = i;
            for(int j = i + 1; j <= to[a[pos]]; ++j) {
                if(to[a[j]] <= pos) {
                    ans += abs(pos - j);
                    path.push_back({pos, j});
                    swap(a[pos], a[j]);
                    pos = j;
                }
            }
        }
        printf("%d\n%d\n", ans, path.size());
        for(auto p : path) printf("%d %d\n", p.first, p.second);
    }
    return 0;
}
