#include <string>
#include <vector>
#include <algorithm>
//#define fastio cin.tie(0)->ios::sync_with_stdio(0);

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int cursor = -1;
    
    sort(targets.begin(), targets.end(), [&](vector<int>& v1, vector<int>& v2){
       return v1[1] < v2[1];
    });
    
    for(auto& v: targets){
        if(v[0] < cursor) continue;
        answer++;
        cursor = v[1];
    }
    
    return answer;
}