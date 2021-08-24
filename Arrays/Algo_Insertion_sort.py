def insertionSort(arr):
    for i in range(len(arr)):
        if (arr[i]<arr[i-1]):
            temp=arr[i]
            for j in range(i-1,-1,-1):
                arr[j+1]=arr[j]
                if(j==0 or temp>arr[j-1]):
                    arr[j]=temp
                    break

arr = [6,5,4,3,0,1]
insertionSort(arr)
print(arr)