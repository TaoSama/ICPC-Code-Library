//
//  Created by TaoSama on 2017-02-14
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

int n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        vector<int> v(n);
        for(int i = 0; i < n; ++i) scanf("%d", &v[i]);

        long long ans = 0;
        while(v[0] != 0) {
            if(v[0] != 1) {
                ++ans;
                int ft = v.front();
                v.erase(v.begin());
                v.insert(v.begin() + ft, ft);
            } else {
                int p = -1;
                for(int i = 0; i < n && !~p; ++i)
                    if(v[i] != i + 1) p = i;
                ans += (1LL << p) - 1;
                int b = v[p];
                v.erase(v.begin() + p);
                v.insert(v.begin(), b);
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}
