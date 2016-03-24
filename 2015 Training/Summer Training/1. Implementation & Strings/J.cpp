//
//  Created by TaoSama on 2015-07-18
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

int t;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> t;
    while(t--) {
        string s; cin >> s;
        int n = s.size(), ans = n;
        for(int i = 0; i < n - 1; ++i) {
            int now = i + 1;
            if(n % now != 0) continue;
            bool ok = true;
//            prln(now);
            for(int j = now, k = 0; j < n; ++j, k = (k + 1) % now) {
//              pr(s[j]); prln(s[k]);
                if(s[j] != s[k]) {
                    ok = false;
                    break;
                }
            }
//            cout << endl;
            if(ok) {ans = now; break;}
        }
        cout << ans << '\n';
        if(t) cout << '\n';
    }
    return 0;
}
