from collections import defaultdict

def solution(genres, plays):
    all_cnt = defaultdict(int)
    cnt = defaultdict(list)
    n = len(plays)
    answer = []
    
    for i in range(n):
        genre, play = genres[i], plays[i]
        all_cnt[genre] += play
        cnt[genre].append((play, i))
        
    sorted_g = sorted(all_cnt.keys(), key=lambda x: all_cnt[x], reverse=True)
    
    for g in sorted_g:
        songs = cnt[g]
        sorted_s = sorted(songs, key=lambda x:(-x[0], x[1]))
        answer += [s[1] for s in sorted_s][:2]
        
    return answer