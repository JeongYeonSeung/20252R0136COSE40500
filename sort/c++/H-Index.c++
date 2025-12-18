#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] < i + 1) break;
        answer = i + 1;
    }
    return answer;
}

/*
n편 중, h번 이상 인용된 논문이 h편 이상이다.

정렬 -> 내림차순으로 한다.
6 5 3 1 0

6 -> 1편, 최소=6 -> 6번 이상 = 1편 이상있다 -> h = 1 ok
5 -> 2편, 최소=5 -> 5번 이상 = 2편 이상 -> h = 2 ok
3 -> 3편, 최소=3 -> 3번 이상 = 3편 이상 -> h = 3 ok
1 -> 4편, 최소=1 -> 1번 이상 = 4편 이상 

오름차순 정렬하면, idx+1편 중 최소 인용 횟수가 citations[i] 라는 의미 ->
idx+1 == citations[i] 면, h번 이상 인용된 논문이 h편이라는 의미.
*/