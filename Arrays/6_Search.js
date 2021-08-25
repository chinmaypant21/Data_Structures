array = [1, 4, 46, 37, 8, 52, 0, 3, 43, 5, 6, 7, 54]

function linear_search(array,to_find)
{
    for(var i=0;i<array.length;i++)
    {
        if (array[i]==to_find) return i;
    }
    return -1;
}

/*
Time Complexity for linear search:
Best case O(1) when element found at first place
Worst case O(n) when element found at end
Avg case O(n)
*/

index = linear_search(array,54);
console.log("\nLINEAR SEARCH:");
if(index!=-1) console.log("Number found at index ",index);
else console.log("Number not present in array");

function binary_search(array,to_find,end=array.length-1,start=0)
{
    if (end>=start)
    {
        middle=parseInt((start+end)/2);
        if (to_find>array[middle])
            return binary_search(array,to_find,end,middle+1);

        else if (to_find<array[middle])
            return binary_search(array,to_find,middle-1,start);

        else return middle;
    }

    else return -1;
}

array.sort(function(a, b){return a-b});
//We need a sorted array for performing binary search
console.log("\nSorted Array: ",array);


console.log("\nBINARY SEARCH: ");
index = binary_search(array,8);
if(index!=-1) console.log("Number found at index ",index);
else console.log("Number not present in array");