//
//
//
//  Created by TaoSama on 2015-03-30
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

struct ACM {
    int id, s, h;
    bool operator<(const ACM& rhs) const {
        return s > rhs.s;
    }
} a[30005];
int m, q;
int mp[1000000], boss[30005], sons[30005];

int findBoss(int x, int pos) {
    if(pos == 0) return 0;
    if(a[pos].h >= a[x].h) return pos;
    return findBoss(x, boss[pos]);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &m, &q);
        for(int i = 1; i <= m; ++i)
            scanf("%d%d%d", &a[i].id, &a[i].s, &a[i].h);
        sort(a + 1, a + 1 + m);
        for(int i = 1; i <= m; ++i) mp[a[i].id] = i;

        for(int i = 1; i <= m; ++i) boss[i] = findBoss(i, i - 1);
//        for(int i = 1; i <= m; ++i) cout<<boss[i]<<' ';
//        cout<<endl;
        memset(sons, 0, sizeof sons);
        for(int i = m; i >= 1; --i) sons[boss[i]] += sons[i] + 1;

        for(int i = 1; i <= q; ++i) {
            int x; scanf("%d", &x);
            printf("%d %d\n", a[boss[mp[x]]].id, sons[mp[x]]);
        }
    }
    return 0;
}
