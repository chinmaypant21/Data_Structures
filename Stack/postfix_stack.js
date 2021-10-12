var operator_dict = {
    '\0':0,
    '+':1,
    '-':1,
    '*':2,
    "/":2
}

class Stack
{
    constructor(size)
    {
        this.size = size;
        this.top  = -1;
        this.data = {};
    }

    push(element)
    {
        if(this.isFull())
        {
            console.log("Can not push to already full stack");
            return;
        }

        this.top++;
        this.data[this.top] = element;
    }

    pop()
    {
        if(this.isEmpty())
        {
            console.log("Can not pop from an empty stack");
            return -1;
        }
        return this.data[this.top--];
    }

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
        for(var i=0;i<=this.top;i++)
        {
            console.log(this.data[i]<<", ");
        }
        console.log("]");
    }

    atTop()
    {
        if (this.top > -1)
            return this.data[this.top];

        else return '\0';
    }


    len()
    {
        return this.top+1;
    }
}

function isOperator(c)
{
    return Object.keys(operator_dict).includes(c)
}

function precedence(opr)
{
    return operator_dict[opr];
}

// statement = "a*d/e-b+c";
statement = "a+b*c-d/e";
postfix = "";
operator_precedence_stack = new Stack(statement.length);

for(var i=0; i<statement.length; i++)
{
    if(isOperator(statement[i]))
    {
        if(precedence(statement[i]) > precedence(operator_precedence_stack.atTop()))
        {
            operator_precedence_stack.push(statement[i]);
        }

        else
        {
            while(true)
            {
                if(precedence(statement[i])>precedence(operator_precedence_stack.atTop()))
                {
                    operator_precedence_stack.push(statement[i]);
                    break;
                }
                
                else
                {
                    postfix+=operator_precedence_stack.pop();
                }
            }
        }             
    }
    
    else
    {
        postfix+=statement[i];
    }
}

while(operator_precedence_stack.atTop() != '\0')
{
    postfix+= operator_precedence_stack.pop();
}
console.log("\nInfix: ",statement,"\nPostfix: ",postfix);

