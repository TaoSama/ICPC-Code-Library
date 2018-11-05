
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
        
    for(int i = 1; i < 100; ++i) {
        printf("Test %d:\n", i);
        system("sh do.sh");
        fstream in("std");
        fstream in2("greedy");
        int x, y; in >> x; in2 >> y;
        printf("std: %d, greedy: %d\n", x, y);
        if(3 * x <= y) {
            cout << "Got it\n";
            break;
        }
    }
    return 0;
}
