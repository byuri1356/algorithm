#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;
using ll = long long;

int solution(vector<int> money) {
    int answer = 0, sz = money.size();
    vector<int>dp(sz);
    
    dp[0] = money[0];
    dp[1] = max(money[0], money[1]);
    
    for(int i = 2; i < sz; ++i){
        dp[i] = max(money[i] + dp[i - 2], dp[i-1]);
    }
    
    dp[sz-1] -= money[0];
    
    for(int i = 0; i < sz; ++i){
        answer = max(answer, dp[i]);
    }
    
    dp[0] = -1000000000;
    dp[1] = money[1];
    
     for(int i = 2; i < sz; ++i){
        dp[i] = max(money[i] + dp[i - 2], dp[i - 1]);
    }
    
    for(int i = 0; i < sz; ++i){
        answer = max(answer, dp[i]);
    }
    
    return answer;
}