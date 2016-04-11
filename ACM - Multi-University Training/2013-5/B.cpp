//
//  Created by TaoSama on 2016-03-12
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 2e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char s[N], t[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s", s) == 1) {
        vector<pair<char, int> > trans;
        for(int i = 0; s[i]; ++i) trans.push_back({s[i], i});
        sort(trans.begin(), trans.end());
        int cur = 0;
        for(int i = 0; i < trans.size(); ++i) {
            s[i] = trans[cur].first;
            cur = trans[cur].second;
        }
        vector<int> nxt(N);
        int q; scanf("%d", &q);
        while(q--) {
            scanf("%s", t);
            nxt[0] = -1;
            int i = 0, j = -1;
            while(t[i]) {
                if(j == -1 || t[i] == t[j]) nxt[++i] = ++j;
                else j = nxt[j];
            }
            i = j = 0;
            bool ok = false;
            while(s[i]) {
                if(j == -1 || s[i] == t[j]) ++i, ++j;
                else j = nxt[j];
                if(j > 0 && !t[j]) {ok = true; break;}
            }
            puts(ok ? "YES" : "NO");
        }
    }
    return 0;
}
