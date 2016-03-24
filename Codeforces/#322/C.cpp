//
//  Created by TaoSama on 2015-09-28
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

int n, k, a[N];

struct cmp {
    bool operator()(const int& x, const int& y) const {
        return x % 10 < y % 10;
    }
};

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2) {
        int ans = 0;
        priority_queue<int, vector<int>, cmp> pq;
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            ans += x / 10;
            if(x != 100) pq.push(x);
        }
        while(k > 0 && pq.size()) {
            int x = pq.top(); pq.pop();
//          printf("%d %d\n", x, k);
            k -= 10 - x % 10;
            x += 10 - x % 10;
            if(k >= 0) ++ans;
            if(x != 100) pq.push(x);
        }
        printf("%d\n", ans);
    }
    return 0;
}
