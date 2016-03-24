//
//  Created by TaoSama on 2015-08-04
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

int n, m;
char a[105][105];
struct P {
    int r, x, y;
    bool operator< (const P& rhs) const {
        if(r != rhs.r) return r < rhs.r;
        else {
            if(x != rhs.x) return x < rhs.x;
            else return y < rhs.y;
        }
    }
};

vector<P> ans;

void check(int i, int j) {
    vector<int> up, down, lef, rig;
    for(int k = 0; k < i; ++k)
        if(a[k][j] == '1') up.push_back(k);
//    if(i == 8 && j == 16) {for(auto &k: up) cout << k << ' '; cout << endl;}
    for(int k = i + 1; k < n; ++k)
        if(a[k][j] == '1') down.push_back(k);
//    if(i == 8 && j == 16) {for(auto &k: down) cout << k << ' '; cout << endl;}
    for(int k = 0; k < j; ++k)
        if(a[i][k] == '1') lef.push_back(k);
//    if(i == 8 && j == 16) {for(auto &k : lef) cout << k << ' '; cout << endl;}
    for(int k = j + 1; k < m; ++k)
        if(a[i][k] == '1') rig.push_back(k);
//    if(i == 8 && j == 16) {for(auto &k : rig) cout << k << ' '; cout << endl;}


    vector<int> ud, lr;
    //check the radius of 4 directions
    for(auto &x : up)
        for(auto &y : down)
            if(abs(i - x) == abs(i - y)) ud.push_back(abs(i - x));
//    if(i == 8 && j == 16) {for(auto &k : ud) cout << k << ' '; cout << endl;}

    for(auto &x : lef)
        for(auto &y : rig)
            if(abs(j - x) == abs(j - y)) lr.push_back(abs(j - x));
//    if(i == 8 && j == 16) {for(auto &k : lr) cout << k << ' '; cout << endl;}

    //check the circle
    for(auto &x : ud)
        for(auto &y : lr)
            if(x == y) ans.push_back((P) {x, j, i});
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d%d", &m, &n);
        for(int i = 0; i < n; ++i) scanf("%s", a[i]);

        ans.clear();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                check(i, j);
            }
        }
        sort(ans.begin(), ans.end());
        printf("Case %d: %d", ++kase, ans.size());
        for(auto &i : ans) if(i.r >= 5) printf(" (%d,%d,%d)", i.r, i.x, i.y);
        puts("");
    }
    return 0;
}
