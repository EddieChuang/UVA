while True:
    try: 
        n = int(input())
        sum = 1
        for i in range(1, n + 1):
            sum *= i
        
        print(str(n) + "!")
        print(sum)
    except EOFError:
        break


