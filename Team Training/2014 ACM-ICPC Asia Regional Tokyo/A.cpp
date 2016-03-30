//
//  Created by TaoSama on 2015-12-04
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

int n, m;
int a[20], b[20];

int get() {
    if(accumulate(a + 1, a + 1 + n, 0) != accumulate(b + 1, b + 1 + n, 0))
        return INF;
    int t[20]; memcpy(t, b, sizeof b);
    int ret = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i] == t[i]) continue;
        for(int j = i + 1; j <= n; ++j) {
            if(t[j] == a[i]) {
                while(j > i) {
                    swap(t[j], t[j - 1]);
                    --j; ++ret;
                }
                break;
            }
        }
    }
    return ret;
}

int calc() {
    int ans1 = get();
    for(int i = 1; i <= n; ++i) b[i] ^= 1;
    int ans2 = get();
    return min(ans1, ans2);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        int idx = 1, v = 1;
        while(m--) {
            int x; scanf("%d", &x);
            while(x--) b[idx++] = v;
            v ^= 1;
        }
        printf("%d\n", calc());
    }
    return 0;
}
