//
//  Created by TaoSama on 2015-08-16
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 5e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, kase, sz;
char expr[N * 6], *p;
int done[N];

struct Node {
    char s[5];
    int hash, lef, rig;
    bool operator< (const Node& rhs) const {
        if(hash != rhs.hash) return hash < rhs.hash;
        if(lef != rhs.lef) return lef < rhs.lef;
        return rig < rhs.rig;
    }
} node[N];

map<Node, int> mp;

int parse() {
    int id = ++sz, idx = 0;
    Node &u = node[id];
    memset(&u, 0, sizeof(Node));
    while(isalpha(*p)) {
        //cause 0==0000 makes a==aaaa leads to wrong
        //cause string compare is slow
        u.hash = u.hash * 27 + *p - 'a' + 1;
        u.s[idx++] = *p;
        ++p;
    }

    if(*p == '(') { //(L, R)
        ++p; u.lef = parse(); //jump (
        ++p; u.rig = parse(); //jump ,
        ++p; //jump )
    }

    if(mp.count(u)) --sz;
    else mp[u] = id;

    return mp[u];
}

void print(int u) {
    if(done[u] == kase) {
        printf("%d", u);
        return;
    }

    done[u] = kase;
    printf("%s", node[u].s);

    //cause each subtree either has both sons or none
    if(node[u].lef) {
        putchar('(');
        print(node[u].lef);
        putchar(',');
        print(node[u].rig);
        putchar(')');
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%s", expr);
        p = expr;
        ++kase; sz = 0; mp.clear();
        print(parse());
        puts("");
    }
    return 0;
}
