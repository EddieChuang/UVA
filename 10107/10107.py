arr = list()
while True:
    insert = int(input())
    for i in range(0, len(arr)):
        if arr[i] > insert:
            tmp = arr[i]
            arr[i] = insert
            insert = tmp
    arr.append(insert)
    
    size = len(arr)
    if size % 2 == 1:
        print (arr[int(size / 2)])
    else:
        print (int((arr[int(size / 2)] + arr[int(size / 2) - 1]) / 2))