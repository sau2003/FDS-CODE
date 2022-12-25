'''Write a Python program to store marks scored in subject “Fundamental of Data
Structure” by N students in the class. Write functions to compute following:
a) The average score of class
b) Highest score and lowest score of class
c) Count of students who were absent for the test
d) Display mark with highest frequency'''

marks = []
present = []
absent = []
def marksobtain():
     n = int(input("Enter number of students:\n"))
     print("consider absent student's score as 0")
     for i in range(1, n + 1):
        s = int(input("Enter marks of students out of 50:",))
        marks.append(s)
        if (s > 0):
            present.append(s)
        else:
            absent.append(s)
            print("absent student score out of 50", marks)
marksobtain()
print(marks)
while(True):
    print("1. The average score of class \n2.Highest score and lowest score of class \n"
          "3. Count of students who were absent for the test\n4.Display mark with highest frequency")
    ch=int(input("enter your choice:"))
    if ch==1:
# Function for average
      def average():
          p = 0
          for i in present:
            p = p + i
            average = p / (len(present))
          print("average marks of class is:", average)
      average()
    elif ch==2:
# Function for highest and lowest marks
        def high_low():
            max_value=0
            for num in present:
                if (max_value== 0 or num > max_value):
                   max_value = num
            print('Maximum value:', max_value)
            min=present[0]
            for i in range (1,len(present)):
                if (present[i]<min):
                    min=present[i]
            print("lowest mark:", min)
        high_low()

    elif ch==3:
# Function for absent students
        def absent_length():
            print("count of students who are absent for the test:", len(absent))
        absent_length()
    elif ch<=4:
# Function for number with highest frequency
        def frequency():
            dict = {}
            count, itm = 0, ''
            for item in reversed(present):
                dict[item] = dict.get(item, 0) + 1
                if dict[item] >= count:
                     count, itm = dict[item], item
            return (itm)
        print(frequency())
    else:
        print("opps! wrong choice")
        break







