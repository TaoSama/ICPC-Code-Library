//
//  Created by TaoSama on 2015-10-30
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

int n;
string s[15];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> s[i];
        string ans;
        for(int sz = 60; sz >= 3; --sz) {
            for(int st = 0; st + sz - 1 < 60; ++st) {
                bool ok = true;
                string cur = s[1].substr(st, sz);
                for(int i = 2; i <= n; ++i) {
                    if(s[i].find(cur) == string::npos) {
                        ok = false;
                        break;
                    }
                }
                if(!ok) continue;
                if(!ans.size() || cur < ans) ans = cur;
            }
            if(ans.size()) break;
        }
        if(ans.size()) cout << ans << '\n';
        else cout << "no significant commonalities\n";
    }
    return 0;
}
