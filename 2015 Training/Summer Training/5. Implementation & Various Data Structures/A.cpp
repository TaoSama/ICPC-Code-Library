//
//  Created by TaoSama on 2015-07-23
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

int n, tim[8], Q;
int val[26], wh[1005];
bool lock;
string code[1005];
deque<int> ready, block;

void run(int cur) {
    int left = Q;
    while(left > 0) {
        string &op = code[wh[cur]];
        if(op[2] == '=') { //assignment
            int x = op[0] - 'a';
            int v = isdigit(op[5]) ? 10 * (op[4] - '0') + op[5] - '0' : op[4] - '0';
            val[x] = v;
            left -= tim[1];
        } else if(op[2] == 'i') { //print
            cout << cur << ": " << val[op[6] - 'a'] << '\n';
            left -= tim[2];
        } else if(op[2] == 'c') { //lock
            if(lock) {
                block.push_back(cur); //lose the remaining time
                return;
            }
            lock = true;
            left -= tim[3];
        } else if(op[2] == 'l') { //unlock
            if(block.size()) {
                ready.push_front(block.front());
                block.pop_front();
            }
            lock = false;
            left -= tim[4];
        } else if(op[2] == 'd') //end there may be blank line
            return;
        wh[cur]++; //next instruction
    }
    ready.push_back(cur); //still have instruction
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= 5; ++i) cin >> tim[i];
        cin >> Q; cin.get();
        int cnt = 0;
        memset(val, 0, sizeof val);
        ready.clear(); block.clear();
        for(int i = 1; i <= n; ++i) {
            wh[i] = cnt + 1;
            ready.push_back(i);
            while(getline(cin, code[++cnt]) && code[cnt] != "end");
        }

        lock = false;
        while(ready.size()) {
            int cur = ready.front(); ready.pop_front();
            run(cur);
        }
        if(t) cout << '\n';
    }
    return 0;
}
