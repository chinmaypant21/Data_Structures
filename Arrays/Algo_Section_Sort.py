
def selectionSort(arr):

    for i in range(len(arr)):
        temp_index = i
        for j in range(i+1,len(arr)):
            if(arr[j]<arr[temp_index]):
                temp_index=j
        arr[i],arr[temp_index] = arr[temp_index],arr[i]

arr = [1,4,5,0,2,3]
selectionSort(arr)
print(arr)