//
//  Created by TaoSama on 2015-11-06
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
const int N = 3e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int B = 1024;

int n, q, u, a[N];

vector<int> b[505];

void update(int l, int r, int v, int p) {
    int i = l, j = r, cnt = 0;
    while(i <= j && i % B) if(a[i++] < v) ++cnt;
    while(i <= j && (j + 1) % B) if(a[j--] < v) ++cnt;
    while(i <= j) {
        int o = i / B;
        cnt += lower_bound(b[o].begin(), b[o].end(), v) - b[o].begin();
        i += B;
    }

    a[p] = 1LL * u * cnt / (r - l + 1);
    int wh = p / B;
    for(int i = 0; i < b[wh].size(); ++i)
        b[wh][i] = a[wh * B + i];
    sort(b[wh].begin(), b[wh].end());
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &q, &u) == 3) {
        for(int i = 0; i <= n / B; ++i) b[i].clear();
        for(int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            b[i / B].push_back(a[i]);
        }
        for(int i = 0; i < n / B; ++i) sort(b[i].begin(), b[i].end());

        while(q--) {
            int l, r, v, p; scanf("%d%d%d%d", &l, &r, &v, &p);
            update(l - 1, r - 1, v, p - 1);
        }
        for(int i = 0; i < n; ++i) printf("%d\n", a[i]);
    }
    return 0;
}
