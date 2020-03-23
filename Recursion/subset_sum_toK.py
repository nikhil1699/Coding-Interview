def Sumk(li,k,res):
    if k == 0:
        print(res[1:])
        return
    if len(li) == 0:
        return
    if k < 0:
        return
    Sumk(li[1:],k,res)
    res = res+" "+str(li[0])
    Sumk(li[1:],k-li[0],res)

n = int(input())
li = [int(i) for i in input().split()]
k = int(input())
res = ""
Sumk(li,k,res)