
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int cache[1 << 10];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
   
    string s;
    int tot = 0, hit = 0;
    memset(cache, -1, sizeof cache);
    while(cin >> s && s != "END") {
        ++tot;
        int num = stoi(s, nullptr, 16);
        int tag = num >> 10;
        int addr = num & 1023; 
        if(cache[addr] != tag) {
            cout << "Miss\n";
            int curLine = addr >> 4, nxtLine = curLine + 1;
            for(int i = curLine << 4; i < nxtLine << 4; ++i) cache[i] = tag;
        }
        else {
            cout << "Hit\n";
            ++hit;
        }
    }
    cout << "Hit ratio = " << fixed << setprecision(2) << 100.0 * hit / tot << "%\n";;

    return 0;
}
