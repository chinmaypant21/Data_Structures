
function bubbleSort(arr)
{
    for(var i=0;i<arr.length-1;i++)
    {
        for(var j=0;j<arr.length-i-1;j++)
        {
            if(arr[j]>arr[j+1])  [arr[j], arr[j+1]] = [arr[j+1], arr[j]];
        }
    }
}

arr = [1,4,5,0,2,1];
bubbleSort(arr);
console.log(arr);