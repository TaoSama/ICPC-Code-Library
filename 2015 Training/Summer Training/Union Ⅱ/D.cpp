//
//  Created by TaoSama on 2015-08-24
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

int n, A, sum;
struct P {
    int hp, atk;
    bool operator<(const P& rhs) const {
        int x = (hp + A - 1) / A * sum + (rhs.hp + A - 1) / A * (sum - atk);
        int y = (rhs.hp + A - 1) / A * sum + (hp + A - 1) / A * (sum - rhs.atk);
//      printf("%d %d %d %d %d\n", hp, rhs.hp, sum, x, y);
        return x < y;
    }
} a[10005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d%d", &n, &A);
        sum = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", &a[i].hp, &a[i].atk);
            sum += a[i].atk;
        }
        sort(a + 1, a + 1 + n);
        long long ans = 0;
        for(int i = 1; i <= n; ++i) {
//          printf("%d %d\n", a[i].hp, a[i].atk);
            ans += (a[i].hp + A - 1) / A * sum;
            sum -= a[i].atk;
        }
        printf("Case #%d: %I64d\n", ++kase, ans);
    }
    return 0;
}
