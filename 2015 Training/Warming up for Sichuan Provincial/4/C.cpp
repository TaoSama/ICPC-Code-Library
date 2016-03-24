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

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s) {
        int two = 0, three = 0;
        int pre = 1, cnt = 1;
        cout << s[0];
        for(int i = 1; i < s.size(); ++i) {
            if(s[i] == s[i - 1]) {
                ++cnt;
                if(pre < 2 && cnt <= 2) cout << s[i];
                else --cnt;
            } else {
                cout << s[i];
                pre = cnt;
                cnt = 1;
            }
        }
        cout << '\n';
    }
    return 0;
}
