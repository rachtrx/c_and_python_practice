import math
import random

arr = [random.randint(0, 50) for _ in range(9)]
print(arr)

def merge_sort(arr):

    if len(arr) == 1:
        return arr

    else:
        left_arr = arr[0:math.floor(len(arr)/2)]
        right_arr = arr[math.ceil(len(arr)/2):]
        print(left_arr, right_arr)

        left_sorted_arr = merge_sort(left_arr)
        right_sorted_arr = merge_sort(right_arr)

        result_arr = []
        
        while len(left_sorted_arr) != 0 and len(right_sorted_arr) != 0:
            print(len(right_sorted_arr), len(left_sorted_arr))
            if left_sorted_arr[0] < right_sorted_arr[0]:
                result_arr.append(left_sorted_arr.pop(0))
            elif right_sorted_arr[0] < left_sorted_arr[0]:
                result_arr.append(right_sorted_arr.pop(0))
        else:
            if len(left_sorted_arr) != 0:
                result_arr.extend(left_sorted_arr)
            else:
                result_arr.extend(right_sorted_arr)
        
        return result_arr

print(merge_sort(arr))