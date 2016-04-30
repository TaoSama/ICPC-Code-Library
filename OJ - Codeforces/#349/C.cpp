//
//  Created by TaoSama on 2016-04-30
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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

string s;
int f[N][2];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s) {
        memset(f, 0, sizeof f);
        s = ' ' + s;
        int sz = s.size() - 1;
        set<string> ss;
        for(int i = sz, j = 1; i; --i, ++j) {
            if(j < 2 || i <= 5) continue;
            if(j == 2) {
                ss.insert(s.substr(i, 2));
                f[i][0] = 1;
            } else if(j == 3) {
                ss.insert(s.substr(i, 3));
                f[i][1] = 1;
            } else {
                if(f[i + 2][0]) {
                    string b = s.substr(i + 2, 2);
                    string c = s.substr(i, 2);
                    if(b != c) {
                        ss.insert(c);
                        f[i][0] = 1;
                    }
                }
                if(f[i + 2][1]) {
                    string c = s.substr(i, 2);
                    ss.insert(c);
                    f[i][0] = 1;
                }
                if(f[i + 3][0]) {
                    string c = s.substr(i, 3);
                    ss.insert(c);
                    f[i][1] = 1;
                }
                if(f[i + 3][1]) {
                    string b = s.substr(i + 3, 3);
                    string c = s.substr(i, 3);
                    if(b != c) {
                        ss.insert(c);
                        f[i][1] = 1;
                    }
                }
            }
        }
//        for(int i = 1; i < s.size(); ++i){
//          printf("f[%d][0] = %d\n", i, f[i][0]);
//          printf("f[%d][1] = %d\n", i, f[i][1]);
//        }
        cout << ss.size() << '\n';
        for(auto s : ss) cout << s << '\n';
    }
    return 0;
}
