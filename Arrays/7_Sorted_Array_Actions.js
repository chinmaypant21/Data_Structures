function insert_sorted(arr,to_insert)
{
    for(let i=arr.length;i>=0;i--)
    {
        if(to_insert>arr[i-1] || i==0)
        {
            arr[i]=to_insert
            return;
        }
        arr[i]=arr[i-1]
    }
}

var to_insert = 5;
var sorted_array= [1,3,6,11,13,14,18];
insert_sorted(sorted_array,to_insert);
console.log(sorted_array);