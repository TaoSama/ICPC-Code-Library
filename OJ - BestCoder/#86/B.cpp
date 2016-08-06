//
//  Created by TaoSama on 2016-08-06
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

int n, a[N];

int get(priority_queue<int>& q, int cur) {
    if(cur == q.top()) {
        q.pop();
        int ret = q.top();
        q.push(cur);
        return ret;
    }
    return q.top();
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        priority_queue<int> q;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            if(i > 1) q.push(abs(a[i] - a[i - 1]));
        }

        long long ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(i == 1) {
                int cur = abs(a[2] - a[1]);
                ans += get(q, cur);
            } else if(i == n) {
                int cur = abs(a[n] - a[n - 1]);
                ans += get(q, cur);
            } else {
                int lft = abs(a[i] - a[i - 1]);
                int rht = abs(a[i + 1] - a[i]);
                if(rht > lft) swap(lft, rht);
                bool f = false, s = false;
                if(lft == q.top()) {
                    q.pop();
                    f = true;
                }
                if(rht == q.top()) {
                    q.pop();
                    s = true;
                }
                int nxt = abs(a[i + 1] - a[i - 1]);
                if(q.size()) nxt = max(q.top(), nxt);
                ans += nxt;
                if(s) q.push(rht);
                if(f) q.push(lft);
            }
        }
        printf("%I64d\n", ans);
    }

    return 0;
}
