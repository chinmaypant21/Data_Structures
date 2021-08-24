class Array:

    def __init__(self):
        self.length=0
        self.data=[]

    def at(self,index):
        if(index>self.length):
            print("\n[-]Undefined\n")
            return
        return self.data[index]

    def push(self,element):
        self.data.append(element)
        self.length+=1

    def pop(self):
        if(self.length==0):
            print("\n[-]Empty Array\n")
            return
        del(self.data[-1])
        self.length-=1

    def shift(self,index):
        for i in range(index,self.length-1):
            self.data[i] = self.data[i+1]
        del(self.data[-1])

    def delete(self,index):
        if(self.length<index+1):
            print("\n[-]Undefined\n")
            return
        self.shift(index)
        self.length-=1

    def __str__(self): 
        return " ".join([str(elem) for elem in self.data])

myArray = Array()
myArray.push(1)
myArray.push(2)
myArray.push(3)
myArray.push(4)
print(myArray) #after push

myArray.pop()
print(myArray) #after pop

myArray.delete(1) #delete from index 2
print(myArray)