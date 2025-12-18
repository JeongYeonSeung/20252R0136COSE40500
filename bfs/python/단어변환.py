'''
begin -> target
1. 한번에 한개 알파벳 교체
2. words에 있는 단어로만

최소 횟수에 초점을 맞춰보면 bfs일듯.
각 단어의 길이는 같고, 3 - 10.
중복되는 단어는 없음.
시간 복잡도는 별로 안 클 것 같다
하나의 알파벳만 바꿔서 만들 수 있는지 판별할 수 있어야함.
같은 글자 수가 몇 개인지 판별. for문으로?
'''
from collections import deque

def solution(begin, target, words):
    word_map = {}
    queue = deque([begin])
    word_len = len(words[0])
    dist = [0 for idx in range(len(words))]
    visited = [0 for idx in range(len(words))]
    
    for i in range(len(words)):
        word_map[words[i]] = i
    
    if word_map.get(target, -1) == -1:
        return 0
        
    while len(queue) > 0:
        cur = queue.popleft()
        cur_idx = word_map.get(cur, -1)
        for i in range(len(words)):
            if cur_idx == i:
                continue
            if visited[i] == 1:
                continue
            if count_same_alph(cur, words[i]) == word_len - 1:
                queue.append(words[i])
                visited[i] = 1
                if cur_idx == -1:
                    dist[i] = 1
                else:
                    dist[i] = dist[cur_idx] + 1

    print(dist)
    return dist[word_map[target]]

def count_same_alph(word_1, word_2):
    count = 0
    for i in range(len(word_1)):
        if word_1[i] == word_2[i]:
            count += 1
    
    return count
    