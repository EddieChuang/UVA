ans = [0, 1, 2, 2]
for i in range(4, 77):    
    ans.append(ans[i - 2] + ans[i - 3])
while True:
    try:
        n = int(input())
        print(ans[n])    
        
    except EOFError:
        break