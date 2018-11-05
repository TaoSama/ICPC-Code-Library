
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int root1[N], root2[N];
struct PersistentSegTree {
    static const int M = N * 50;
    int sz;
    struct Node {
        int ls, rs, sum;
    } tree[M];
    void init() {
        sz = 0;
        memset(&tree[0], 0, sizeof tree[0]);
    }
    int newNode(int rt) {
        tree[++sz] = tree[rt];
        return sz;
    }
    void update(int o, int v, int l, int r, int& rt) {
        rt = newNode(rt);
        tree[rt].sum = v;
        if(l == r) return;
        int m = l + r >> 1;
        if(o <= m) update(o, v, l, m, tree[rt].ls);
        else update(o, v, m + 1, r, tree[rt].rs);
    }
    int query(int o, int l, int r, int rt) {
        if(l == r) return tree[rt].sum;
        int m = l + r >> 1, ret = 0;
        if(o <= m) return query(o, l, m, tree[rt].ls);
        return query(o, m + 1, r, tree[rt].rs);
    }
} T1;
struct PersistentSegTree2 {
    static const int M = N * 100;
    int sz;
    struct Node {
        int ls, rs, sum;
    } tree[M];
    void init() {
        sz = 0;
        memset(&tree[0], 0, sizeof tree[0]);
    }
    int newNode(int rt) {
        tree[++sz] = tree[rt];
        return sz;
    }
    void update(int o, int v, int l, int r, int& rt) {
        rt = newNode(rt);
        tree[rt].sum += v;
        if(l == r) return;
        int m = l + r >> 1;
        if(o <= m) update(o, v, l, m, tree[rt].ls);
        else update(o, v, m + 1, r, tree[rt].rs);
    }
    int query(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) return tree[rt].sum;
        int m = l + r >> 1, ret = 0;
        if(L <= m) ret += query(L, R, l, m, tree[rt].ls);
        if(R > m) ret += query(L, R, m + 1, r, tree[rt].rs);
        return ret;
    }
} T2;

map<string, int> idx;
int cnt;
int get(const string& s) {
    if(!idx.count(s)) idx[s] = ++cnt;
    return idx[s];
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int q;
    const int R = 1000000000;
    while(scanf("%d", &q) == 1) {
        cnt = 0;
        idx.clear();
        T1.init(); T2.init();
        for(int i = 1; i <= q; ++i) {
            char op[20], s[20];
            scanf("%s%s", op, s);
            int last = 1;
            if(*op == 'u') {
                int d = atoi(s);
                last = d + 1;
            }
            int id = get(s);
            // printf("id = %d\n", id);
            root1[i] = root1[i - last];
            root2[i] = root2[i - last];
            if(*op == 's') {
                int x; scanf("%d", &x);
                int old = T1.query(id, 1, q, root1[i]);
                T1.update(id, x, 1, q, root1[i]);
                // printf("old = %d\n", old);
                if(old) T2.update(old, -1, 0, R, root2[i]);
                T2.update(x, 1, 0, R, root2[i]);
            }
            else if(*op == 'r') {
                int old = T1.query(id, 1, q, root1[i]);
                if(old) {
                    T1.update(id, 0, 1, q, root1[i]);
                    T2.update(old, -1, 0, R, root2[i]);
                }
            }
            else if(*op == 'q') {
                int x = T1.query(id, 1, q, root1[i]);
                // printf("id = %d q = %d\n", id, x);
                int ans = x == 0 ? -1 : T2.query(0, x - 1, 0, R, root2[i]);
                printf("%d\n", ans);
                fflush(stdout);
            }
            else {
    
            }
        }
        // puts("");
    }
    return 0;
}
