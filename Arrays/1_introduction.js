var character_array = ['a','b','c','d','e']

character_array.push('f'); // O(1)
console.log("Insert at End");
console.log(character_array);

character_array.pop()  // O(1)
console.log("\nDelete at End");
console.log(character_array);

character_array.unshift('o');  // O(n)
console.log("\nInsert at Beginning");
console.log(character_array);

character_array.splice(2,0,'z'); //O(n)
console.log("\nInsert at index 2");
console.log(character_array);

character_array.splice(2,2); //O(n)
console.log("\nDelete 2 elements from index 2");
console.log(character_array);