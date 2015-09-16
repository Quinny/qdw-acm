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
