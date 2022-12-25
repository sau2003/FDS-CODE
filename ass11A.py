'''a) Write a Python program to store roll numbers of student in array who attended
training program in random order. Write function for searching whether particular
student attended training program or not, using Linear search.

b) Write a Python program to store roll numbers of student array who attended training
program in sorted order. Write function for searching whether particular student
attended training program or not, using Binary search and Fibonacci search'''

array = []
n = int(input("Enter the total no. of students who attended the training program: "))
for i in range(n):
    r = int(input("Enter the roll no. of students who attended the training program: "))
    array.append(r)
search_element = int(input("Enter the roll no. that you want to search : "))
array.sort()
start=0

def linear_search(x, y):
    for i in x:
        if i == y:
            return 1
    return -1


def sentinel_search(students_attend, search_element, n):
    # Last element of the array
    last = students_attend[n - 1]
    students_attend[n - 1] = search_element
    i = 0
    while (students_attend[i] != search_element):
        i += 1
    students_attend[n - 1] = last
    if ((i < n - 1) or (search_element == students_attend[n - 1])):
        return 1
    else:
        return -1

def binary_search(students_attend,search_element,start,n):

    if start > n:
        return -1

    mid = (start+n)//2

    if search_element == students_attend[mid]:
        return mid

    if search_element < students_attend[mid]:
        return binary_search(students_attend,search_element,start,mid-1)
    else:
        return binary_search(students_attend,search_element,mid+1,n)

def fibonacci_search(students_attend, search_element, n):
    fibm2 = 0
    fibm1 = 1
    fibM = fibm2 + fibm1

    while (fibM < n):
        fibm2 = fibm1
        fibm1 = fibM
        fibM = fibm2 + fibm1

    offset = -1

    while (fibM > 1):

        i = min(offset+fibm2, n-1)

        if (students_attend[i] < search_element):
            fibM = fibm1
            fibm1 = fibm2
            fibm2 = fibM - fibm1
            offset = i

        elif (students_attend[i] > search_element):
            fibM = fibm2
            fibMMm1 = fibm1 - fibm2
            fibm2 = fibM - fibm1

        else :
            return i

    if(fibm1 and students_attend[offset+1] == search_element):
        return offset+1

    else:
        return -1


while(True):
    print("1) Linear search\n2) Sentinal search\n3) binary_search\n4)  fibonacci_search")
    ch = int(input("Enter your choice "))

    if ch == 1:
       result = linear_search(array, search_element)
       if result == -1:
          print("The entered roll no. did not attend the training program.")
       else:
        print("The entered roll no. has attended the training program.")

    elif ch == 2:
         result = sentinel_search(array, search_element, n)
         if result == -1:
            print("The entered roll no. did not attend the training program.")
         else:
           print("The entered roll no. has attended the training program.")

    elif ch == 3:
         result = binary_search(array,search_element,start,n)
         if result == -1 :
             print("The entered roll no. did not attend the training program.")
         else:
           print("The entered roll no. has attended the training program.")

    elif ch== 4:
         result = fibonacci_search(array, search_element, n)
         if result == -1 :
            print("The entered roll no. did not attend the training program.")
         else:
           print("The entered roll no. has attended the training program.")

    else:
       print("Sorry wrong choice")
       break





