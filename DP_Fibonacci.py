#+++++++++++++++++++++++++++++++++++++++++++++++++++++
# Generate the n-th number in the Fibonacci sequence
# 0, 1, 1, 2, 3, 5, 8, 13, 21, .....
#+++++++++++++++++++++++++++++++++++++++++++++++++++++

# A naive Recursive solution
def fib_rec(n):
    if n == 0 or n == 1:
        result = n
    else:
        result = fib_rec(n-1) + fib_rec(n-2)
    return result

#+++++++++++++++++++++++++++++++++++++++++++++++++++++
# A Bottom-up solution
def fib_bu(n):
    if n == 0 or n == 1:
        return n
    bottom_up = [None] * (n+1)
    bottom_up[0] = 0
    bottom_up[1] = 1
    for i in range(2, n+1):
        bottom_up[i] = bottom_up[i-1] + bottom_up[i-2]
    return bottom_up[n]

#+++++++++++++++++++++++++++++++++++++++++++++++++++++
# A Memoization-based solution
def fib(n, memo):
    if memo[n] is not None:
        return memo[n]
    if n == 0 or n == 1:
        result = n
    else:
        result = fib(n-1, memo) + fib(n-2, memo)
    memo[n] = result
    return result

def fib_memo(n):
    memo = [None] * (n + 1)
    return fib(n, memo)

#+++++++++++++++++++++++++++++++++++++++++++++++++++++

