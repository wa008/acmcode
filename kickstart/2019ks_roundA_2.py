import queue

t = int(input())
fir = 0
while t>0:
    t -= 1
    fir += 1
    n, m = list(map(int, input().split()))
    ch = [0]*n
    for i in range(n):
        ch[i] = input()
    def che(x):
        global n
        global m
        global ch
        des = [[0,1],[0,-1],[1,0],[-1,0]]
        vis = [[0 for i in range(m)] for j in range(n)]
        qu = queue.Queue()
        ant = 0
        for i in range(n):
            for j in range(m):
                if ch[i][j] == '1':
                    qu.put([i,j,0])
                    vis[i][j] = 1
                    ant += 1
        while not qu.empty():
            i,j,now = qu.get()
            if now == x:
                continue
            for k in range(4):
                ni = i + des[k][0]
                nj = j + des[k][1]
                if ni>=0 and ni<n and nj>=0 and nj<m and vis[ni][nj] == 0:
                    vis[ni][nj] = 1
                    qu.put([ni,nj,now+1])
                    ant += 1
        if ant == n*m:
            return True
        mx1 = mx2 = -100000
        mn1 = mn2 = 100000
        
        for i in range(n):
            for j in range(m):
                if vis[i][j] == 0:
                    mx1 = max(mx1, i+j)
                    mn1 = min(mn1, i+j)
                    mx2 = max(mx2, i-j)
                    mn2 = min(mn2, i-j)
        if mx1-x<=mn1+x and mx2-x<=mn2+x:
            if mn1+x>=mx2-x:
                if (mn1+mx2)&1:
                    if mx1-x<mn1+x or mx2-x<mn2+x:
                        return True
                    else:
                        return False
                else:
                    return True
        return False
    

    che(1)
    l = 0
    r = m+n
    while l<r:
        mid = (l+r)>>1
        if che(mid):
            r = mid
        else:
            l = mid + 1
    print("Case #%d: %d" % (fir,l))
