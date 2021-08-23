var twoD_array = [ [1,2], [2,3], [5,6] ];
console.log(twoD_array);

//Another method
twoD_array = new Array(3);

for (var i = 0; i < twoD_array.length; i++) {
  twoD_array[i] = new Array(2);
}

for(var i=0,counter=0; i<twoD_array.length; i++)
{
    for(var j=0; j<twoD_array[i].length;j++,counter++)
    {
        twoD_array[i][j] = counter;
    }
}
console.log(twoD_array);