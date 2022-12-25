#PROBLEM NO 1:
'''In second year computer engineering class, group A student’s play cricket, group B
students play badminton and group C students play football.
Write a Python program using functions to compute following: -
a) List of students who play both cricket and badminton
b) List of students who play either cricket or badminton but not both
c) Number of students who play neither cricket nor badminton
d) Number of students who play cricket and football but not badminton'''
classroom=[]
group_A=[]
group_B=[]
group_C=[]
def universalset():
    n=int(input("enter a total no of student in class:"))
    for i in range(n):
        u = int(input("enter a roll no. of student in class:"))
        classroom.append(u)
universalset()
print(classroom)

def playingcricket():
    n=int(input("enter a how many student play a cricket:"))
    for i in range(n):
        c=int(input("enter a roll no. of student playing cricket:"))
        group_A.append(c)
playingcricket()
print(group_A)

def playingbadminton():
    m=int(input("enter a how many student play a badminton:"))
    for i in range(m):
        b=int(input("enter a roll no. of student playing badminton:"))
        group_B.append(b)
playingbadminton()
print(group_B)

def playingfootball():
    o=int(input("enter a how many student play a football:"))
    for i in range(o):
         f=int(input("enter a roll no. of student playing football:"))
         group_C.append(f)
playingfootball()
print(group_C)
while(True):
    print("1.List of students who play both cricket and badminton\n2.List of students who play either cricket or badminton but not both"
          "\n3.Number of students who play neither cricket nor badminton\n4.Number of students who play cricket and football but not badminton")
    ch = int(input("enter a your choice"))
#case 1 : students who play both cricket and badminton
    if ch==1:
       def unionA_B(x,y):
           either_note = []
           for i in x:
               if i in y:
                   either_note.append(i)
           print("students who play both cricket and badminton:",either_note)
       unionA_B(group_A,group_B)


#case 2 : students who play either cricket or badminton but not both
    elif ch==2:
        def intersectA_B():
            cri_or_bad=[]
            for i in group_A:
                if i not in group_B:
                    cri_or_bad.append(i)
            for j in group_B:
                if j not in group_A:
                    cri_or_bad.append(j)
            print(" students who play either cricket or badminton but not both:",cri_or_bad)
        intersectA_B()

#case 3 :Number of students who play neither cricket nor badminton
    elif  ch==3:
        def nei_cri_nor_bad():
            uni_cri_bad=[]
            uni_cri_bad.extend(group_A)
            for j in group_B:
                if j not in group_A:
                    uni_cri_bad.append(j)
            print(uni_cri_bad)
            not_cri_bad=[]
            for i in classroom:
                if i not in uni_cri_bad:
                    not_cri_bad.append(i)
            print(not_cri_bad)
            print("Number of students who play neither cricket nor badminton:",len(not_cri_bad))
        nei_cri_nor_bad()

#case 4 :Number of students who play cricket and football but not badminton
    elif ch==4:
        cri_foot=[]
        cri_foot.extend(group_A)
        for i in group_C:
            if i not in group_A:
                cri_foot.append(i)
        cri_foot_not_bad=[]
        for j in cri_foot:
            if j not in group_B:
                cri_foot_not_bad.append(j)
        print(cri_foot_not_bad)
        print("Number of students who play cricket and football but not badminton:",len(cri_foot_not_bad))

    else:
        print("opps! wrong choice")









