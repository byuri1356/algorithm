#include <string>
#include <vector>

using namespace std;

int dep;

void combi(int cur, vector<int> rate, vector<vector<int>>& users, vector<int>& emoticons,
          vector<int>& answer){
    if(cur == dep){
        int join = 0, total = 0;
        for(auto& user: users){
            int tot = 0;
            for(int i = 0; i < rate.size(); ++i){
                if(user[0] <= rate[i]){
                    tot += (emoticons[i] / 100 * (100 - rate[i]));
                }
            }
            
            if(user[1] <= tot){
                tot = 0;
                join++;
            }
            total+= tot;
        }
        
        if(answer[0] < join){
            answer[0] = join;
            answer[1] = total;
        }
        else if(answer[0] == join && answer[1] < total){
            answer[1] = total;
        }
        return;
    }
    
    for(int i=10; i<=40; i+=10){
        rate.push_back(i);
        combi(cur+1, rate, users, emoticons, answer);
        rate.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    dep = emoticons.size();
    vector<int> answer;
    vector<int> rate;
    
    answer.push_back(0);
    answer.push_back(0);
    
    combi(0, rate, users, emoticons, answer);
    
    return answer;
}