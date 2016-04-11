#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

string word;
int cur;
bool fst=true;
int main()
{
#ifdef LOCAL
    freopen("ACM_in.txt","r",stdin);
    //freopen("ACM_out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    while(cin>>word) {
        if(word=="<hr>") {
            cur=0;
            string tab(80,'-');
            if(fst) cout<<tab<<endl;
            else    cout<<'\n'<<tab<<endl;
            fst=true;
        } else if(word=="<br>") {
            cur=0;
            cout<<endl;
            fst=true;
        } else {
            int sz=word.size();
            if(fst) {
                cur+=sz; fst=false;
                cout<<word;
            } else if(cur+sz+1>80) {
                cur=sz+1;
                cout<<'\n'<<word;
            } else {
                cur+=sz+1;
                cout<<' '<<word;
            }
        }
    }
    cout<<endl;
    return 0;
}