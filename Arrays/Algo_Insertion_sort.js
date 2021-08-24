function insertionSort(arr)
{
    for(var i=1;i<arr.length;i++)
    {
        if(arr[i]<arr[i-1])
        {
            var temp=arr[i];
            for(var j=i-1;j>=0;j--)
            {
                arr[j+1]=arr[j];
                if(j==0 || temp>arr[j-1])
                {
                    arr[j]=temp;
                    break;
                }
            }
        }
    }
}

var arr = [6,5,4,3,0,1];
insertionSort(arr);
console.log(arr);