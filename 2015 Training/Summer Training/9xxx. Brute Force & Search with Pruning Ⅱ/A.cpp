//
//  Created by TaoSama on 2015-07-28
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

long long V, s1, v1, s2, v2;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    int kase = 0;
    while(t--) {
        cin >> V >> s1 >> v1 >> s2 >> v2;
        long long ans = 0;
        if(s1 < s2) swap(s1, s2), swap(v1, v2);
        if(s1 * s1 >= V) {
            for(int i = 0; i <= V / s1; ++i) {
                ans = max(ans, i * v1 + (V - i * s1) / s2 * v2);
            }
        } else {
            if(s2 * v1 < s1 * v2) swap(s1, s2), swap(v1, v2);
            //s2 * v1 >= s1 * v2 := v2 can buy at most s1
            for(int i = 0; i <= s1; ++i) {
                ans = max(ans, i * v2 + (V - i * s2) / s1 * v1);
            }
        }
        cout << "Case #" << ++kase << ": " << ans << '\n';
    }
    return 0;
}
