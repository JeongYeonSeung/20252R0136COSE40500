from collections import deque

def solution(prices):
    answer = [0] * len(prices)
    st = deque([])
    
    for time, price in enumerate(prices):
        if not st:
            st.append((time, price))
        else:
            while st:
                top_t, top_p = st[-1]
                if price >= top_p:
                    st.append((time, price))
                    break
                else:
                    pop = st.pop()
                    answer[pop[0]] = time - pop[0]
            
            if not st:
                st.append((time, price))
    
    last = len(prices) - 1
    while st:
        pop = st.pop()
        answer[pop[0]] = last - pop[0]
        
    return answer