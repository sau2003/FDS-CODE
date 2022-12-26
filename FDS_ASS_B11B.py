'''Write a Python program to store roll numbers of student array who attended training
program in sorted order. Write function for searching whether particular student
attended training program or not, using Binary search and Fibonacci search'''
a=[]
n = int(input("Enter number of students present : "))
for i in range(n):
    elem=int(input("Enter the roll no. of student:"))
    a.append(elem)
print(a)


def binary_search():
    start=0
    target = int(input("Enter the roll no. to be searched in list:"))
    end=len(a)-1
    while(start<=end):
        mid=int((start+end)/2)
        if(a[mid]==target):
            print("Roll no.",target,"is present at index",mid)
            break
        elif(target>a[mid]):
            start=mid+1
        elif(target<a[mid]):
            end=mid-1
    else:
        print("Roll no.",target,"not found in list")

def fibonacci_search():
    target = int(input("Enter the roll no. to be searched in list:"))
    n=len(a)
    fibn_2=0
    fibn_1=1
    fibn=fibn_1+fibn_2
    while(fibn<=n):
        fibn_2=fibn_1
        fibn_1=fibn
        fibn=fibn_1+fibn_2

    offset=-1
    while(fibn_1!=0):
        i=min((offset+fibn_2),n-1)
        if(target>a[i]):
            fibn=fibn_1
            fibn_1=fibn_2
            fibn_2=fibn-fibn_1
            offset=i
        elif(target<a[i]):
            fibn=fibn_2
            fibn_1=fibn_1-fibn_2
            fibn_2=fibn-fibn_1
        elif(target==a[i]):
            print("Roll no.",target,"is present at index",i)
            break
    else:
        print("Roll no.",target,"not found in list")

while(True):
     print("1.Binary Search\n2.Fibonacci Search")
     choice1=int(input("Enter the choice:"))
     if(choice1==1):
        binary_search()
     if(choice1==2):
        fibonacci_search()

