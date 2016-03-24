//
//  Created by TaoSama on 2015-11-07
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

int reg[10], ram[1005];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    cin.get(); cin.get();
    while(t--) {
        int cnt = 0, ans = 0, idx = 0;
        memset(reg, 0, sizeof reg);
        memset(ram, 0, sizeof ram);
        string op;
        while(getline(cin, op)) {
            if(op.size() == 0) break;
            for(auto c : op) ram[cnt] = ram[cnt] * 10 + c - '0';
            ++cnt;
        }
        while(true) {
            ++ans;
            int cmd = ram[idx++];
            if(cmd == 100) break;
            int x = cmd / 100, y = cmd % 100 / 10, z = cmd % 10;
            switch(x) {
            case 0:
                if(reg[z]) idx = reg[y];
                break;
            case 2:
                reg[y] = z;
                break;
            case 3:
                (reg[y] += z) %= 1000;
                break;
            case 4:
                (reg[y] *= z) %= 1000;
                break;
            case 5:
                reg[y] = reg[z];
                break;
            case 6:
                (reg[y] += reg[z]) %= 1000;
                break;
            case 7:
                (reg[y] *= reg[z]) %= 1000;
                break;
            case 8:
                reg[y] = ram[reg[z]];
                break;
            case 9:
                ram[reg[z]] = reg[y];
                break;
            }
//            for(int i = 0; i < 10; ++i) printf("%6d", i); puts("");
//            for(int i = 0; i < 10; ++i) printf("%6d", reg[i]); puts("");
//            if(idx == 5) break;
        }
        cout << ans << '\n';
        if(t) cout << '\n';
    }
    return 0;
}
