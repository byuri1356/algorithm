#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
using namespace std;
using vv = vector<vector<int>>;

int start, cnt, sccCnt = 1, ans;
vv adj, sccAdj;
vector<int> cost, sccCost, st, parent, conn, sccLevel, sccSum;
vector<bool> rest, sccRest, vst, sccVst;

inline void bfs() {

    sccAdj.resize(sccCnt);
    sccLevel.resize(sccCnt);
    sccSum.resize(sccCnt);
    sccVst.resize(sccCnt);

    for (int i = 0; i < adj.size(); ++i) {
        for (auto& it : adj[i]) {
            if (conn[i] != conn[it] && conn[it] != conn[start]) {
                sccAdj[conn[i]].push_back(conn[it]);
                sccLevel[conn[it]]++;
            }
        }
    }


    sccSum[conn[start]] = sccCost[conn[start]];
    sccVst[conn[start]] = true;
    queue<int> q;

    for (int i = 0; i < sccCnt; ++i) {
        if(!sccLevel[i]) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto& it : sccAdj[cur]) {
            sccLevel[it]--;

            if (sccVst[cur]) {
                sccVst[it] = true;
                sccSum[it] = max(sccSum[it], sccSum[cur] + sccCost[it]);
            }

            if (!sccLevel[it]) {
                q.push(it);
            }
        }

    }

}

inline int dfs(int cur) {
    vst[cur] = true;
    st.push_back(cur);
    int in = ++cnt;
    parent[cur] = cnt;

    for (auto& it : adj[cur]) {
        int nxt = it;
        if (!vst[nxt]) {
            in = min(in, dfs(nxt));
        }
        else if (!conn[nxt]) {
            in = min(in, parent[nxt]);
        }
    }

    if (in == parent[cur]) {
        sccCost.push_back(0);
        sccRest.push_back(false);
        while (true) {
            int res = st.back();
            st.pop_back();

            conn[res] = sccCnt;
            sccCost.back() += cost[res];
            sccRest.back() = sccRest.back() || rest[res];

            if (res == cur) break;
        }

        sccCnt++;
    }

    return in;
}

int main() {

    fastio;

    int N, M;
    cin >> N >> M;

    adj.resize(N + 1);
    cost.resize(N + 1);
    parent.resize(N + 1);
    rest.resize(N + 1);
    vst.resize(N + 1);
    conn.resize(N + 1);
    sccCost.push_back(0);
    sccRest.push_back(false);

    while (M--) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
    }

    for (int i = 1; i <= N; ++i) {
        cin >> cost[i];
    }

    cin >> start >> M;
    while (M--) {
        int a;
        cin >> a;
        rest[a] = true;
    }

    for (int i = 1; i <= N; ++i) {
        if (!vst[i]) {
            dfs(i);
        }
    }

    bfs();
    
    for (int i = 0; i < sccCnt; ++i) {
        if (sccVst[i] && sccRest[i]) {
            ans = max(ans, sccSum[i]);
        }
    }

    cout << ans;

    return EXIT_SUCCESS;
}