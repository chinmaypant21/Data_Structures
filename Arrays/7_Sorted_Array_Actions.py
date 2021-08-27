def insert_sorted(arr,to_insert):
    arr.append(0)
    for i in range(len(arr)-1,-1,-1):
        # print(i)
        if(to_insert>arr[i-1] or i==0):
            arr[i]=to_insert
            return
        arr[i]=arr[i-1]

def checkSorted(arr):
    for i in range(len(arr)):
        if(arr[i]<arr[i-1]):
            return False
    return True

to_insert = 5
sorted_array= [1,3,6,11,13,14,18]
insert_sorted(sorted_array,to_insert)
print(sorted_array)
