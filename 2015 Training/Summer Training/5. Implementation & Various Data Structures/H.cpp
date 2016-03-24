//
//  Created by TaoSama on 2015-07-23
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
#include <sstream>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int ls[N], rs[N], post[N], in[N];
int n, minv, ans;

bool read(int *in) {
    string line;
    if(!getline(cin, line)) return false;
    n = 0;
    int x;
    stringstream ss(line);
    while(ss >> x) in[++n] = x;
    return n > 0;
}

int build(int n, int *in, int *post) {
    if(n <= 0) return 0;
    int rt = post[n];
    int p = find(in + 1, in + 1 + n, rt) - in;
//  pr(n); pr(p); prln(rt);
    ls[rt] = build(p - 1, in, post);
    rs[rt] = build(n - p, in + p, post + p - 1);
    return rt;
}

void dfs(int rt, int sum) {
    sum += rt;
//  pr(rt); pr(ls[rt]); prln(rs[rt]);
    if(!ls[rt] && !rs[rt]) {
//      pr(minv); prln(sum);
        if(sum < minv) minv = sum, ans = rt;
        if(sum == minv && rt < ans) ans = rt;
        return;
    }
    if(ls[rt]) dfs(ls[rt], sum);
    if(rs[rt]) dfs(rs[rt], sum);
}

void print(int rt) {
    if(!rt) return;
    cout << rt << ' ';
    print(ls[rt]);
    print(rs[rt]);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(read(in)) {
        read(post);
        int rt = build(n, in, post);
//      print(rt); cout << endl;
        minv = INF;
        dfs(rt, 0);
        cout << ans << '\n';
    }
    return 0;
}
