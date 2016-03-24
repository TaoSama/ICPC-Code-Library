//
//  Created by TaoSama on 2015-08-01
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
string s[1005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n && n) {
        for(int i = 1; i <= n; ++i) cin >> s[i];
        sort(s + 1, s + 1 + n);

        string& u = s[n >> 1], &v = s[(n >> 1) + 1];
//        string ans = string(1, u[0]);
//        if(v.size() > 1 && u[0] < v[0]) ans[0]++;
//        if(ans >= u && ans < v) {
//            cout << ans << '\n';
//            continue;
//        }
//        for(int i = 1; i < u.size(); ++i) {
//          cout << s[m][i] << ' ' << s[m + 1][i] << '\n';
//            if(u[i] == v[i] || u[i] + 1 == v[i] || u[i] == 'Z') ans += u[i];
//            else {
//                ans += char(u[i] + (i != u.size() - 1));
//                break;
//            }
//            if(i == v.size()) break;
//        }
        string ans, tmp;
        int cur = 0;
        bool ok = false;
        while(true) {
            for(int i = 0; i < 26; ++i) {
                tmp = ans;
                tmp.push_back('A' + i);
                if(tmp >= u && tmp < v) {
                    ans = tmp;
                    ok = true;
                    break;
                }
            }
            if(ok) break;
            ans.push_back(u[cur++]);
        }
        cout << ans << '\n';
    }
    return 0;
}

/*
2
AAAZAAA
AAB
2
AAA
AAB
2
AAA
AAB
2
NM
OM
0

AAAZB
AAA
AAA
O
*/
