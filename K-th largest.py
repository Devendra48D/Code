import random
def kth(arr, k):
    k = len(arr) - k
    r = random.randint(0, len(arr)-1)
    pivot = arr[r]
    A1 = []
    A2 = []
    for i in range(len(arr)):
        if arr[i] < pivot:
            A1.append(arr[i])
        elif arr[i] > pivot:
            A2.append(arr[i])
    if k < len(A1):
        return kth(A1, k)
    elif k > len(arr)- len(A2):
        return kth(A2, k - (len(arr) - len(A2)))
    return pivot

