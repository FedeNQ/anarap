
import sys, math
input = sys.stdin.readline

def inp():
    return(int(input()))
    
t = inp()
for T in range(0, t):
	n = inp()
	print((((n*(n+1))//2 + (n*(n+1)*(2*n+1))//6)//2)%((1<<31)-1))
