//
//  Created by TaoSama on 2016-07-24
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

int n, k, a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    scanf("%d%d", &n, &k);
    map<int, int> mp;
    set<int> s;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        if(i <= k) ++mp[a[i]];
        if(i >= k) {
            if(i == k) {
                for(auto p : mp) if(p.second == 1) s.insert(p.first);
            } else {

                ++mp[a[i]];
                if(mp[a[i]] == 1) s.insert(a[i]);
                else s.erase(a[i]);

                --mp[a[i - k]];
                if(mp[a[i - k]] == 0) s.erase(a[i - k]);
                else if(mp[a[i - k]] == 1) s.insert(a[i - k]);
            }

            if(s.size()) printf("%d\n", *s.rbegin());
            else puts("Nothing");
        }
    }


#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
