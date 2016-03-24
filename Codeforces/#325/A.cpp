//
//  Created by TaoSama on 2015-10-12
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

int n, a[105];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int i = 1; i <= n; ++i) cin >> a[i];
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(a[i] == 0) continue;
            bool in = true;
            for(; i <= n; ++i) {
                if(a[i]) in = true, ++ans;
                else {
                    if(in) {
                        if(i + 1 <= n && a[i + 1]) ++ans;
                        else in = false;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
