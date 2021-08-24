function selectionSort(arr)
{
    for(let i=0;i<arr.length;i++)
    {
        var temp_index = i;
        for(let j=i+1;j<arr.length;j++)
        {
            if(arr[j]<arr[temp_index])  temp_index=j;
        }
     
        [arr[i], arr[temp_index]] = [arr[temp_index], arr[i]];
    }
}

arr = [1,4,5,0,2,3];
selectionSort(arr);
console.log(arr);