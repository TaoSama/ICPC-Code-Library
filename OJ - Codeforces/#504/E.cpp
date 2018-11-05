
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int r[][2] ={1, 0, 0, 1};

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
    //  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int,int>>path[2];
    pair<int,int> now={1,1};
    path[0].push_back(now);
    for(int j=1;j<n;j++){
        for(int k=0;k<2;k++){
            int x1=now.first+r[k][0],y1=now.second+r[k][1];
            printf("? %d %d %d %d",x1,y1,n,n);cout<<endl;
            string s; cin >> s;
            if(s == "YES") {
                now={x1,y1};
                break;
            }
        }
        path[0].push_back(now);
    }

    now = {n,n};
    path[1].push_back(now);
    for(int j=1;j<n;j++){
        for(int k=1;k>=0;k--){
            int x1=now.first-r[k][0],y1=now.second-r[k][1];
            printf("? %d %d %d %d",1,1,x1,y1);cout<<endl;
            string s; cin >> s;
            if(s == "YES") {
                now={x1,y1};
                break;
            }
        }
        path[1].push_back(now);
    }
    path[1].pop_back();
    reverse(path[1].begin(),path[1].end());

    vector<pair<int,int>> all;
    for(int i = 0; i < 2; ++i) {
        all.insert(all.end(), path[i].begin(), path[i].end());
    }

    printf("! ");
    for(int j=1;j<all.size();j++){
        if(all[j].first!=all[j-1].first) printf("D");
        else printf("R");
    }
    cout<<'\n';
    return 0;
}
