//
//  Created by TaoSama on 2015-08-09
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

int n;
struct P {
    string name;
    int taxi, pizza, girl;
} a[105];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
//  ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int i = 1; i <= n; ++i) {
            int k; cin >> k >> a[i].name;
            a[i].pizza = a[i].taxi = a[i].girl = 0;
            for(int j = 1; j <= k; ++j) {
                string buf; cin >> buf;
                buf.erase(2, 1); buf.erase(4, 1);

                bool same = true;
                for(int c = 1; c < buf.size(); ++c)
                    if(buf[c] != buf[c - 1]) {same = false; break;}
                if(same) a[i].taxi++;

                bool dec = true;
                for(int c = 1; c < buf.size(); ++c)
                    if(buf[c] >= buf[c - 1]) {dec = false; break;}
                if(dec) a[i].pizza++;

                if(!dec && !same) a[i].girl++;
            }
        }

        int taxi = 0, pizza = 0, girl = 0;
        for(int i = 1; i <= n; ++i) {
            taxi = max(taxi, a[i].taxi);
            pizza = max(pizza, a[i].pizza);
            girl = max(girl, a[i].girl);
        }

        cout << "If you want to call a taxi, you should call:";
        bool first = true;
        for(int i = 1; i <= n; ++i) {
            if(a[i].taxi == taxi) {
                if(first) {
                    first = false;
                    cout << ' ';
                } else  cout << ", ";
                cout << a[i].name;
            }
        }
        puts(".");

        cout << "If you want to order a pizza, you should call:";
        first = true;
        for(int i = 1; i <= n; ++i) {
            if(a[i].pizza == pizza) {
                if(first) {
                    first = false;
                    cout << ' ';
                } else  cout << ", ";
                cout << a[i].name;
            }
        }
        puts(".");

        cout << "If you want to go to a cafe with a wonderful girl, you should call:";
        first = true;
        for(int i = 1; i <= n; ++i) {
            if(a[i].girl == girl) {
                if(first) {
                    first = false;
                    cout << ' ';
                } else  cout << ", ";
                cout << a[i].name;
            }
        }
        puts(".");

    }
    return 0;
}
