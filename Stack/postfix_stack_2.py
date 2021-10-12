operator_dict = {
    '\0':(-1,-1),
    '+':(1,2),
    '-':(1,2),
    '*':(3,4),
    "/":(3,4),
    "^":(6,5),
    "(":(7,0),
    ")":(0,None)
}

class Stack:
    def __init__(self,size):
        self.size = size
        self.top  = -1
        self.data = [None]*size
    

    def push(self,element):
        if(self.isFull()):
            print("Can not push to already full stack")
            return
        self.top += 1
        self.data[self.top] = element
    

    def pop(self):
        if(self.isEmpty()):
            print("Can not pop from an empty stack")
            return -1
        self.top -= 1
        return self.data[self.top+1]
    

    def isEmpty(self):
        if (self.top < 0):
            return True
        return False
    

    def isFull(self):
        if (self.top == self.size-1):
            return True
        return False

    def atTop(self):
        if (self.top > -1):
            return self.data[self.top]
        else:
             return '\0'
    
    def length():
        return self.top+1
    


def isOperator(c):
    return (c in operator_dict.keys())


def out_precedence(opr):
    return operator_dict[opr][0]

def in_precedence(opr):
    return operator_dict[opr][1]

statement = "((a+b)*c)-d^e^f"
postfix = ""
operator_stack = Stack(len(statement))

for item in statement:
    if(isOperator(item)):
        if(item==')'):
            while(in_precedence(operator_stack.atTop()) != out_precedence(item)):
                postfix+=operator_stack.pop()
            operator_stack.pop()

        elif(out_precedence(item) > in_precedence(operator_stack.atTop())):
            operator_stack.push(item)

        else:
            while(out_precedence(item) < in_precedence(operator_stack.atTop())):
                postfix+=operator_stack.pop()
            operator_stack.push(item)
    else:
        postfix+=item

while(operator_stack.atTop() != '\0'):
    postfix+= operator_stack.pop()

print("\nInfix: "+statement+"\nPostfix: "+postfix)

