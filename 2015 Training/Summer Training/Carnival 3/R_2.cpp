//
//  Created by TaoSama on 2015-08-09
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

char s[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s) {
        int k; cin >> k;
        int ans = 0;
        while(k--) {
            char a, b; cin >> a >> b;
            for(int i = 0; s[i]; ++i) {
                int l = 0, r = 0;
                while(s[i] == a || s[i] == b) {
                    if(s[i] == a) ++l;
                    else ++r;
                    ++i;
                }
                ans += min(l, r);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
