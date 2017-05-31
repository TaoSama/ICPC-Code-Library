//
//  Created by TaoSama on 2017-05-06
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, d, q;
typedef long long LL;
LL ans[N], sum;

namespace KDT {
    const int M = 2e5 + 10, K = 2;
    struct Point {
        int d[K], id;
        void read() {
            for(int i = 0; i < K; ++i) scanf("%d", d + i);
        }
        void write() {
            for(int i = 0; i < K; ++i) printf("%d%c", d[i], " \n"[i + 1 == K]);
        }
        bool operator==(const Point& p) const {
            return id == p.id;
        }
        int& operator[](int k) {return d[k];}
        const int& operator[](int k) const {return d[k];}
    } a[M], b[M];
    int D;
    bool cmp(const Point& p, const Point& q) {
        if(p[D] != q[D]) return p[D] < q[D];
        return p.id < q.id;
    };

    struct Node {
        Point key, maxd, mind;
        int sz;
        bool exist;
        Node* ch[2];
        inline void up() {
            sz = ch[0]->sz + ch[1]->sz + exist;
            for(int i = 0; i < K; ++i) {
                maxd[i] = max(ch[0]->maxd[i], ch[1]->maxd[i]);
                mind[i] = min(ch[0]->mind[i], ch[1]->mind[i]);
            }
            if(!exist) return;
            for(int i = 0; i < K; ++i) {
                maxd[i] = max(maxd[i], key[i]);
                mind[i] = min(mind[i], key[i]);
            }
        }
    } pool[M], *ptr, *null, *root;

    inline Node* newNode(const Point& p) {
        ptr->key = p;
        ptr->sz = ptr->exist = 0;
        ptr->ch[0] = ptr->ch[1] = null;
        return ptr++;
    }
    void init() {
        ptr = pool;
        null = ptr++;
        null->key = Point();
        null->sz = 0;
        null->ch[0] = null->ch[1] = null;
        for(int i = 0; i < K; ++i) {
            null->mind[i] = INF;
            null->maxd[i] = -INF;
        }
    }

    inline int dist(Point& p, Point& q) {
        int ret = 0;
        for(int i = 0; i < K; ++i) ret += abs(p[i] - q[i]);
        return ret;
    }
    inline int h(Node* o, Point& p) {
        int ret = 0;
        for(int i = 0; i < K; ++i) {
            if(o->mind[i] > p[i]) ret += o->mind[i] - p[i];
            else if(p[i] > o->maxd[i]) ret += p[i] - o->maxd[i];
        }
        return ret;
    }

    void build(Node*& o, int l, int r, int dim) {
        if(l > r) return;
        int m = l + r >> 1;
        D = dim;
        nth_element(a + l, a + m, a + r + 1, cmp);
        o = newNode(a[m]);
        build(o->ch[0], l, m - 1, (dim + 1) % K);
        build(o->ch[1], m + 1, r, (dim + 1) % K);
        o->up();
    }
    void insert(Node*& o, const Point& p, int v, int dim) {
        if(o->key == p) {
            o->exist = v;
            o->up();
            return;
        }
        D = dim;
        if(cmp(p, o->key)) insert(o->ch[0], p, v, (dim + 1) % K);
        else insert(o->ch[1], p, v, (dim + 1) % K);
        o->up();
    }
    int query(Node* o, const Point& p) {
        if(o == null) return 0;
        if(o->maxd[0] < p[0] - d || o->mind[0] > p[0] + d ||
                o->maxd[1] < p[1] - d || o->mind[1] > p[1] + d) return 0;
        if(p[0] - d <= o->mind[0] && o->maxd[0] <= p[0] + d &&
                p[1] - d <= o->mind[1] && o->maxd[1] <= p[1] + d) return o->sz;
        int ret = o->exist && p[0] - d <= o->key[0] && o->key[0] <= p[0] + d &&
                  p[1] - d <= o->key[1] && o->key[1] <= p[1] + d;
        ret += query(o->ch[0], p);
        ret += query(o->ch[1], p);
        return ret;
    }
}

using namespace KDT;

struct Query {
    int l, r, block, id;
};
const int B = 100;

bool cmpSeq(const Query& a, const Query& b) {
    return a.block < b.block ||
           a.block == b.block && a.r < b.r;
}

inline Point rotate(const Point& p) {
    return {p[0] - p[1], p[0] + p[1], p.id};
}

void add(int x) {
    int tmp = query(root, b[x]);
    sum += tmp;
    insert(root, b[x], 1, 0);
//    printf("add %d %d\n", x, tmp);
}

void del(int x) {
    insert(root, b[x], 0, 0);
    int tmp = query(root, b[x]);
    sum -= tmp;
//    printf("del %d %d\n", x, tmp);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);


    while(scanf("%d%d%d", &n, &d, &q) == 3) {
        for(int i = 1; i <= n; ++i) {
            a[i].read(); a[i].id = i;
            a[i] = rotate(a[i]);
            b[i] = a[i];
        }
        init();
        build(root, 1, n, 0);
//        puts("build ok");

        vector<Query> qs(q);
        for(int i = 0; i < q; ++i) {
            int l, r; scanf("%d%d", &l, &r);
            int b = l / B;
            qs[i] = {l, r, b, i};
        }

        sort(qs.begin(), qs.end(), cmpSeq);

        sum = 0;
        int l = 1, r = 0;
        for(auto& q : qs) {
            while(r < q.r) add(++r);
            while(l < q.l) del(l++);
            while(r > q.r) del(r--);
            while(l > q.l) add(--l);
            ans[q.id] = sum;
        }

        static int kase = 0;
        printf("Case %d:\n", ++kase);
        for(int i = 0; i < q; ++i) printf("%lld\n", ans[i]);
    }
    return 0;
}
