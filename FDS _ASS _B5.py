''' Write a python program to store first year percentage of students in an array.
Write function for sorting array of floating point numbers in ascending order using:
a) Selection Sor
b) Bubble Sort and display top five scores'''

marks=[]
n = int(input("Enter number of students whose marks are to be displayed : "))
print("Enter marks for",n,"students (Press ENTER after every students marks): ")
for i in range(0, n):
    ele = int(input())
    marks.append(ele)
print("The marks of",n,"students are : ")
print(marks)

# Function for Selection Sort of elements
def Selection_Sort(marks):
    for i in range(len(marks)):
        min_idx = i
        for j in range(i + 1, len(marks)):
            if marks[min_idx] > marks[j]:
                min_idx = j
        marks[i], marks[min_idx] = marks[min_idx], marks[i]
    print("Marks of students after performing Selection Sort on the list : ")
    for i in range(len(marks)):
        print(marks[i],end=" ")

# Function for Bubble Sort of elements
def Bubble_Sort(marks):
    n = len(marks)
    for i in range(n - 1):
        for j in range(0, n - i - 1):
            if marks[j] > marks[j + 1]:
                marks[j], marks[j + 1] = marks[j + 1], marks[j]

    print("Marks of students after performing Bubble Sort on the list :")
    for i in range(len(marks)):
        print(marks[i],end=" ")

# Function for displaying top five marks
def top_five(a):
    print("Top five score are : ")
    cnt = len(a)
    if cnt < 5:
        start, stop = cnt - 1, -1
    else:
        start, stop = cnt - 1, cnt - 6

    for i in range(start, stop, -1):
        print("\t {0:.2f}".format(a[i]), end=" ")


while (True):
    print("\n---------------MENU---------------\n1. Selection Sort of the marks\n2. Bubble Sort of the marks\n3. Exit")
    ch=int(input("\n\nEnter your choice (from 1 to 3) : "))

    if ch==1:
        Selection_Sort(marks)
        a=input("\nDo you want to display top five marks from the list (yes/no) : ")
        if a=='yes':
            top_five(marks)
        else:
            print("\nwelcome....")

    elif ch==2:
        Bubble_Sort(marks)
        a = input("\nDo you want to display top five marks from the list (yes/no) : ")
        if a == 'yes':
            top_five(marks)
        else:
            print("\n welcome....")
    elif ch==3:
        print("\nsorry! wrong command.")
    else:
        print("\nEnter a valid choice!!")
        print("\nsorry! wrong command.")
        break





