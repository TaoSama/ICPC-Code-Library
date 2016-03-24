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

int n, m;
string s[1005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) cin >> s[i];

        int cnt = 0; string ans(m, ' ');
        for(int i = 0; i < m; ++i) {
            map<char, int> mp;
            for(int j = 1; j <= n; ++j) {
                char c = s[j][i];
//              cout << c;
                if(!mp.count(c)) mp[c] = 1;
                else mp[c]++;
            }
//          cout << endl;
            int now = 0;
            for(auto &k : mp) {
                if(k.second > now) {
                    now = k.second;
                    ans[i] = k.first;
                }
            }
            cnt += (n - now);
        }
        cout << ans << '\n' << cnt << '\n';
    }
    return 0;
}
