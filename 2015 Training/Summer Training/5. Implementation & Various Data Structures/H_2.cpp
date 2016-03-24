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

int post[N], in[N];
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

void dfs(int n, int *in, int *post, int sum) {
    if(n <= 0) return;
    int rt = post[n];
    sum += rt;
    if(n == 1) {
        if(sum < minv) minv = sum, ans = rt;
        if(sum == minv && rt < ans) ans = rt;
        return;
    }
    int p = find(in + 1, in + 1 + n, rt) - in;
    dfs(p - 1, in, post, sum);
    dfs(n - p, in + p, post + p - 1, sum);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(read(in)) {
        read(post);
        minv = INF;
        dfs(n, in, post, 0);
        cout << ans << '\n';
    }
    return 0;
}
