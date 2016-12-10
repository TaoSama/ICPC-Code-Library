//
//  Created by TaoSama on 2016-10-29
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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

set<string> s;
vector<int> digit(10, 0), d(10);
vector<string> v;

int ans;

vector<string> path;
void dfs(int u, int cur) {
    if(u == 22 || accumulate(d.begin(), d.end(), 0) == 0) {
        if(cur + 15 <= ans) return;
        vector<int> g = d;
        for(int i = 22; i < v.size(); ++i) {
            bool ok = true;
            for(int i = 0; i < 3; ++i) ok &= --g[v[u][i] - '0'] >= 0;
            cur += ok;
            if(!ok) for(int i = 0; i < 3; ++i) ++g[v[u][i] - '0'];
        }
        ans = max(ans, cur);
        return;
    }
    bool ok = true;
    for(int i = 0; i < 3; ++i) ok &= --d[v[u][i] - '0'] >= 0;
    if(ok) dfs(u + 1, cur + 1);
    for(int i = 0; i < 3; ++i) ++d[v[u][i] - '0'];
    dfs(u + 1, cur);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    for(int i = 2; i <= 9; ++i) {
        for(int j = 2; j <= 9; ++j) {
            if(i + j <= 9) {
                char buf[5];
                sprintf(buf, "%d%d%d", i, j, i + j);
                if(!s.count(buf)) {
                    s.insert(buf);
                    ++digit[i]; ++digit[j]; ++digit[i + j];
                }
            }
        }
    }
    for(int i = 1; i <= 8; ++i) {
        char buf[5];
        sprintf(buf, "%d%d%d", 1, i, 1 + i);
        if(!s.count(buf)) {
            s.insert(buf);
            ++digit[i]; ++digit[1]; ++digit[i + 1];
        }
        sprintf(buf, "%d%d%d", i, 1, 1 + i);
        if(!s.count(buf)) {
            s.insert(buf);
            ++digit[i]; ++digit[1]; ++digit[i + 1];
        }
    }
    v = vector<string>(s.begin(), s.end());
//  cout << s.size() << endl;
//  for(int i = 1; i <= 9; ++i) cout << digit[i] << ' ';cout << endl;

    int maxAns = v.size();

    int t; scanf("%d", &t);
    while(t--) {
        bool ok = true;
        for(int i = 1; i <= 9; ++i) {
            scanf("%d", &d[i]);
            ok &= d[i] >= digit[i];
        }

        static int kase = 0;
        printf("Case #%d: ", ++kase);
        if(ok) {printf("%d\n", maxAns); continue;}

        ans = 0;
        dfs(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}
