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
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, lef[N], rig[N];

void link(int l, int r) {
    rig[l] = r; lef[r] = l;
}

void print() {
    int cur = 0;
    for(int i = 1; i <= n + 2; ++i) cout << cur << ' ', cur = rig[cur];
    cout << endl;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(cin >> n >> m) {
        for(int i = 1; i <= n; ++i) {
            lef[i] = i - 1;
            rig[i] = i + 1;
        }
        //to virtualize two point 0, n+1
        lef[0] = rig[n + 1] = 0;
        rig[0] = 1; lef[n + 1] = n;

        int op, x, y, inv = 0;
        for(int i = 1; i <= m; ++i) {
//            print();
            cin >> op;
            if(op == 4) {
                inv ^= 1;
                continue;
            }
            cin >> x >> y;
            //adjacent to each other and uniform the two to x y
            if(op == 3 && rig[y] == x) swap(x, y); //y x -> x y
            if(op != 3 && inv) op = 3 - op;
            if(op == 1 && x == lef[y]) continue; // x -> []y
            if(op == 2 && x == rig[y]) continue; // x -> y[]

            int lx = lef[x], rx = rig[x], ly = lef[y], ry = rig[y];
            if(op == 1) { // x -> []y
                link(lx, rx); // erase x
                link(ly, x); link(x, y);  //[] x y
            }
            if(op == 2) { // x -> y[]
                link(lx, rx); //erase x
                link(y, x); link(x, ry); //y x []
            }
            if(op == 3) {
//                cout << lx << ' ' << x << ' ' << rx << endl;
//                cout << ly << ' ' << y << ' ' << ry << endl;

                if(rig[x] == y) { // ( y x -> x y || x y ) -> swap
                    link(lx, y); link(y, x); link(x, ry); //rebuild the link
                } else {
                    link(lx, y); link(y, rx); //rebuild the link
                    link(ly, x); link(x, ry);
                }
            }
        }
//        print();
        int cur = rig[0];
        long long ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(i & 1) ans += cur;
            cur = rig[cur];
        }
        //if odd no changes with odd-indexed
        if(inv && n % 2 == 0) ans = 1LL * n * (n + 1) / 2 - ans;
        cout << "Case " << ++kase << ": " << ans << '\n';
    }
    return 0;
}
