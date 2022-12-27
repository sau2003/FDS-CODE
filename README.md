# SE-CODE
l= []
def get():
    n=int(input(" Enter no of students in class SE : "))
    for i in range (n):
         k=int(input(" Enter roll no = "))
         l.append(k)

def dis():
    for i in l:
         print(i, end=" ")

def linear(key):
    cnt=0
    for i in range(len(l)):
         if (key== l[i]):
              print(" Student attended session at ", i+1," location ")
              break
         else :
            cnt =cnt+1

    if (cnt-1==i):
        print(" Student did not attend session ")

def bin(low,high,array,x):
    while low <= high:
        mid = low + (high - low) // 2
        if array[mid] == x:
            print("yes")
            return mid
        elif array[mid] < x:
            low = mid + 1
        else:
            high = mid - 1
    return -1

def sentinel(array,n,key):
    last = array[n - 1]
    array[n - 1] = key
    i = 0
    while (array[i] != key):
        i += 1
    array[n - 1] = last
    if ((i < n - 1) or (array[n - 1] == key)):
        print(key, "is present at index", i)
    else:
        print("Element Not found")


def fibonaccisearch(array, x, n):
    fibMMm2 = 0
    fibMMm1 = 1
    fibM = fibMMm2 + fibMMm1
    while (fibM < n):
        fibMMm2 = fibMMm1
        fibMMm1 = fibM
        fibM = fibMMm2 + fibMMm1
    offset = -1
    while (fibM > 1):
        i = min(offset + fibMMm2, n - 1)
        if (array[i] < x):
            fibM = fibMMm1
            fibMMm1 = fibMMm2
            fibMMm2 = fibM - fibMMm1
            offset = i
        elif (array[i] > x):
            fibM = fibMMm2
            fibMMm1 = fibMMm1 - fibMMm2
            fibMMm2 = fibM - fibMMm1
        else:
            return i
    if (fibMMm1 and array[offset + 1] == x):
        return offset + 1
    return -1



get()
dis()
def main():
    a=1
    while(a!=0):
        key = int(input("\n Enter roll for searching whether particular \n"
                    " student attended training program or not:  "))
        ch=int(input("enter 1.binary 2.linear 3. sentinel 4.Fibonacci \n"))
        if ch==1:
            bin(0,len(l),l,key)
        elif ch==2:
            linear(key)
        elif ch==3:
            sentinel(l,len(l),key)
        elif ch==4:
            p=fibonaccisearch(l,key,len(l))
            if p==-1:
                print("not found")
            else:
                print("found at ",p+1)
        else:
            a=0
main()
