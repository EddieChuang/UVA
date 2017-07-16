def binarySearch(chimp, left, right, pivot):
    
    h = list()
    index = -1
    while left < right:
        mid = int((left + right) / 2)
        if chimp[mid] < pivot:
            left = mid + 1
        elif chimp[mid] > pivot:
            right = mid - 1
        else:
            index = mid
            break;
    if index == -1:
        index = right
    
    if chimp[index] == pivot:
        h.append(index - 1)
        h.append(index + 1)
    elif chimp[index] > pivot:
        h.append(index - 1)
        h.append(index)
    else:
        h.append(index)
        h.append(index + 1)
    
    while (str(chimp[h[0]]) == str(pivot)) or (str(chimp[h[1]]) == str(pivot)):
        if str(chimp[h[0]]) == str(pivot):
            h[0] -= 1
        if str(chimp[h[1]]) == str(pivot):
            h[1] += 1 
    
    return h

n = int(input())
chimp = input().split()
chimp = [int(x) for x in chimp]
chimp.insert(0, 'X')
chimp.insert(n + 1, 'X')

q = int(input())
luchu = input().split()

for x in luchu:
    h = binarySearch(chimp, 1, len(chimp) - 2, int(x))
    print(str(chimp[h[0]]) + ' ' + str(chimp[h[1]]))