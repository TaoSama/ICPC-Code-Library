//
//  Created by TaoSama on 2017-04-03
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

typedef long long LL;
const LL LLINF = 0x3f3f3f3f3f3f3f3fLL;
namespace KDT {
    const int M = 1 << 16, K = 2;
    int D;
    struct Point {
        LL d[K];
        inline LL& operator[](int k) {return d[k];}
        inline const LL& operator[](int k) const {return d[k];}
        inline bool operator<(const Point& p) const {
            return d[D] < p.d[D];
        }
    } a[M];
    struct Node {
        Point key, maxd, mind;
        Node* ch[2];
        int sz;
        inline void up() {
            sz = ch[0]->sz + ch[1]->sz + 1;
            for(int i = 0; i < K; ++i) {
                maxd[i] = max(maxd[i], ch[0]->maxd[i]);
                maxd[i] = max(maxd[i], ch[1]->maxd[i]);
                mind[i] = min(mind[i], ch[0]->mind[i]);
                mind[i] = min(mind[i], ch[1]->mind[i]);
            }
        }
    } pool[M], *ptr, *null, *root;

    inline bool onLine(const Point& p, const Point& q) {
        return 2 * p[0] * q[0] + p[1] + q[1] >= 0;
    }
    inline int h(Node* o, const Point& p) {
        int ret = 0;
        ret += onLine({o->mind[0], o->mind[1]}, p);
        ret += onLine({o->mind[0], o->maxd[1]}, p);
        ret += onLine({o->maxd[0], o->mind[1]}, p);
        ret += onLine({o->maxd[0], o->maxd[1]}, p);
        return ret;
    }

    inline Node* newNode(const Point& p) {
        ptr->key = p;
        ptr->ch[0] = ptr->ch[1] = null;
        for(int i = 0; i < K; ++i)
            ptr->maxd[i] = ptr->mind[i] = ptr->key[i];
        return ptr++;
    }

    void init() {
        ptr = pool;
        null = ptr++;
        null->sz = 0;
        null->ch[0] = null->ch[1] = null;
        for(int i = 0; i < K; ++i) {
            null->mind[i] = LLINF;
            null->maxd[i] = -LLINF;
        }
    }
    void build(Node*& o, int l, int r, int dim) {
        if(l > r) return;
        int m = l + r >> 1;
        D = dim;
        nth_element(a + l, a + m, a + r + 1);
        o = newNode(a[m]);
        build(o->ch[0], l, m - 1, (dim + 1) % K);
        build(o->ch[1], m + 1, r, (dim + 1) % K);
        o->up();
    }
    int query(Node* o, const Point& p) {
        if(o == null) return 0;
        int have = h(o, p);
        if(!have) return 0;
        if(have == 4) return o->sz;

        int ret = onLine(o->key, p);
        ret += query(o->ch[0], p);
        ret += query(o->ch[1], p);
        return ret;
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//    freopen("C:\\Users\\TaoSama\\Desktop\\out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        vector<int> v(n);
        for(int& x : v) scanf("%d", &x);

        int hf = (n + 1) >> 1;
        for(int s = 0; s < 1 << hf; ++s) {
            LL va = 0, vb = 0;
            for(int i = 0; i < hf; ++i) {
                if(s >> i & 1) {
                    va += v[i];
                    vb += 1LL * v[i] * v[i];
                }
            }
            KDT::a[s + 1] = {va, va* va - vb};
        }

        KDT::init();
        KDT::Node*& root = KDT::root;
        KDT::build(root, 1, 1 << hf, 0);

        n >>= 1;
        int ans = 0;
        for(int s = 0; s < 1 << n; ++s) {
            LL va = 0, vb = 0;
            for(int i = 0; i < n; ++i) {
                if(s >> i & 1) {
                    va += v[hf + i];
                    vb += 1LL * v[hf + i] * v[hf + i];
                }
            }
            ans += KDT::query(root, {va, va * va - vb});
        }
        printf("%d\n", ans - 1);
    }

    return 0;
}
