//
//  Created by TaoSama on 2015-12-26
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

double f[2][32][32];
bool vis[2][32][32];

int get(char c) {
    if(c == 'A') return 1;
    else if(isdigit(c)) return c - '0';
    return 10;
}

//1->losing prob
double dfs1(int a, int b) {
    if(b > 21) return 1;
    double &ret = f[1][a][b], tmp = 0;
    if(vis[1][a][b]) return ret;
    vis[1][a][b] = true;
    ret = a > b;
    for(int i = 1; i <= 9; ++i) tmp += dfs1(a, b + i);
    tmp += 4 * dfs1(a, b + 10);
    tmp /= 13;
    return ret = min(ret, tmp);
}

//0->winning prob
double dfs0(int a, int b) {
    if(a > 21) return 0;
    double &ret = f[0][a][b], tmp = 0;
    if(vis[0][a][b]) return ret;
    vis[0][a][b] = true;
    ret = dfs1(a, b);
    for(int i = 1; i <= 9; ++i) tmp += dfs0(a + i, b);
    tmp += 4 * dfs0(a + 10, b);
    tmp /= 13;
    return ret = max(ret, tmp);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        char s[5]; scanf("%s", s);
        double ans = dfs0(get(s[0]) + get(s[1]), get(s[2]) + get(s[3]));
//      printf("%.10f\n", ans);
        puts(ans > 0.5 ? "YES" : "NO");
    }
    return 0;
}
