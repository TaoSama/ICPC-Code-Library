//
//  Created by TaoSama on 2015-07-27
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

string s, ans;
int p, Max;

void dfs(string u) {
    if(u.size() > p || s.size() / u.size() <= Max ||
            u.size() > s.size()) return;
    int cnt = 0;
    for(int i = 0; i <= s.size() - u.size(); ++i) {
        bool ok = true;
        for(int j = 0; j < u.size(); ++j) {
            if(s[i + j] != u[j]) {
                ok = false;
                break;
            }
        }
        if(ok) cnt++;
        i += u.size() - 1;
    }
    if(cnt > Max) Max = cnt, ans = u;
    dfs(u + "4");
    dfs(u + "7");
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s) {
        Max = p = 0;
        ans.clear();
        for(int i = 0; i < s.size(); ++i)
            if(s[i] == '4' || s[i] == '7') ++p;
        dfs("4");
//        cout << ans << ' ' << Max << endl;
        dfs("7");
//        cout << ans << ' ' << Max << endl;

        if(ans.size() == 0) ans = "-1";
        cout << ans << '\n';
    }
    return 0;
}
