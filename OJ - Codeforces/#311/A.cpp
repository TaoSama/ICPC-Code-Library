//
//  Created by TaoSama on 2015-06-30
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

int n, a[3][2];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int i = 0; i < 3; ++i) for(int j = 0; j < 2; ++j) cin >> a[i][j];
        int sum = a[1][0] + a[2][0];
        bool ok = false;
        int ans[3];
        for(int i = min(n - sum, a[0][1]); i >= a[0][0]; --i) {
            for(int j = min(n - i - a[2][0], a[1][1]); j >= a[1][0]; --j) {
                if(n - i - j >= a[2][0] && n - i - j <= a[2][1]) {
                    ok = true;
                    ans[0] = i; ans[1] = j; ans[2] = n - i - j;
                    break;
                }
            }
            if(ok) break;
        }
        for(int i = 0; i < 3; ++i) cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}
