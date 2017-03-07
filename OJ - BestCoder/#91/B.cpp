//
//  Created by TaoSama on 2017-01-21
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

int n;
int a[N], b[N], c[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        vector<pair<pair<int, int>, int> > v;
        long long ans = 0, sum = 0;
        for(int i = 1; i <= n; ++i) {
            int l, r; scanf("%d%d", &l, &r);
            scanf("%d%d%d", a + i, b + i, c + i);
            v.push_back(make_pair(make_pair(l, 1), i));
            v.push_back(make_pair(make_pair(r + 1, -1), i));
            sum += c[i];
        }

        sort(v.begin(), v.end());
        int lastP = -1, lastD = -1;
//        prln(sum);
        for(int i = 0; i < v.size(); ++i) {
            int p = v[i].first.first, d = v[i].first.second;
            int id = v[i].second;
            if(lastP != p || lastD != d) ans = max(ans, sum);
            if(d == 1) {
                sum -= c[id];
                sum += a[id];
            } else {
                sum -= a[id];
                sum += b[id];
            }
//          pr(p); pr(d); pr(id); prln(sum);
            lastP = p;
            lastD = d;

        }
        ans = max(ans, sum);
        printf("%I64d\n", ans);
    }

    return 0;
}
