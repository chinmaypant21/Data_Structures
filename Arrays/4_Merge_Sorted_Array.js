var array1= [1,2,3,4,5];
var array2= [4,6,7,8,9];
var merged_array = [];

var first_array_iterator=0;
var second_array_iterator=0;

while(first_array_iterator<array1.length && second_array_iterator<array2.length)
{
    if(array1[first_array_iterator]==array2[second_array_iterator])
    {
        merged_array.push(array1[first_array_iterator++]);
        // merged_array[i++]=array2[second_array_iterator++];  /*Using this statement will cause duplicate elements*/
        second_array_iterator++;
    }

    else if(array1[first_array_iterator]<array2[second_array_iterator])
    {
        merged_array.push(array1[first_array_iterator++]);
    }

    else
    {
        merged_array.push(array2[second_array_iterator++]);
    }
}

//when elements of any of those array are completely used, then we can add elements of second array directly
if(first_array_iterator==array1.length)
{
    while(second_array_iterator<array2.length)
    {
        merged_array.push(array2[second_array_iterator++]);
    }
}

else
{
    while(first_array_iterator<array1.length)
    {
        merged_array.push(array2[second_array_iterator++]);
    }
}

console.log(merged_array);