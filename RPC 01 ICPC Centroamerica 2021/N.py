
import sys, math
input = sys.stdin.readline

def inp():
    return(int(input()))
    
ve2 = [None] * 40001
#for i in range(1, 40001):
#	ve2[i] = ve2[i-1]*2
	
ve5 = [None] * 60001
ve2[0] = 1
ve5[0] = 1
#for i in range(1, 60001):
#	ve5[i] = ve5[i-1]*5

def expMod2(e):
	if ve2[e] is not None:
		return ve2[e]
	if e%2 == 1:
		ve2[e] = 2*expMod2(e-1)
	else:
		ve2[e] = expMod2(e//2)*expMod2(e//2)
	return ve2[e]
	
def expMod5(e):
	if ve5[e] is not None:
		return ve5[e]
	if e%2 == 1:
		ve5[e] = 5*expMod5(e-1)
	else:
		ve5[e] = expMod5(e//2)*expMod5(e//2)
	return ve5[e]

while True:
	try:
		a, n = map(int,input().split())
		e2 = 0
		e5 = 0
		while(a%2 == 0):
			a = a/2
			e2 = e2+1
		while(a%5 == 0):
			a = a/5
			e5 = e5+1
		e2 *= n
		e5 *= n
		if n == 0:
			print("0 1")
		elif a != 1:
			print("Precision Error")
		else:
			if(e2 == e5):
				print(f"{e2} 1")
			elif(e2 < e5):
				delta = e5-e2
				print(f"{e5} {expMod2(delta)}")
			else:
				delta = e2-e5
				print(f"{e2} {expMod5(delta)}")
	except:
		break
		
