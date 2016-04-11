//
//  Created by TaoSama on 2015-06-25
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
        set<string> ss;
        for(int i = 0; i <= s.size(); ++i) {
            for(char c = 'a'; c <= 'z'; ++c) {
                string t = s;
                t.insert(i, 1, c);
                ss.insert(t);
            }
        }
        cout << ss.size() << '\n';
    }
    return 0;
}
