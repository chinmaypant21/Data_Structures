array = [1,2,3,4,5,6,7]
print(array)

# Insert at End O(1)
array.append(8)
print(array)

# Delete from End O(1)
array.pop()
print(array)

# Insert at Beginning O(n)
array.insert(0,0)
print(array)

# Insert at index 3 O(n)
array.insert(3,9)
print(array)

# Remove from index 3 O(n) 
array.pop(3)
print(array)
