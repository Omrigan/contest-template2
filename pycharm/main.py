__author__ = 'oleg'


def dist(t, darr):
    ret = 0
    for dx, dv  in zip(darr[:3],darr[3:]):
        ret+=(dx + t*dv)**2
    return ret


arr = map(lambda x: int(x), input().split(" "))
arr2 = map(lambda x: int(x), input().split(" "))

darr = map(lambda x, x2: x-x2, arr, arr2)[:-1]


