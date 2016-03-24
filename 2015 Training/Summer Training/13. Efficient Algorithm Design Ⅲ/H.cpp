//
//  Created by TaoSama on 2015-08-03
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

int n, a[1005], b[1005];

int calc(int *a) {
    int ret = 0;
    memcpy(b, a, n * sizeof(int));
//    for(int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl;
    for(int i = 0; i < n; ++i) {
        if(b[i] != i + 1) {
            ret++;
            for(int j = i + 1; j < n; ++j) {
                if(b[j] == i + 1) {
                    swap(b[i], b[j]);
                    break;
                }
            }
        }
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n && n) {
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            a[i + n] = a[i];
        }

        int ans = INF;
        for(int i = 1; i <= n; ++i)
            ans = min(ans, calc(a + i));
        reverse(a + 1, a + 2 * n + 1);
        for(int i = 1; i <= n; ++i)
            ans = min(ans, calc(a + i));
        cout << ans << '\n';
    }
    return 0;
}
