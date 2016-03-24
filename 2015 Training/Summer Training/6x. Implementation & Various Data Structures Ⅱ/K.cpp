//
//  Created by TaoSama on 2015-07-24
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char pre[50], in[50];
int ls[50], rs[50];

int build(int inL, int inR, int preL, int preR) {
    if(inL > inR) return -1;
    int rt = pre[preL] - 'A';
    int p = find(in + inL, in + inR + 1, pre[preL]) - in;
    int cnt = p - inL + 1;
//  prln(rt);
//  pr(inL); pr(inR); pr(preL); prln(preR);
    ls[rt] = build(inL, p - 1, preL + 1, preL + cnt);
//  pr(rt); prln(ls[rt]);
    rs[rt] = build(p + 1, inR, preL + cnt, preR);
//    pr(rt); prln(rs[rt]);
    return rt;
}

void print(char rt) {
    if(rt == -1) return;
    print(ls[rt]);
    print(rs[rt]);
    cout << char(rt + 'A');
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> (pre + 1) >> (in + 1)) {
        int n = strlen(pre + 1);
        int rt = build(1, n, 1, n);
        print(rt); cout << '\n';
    }
    return 0;
}
