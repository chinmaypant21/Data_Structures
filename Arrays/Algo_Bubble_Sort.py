def bubbleSort(arr):
    for i in range(0,len(arr)):
        for j in range(0,len(arr)-i-1):
             if(arr[j]>arr[j+1]):
                arr[j],arr[j+1] = arr[j+1],arr[j]

arr = [1,4,5,0,2,1]
bubbleSort(arr)
print(arr)