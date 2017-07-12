def minHeapify(ages, root, n):
    left = 2 * root + 1
    right = 2 * (root + 1)
    if left < n:
        minHeapify(ages, left, n)
        if ages[root] > ages[left]:
            swap(ages, root, left)
    if right < n:
        minHeapify(ages, right, n)
        if ages[root] > ages[right]:
            swap(ages, root, right)
    
def heapSort(ages, n):
    for i in range(0, n):
        minHeapify(ages, 0, n - i)
        print(ages[0], end=' ')
        swap(ages, 0, n - i - 1)

def swap(ages, x, y):
    ages[x], ages[y] = ages[y], ages[x]

n = int(input())  
while n != 0:

    ages = input().split(" ");
    ages = [int(x) for x in ages]

    heapSort(ages, len(ages))   
    print ()
    n = int(input())
