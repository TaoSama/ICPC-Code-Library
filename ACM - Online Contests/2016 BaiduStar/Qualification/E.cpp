//
//  Created by TaoSama on 2016-05-14
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
#include <sstream>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, global;
const int OFF = 10005;

struct Node {
    int l, r;
    int lazy, have;
    Node() {}
    Node(int l, int r): l(l), r(r) {
        lazy = 0;
        have = 1;
    }
    void set() {
        lazy = 1;
        have = 0;
    }
    void display() {
        printf("(%d, %d): lazy = %d have = %d\n",
               l, r, lazy, have);
    }
};

struct SegTree {
    Node dat[N << 2];
    void up(int rt) {
        int ls = rt << 1, rs = ls | 1;
        dat[rt].have = dat[ls].have | dat[rs].have;
    }
    void down(int rt) {
        if(dat[rt].lazy) {
            int ls = rt << 1, rs = ls | 1;
            dat[ls].set();
            dat[rs].set();
            dat[rt].lazy = 0;
        }
    }
    void build(int l, int r, int rt) {
        dat[rt] = Node(l, r);
        if(l == r) return;
        int m = l + r >> 1;
        build(l, m, rt << 1);
        build(m + 1, r, rt << 1 | 1);
    }
    void update(int L, int R, int rt) {
//      dat[rt].display();
        if(L <= dat[rt].l && dat[rt].r <= R) {
            dat[rt].set();
            return;
        }
        down(rt);
        int m = dat[rt].l + dat[rt].r >> 1;
        if(L <= m) update(L, R, rt << 1);
        if(R > m) update(L, R, rt << 1 | 1);
        up(rt);
    }
    bool query(int L, int R, int rt) {
//        dat[rt].display();
        if(L <= dat[rt].l && dat[rt].r <= R) return dat[rt].have;
        down(rt);
        int m = dat[rt].l + dat[rt].r >> 1, ret = 0;
        if(L <= m) ret |= query(L, R, rt << 1);
        if(R > m) ret |= query(L, R, rt << 1 | 1);
        return ret;
    }
} T[40];

int cnt;
map<string, int> mp;
int ID(string s) {
    if(!mp[s]) return mp[s] = cnt++;
    return mp[s];
}

#define MP make_pair
#define F first
#define S second
vector<pair<pair<int, int>, int> > qs[N];

int getO(string& s) {
    if(s == "<") return 1;
    else if(s == ">") return 2;
    else if(s == "<=") return 3;
    else if(s == ">=") return 4;
    else return 5;
}
bool isEmpty[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    cin >> n; cin.get();

    for(int i = 1; i <= n; ++i) {
        for(int i = 0; i < 40; ++i) T[i].build(1, N, 1);

        string line; getline(cin, line);
        for(int j = 0; j < line.size(); ++j)
            if(line[j] == ',') line[j] = ' ';

        stringstream ss(line);
        string a, b; int c;

        bool emptySet = false;
        while(ss >> a >> b >> c) {
            int id = ID(a), o = getO(b); c += OFF;
            qs[i].push_back(MP(MP(id, o), c));

//            printf("id = %d o = %d c = %d\n", id, o, c);
            if(o == 1) { //<
                T[id].update(c, N, 1);
            } else if(o == 2) { //>
                T[id].update(1, c, 1);
            } else if(o == 3) { //<=
                T[id].update(c + 1, N, 1);
            } else if(o == 4) { //>=
                T[id].update(1, c - 1, 1);
            } else { //==
                T[id].update(1, c - 1, 1);
                T[id].update(c + 1, N, 1);
            }
            emptySet |= (T[id].query(1, N, 1) == 0);
//            printf("c = %d\n", T[id].query(c, c, 1));
        }

        isEmpty[i] = emptySet;
        vector<int> ans;
        if(isEmpty[i]) {
            for(int j = 1; j < i; ++j)
                if(isEmpty[j]) ans.push_back(j);
        } else {
            for(int j = 1; j < i; ++j) {
                if(isEmpty[j]) continue;
                bool have = 0;
                for(int k = 0; k < qs[j].size(); ++k) {
                    int id = qs[j][k].F.F, o = qs[j][k].F.S, c = qs[j][k].S;
                    if(o == 1) { //<
                        have |= T[id].query(1, c - 1, 1);
                    } else if(o == 2) { //>
                        have |= T[id].query(c + 1, N, 1);
                    } else if(o == 3) { //<=
                        have |= T[id].query(1, c, 1);
                    } else if(o == 4) { //>=
                        have |= T[id].query(c, N, 1);
                    } else { //==
                        have |= T[id].query(c, c, 1);
                    }
                }
                if(have) ans.push_back(j);
            }
        }

        if(!ans.size()) cout << "unique\n";
        else {
            for(int j = 0; j < ans.size(); ++j)
                cout << ans[j] << " \n"[j == ans.size() - 1];
        }

//        return 0;
    }

//    for(int j = 1; j <= n; ++j) {
//        for(int k = 0; k < qs[j].size(); ++k) {
//            int id = qs[j][k].F.F, o = qs[j][k].F.S, c = qs[j][k].S;
//            printf("(%d, %d, %d) ", id, o,c);
//        }
//        puts("");
//    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
