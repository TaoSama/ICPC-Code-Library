//
//  Created by TaoSama on 2017-02-27
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
struct Node {
    int l, r, d;
    bool operator<(const Node& r) const {
        return d > r.d;
    }
    void see() {
        pr(l); pr(r); prln(d);
    }
};

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        vector<Node> a, b;
        a.reserve(n); b.reserve(m);
        for(int i = 1; i <= n; ++i) {
            int l, r; scanf("%d%d", &l, &r);
            if(a.size() && a.back().r + 1 == l)
                a.back().r = r;
            else a.push_back({l, r, 0});
        }
        for(int i = 1; i <= m; ++i) {
            int l, r, d; scanf("%d%d%d", &l, &r, &d);
            b.push_back({l, r, d});
        }
        b.push_back({INF, -1, -1});
        sort(b.begin(), b.end(), [](const Node & a, const Node & b) {
            return a.l < b.l;
        });

        int ans = 0;
        priority_queue<Node> q;
        for(int i = 0, j = 0; i < a.size(); ++i) {
            int cur = a[i].l;
            for(; cur <= a[i].r;) {
                for(; b[j].l <= cur; ++j) q.push(b[j]); //insert
                while(q.size() && q.top().r - q.top().d + 1 < cur) q.pop(); //delete
                if(!q.size()) {cur = b[j].l; continue;}

                Node tp = q.top();
                int r = min(a[i].r, tp.r);
                int cnt = (min(r, b[j].l - 1) - cur + 1) / tp.d;
                ans += cnt;
                cur += cnt * tp.d;
                if(!cnt) {
                    int nxt = cur + tp.d - 1;
                    if(nxt <= r) q.push({b[j].l, nxt, nxt - b[j].l + 1});
                    cur = b[j].l;
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
