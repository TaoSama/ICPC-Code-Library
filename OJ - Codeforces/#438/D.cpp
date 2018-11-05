
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;

struct Data {
    static const int M = 17;
    string pre, suf; 
    bitset<1 << (M + 1)> bs;
    
    void add(const string& s) {
        for(int i = 0; i < s.size(); ++i) {
            for(int l = 1; l <= M && i + l - 1 < s.size(); ++l) {
                string sub = s.substr(i, l);
                int mask = 0;
                for(char c : sub) mask = mask << 1 | (c - '0');
                bs[(1 << l) - 2 + mask] = 1;
            }
        }
    }
    void add(const Data& d2) {
        bs |= d2.bs;
        add(suf + d2.pre);

        if(pre.size() < M) pre += d2.pre;
        if(d2.suf.size() < M) suf = suf + d2.suf;
        else suf = d2.suf;
        simplify();
    }
    void simplify() {
        if(pre.size() > M) pre = pre.substr(0, M);
        if(suf.size() > M) suf = suf.substr(suf.size() - M, M);
    }
    int query() {
        for(int i = M; i; --i) {
            int st = (1 << i) - 2, ok = 1;
            for(int j = st; ok && j < st + (1 << i); ++j) 
                ok &= bs[j];
            if(ok) return i;
        }
        return 0;
    }
} a[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n) {
        for(int i = 1; i <= n; ++i) {
            string s; cin >> s;
            a[i].pre = a[i].suf = s;
            a[i].simplify();
            a[i].add(s);
        }
        cin >> q;
        for(int i = n + 1; i <= n + q; ++i) {
            int x, y; cin >> x >> y;
            a[i] = a[x];
            a[i].add(a[y]);
            cout << a[i].query() << '\n';
        }
    }
    return 0;
}
