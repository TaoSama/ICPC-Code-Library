//
//  Created by TaoSama on 2016-07-21
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

int p[N];
int find(int x) {
    return p[x] = p[x] == x ? x : find(p[x]);
}
bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return false;
    p[x] = y;
    return true;
}

int main() {
#ifdef LOCAL
//    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    vector<pair<int, int> > v;
    int n = 10000;
    srand(time(0));
    printf("%d\n", n);
    for(int i = 1; i <= n; ++i) p[i] = i;
    for(int i = 2; i <= n; ++i) {
        v.push_back({rand() % (i - 1) + 1, i});
    }
    for(auto p : v) printf("%d %d\n", p.first, p.second);
    puts("");
    for(int i = v.size() - 1; ~i; --i) printf("%d %d\n", v[i].second, v[i].first);

#ifdef LOCAL
//    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
