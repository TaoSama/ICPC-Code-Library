//
//  Created by TaoSama on 2015-07-25
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
int all;
map<long long, int> mp;
//save the number of based node of all the total weight

void dfs(int l, int r, int dep) {
    if(s[l] == '[') {
        int cnt = 0;
        //find the subtree
        for(int i = l + 1; i < r; ++i) {
            if(s[i] == '[') ++cnt;
            if(s[i] == ']') --cnt;
            if(cnt == 0 && s[i] == ',') {
                dfs(l + 1, i - 1, dep + 1);
                dfs(i + 1, r - 1, dep + 1);
            }
        }
    } else { //leaf node
        long long w = 0;
        for(int i = l; i <= r; ++i) w = w * 10 + s[i] - '0';
        ++all; ++mp[w << dep];
        //w << dep := w-based balance's total weight
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> s;
        all = 0; mp.clear();
        dfs(0, s.size() - 1, 0);
        int maxn = -INF;
        for(auto &i : mp) maxn = max(maxn, i.second);
        cout << all - maxn << '\n';
    }
    return 0;
}
