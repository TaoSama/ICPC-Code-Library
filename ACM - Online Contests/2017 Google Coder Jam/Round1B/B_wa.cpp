//
//  Created by TaoSama on 2017-04-22
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

const char* code = ".ROYGBV";
int g[10][10];

int get(char c) {return strchr(code, c) - code;}
void addEdge(int u, int v) { g[u][v] = g[v][u] = 1; }

int main() {
#ifdef LOCAL
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    addEdge(get('G'), get('R'));
    addEdge(get('R'), get('Y'));
    addEdge(get('Y'), get('V'));
    addEdge(get('Y'), get('B'));
    addEdge(get('B'), get('O'));
    addEdge(get('B'), get('R'));

    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        int cc[10];
        for(int i = 1; i <= 6; ++i) scanf("%d", cc + i);

        string ans;
        bool ok = true;
        for(int j = 1; j <= 6; ++j) {
            if(cc[j] == 0) continue;

            int cnt[10]; memcpy(cnt, cc, sizeof cc);
            ans.clear();
            --cnt[j]; ans += char('0' + j);

            ok = true;
            for(int i = 2; i <= n && ok; ++i) {
                pair<int, int> mx = {0, 0};
                for(int j = 1; j <= 6; ++j) {
                    if(g[ans.back() - '0'][j] == 0) continue;
                    mx = max(mx, {cnt[j], j});
                }
                if(cnt[mx.second] == 0) {
                    ok = false;
                }
                --cnt[mx.second];
                ans += char('0' + mx.second);
            }
            if(!ok || ans.size() > 1 && ans.front() == ans.back()) {
                ok = false;
                ans = "IMPOSSIBLE";
            } else break;
        }
        if(ok) for(auto& c : ans) c = code[c - '0'];
//        prln(ok);

        static int kase = 0;
        printf("Case #%d: %s\n", ++kase, ans.c_str());
    }

    return 0;
}
