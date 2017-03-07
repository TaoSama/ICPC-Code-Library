//
//  Created by TaoSama on 2017-01-16
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
string s[N], t[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m) {
        int same = 0;
        for(int i = 1; i <= n; ++i) cin >> s[i];
        for(int i = 1; i <= m; ++i) {
            cin >> t[i];
            for(int j = 1; j <= n; ++j) {
                if(t[i] == s[j]) {
                    ++same;
                    break;
                }
            }
        }
        int a = (same + 1) / 2 + n - same;
        int b = (same) / 2 + m - same;
//        pr(a); prln(b);
        cout << (a > b ? "YES" : "NO") << endl;
    }

    return 0;
}
