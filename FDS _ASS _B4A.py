'''a) Write a Python program to store roll numbers of student in array who attended
training program in random order. Write function for searching whether particular
student attended training program or not, using Linear search and Sentinel search. '''
L=[]
def get():
    n=int(input ("Enter no of students in class SE: "))
    for i in range (n) :
        k=int(input ( "Enter roll no= ") )
        L . append (k)
get ()

def dis():
    for i in L:
       print(i,end=" ")
dis ()

def search():
    i=0
    key=int(input("enter a roll of searching whether particular student attended training program or not"))
    while(i<len(L)):
          if key==L[i]:
              print ("Student attended session at", i, "location")
              break
          i+=1
    if(i==len(L)):
        print ("Student did not attend session")
def sentinel() :
     item=int(input("Enter roll for searching whether particular student attended training program or not:"))
     last=L[-1]
     L[-1]=item
     i=0
     while(item!=L[i]):
        i+=1
     L[-1]=last
     if(i<len(L)-1 or item ==L[-1]):
         print ("Roll no. is found at",i,"location")
     else:
         print("No is not found")

while(True):
      print ("\n1. Linear Search using for While \n2.Sentinel Search")
      ch=int(input("Enter choice:"))
      if(ch==1):
          search()
      if(ch==2):
         sentinel ()
         break
