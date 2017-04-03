//
//  Created by TaoSama on 2016-11-23
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

int x[2], y[2];

namespace KDT {
    const double alpha = 0.6;
    const int M = 2e5 + 10, S = 2;
    int D, K = 2;
    struct Point {
        int d[S], c;
        void read() {
            for(int i = 0; i < K; ++i) scanf("%d", d + i);
        }
        void write() {
            for(int i = 0; i < K; ++i) printf("%d%c", d[i], " \n"[i + 1 == K]);
        }
        int& operator[](int k) {return d[k];}
        bool operator<(const Point& p) const {
            return d[D] < p.d[D];
        }
    } a[M];
    int cnt;
    struct Node {
        Point key, maxd, mind;
        Node* ch[2];
        int sum, sz, cover;  //sz for valid, cover for total
        bool exist;
        inline bool isBad() {
            return ch[0]->cover > cover * alpha + 5 ||
                   ch[1]->cover > cover * alpha + 5;
        }
        inline void up() {
            sum = ch[0]->sum + ch[1]->sum + (exist ? key.c : 0);
            sz = ch[0]->sz + ch[1]->sz + exist;
            cover = ch[0]->cover + ch[1]->cover + 1;
            for(int i = 0; i < K; ++i) {
                maxd[i] = max(maxd[i], ch[0]->maxd[i]);
                maxd[i] = max(maxd[i], ch[1]->maxd[i]);
                mind[i] = min(mind[i], ch[0]->mind[i]);
                mind[i] = min(mind[i], ch[1]->mind[i]);
            }
        }
    };
    Node pool[M], *ptr, *null, *root;   //memory pool
    Node* stk[M]; int top;       //free list

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

    inline Node* newNode(const Point& p) {
        Node* o = top ? stk[--top] : ptr++;
        o->key = p;
        o->sum = p.c;
        o->ch[0] = o->ch[1] = null;
        o->sz = o->cover = o->exist = 1;
        for(int i = 0; i < K; ++i)
            o->maxd[i] = o->mind[i] = o->key[i];
        return o;
    }
    void init() {
        top = 0;
        ptr = pool;
        null = ptr++;
        null->ch[0] = null->ch[1] = null;
        for(int i = 0; i < K; ++i) {
            null->mind[i] = INF;
            null->maxd[i] = -INF;
        }
        root = null;
    }
    void build(Node*& o, Point* a, int l, int r, int dim) {
        if(l > r) return;
        int m = l + r >> 1;
        D = dim;
        nth_element(a + l, a + m, a + r + 1);
        o = newNode(a[m]);
        build(o->ch[0], a, l, m - 1, (dim + 1) % K);
        build(o->ch[1], a, m + 1, r, (dim + 1) % K);
        o->up();
    }
    void dfs(Node* o) { //in order
        if(o == null) return;
        dfs(o->ch[0]);
        if(o->exist) a[++cnt] = o->key;
        stk[top++] = o;
        dfs(o->ch[1]);
    }
    void rebuild(Node*& o, int dim) {
        cnt = 0;
        dfs(o);
        build(o, a, 1, cnt, 0);
    }
    void insert(Node*& o, Point& p, int dim) {
        if(o == null) {
            o = newNode(p);
            return;
        }
        bool to = p[dim] < o->key[dim] ? 0 : 1;
        insert(o->ch[to], p, (dim + 1) % K);
        if(o->isBad()) rebuild(o, dim);
        o->up();
    }
    void query(Node* o, Point p, int& ans) {
        int cur = dist(o->key, p), dis[2] = {INF, INF};
        ans = min(ans, cur);
        for(int i = 0; i < 2; ++i) if(o->ch[i] != null) dis[i] = h(o->ch[i], p);
        bool t = dis[0] > dis[1];
        for(int i = 0; i < 2; ++i, t ^= 1)
            if(o->ch[t] != null && dis[t] < ans) query(o->ch[t], p, ans);
    }
    inline bool intersect(Node* o) {
        if(o->mind[0] > x[1] || o->maxd[0] < x[0] ||
                o->mind[1] > y[1] || o->maxd[1] < y[0])
            return false;
        return true;
    }
    void query(Node* o, int& ans) {
        if(x[0] <= o->mind[0] && o->maxd[0] <= x[1] &&
                y[0] <= o->mind[1] && o->maxd[1] <= y[1]) {
            ans += o->sum;
            return;
        }
        if(x[0] <= o->key[0] && o->key[0] <= x[1] &&
                y[0] <= o->key[1] && o->key[1] <= y[1]) {
            ans += o->key.c;
        }
        for(int i = 0; i < 2; ++i)
            if(o->ch[i] != null && intersect(o->ch[i]))
                query(o->ch[i], ans);
    }
}
using namespace KDT;

int n, q;

inline int readInt() {
    int c = getchar(), f = 1, x = 0;
    while(c <= 32) c = getchar();
    if(c == '-') f = -1, c = getchar();
    for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
    return x * f;
}

void writeInt(int x) {
    if(x < 0) putchar('-'), x = -x;
    if(x >= 10) writeInt(x / 10);
    putchar(x % 10 + '0');
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    n = readInt();
    init();
    Point p;
    p.d[0] = p.d[1] = n / 2;
    p.c = 0;
    insert(root, p, 0);
//    prln(1);
    int op, ans = 0;
    int cnt = 0;
    while(true) {
        op = readInt();
        if(op == 3) break;
//      prln(op);
        if(op == 1) {
            p.d[0] = readInt() ^ ans;
            p.d[1] = readInt() ^ ans;
            p.c = readInt() ^ ans;
            insert(root, p, 0);
        } else {
            for(int i = 0; i < 2; ++i) {
                x[i] = readInt() ^ ans;
                y[i] = readInt() ^ ans;
//                printf("%d %d\n", x[i], y[i]);
            }
            ans = 0;
            query(root, ans);
            writeInt(ans); putchar('\n');
        }
//        if(++cnt % 5000 == 0) rebuild(root, 0);
    }

    return 0;
}
