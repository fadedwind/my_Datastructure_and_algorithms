def Qsort(A, p, r):
    if p < r:
        q = Partition(A, p, r)
        Qsort(A, p, q-1)
        Qsort(A, q+1, r)
    return A
    
def Partition(A, p, r):
    pivot = A[r]
    i = p - 1
    for j in range(p, r):
        if pivot >= A[j]:
            i = i + 1
            swap(A,i,j)
    swap(A,i+1,r)
    return i+1

def swap(A,i,j):
    A[i],A[j] = A[j],A[i]
    
A = [2,6,5,0,8,7,1,3]
Qsort(A,0,len(A)-1)
print(A)

#`for i in range(0,5)` 这个循环会执行5次。
# #Python中，`range(0,5)` 会生成一个包含0到4的整数序列，总共有5个数。
            
    