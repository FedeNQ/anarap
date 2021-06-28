import sys, math
input = sys.stdin.readline
 
############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(float,input().split()))
    

x = inp()

if x == 1:
	print("0 0")
else:
	ans1 = x
	ans2 = 1
	for k in range(2, 200):
		L = 2*k-1
		R = int(x**(1/k)*k)
		aux = x
		for asd in range(1, k+1):
			aux *= asd
		while(L < R):
			M = (L+R)//2
			cur = 1
			for asd in range(0, k):
				cur *= M-asd
			if(cur >= aux):
				R = M
			else:
				L = M+1
		M = L
		cur = 1
		for asd in range(0, k):
			cur *= M-asd
		if cur == aux and M < ans1:
			ans1 = M
			ans2 = k
	print(f"{ans1} {ans2}")
