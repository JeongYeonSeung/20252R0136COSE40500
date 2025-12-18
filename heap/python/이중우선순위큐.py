import heapq

def solution(operations):
    min_heap = []
    max_heap = []
    poped = set()
    
    for i, op in enumerate(operations):
        typ, n = op.split()
        if typ == 'I':
            heapq.heappush(min_heap, (int(n), i))
            heapq.heappush(max_heap, (int(n) * -1, i))
        else:
            if n == '-1':
                while min_heap and min_heap[0][1] in poped:
                    heapq.heappop(min_heap)
                if min_heap:
                    poped.add(heapq.heappop(min_heap)[1])
            else:
                while max_heap and max_heap[0][1] in poped:
                    heapq.heappop(max_heap)
                if max_heap:
                    poped.add(heapq.heappop(max_heap)[1])
    
    while min_heap and min_heap[0][1] in poped:
        heapq.heappop(min_heap)
        
    while max_heap and max_heap[0][1] in poped:
        heapq.heappop(max_heap)
        
    if not min_heap and not max_heap:
        return [0, 0]
    
    mn = min_heap[0][0] if min_heap else max_heap[0][0] * -1
    mx = -1 * max_heap[0][0] if max_heap else min_heap[0][0]
        
    return [mx, mn]