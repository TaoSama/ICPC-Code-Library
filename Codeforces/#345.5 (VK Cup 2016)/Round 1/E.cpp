//
//  Created by TaoSama on 2016-03-30
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
int n, k, a[N];
LL b, c;

int get(int x) {return (x % 5 + 5) % 5;}
int count(int x) {return (x - get(x)) / 5;}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d%I64d%I64d", &n, &k, &b, &c);
    for(int i = 1; i <= n; ++i) scanf("%d", a + i);
    b = min(b, 5 * c);
    sort(a + 1, a + 1 + n);

    multiset<LL> s[5];
    LL ans = 1e18, cost[5] = {};

    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 5; ++j) {
            int wh = get(a[i] + j);
            int times = count(a[i] + j);
            LL cur = j * c - times * b;

            s[wh].insert(cur);
            cost[wh] += cur;
            if(s[wh].size() > k) {
                cost[wh] -= *s[wh].rbegin();
                s[wh].erase(s[wh].find(*s[wh].rbegin()));
            }

            if(s[wh].size() == k) {
                LL tmp = cost[wh] + times * b * k;
                ans = min(ans, tmp);
            }
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
