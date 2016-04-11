//
//  Created by TaoSama on 2016-04-08
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct BIT {
    int n, b[N];
    void init(int _n) {
        n = _n;
        memset(b, 0, sizeof b);
    }
    void add(int i, int v) {
        for(; i; i -= i & -i) b[i] += v;
    }
    int sum(int i) {
        int ret = 0;
        for(; i <= n; i += i & -i) ret += b[i];
        return ret;
    }
} bit;

struct Manacher {
    char s[N << 1];
    int n, p[N << 1];
    void init(char* a) {
        s[0] = '@'; s[1] = '#'; n = 2;
        for(int i = 1; a[i]; ++i)
            s[n++] = a[i], s[n++] = '#';
        s[n] = 0;
    }
    int gao() {
        int mx = 0, id, ret = 0;
        for(int i = 1; i < n; ++i) {
            p[i] = mx > i ? min(mx - i, p[2 * id - i]) : 1;
            while(s[i - p[i]] == s[i + p[i]]) ++p[i];
            if(mx < i + p[i]) mx = i + p[i], id = i;
            ret = max(ret, p[i] - 1);
        }
        return ret;
    }
    bool ok(int l, int r) {
        l <<= 1; r <<= 1;
        int k = l + r >> 1;
        return k + p[k] - 1 >= r;
    }
} manacher;

typedef unsigned long long ULL;
const ULL seed[2] = {MOD, MOD + 2};
struct Hash {
    typedef pair<ULL, ULL> Type;
    ULL power[2][N], h[2][N];

    void init(char* a) {
        for(int i = 0; i < 2; ++i) {
            power[i][0] = 1; h[i][0] = 0;
            for(int j = 1; a[j]; ++j) {
                power[i][j] = power[i][j - 1] * seed[i];
                h[i][j] = h[i][j - 1] * seed[i] + a[j];
            }
        }
    }

    Type get(int l, int r) { // [l, r]
        Type ret;
        ret.first = h[0][r] - h[0][l - 1] * power[0][r - l + 1];
        ret.second = h[1][r] - h[1][l - 1] * power[1][r - l + 1];
        return ret;
    }
} hsh;

int n, q;
const int Q = 1e5 + 10;
int ans[Q];
char a[N];
vector<pair<int, int> > qs[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%s", a + 1);
        n = strlen(a + 1);

        hsh.init(a);
        manacher.init(a);
        manacher.gao();

        scanf("%d", &q);
        for(int i = 1; i <= n; ++i) qs[i].clear();
        for(int i = 1; i <= q; ++i) {
            int l, r; scanf("%d%d", &l, &r);
            qs[r].push_back({l, i});
        }

        bit.init(n);
        map<Hash::Type, int> mp;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= i; ++j) {
                if(!manacher.ok(j, i)) continue; //not palindromic
                Hash::Type h = hsh.get(j, i);
                if(mp.count(h)) bit.add(mp[h], -1);
                bit.add(j, 1);
                mp[h] = j;
            }
            for(auto& q : qs[i]) ans[q.second] = bit.sum(q.first);
        }
        for(int i = 1; i <= q; ++i) printf("%d\n", ans[i]);
    }
    return 0;
}
