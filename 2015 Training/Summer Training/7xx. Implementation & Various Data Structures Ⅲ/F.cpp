//
//  Created by TaoSama on 2015-07-25
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <ctime>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int ans;
set<vector<deque<int> > > s;
deque<int> pile[10];
deque<int>& q = pile[0]; // 0 for hand to simulate queue

void check(deque<int>& cur) {
    while(true) {
        int n = cur.size();
        if(n < 3) return;
        //in ascending order
        if((cur[0] + cur[1] + cur[n - 1]) % 10 == 0) {
            q.push_back(cur[0]);
            q.push_back(cur[1]);
            q.push_back(cur[n - 1]);
            cur.pop_front();
            cur.pop_front();
            cur.pop_back();
        } else if((cur[0] + cur[n - 1] + cur[n - 2]) % 10 == 0) {
            q.push_back(cur[0]);
            q.push_back(cur[n - 2]);
            q.push_back(cur[n - 1]);
            cur.pop_front();
            cur.pop_back();
            cur.pop_back();
        } else if((cur[n - 1] + cur[n - 2] + cur[n - 3]) % 10 == 0) {
            q.push_back(cur[n - 3]);
            q.push_back(cur[n - 2]);
            q.push_back(cur[n - 1]);
            cur.pop_back();
            cur.pop_back();
            cur.pop_back();
        } else
            return;
    }
}

int play() {  //1->win 2->lose 3->draw
    while(true) { // - - 手贱坑自己一小时 老老实实写死循环多好
        //check each pile
        for(int i = 1; i <= 7; ++i) {
            if(q.size() == 52) return 1;  //win
            if(q.size() == 0) return 2;   //lose
            if(pile[i].size() == 0) continue;

            //hand out a card;
            ++ans;
            pile[i].push_back(q.front());
            q.pop_front();

            check(pile[i]); //play

            //check for draw
            vector<deque<int> > Sta;
            for(int i = 0; i <= 7; ++i)
                Sta.push_back(pile[i]);
            if(s.count(Sta)) return 3;  //draw
            else s.insert(Sta);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//    freopen("C:\\Users\\TaoSama\\Desktop\\out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

//  for(int i = 0; i < 1000; ++i){
//      for(int j = 0; j < 52; ++j)
//          cout << rand() % 10 + 1 << ' ';
//      cout <<endl;
//  }cout << 0 << endl;
//  return 0;

    int x;
    while(cin >> x && x) {
        s.clear();
        for(int i = 0; i <= 7; ++i) pile[i].clear();
        q.push_back(x);
        for(int i = 1; i < 52; ++i) {
            cin >> x;
            q.push_back(x);
        }

        //hand 14 first
        for(int i = 0; i < 2; ++i) {
            for(int j = 1; j <= 7; ++j) {
                pile[j].push_back(q.front());
                q.pop_front();
            }
        }

        ans = 14;
        int ret = play();
        if(ret == 1) cout << "Win : " << ans << '\n';
        else if(ret == 2) cout << "Loss: " << ans << '\n';
        else cout << "Draw: " << ans << '\n';
    }
    return 0;
}
