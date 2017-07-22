def fib(n):
    global ans 
    if ans[n] != 0:
        return ans[n]
    
    ans[n] += fib(n-1) + fib(n-2)
    return ans[n]

global ans
ans = [0 for x in range(51)]
ans[1], ans[2] = 1, 2
n = int(input())
while n != 0:
    print (fib(n))
    n = int(input())