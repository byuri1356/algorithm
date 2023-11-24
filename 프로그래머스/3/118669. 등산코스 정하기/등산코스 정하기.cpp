#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool isTop[200001];
vector<int> dist(200001, 10000001), answer;
vector<pair<int, int>> adj[200001];

typedef struct compare{
    bool operator()(const pair<int, int>& o1, const pair<int, int>& o2){
        if(o2.second == o1.second) return o2.first < o1.first;
        return o2.second < o1.second;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

void dijkstra(){
    
    while(!pq.empty()){
        
        int cur = pq.top().first;
        int dis = pq.top().second;
        
        pq.pop();
        
        if(isTop[cur]){
            if(dis < answer[1]){
                answer[0] = cur;
                answer[1] = dis;
            }
            else if(dis == answer[1] && cur < answer[0]){
                answer[0] = cur;
            }
            
            continue;
        }
        if(dist[cur] < dis) continue;
        
        for(int i=0; i<adj[cur].size(); ++i){
            int nCur = adj[cur][i].first;
            int nDis = max(adj[cur][i].second, dis);
            
            if(nDis < dist[nCur]){
                dist[nCur] = nDis;
                pq.push({nCur, nDis});
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {

    answer.push_back(200001);
    answer.push_back(10000001);
    
    for(auto& path: paths){
        adj[path[0]].push_back({path[1], path[2]});
        adj[path[1]].push_back({path[0], path[2]});
    }
    
    for(auto& gate: gates){
        pq.push({gate, 0});
        dist[gate] = 0;
    }
    
    for(auto& summit: summits){
        isTop[summit] = true;
    }
    
    dijkstra();
    
    return answer;
}