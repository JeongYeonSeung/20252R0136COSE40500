from collections import defaultdict

def solution(m, n, puddles):
    answer = 0
    is_puddle = defaultdict(bool)
    DP = [[0 for _ in range(m)] for _ in range(n)]
    DIVIDE = 1000000007
    
    for p in puddles:
        x, y = p
        is_puddle[(y-1, x-1)] = True
    
    for i in range(1, m):
        if not is_puddle[(0, i)]:
            DP[0][i] = 1
        else:
            break
    
    for i in range(1, n):
        if not is_puddle[(i, 0)]:
            DP[i][0] = 1
        else:
            break
    
    for i in range(1, n):
        for j in range(1, m):
            if is_puddle[(i, j)]:
                continue
            else:
                DP[i][j] = (DP[i-1][j] + DP[i][j-1]) % DIVIDE
                            
    return DP[n-1][m-1] % DIVIDE

'''
어떤 좌표 i,j는 i-1,j / i,j-1에서 올 수 있다.
puddle을 지나는 경로는 불가능하다. 따라서 puddle

'''