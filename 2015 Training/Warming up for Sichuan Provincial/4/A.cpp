//
//  Created by TaoSama on 2015-06-10
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
const string x[10] = {"O-|-OOOO",  "O-|O-OOO", "O-|OO-OO", "O-|OOO-O", "O-|OOOO-",
                      "-O|-OOOO", "-O|O-OOO", "-O|OO-OO", "-O|OOO-O", "-O|OOOO-"
                     };

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s) {
        int e = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != '0') {
                e = i;
                break;
            }
        }
        for(int i = s.size() - 1; i >= e; --i)
            cout << x[s[i] - '0'] << '\n';
    }
    return 0;
}
