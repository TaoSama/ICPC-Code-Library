//
//  Created by TaoSama on 2015-09-21
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
#include <stack>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
int l[N], r[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);

        stack<int> s;
        for(int i = 1; i <= n; ++i) {
            while(s.size() && a[s.top()] >= a[i]) s.pop();
            l[i] = s.size() ? s.top() : 0;
            s.push(i);
        }
        while(s.size()) s.pop();
        for(int i = n; i >= 1; --i) {
            while(s.size() && a[s.top()] >= a[i]) s.pop();
            r[i] = s.size() ? s.top() : n + 1;
            s.push(i);
        }

        long long ans = 0;
        for(int i = 1; i <= n; ++i)
            ans = max(ans, 1LL * a[i] * (r[i] - l[i] - 1));
        printf("%lld\n", ans);
    }
    return 0;
}
