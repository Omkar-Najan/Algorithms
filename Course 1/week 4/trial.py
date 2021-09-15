n = int(input())

def printMid(low,high):
    mid = (low + high)//2
    if(mid == low or mid == high):
        return 0
    print(mid)

    print("larger Than = 1 smaller than = 0 ")
    flag = int(input())
    if(flag):
        printMid(mid+1 , high)
    else:
        printMid(low , mid-1)
    
printMid(1,n)