def isvalid(cell):
    return 1<=cell[0]<=8 and 1<=cell[1]<=8

def getneighbors(cell):
    offset = [(2, 1), (-2,1), (2, -1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]
    ret = []
    for a in offset:
        if isvalid((cell[0]+a[0], cell[1]+a[1])):
            ret.append((cell[0]+a[0], cell[1]+a[1]))
    return ret



def path(start, end):
    tocheck = [(start, 0)]
    visited = {start: True}
    while tocheck:
        curr = tocheck[0][0]
        currlen = tocheck[0][1]
        tocheck.pop(0)
        if curr == end:
            return currlen
        for cell in getneighbors(curr):
            if cell not in visited:
                visited[cell] = True
                tocheck.append((cell, currlen+1))

print path((2, 1), (4, 5))
print path((1, 6), (2, 8))
print path((8, 1), (7, 2))
print path((8, 8), (4, 7))
print path((1, 1), (8, 8))
print path((1, 1), (1, 3))
