# A wrapper which memoizes function return values
# and provides them to subsequent calls.  Useful for
# dynamic programming problems where recursive solutions are simple.
# Speeds up Naive recursive solutions
def memoize(func):
    cache = {}
    def wrap(*args):
        if args in cache:
            return cache[args]
        ret = func(*args)
        cache[args] = ret
        return ret
    return wrap

@memoize
def fib(n):
    if n < 2:
        return n
    return fib(n - 1) + fib(n - 2)

for i in range(100):
    print fib(i)
