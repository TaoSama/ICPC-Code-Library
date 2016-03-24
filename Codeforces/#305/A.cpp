//
//  Created by TaoSama on 2015-05-27
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
int n;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s >> n) {
        int c = s.size() / n;
        //cout << c<<endl;
        if(s.size() % n != 0) {
            cout << "NO\n";
            continue;
        }
        bool yes = true;
        for(int i = 0; i < s.size(); i += c) {
            for(int j = i, k = i + c - 1; j < k; ++j, --k) {
                if(s[j] != s[k]) {
                    yes = false;
                    break;
                }
            }
            if(!yes) break;
        }
        if(yes) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
