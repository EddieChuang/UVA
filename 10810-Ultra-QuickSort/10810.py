#Verdict: Time Limit Exceeded
#當右子數列大於左子數列時, 兩數才會交換, 右值移動的次數即為交換次數
def mergeSort(ary, left, size):   
    if size != 1: 
        n1 = int(size / 2)
        n2 = size - n1
        right = left + n1
        mergeSort(ary, left, n1)
        mergeSort(ary, right, n2)
        merge(ary, left, size)

def merge(ary, left, size):
    global count
    tmp = list()
    n1 = int(size / 2)
    n2 = size - n1
    right = left + n1
    i, j = 0, 0
    for k in range(0, size):
        if i == n1:
            tmp.append(ary[right + j])
            j += 1
        elif j == n2:
            tmp.append(ary[left + i])
            i += 1
        elif ary[left + i] < ary[right + j]:
            tmp.append(ary[left + i])
            i += 1
        else:
            count += (right + j) - (left + k)
            tmp.append(ary[right + j])
            j += 1
            
    for i in range(left, size):
        ary[left + i] = tmp[i]

n = int(input())
while n > 0:
    count = 0
    ary = [int(input()) for i in range(0, n)]
    mergeSort(ary, 0, len(ary))
    print (count)
    n = int(input())