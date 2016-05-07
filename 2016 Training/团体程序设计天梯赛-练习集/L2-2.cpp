//
//  Created by TaoSama on 2016-05-07
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int addr[N], val[N];
int start, n;
struct Node {
    int addr, v, nxt;
    void read() {
        scanf("%d%d%d", &addr, &v, &nxt);
    }
    void print() {
        printf("%05d %d ", addr, v);
        if(nxt == -1) puts("-1");
        else printf("%05d\n", nxt);
    }
} dat[N];


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    scanf("%d%d", &start, &n);
    for(int i = 1; i <= n; ++i) {
        dat[i].read();
        addr[dat[i].addr] = i;
    }
    vector<Node> lft, del;
    while(start != -1) {
        int p = addr[start];
        Node& cur = dat[p];
        if(!val[abs(cur.v)]) {
            val[abs(cur.v)] = true;
            if(lft.size()) lft.back().nxt = start;
            lft.push_back(cur);
        } else {
            if(del.size()) del.back().nxt = start;
            del.push_back(cur);
        }
        start = cur.nxt;
    }
    lft.back().nxt = -1;
    if(del.size()) del.back().nxt = -1;

    for(auto& x : lft) x.print();
    for(auto& x : del) x.print();

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
