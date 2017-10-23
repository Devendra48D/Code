def power_set(arr):
    size = 2 ** (len(arr))
    ret = []
    for i in range(size):
        temp = []
        for j in range(len(arr)):
            if i & (2 ** j):
                temp.append(arr[j])
        ret.append(temp)
    return ret

print power_set([1, 2, 3])

""" [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]] """
