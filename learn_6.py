
def my_compute(a,b,func):
    print(func(a,b))

def my_add(a,b):
    return a+b

def my_minus(a,b):
    return a-b

if __name__ == "__main__":
    a,b = 3,5
    func_list = [my_add,my_minus]
    for func in func_list:
        my_compute(a,b,func)