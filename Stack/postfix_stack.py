operator_dict = {
    '\0':0,
    '+':1,
    '-':1,
    '*':2,
    "/":2
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


def precedence(opr):
    return operator_dict[opr]


# statement = "a*d/e-b+c"
statement = "a+b*c-d/e"
postfix = ""
operator_precedence_stack = Stack(len(statement))

for symbol in statement:
    if(isOperator(symbol)):
        if(precedence(symbol) > precedence(operator_precedence_stack.atTop())):
            operator_precedence_stack.push(symbol)

        else:
            while(True):
                if(precedence(symbol)>precedence(operator_precedence_stack.atTop())):
                    operator_precedence_stack.push(symbol)
                    break

                else:
                    postfix+=operator_precedence_stack.pop()
    else:
        postfix+=symbol


while(operator_precedence_stack.atTop() != '\0'):
    postfix+= operator_precedence_stack.pop()

print("\nInfix: "+statement+"\nPostfix: "+postfix)

