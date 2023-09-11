outer_function_count = 0
inner_function_count = 0

def h(f, x):
    global outer_function_count
    global inner_function_count
    outer_function_count += 1
    print("outer function count #{}".format(outer_function_count))
    
    def h(g, x):
        global inner_function_count
        inner_function_count += 1
        print("inner function count #{}".format(inner_function_count))
        if x <= 1:
            print("inner function and x = {}".format(x))
            return 1
        else:
            print("inner function and x = {}".format(x))
            return 3 * g(f, x-1)
        
    inner_function_count = 0

    if x <= 1:
        print("outer function and x = {}".format(x))
        return 1
    else:
        print("outer function and x = {}".format(x))
        return 2 * f(h, x-1)

print("answer = {}".format(h(h, 5)))
