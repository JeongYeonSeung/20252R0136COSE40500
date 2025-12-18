#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool is_convertable(string s1, string s2) {
    int cnt = 0;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) cnt++;
    }
    return (cnt == 1) ? true : false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    if (words.end() == find(words.begin(), words.end(), target)) return 0;
    vector<bool> visited(words.size(), false);
    queue<pair<string, int>> q;
    q.push({begin, 0});
    
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        if (curr.first == target) {
            answer = curr.second;
            break;
        }
        for (int i = 0; i < words.size(); i++) {
            if (visited[i]) continue;
            if (is_convertable(curr.first, words[i])) {
                q.push({words[i], curr.second+1});
                visited[i] = true;
            }
        }
    }
    
    
    return answer;
}

/*
최소 단계를 찾는다
50개 이하의 단어, 중복되는 단어는 없다
한번 방문한 word에서 갈 수 있는 것들을 모두 큐에 넣고, 방문 처리 (돌아갈 필요가 없다?)
어차피 앞에서 방문한 경우보다 개수가 작은 경우는 없을테니... O(N^2) 으로 풀 수 있을 것 같다.
*/