//
//  Created by TaoSama on 2015-07-24
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

string s;
int n, cnt, ans, a[N];

void dfs(int k) {
    if(k > 2048 || cnt >= n) return;
    char c = s[cnt++];
    if(c == 'f') a[k] = 1;
    else if(c == 'p') {
        dfs(k * 4 - 2);
        dfs(k * 4 - 1);
        dfs(k * 4);
        dfs(k * 4 + 1);
    }
}

void sum(int k, int dep) {
    if(k > 2048) return;
    if(a[k]) {
//      cout << k << endl;
        ans += 1 << (10 - dep);
        return;
    }
    sum(k * 4 - 2, dep + 2);
    sum(k * 4 - 1, dep + 2);
    sum(k * 4, dep + 2);
    sum(k * 4 + 1, dep + 2);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        memset(a, 0, sizeof a);
        cin >> s;
        cnt = 0; n = s.size();
        dfs(1);
        cin >> s;
        cnt = 0; n = s.size();
        dfs(1);

        ans = 0;
        sum(1, 0);
        cout << "There are " << ans << " black pixels.\n";
    }
    return 0;
}
