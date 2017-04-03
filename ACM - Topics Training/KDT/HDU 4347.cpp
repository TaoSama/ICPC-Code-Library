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

typedef long long LL;
const LL INFLL = 0x3f3f3f3f3f3f3f3fLL;

namespace KDT {
    const int M = 1e6 + 10, S = 5;
    int D, K;
    struct Point {
        int d[S];
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
    struct Node {
        Point key, maxd, mind;
        Node* ch[2];
        inline void up() {
            for(int i = 0; i < K; ++i) {
                maxd[i] = max(maxd[i], ch[0]->maxd[i]);
                maxd[i] = max(maxd[i], ch[1]->maxd[i]);
                mind[i] = min(mind[i], ch[0]->mind[i]);
                mind[i] = min(mind[i], ch[1]->mind[i]);
            }
        }
    } pool[M], *ptr, *null;

    struct QNode {
        LL dis;
        Point p;
        bool operator<(const QNode& r) const {
            return dis < r.dis;
        }
    };
    priority_queue<QNode> heap;

    inline LL f(int x) {return 1LL * x * x;}
    inline LL dist(Point& p, Point& q) {
        LL ret = 0;
        for(int i = 0; i < K; ++i) ret += f(p[i] - q[i]);
        return ret;
    }
    inline LL h(Node* o, Point& p) {
        LL ret = 0;
        for(int i = 0; i < K; ++i) {
            if(o->mind[i] > p[i]) ret += f(o->mind[i] - p[i]);
            else if(p[i] > o->maxd[i]) ret += f(p[i] - o->maxd[i]);
        }
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
        null->ch[0] = null->ch[1] = null;
        for(int i = 0; i < K; ++i) {
            null->mind[i] = INF;
            null->maxd[i] = -INF;
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
    void insert(Node*& o, Point p, int dim) {
        if(o == null) {
            o = newNode(p);
            return;
        }
        if(p[dim] < o->key[dim]) insert(o->ch[0], p, (dim + 1) % K);
        else insert(o->ch[1], p, (dim + 1) % K);
        o->up();
    }
    void query(Node* o, Point& p, int k) {
        LL cur = dist(o->key, p), dis[2] = {INFLL, INFLL};
        if(heap.size() < k) heap.push({cur, o->key});
        else if(cur < heap.top().dis) {heap.pop(); heap.push({cur, o->key});}
        for(int i = 0; i < 2; ++i) if(o->ch[i] != null) dis[i] = h(o->ch[i], p);
        bool t = dis[0] > dis[1];
        for(int i = 0; i < 2; ++i, t ^= 1)
            if(o->ch[t] != null && (heap.size() < k) || dis[t] < heap.top().dis)
                query(o->ch[t], p, k);
    }
}
KDT::Node* root;
KDT::Point* a = KDT::a;

int n, q, &K = KDT::K;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &K) == 2) {
        for(int i = 1; i <= n; ++i)
            for(int j = 0; j < K; ++j)
                scanf("%d", &a[i][j]);

        KDT::init();
        KDT::build(root, 1, n, 0);
        scanf("%d", &q);
        while(q--) {
            KDT::Point p; p.read();
            int k; scanf("%d", &k);
            KDT::query(root, p, k);
            printf("the closest %d points are:\n", k);
            vector<KDT::Point> v;  v.reserve(k);
            while(KDT::heap.size()) {
                v.push_back(KDT::heap.top().p);
                KDT::heap.pop();
            }
            for(int i = k - 1; ~i; --i) v[i].write();
        }
    }

    return 0;
}
