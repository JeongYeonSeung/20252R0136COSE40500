def dfs(in_network, computers, i, n):
    in_network[i] = 1
    connections = computers[i]
    
    for idx in range(n):
        if connections[idx] == 0 or idx == i:
            continue
        if in_network[idx] == 1:
            continue
        else:
            dfs(in_network, computers, idx, n)
    
def solution(n, computers):
    in_network = [0 for idx in range(n)]
    answer = 0
    
    for i in range(n):
        if in_network[i] == 1:
            continue
        else:
            dfs(in_network, computers, i, n)
            answer += 1
        
    return answer

'''
네트워크 연결 여부 확인하기
하나의 노드는 하나의 네트워크에만 속할 수 있다
순회하면서, 아직 네트워크에 포함되지 않은 노드만 dfs를 돈다

dfs를 돌 때 이미 네트워크에 포함된 노드와 연결되어있다면 dfs 멈춘다
포함되지 않은 노드와 연결되어있다면 그 노드에 대해 다시 dfs
끊겼다면 새로운 네트워크

그리고 이거 역시 DFS 문제다.
'''