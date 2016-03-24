//
//  Created by TaoSama on 2015-09-27
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

long long d, s1, s2;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%I64d%I64d%I64d", &d, &s1, &s2);
        int n = __builtin_popcountll(d);
        int cnt = 0;
        for(int i = 0; i < 32; ++i) {
            if(d >> i & 1LL) ++cnt;
            else {
                long long ans = d, have = n - cnt + 1;
                ans |= 1LL << i;
                bool ok = false;
                for(int j = 0; j < i; ++j) {
                    if(have < s1) {
                        ans |= 1LL << j;
                        if(++have == s1) ok = true;
                    } else {
                        ok = true;
                        ans &= ~(1LL << j);
                    }
                }
                int tmp = __builtin_popcountll(ans);
                ok = tmp >= s1 && tmp <= s2;
                if(ok) {
                    printf("Case #%d: %I64d\n", ++kase, ans);
                    break;
                }
            }
        }
    }
    return 0;
}
