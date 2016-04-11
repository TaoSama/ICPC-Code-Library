//
//  Created by TaoSama on 2015-04-26
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, a[55], ans;
char t[55], tt[55];
bool used[55];

void dfs(int dep) {
    if(dep == n) {
		bool ok = true;
        for(int i = 0; i < n - 1; ++i) {
            if(tt[i] == tt[i + 1]) {
                ok = false;
                break;
            }
        }
        if(ok) ++ ans;
    }
    for(int i = 0; i < n; ++i) {
        if(!used[i]) {
            used[i] = true;
            tt[dep] = t[i];
            dfs(dep + 1);
            used[i] = false;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    int kase = 0;
    while(T--) {
        cin >> n;
        for(int i = 0; i < n; ++i) {
            char s[5]; cin >> s;
            t[i] = s[0];
        }
        ans = 0;
        dfs(0);
        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}
