//
//  Created by TaoSama on 2016-06-04
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
const int N = 1e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int in[N], post[N];
int ls[N], rs[N];

bool read(int* a) {
    string line;
    if(!getline(cin, line)) return false;
    stringstream ss(line);
    n = 0;
    int x;
    while(ss >> x) a[++n] = x;
    return true;
}

int build(int inL, int inR, int postL, int postR) {
//    printf("(%d, %d) (%d, %d)\n", inL, inR, postL, postR);
    if(inL > inR) return -1;
    int rt = post[postR];
    int p = find(in + inL, in + inR + 1, rt) - in;
    int sz = inR - p; //右子树大小
//    printf("p = %d cnt = %d\n", p, sz);
//    return -1;

    rs[rt] = build(p + 1, inR, postR - sz, postR - 1);
    ls[rt] = build(inL, p - 1, postL, postR - sz - 1);
    return rt;
}

void dfs(int rt, int sum, pair<int, int>& ans) {
    sum += rt;
    if(ls[rt] == -1 && rs[rt] == -1) {
        ans = min(ans, {sum, rt});
        return;
    }
    if(~ls[rt]) dfs(ls[rt], sum, ans);
    if(~rs[rt]) dfs(rs[rt], sum, ans);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    string line;
    while(read(in)) {
        read(post);
        int rt = build(1, n, 1, n);
        pair<int, int> ans = {INF, INF};
        dfs(rt, 0, ans);
        printf("%d\n", ans.second);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
