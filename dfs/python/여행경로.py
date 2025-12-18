from collections import defaultdict, deque

def solution(tickets):
    answer = []
    connects = defaultdict(list)
        
    for arr, dep in tickets:
        connects[arr].append(dep)
    
    for key in connects:
        connects[key].sort(reverse=True)
    
    stack = deque(['ICN'])
    path = []
    
    while stack:
        top = stack[-1]
        if connects[top]:
            stack.append(connects[top].pop())
        else:
            path.append(stack.pop())
    
    return path[::-1]


'''
1. 배열로 주어지는 항공권을 모두 사용해야한다.
2. 가능한 경로가 2개 이상 -> 알파벳 순서가 앞서는 경로를 return
3. 항상 모든 도시를 방문할 수 있다.
4. ICN에서 출발한다.

백트래킹? 
'''