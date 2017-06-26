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

#define y1 sdasdasd
int x1, y1, x2, y2;
int f[205][205][4];
int n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        vector<int> v(n);
        for(int& x : v) cin >> x;
        int same = 1;
        for(int i = 0; i < n; ++i) same &= v[i] == v[0];
        if(same) {
            cout << 0 << endl;
            continue;
        }

        map<deque<int>, int> mp;
        int l = 1, r = n - 1, ans = -1;
        while(l <= r) {
            int k = l + r >> 1;
            deque<int> cur;
            for(int i = 0; i < k - 1; ++i) cur.push_back(v[i]);
            bool ok = true;
            for(int j = k - 1; j + 1 < n; ++j) {
                cur.push_back(v[j]);
                if(mp.count(cur) && v[j + 1] != mp[cur]) {
                    ok = false;
                    break;
                }
                mp[cur] = v[j + 1];
                cur.pop_front();
            }
            if(ok) ans = k, r = k - 1;
            else l = k + 1;
        }
        cout << ans << endl;
    }

    return 0;
}
