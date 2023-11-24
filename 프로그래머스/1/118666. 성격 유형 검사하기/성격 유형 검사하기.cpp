#include <string>
#include <vector>
#include <map>
using namespace std;

map<char, int> test;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    for(int i=0; i<choices.size(); ++i){
        if(choices[i] == 1){
            test[survey[i][0]] = test[survey[i][0]] + 3;
        }
        else if(choices[i] == 2){
            test[survey[i][0]] = test[survey[i][0]] + 2;
        }
        else if(choices[i] == 3){
            test[survey[i][0]] = test[survey[i][0]] + 1;
        }
        else if(choices[i] == 5){
            test[survey[i][1]] = test[survey[i][1]] + 1;
        }
        else if(choices[i] == 6){
            test[survey[i][1]] = test[survey[i][1]] + 2;
        }
        else if(choices[i] == 7){
            test[survey[i][1]] = test[survey[i][1]] + 3;
        }
    }
    
    if(test['T'] <= test['R'])
        answer += "R";
    else answer += "T";
    if(test['F'] <= test['C'])
        answer += "C";
    else answer += "F";
    if(test['M'] <= test['J'])
        answer += "J";
    else answer += "M";
    if(test['N'] <= test['A'])
        answer += "A";
    else answer += "N";
    
    return answer;
}