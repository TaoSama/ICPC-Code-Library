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

int n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> n;
        queue<string> q; set<string> s;
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            string a, b; cin >> a >> b;
            if(a == "in") {
                ++ans;
                q.push(b);
            } else {
                while(q.size() && s.count(q.front())) {
                    q.pop();
                }
                if(q.size() && q.front() != b) {
                    --ans;
                    s.insert(b);
                } else {
                    q.pop();
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
