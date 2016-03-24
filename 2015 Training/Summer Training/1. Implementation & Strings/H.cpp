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
    map<char, double> mp;
    mp['C'] = 12.01; mp['H'] = 1.008;
    mp['O'] = 16.00; mp['N'] = 14.01;
    while(t--) {
        string s; cin >> s;
        double ans = 0; int cnt = 0;
        bool last = false; char c;
        for(int i = 0; i < s.size(); ++i) {
            if(isalpha(s[i])) {
                if(last) cnt = 1;
                ans += mp[c] * cnt;
                c = s[i];
                cnt = 0;
                last = true;
            } else {
                last = false;
                cnt = cnt * 10 + s[i] - '0';
            }
        }
        if(cnt == 0) cnt = 1;
        ans += mp[c] * cnt;
        cout << fixed << setprecision(3) << ans << '\n';
    }
    return 0;
}
