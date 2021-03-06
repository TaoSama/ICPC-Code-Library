//
//  Created by TaoSama on 2016-04-12
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N], k;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        multiset<int> s;
        long long ans = 0;
        for(int l = 1, r = 1; l <= n; ++l) {
            while(r <= n) {
                if(s.size()) {
                    if(a[r] - *s.begin() >= k || *s.rbegin() - a[r] >= k)
                        break;
                }
                s.insert(a[r++]);
            }
            ans += r - l;
            s.erase(s.find(a[l]));
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
