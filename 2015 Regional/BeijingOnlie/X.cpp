#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

int n;

vector<int> answer[8];

int encode(const vector<int> &state) {
    int ret = 0;
    int magic = state.size();
    for(int i = 0; i < (int)state.size(); i++) {
        ret = ret * magic + state[i];
    }
    return ret;
}

int solve() {
    scanf("%d", &n);
    vector<int> init(n, 0), value, tmp;
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        tmp.push_back(x);
        value.push_back(x);
    }
    sort(value.begin(), value.end());
    for(int i = 0; i < n; i++) {
        tmp[i] = lower_bound(value.begin(), value.end(), tmp[i]) - value.begin();
        init[tmp[i]] = i;
    }
    /*cout << "init = ";
    for (int i = 0; i < n; i++) {
        cout << init[i] << " ";
    }
    cout << endl;
    */
    return answer[n][encode(init)];
}

void put(const vector<int> &state, vector<vector<int> > &queue,
         vector<int> &answer, int target) {
    int s = encode(state);
    if(answer[s] != -1) {
        return ;
    }
//    for(auto i: state) printf("%d ", i); puts("");
    queue.push_back(state);
    answer[s] = target + 1;
}

void prepare(int n, vector<int> &answer) {
    answer.clear();

    int mask = 1;
    for(int i = 0; i < n; i++) {
        mask = mask * n;
    }
    for(int i = 0; i < mask; i++) {
        answer.push_back(-1);
    }

    static vector<vector<int> > queue;
    queue.clear();
    vector<int> init;
    for(int i = 0; i < n; i++) {
        init.push_back(i);
    }
    queue.push_back(init);
    answer[encode(init)] = 0;

    vector<int> state;
    for(int head = 0; head < (int)queue.size(); head++) {
        state = queue[head];
        int v = answer[encode(state)];
        static int visit[8];
        fill(visit, visit + n, 0);
        for(int i = 0; i < n; i++) {
            if(!visit[state[i]]) {
                if(state[i] - 1 >= 0 && !visit[state[i] - 1]) {
                    state[i]--;
                    put(state, queue, answer, v);
                    state[i]++;
                }
                if(state[i] + 1 < n && !visit[state[i] + 1]) {
                    state[i]++;
                    put(state, queue, answer, v);
                    state[i]--;
                }

                visit[state[i]] = 1;
            }
        }
    }
}

int main() {
    for(int i = 1; i < 8; i++) {
        prepare(i, answer[i]);
    }
    //cout << "prepare finish" << endl;
    int test;
    scanf("%d", &test);
    while(test--) {
        cout << solve() << endl;
    }
    return 0;
}
