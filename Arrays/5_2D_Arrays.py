twoD_arr = [ [1,2], [2,3], [5,6] ]

#Accessing 2D arrays

#1
print(twoD_arr)

#2
for element in twoD_arr:
    print(element)

#3
for element in twoD_arr:
    for i in element:
        print(i)


row,col=5,5

#Other ways to define 2D arrays
twoD_arr = [[0]*col]*row
print(twoD_arr)

#
twoD_arr = [ [i for i in range(col)] for j in range(row) ]
print(twoD_arr)

#
oneD_arr = [i for i in range(col)] 
twoD_arr = [oneD_arr for j in range(row)]
print(twoD_arr)


#
twoD_arr.clear()
for i in range(row):
    column = []
    for j in range(col):
        column.append(0)
    twoD_arr.append(column)
print(twoD_arr)