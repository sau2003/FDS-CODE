'''Write a Python program to compute following computation on matrix:
a) Addition of two matrices
B) Subtraction of two matrices
c) Multiplication of two matrices
d) Transpose of a matrix'''

matrix= []
matrix_1= []
matrix_2= []
res=[[0,0,0,0,0], [0,0,0,0,0], [0,0,0,0,0], [0,0,0,0,0], [0,0,0,0,0]]
print("Enter the entries row wise:")
R1=int(input("enter a number of row in first matrix:"))
C1=int(input("enter a number of column in first matrix:"))
R2=int(input("enter a number of row in second matrix:"))
C2=int(input("enter a number of column in second matrix:"))
def enter(matrix,R,C):
	for i in range (R):
		e=[]
		for j in range(C):
			n=(int(input("enter a value of matrix["+str(i)+"]["+str(j)+"]::")))
			e.append(n)
			print("_________________________________________")
		matrix.append(e)

def display(matrix,R,C):
	for i in range(R):
		for j in range(C):
			print(matrix[i][j],end=' ')
		print()

def add_mat(matrix_1,matrix_2,R,C):
	for i in range(R):
		for j in range(C):
	         res [i][j]=matrix_1[i][j]+matrix_2[i][j]


def sub_mat(matrix_1,matrix_2,R,C):
	for i in range(R):
		for j in range(C):
			res [i][j] = matrix_1[i][j] - matrix_2[i][j]

def mul_mat(matrix_1,matrix_2,R,C):
	for i in range(R):
		for j in range(C):
			for k in range(C):
				res[i][j] =res[i][j]+ matrix_1[i][k]*matrix_2[k][j]

def trans_mat(matrix,R,C):
	for i in range(R):
		for j in range(C):
			res[i][j] = matrix[j][i]


def main():

		print("1.accept two matrices from user:\n2.show the matrices values:\n3.addition of two matrices:"
			  "\n4.subtraction of two matrices:\n5.multiplication of two matrices:\n6.transpose of  matrix:\n7.exit")
		ch= int(input("enter your choice"))
		if ch==1:
			print("please enter the values for first matrix:")
			enter(matrix_1,R1,C1)
			print("please enter the values for second matrix:")
			enter(matrix_2,R2,C2)
			main()
		elif ch==2:
			print("the value of first matrix is as follow :")
			display(matrix_1,R1,C1)
			print("the value of second matrix is as follow:")
			display(matrix_2,R2,C2)
			main()

		elif ch==3:
			print("the addition of two matrices are follow ..")
			if ((R1==R2) and (C1==C2)):
				add_mat(matrix_1,matrix_2,R1,C1)
				display(res,R1,C1)
			else:
				print("sorry!!! addition is not possible...")
			main()

		elif ch==4:
			print("the subtraction of two matrices are follow ..")
			if ((R1 == R2) and (C1 == C2)):
				sub_mat(matrix_1, matrix_2, R1, C1)
				display(res, R1, C1)
			else:
				print("sorry!!! subtraction is not possible...")
			main()

		elif ch==5:
			print("the multiplication of two matrices are as follow...")
			if (C1==R2):
				mul_mat(matrix_1, matrix_2, R2, C1)
				display(res,R2,C1)
			else:
				print("sorry!!! multiplication is not possible...")
			main()

		elif ch==6:
			print("before transpose of matrix the element in matrix are as follows:")
			display(matrix_1, R1, C1)
			print("after applying transpose on matrix element are as follows:")
			trans_mat(matrix_1, R1, C1)
			display(res, R1, C1)
			main()

		elif ch==7:
			exit
		else:
			print("please enter valid choice.")
main()












