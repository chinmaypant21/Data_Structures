array = [1, 4, 46, 37, 8, 52, 0, 3, 43, 5, 6, 7, 54]

def linear_search(array,to_find):
    for i,element in enumerate(array):
        if element==to_find:
            return i
    return -1
#Time Complexity for linear search:
'''
Best case O(1) when element found at first place
Worst case O(n) when element found at end
Avg case O(n)
'''

print("\nLINEAR SEARCH:")
if (a:=linear_search(array,54))!=-1:
    print("Number found at index",a)
else:
    print("Number not present in array")

def binary_search(array,to_find,end=len(array)-1,start=0):

    if end>=start:
        middle=int((start+end)/2)
        if to_find>array[middle]:
            return binary_search(array,to_find,end,middle+1)

        elif to_find<array[middle]:
            return binary_search(array,to_find,middle-1,start)

        else:
            return middle
    else:
        return -1

array.sort()
#We need a sorted array for performing binary search
print("\nSorted Array: ",array)


print("\nBINARY SEARCH: ")
if (a:=binary_search(array,54))!=-1:
    print("Number found at index",a)
else:
    print("Number not present in array")