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
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, l, ans[N];
struct ACM {
    int a, c, id;
    bool operator< (const ACM& rhs) const {
        return a > rhs.a;
    }
} A[N], B[N];

typedef pair<int, int> P;

bool check(int x) {
    set<P> s;
    int cost = 0;
    for(int i = 1, j = 1; i <= m;) {
        while(j <= n && A[j].a >= B[i].a) s.insert(P(A[j].c, A[j].id)), j++;
        if(!s.size()) return false;
        cost += s.begin()->first;
        if(cost > l) return false;
        int t = x, id = s.begin()->second;
        s.erase(s.begin());
        while(t-- && i <= m) ans[B[i++].id] = id;
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &m, &l) == 3) {
        for(int i = 1; i <= n; ++i) scanf("%d", &A[i].a);
        for(int i = 1; i <= n; ++i) scanf("%d", &A[i].c), A[i].id = i;
        for(int i = 1; i <= m; ++i) scanf("%d", &B[i].a), B[i].id = i;
        sort(A + 1, A + 1 + n);
        sort(B + 1, B + 1 + m);

        int l = 0, r = 1e5;
        while(l <= r) {
            int m = l + r >> 1;
            if(check(m)) r = m - 1;
            else l = m + 1;
        }
        if(check(l)) {
            puts("Good Luck");
            for(int i = 1; i <= m; ++i) printf("%d%c", ans[i], " \n"[i == m]);
        } else puts("Do it yourself");
    }
    return 0;
}
