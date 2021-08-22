array1= [1,2,3,4,5]
array2= [4,6,7,8,9]
merged_array = []

first_array_iterator=0
second_array_iterator=0

while(first_array_iterator<len(array1) and second_array_iterator<len(array2)):

    if(array1[first_array_iterator]==array2[second_array_iterator]):

        merged_array.append(array1[first_array_iterator])
        #merged_array[i++]=array2[second_array_iterator++];  #Using this statement will cause duplicate elements
        first_array_iterator+=1
        second_array_iterator+=1

    elif(array1[first_array_iterator]<array2[second_array_iterator]):
        merged_array.append(array1[first_array_iterator])
        first_array_iterator+=1

    else:
        merged_array.append(array2[second_array_iterator])
        second_array_iterator+=1

#when elements of any of those array are completely used, then we can add elements of second array directly
if(first_array_iterator==len(array1)):

    while(second_array_iterator<len(array2)):
        merged_array.append(array2[second_array_iterator])
        second_array_iterator+=1

else:
    while(first_array_iterator<len(array1)):
        merged_array.append(array2[second_array_iterator])
        second_array_iterator+=1

print(merged_array)