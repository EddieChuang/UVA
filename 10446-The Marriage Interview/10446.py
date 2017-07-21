def trib(n, back):
    
    global count
    if n <= 1:
        return 1
    if count[n][back] != 0:
        return count[n][back]
    
    count[n][back] = 1
    for i in range(1, back+1):    
        count[n][back] += trib(n - i, back)
    
    return count[n][back]

global count
count = [[0 for x in range(61)] for y in range(61)]
i = 1
while True:  
    try:
        n = input().split()
        n = [int(x) for x in n]
        if n[0] > 60:
            break
            
        trib(n[0], n[1])
        print ("Case " + str(i) + ": " + str(count[n[0]][n[1]]))
        i += 1
    except EOFError:
        break