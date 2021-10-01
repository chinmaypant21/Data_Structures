class Stack
{
    /**
     * In a stack, we add and remove elements only from the top of the stack.
     * We can not access an element directly that is not at the top of the stack
     * For implementing a stack, we need the size of stack, top pointer of stack to maintain
     * operations and a data structure (like array or linked list) to store elements.
     */
    constructor(size)
    {
        this.size = size;
        this.top  = -1; //when stack is empty so the top pointer will not pointing to any location of stack
        this.data = {};
    }

    
    push(element)
    {
        if(isFull())
        {
            console.log("Can not push to already full stack");
            return;
        }

        top++;
        this.data[top] = element;
    }

    pop()
    {
        if(isEmpty())
        {
            console.log("Can not pop from an empty stack");
            return;
        }
        top--;
    }

    //if top is less than 0 it means it is not poiting to any element of stack 
    //thus stack is empty
    isEmpty()
    {
        if (this.top < 0)
            return true;
        return false;
    }

    isFull()
    {
         if (this.top == this.size-1)
            return true;
        return false;

    }

    display()
    {
        console.log("[ ");
        for(let i=0;i<=top;i++)
        {
            console.log(data[i],", ");
        }
        console.log("]");
    }

}

s = new Stack(5);
console.log(s);