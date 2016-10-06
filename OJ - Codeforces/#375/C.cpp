//
//  Created by TaoSama on 2016-10-03
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

int n, m;
int a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m) {
        for(int i = 1; i <= n; ++i) cin >> a[i];
        int avg = n / m;

        map<int, int> mp;
        for(int i = 1; i <= n; ++i) ++mp[a[i]];

        int ans = 0;
        int lft = avg + n % m;
        for(int i = 1; i <= n; ++i) {
            int& cur = mp[a[i]];
            if(a[i] > m) {
                for(int x = 1; x <= m; ++x) {
                    if(mp[x] < avg) {
                        ++mp[x];
                        a[i] = x;
                        ++ans;
                        break;
                    }
                }
            } else {
                if(cur > avg) {
                    for(int x = 1; x <= m; ++x) {
                        if(mp[x] < avg) {
                            ++mp[x];
                            --cur;
                            ++ans;
//                            printf("%d %d -> %d\n", i, a[i], x);
                            a[i] = x;
                            break;
                        }
                    }
                }
            }

        }

        cout << avg << ' ' << ans << endl;
        for(int i = 1; i <= n; ++i) cout << a[i] << ' '; cout << endl;
    }
    return 0;
}
