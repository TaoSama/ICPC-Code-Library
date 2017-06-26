//
//  Created by TaoSama on 2017-06-04
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

string s;
int x, y;
string ans;
bool dfs(int i, int e) {
    if(i == s.size()) {
        return true;
    }
    int to = e ? s[i] - '0' : 9;
    for(int d = to; ~d; --d) {
        if(d == x || d == y || (i == 0 && d == 0)) {
            ans += char('0' + d);
            if(dfs(i + 1, e && d == to)) return true;
            ans.pop_back();
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TsaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s >> x >> y) {
        ans.clear();
        int ret = dfs(0, 1);
        if(!ret) cout << -1 << endl;
        else {
            if(ans.front() == '0') {
                ans.erase(0, 1);
                if(!ans.size()) ans = "-1";
            }
            cout << ans << endl;
        }
    }

    return 0;
}
