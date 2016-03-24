//
//  Created by TaoSama on 2015-06-05
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

string s;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s) {
        int x = s.find("AB");
        int y = s.find("BA");
        bool ok = false;
        if(~x) {
            while(~y) {
                //cout << x << ' '<<y<<endl;
                if(abs(x - y) >= 2) {
                    ok = true;
                    break;
                }
                //cout<<y<<endl;
                y = s.find("BA", y + 1);
            }
        }
        if(ok) {
            puts("YES");
            continue;
        }

        x = s.find("BA");
        y = s.find("AB");
        ok = false;
        if(~x) {
            while(~y) {
                //cout << x << ' '<<y<<endl;
                if(abs(x - y) >= 2) {
                    ok = true;
                    break;
                }
                //cout<<y<<endl;
                y = s.find("AB", y + 1);
            }
        }
        puts(ok ? "YES" : "NO");
    }
    return 0;
}
