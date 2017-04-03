//
//  Created by TaoSama on 2016-11-28
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#pragma pack()
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
#include <cassert>

using namespace std;
#define pr(x)   cout << #x << " = " << x
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;
namespace KDT {
    const int M = 2e5 + 10, K = 2;
    struct Point {
        int d[K], v, id;
        void read() {
            for(int i = 0; i < K; ++i) scanf("%d", d + i);
        }
        void write() {
            for(int i = 0; i < K; ++i) printf("%d%c", d[i], " \n"[i + 1 == K]);
        }
        Point(int v = INF, int id = -1): v(v), id(id) {}
        int& operator[](int k) {return d[k];}
        bool operator==(const Point& p) const {
            return id == p.id;
        }
        bool operator<(const Point& p) const {
            return v < p.v;
        }
    } a[M];
    int D;
    bool cmp(Point& p, Point& q) {
        if(p[D] != q[D]) return p[D] < q[D];
        return p.id < q.id;
    };

    struct Node {
        Point key, minKey, maxd, mind;
        int lazy;
        bool exist;
        Node* ch[2];
        inline void add(int v) {
            lazy += v;
            if(exist) key.v += v;
            minKey.v += v;
        }
        inline void down() {
            if(!lazy) return;
            ch[0]->add(lazy);
            ch[1]->add(lazy);
            lazy = 0;
        }
        inline void up() {
            assert(key.id != -1);
            minKey = min(ch[0]->minKey, ch[1]->minKey);
            for(int i = 0; i < K; ++i) {
                maxd[i] = max(ch[0]->maxd[i], ch[1]->maxd[i]);
                mind[i] = min(ch[0]->mind[i], ch[1]->mind[i]);
            }
            if(!exist) return;
            minKey = min(minKey, key);
            for(int i = 0; i < K; ++i) {
                maxd[i] = max(maxd[i], key[i]);
                mind[i] = min(mind[i], key[i]);
            }
        }
    } pool[M], *ptr, *null, *root;

    inline Node* newNode(const Point& p) {
        ptr->key = p;
        ptr->minKey = Point();
        ptr->lazy = ptr->exist = 0;
        ptr->ch[0] = ptr->ch[1] = null;
        return ptr++;
    }
    void init() {
        ptr = pool;
        null = ptr++;
        null->minKey = null->key = Point();
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
        nth_element(a + l, a + m, a + r + 1, cmp);
        o = newNode(a[m]);
        build(o->ch[0], l, m - 1, (dim + 1) % K);
        build(o->ch[1], m + 1, r, (dim + 1) % K);
        o->up();
    }
    void insert(Node*& o, Point p, int v, int dim) {
        o->down();
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
    void update(Node* o, int x) {
        if(o->mind[0] > x || o->maxd[1] < x) return;
        if(o->maxd[0] <= x && o->mind[1] >= x) {
            o->add(-1);
            return;
        }

        o->down();
        if(o->key[0] <= x && o->key[1] >= x && o->exist) --o->key.v;
        update(o->ch[0], x);
        update(o->ch[1], x);
        o->up();
    }
}

using namespace KDT;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(false);


    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &q, &n);
        n = 0;
        vector<Point> qs(q);
        for(int i = 0; i < q; ++i) {
            char op[2]; scanf("%s", op);
            if(*op == 'C') {
                int l, r, c; scanf("%d%d%d", &l, &r, &c);
                qs[i] = Point(c, i);
                qs[i][0] = l; qs[i][1] = r;
                a[++n] = qs[i];
            } else {
                int x; scanf("%d", &x);
                qs[i] = Point(x, -1);
            }
        }

        init();
        build(root, 1, n, 0);

        int ans = 0;
        static int kase = 0;
        printf("Case #%d:\n", ++kase);
        for(int i = 0; i < q; ++i) {
            auto& query = qs[i];
            if(query.id != -1) {
                insert(root, query, 1, 0);
            } else {
                int x = query.v ^ ans;
                update(root, x);

                static vector<int> v; v.clear();
                while(root->minKey.v == 0) {
                    v.push_back(root->minKey.id);
                    assert(root->minKey.id != -1);
                    insert(root, root->minKey, 0, 0);
                }
                if(v.size()) {
                    sort(v.begin(), v.end());
                    printf("%d", i + 1);
                    for(int x : v) {
                        ans ^= x + 1;
                        printf(" %d", x + 1);
                    }
                    puts("");
                }
            }
        }
    }
    return 0;
}
