'''Write a Python program to store first year percentage of students in array. Write
function for sorting array of floating point numbers in ascending order using quick sort
and display top five scores.'''
perc = []
number_of_students = int(input("Enter the number of Students : "))
for i in range(number_of_students):
    perc.append(float(input("Enter the percentage of Student {0} : ".format(i + 1))))
print(perc)
# Function for performing partition of the Data
def percentage_partition(perc,start,end):
    pivot = perc[start]
    lower_bound = start + 1
    upper_bound = end
    while True:
        while lower_bound <= upper_bound and perc[lower_bound] <= pivot:
            lower_bound += 1
        while lower_bound <= upper_bound and perc[upper_bound] >= pivot:
            upper_bound -= 1
        if lower_bound <= upper_bound:
            perc[lower_bound],perc[upper_bound] = perc[upper_bound],perc[lower_bound]
        else:
            break
    perc[start],perc[upper_bound] = perc[upper_bound],perc[start]
    return upper_bound
def Quick_Sort(perc,start,end):
    while start < end:
        partition = percentage_partition(perc,start,end)
        Quick_Sort(perc,start,partition-1)
        Quick_Sort(perc,partition+1,end)
        return perc
def display_top_five(perc):
    print("Top Five Percentages are : ")
    if len(perc) < 5:
        start, stop = len(perc) - 1, -1
    else:
        start, stop = len(perc) - 1, len(perc) - 6
    for i in range(start, stop, -1):
        print(perc[i],end = " ")
while (True):
    print("\n--------------------MENU--------------------\n1. Perform Quick Sort on the Data\n2. Exit")
    ch = int(input("Enter your choice:"))
    if ch == 1:
        print("Percentages of Students after performing Quick Sort : ")
        sorted_percentage = Quick_Sort(perc,0,len(perc)-1)
        print(sorted_percentage)
        a = input("Do you want to display the Top 5 Percentages of Students (yes/no) : ")
        if a == 'yes':
            display_top_five(sorted_percentage)
    else:
        print("Invalid Choice!!")