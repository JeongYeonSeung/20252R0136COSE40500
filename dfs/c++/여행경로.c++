#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> connects;
    
    for (auto& ticket: tickets) {
        string arv = ticket[0], dep = ticket[1];
        connects[arv].push(dep);
    }
    
    stack<string> st;
    st.push("ICN");
    
    while (!st.empty()) {
        string curr = st.top();
        if (!connects[curr].empty()) {
            st.push(connects[curr].top());
            connects[curr].pop();
        } else {
            answer.push_back(st.top());
            st.pop();
        }
    }
    
    reverse(answer.begin(), answer.end());
        
    return answer;
}

/*
주어진 항공권을 모두 이용한다. 이때 모든 공항은 항상 방문 가능하다.
2개 이상인 경우 알파벳 순서가 앞서는 경로로.
모든 엣지를 탐색하는 문제. 이때 엣지 순서에 따라 방문 불가능한 경우도 있다
재귀로 모든 경우를 하기에는 .. X
스택을 써보자
*/