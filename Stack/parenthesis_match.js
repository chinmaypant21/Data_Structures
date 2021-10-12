
/*LIST FOR PERFORMING STACK OPERATIONS*/
class Node
{
    constructor(value)
    {
        this.data = value;
        this.next = null;
    }
    
    get_data()
    {
        return this.data;
    }
}

class List
{
    constructor(value=null)
    {
        if(value==null)
        {
            this.list_length=0;
            return
        }
        this.newNode = new Node(value)
        this.head = this.newNode;
        this.tail = this.newNode;
        this.tail.next = null;
        this.list_length = 1;
    }

    insert(index,value)
    {
        if(index > this.list_length || index<0)
        {
            console.log("exception: List 'insert' method:  passed index '",
                        index,"' not in index range [0," ,this.list_length, "]\n");
            exit(-1);
        }

        let newNode = new Node(value);
        let index_pointer = this.head;

        if(index == this.list_length) 
            this.tail = newNode;

        this.list_length++;
        if(index==0) 
        {
            newNode.next = this.head;
            this.head    = newNode;
            this.tail    = newNode;
            return newNode;
        }

        for(let i=0; i<index-1; i++)
        {
            index_pointer = index_pointer.next;
        }
        newNode.next       = index_pointer.next;
        index_pointer.next = newNode;
        return newNode;
    }

    remove(index)
    {
        if(index > this.list_length-1 || index<0){
            console.log("\nInvalid index for remove method\n");
            return null;
        }
        this.list_length--;

        if(index==0)
        {
            let return_node = this.head;
            this.head=this.head.next;
            return return_node;
        }

        index_pointer = this.head;
        for(let i=0;i<index-1;i++) index_pointer = index_pointer.next;
        return_node = index_pointer.next;
        index_pointer.next = index_pointer.next.next;
        if(index_pointer.next==null) this.tail = index_pointer;

        return return_node;
    }

    len()
    {
        return this.list_length;
    }

    display()
    {
        current = this.head;
        if (current == null)
        {
            console.log("[]\n");
            return;
        }
        while(current != NULL)
        {
            console.log(current.data,"\n"); 
            current = current.next;
        }
    }
}


class Stack
{
    constructor(size)
    {
        this.size = size;
        this.top = null;
        this.data = new List(); /////////////////
    }

    push(element)
    {
        if(this.isFull())
            return;

        this.top = this.data.insert(0,element);
        
    }

    pop()
    {
        if(this.isEmpty())
            return -1;

        this.top = this.data.remove(0);
        return this.top.get_data();
    }

    isFull()
    {
        if (this.data.len() == this.size)
            return true;
        return false;

    }

    isEmpty()
    {
        if (this.data.len() == 0)
            return true;
        return false;
    }

    display()
    {
        this.data.display();
    }
}


text = String("console.log('Hello there its a normal text')))\nfunction fun(e){{return e})");

parenthesis   = new Stack(text.length);
curly_bracket = new Stack(text.length);

col_counter  = 1
line_counter = 1

for(let i of text)
{
    if(i=='(')
        parenthesis.push(1);
    else if(i==')')
    {
        if(parenthesis.pop() == -1)
        {
            console.log("\n[-]Parenthesis not opened properly at col ",col_counter,
            " and line ",line_counter);
        }
    }

    else if(i=='{')
        curly_bracket.push(1);
    
    else if(i=='}')
    {
        if(curly_bracket.pop() == -1)
        {
            console.log("\n[-]Curly Brackets not opened properly at col ",col_counter,
            " and line ",line_counter);
        }
    }

    else if(i=='\n')
    {
        line_counter++;
        col_counter=0;
    }

    col_counter++;
}

if(!parenthesis.isEmpty())
    console.log("\n[-]Parenthesis not closed properly\n");

if(!curly_bracket.isEmpty())
    console.log("\n[-]Curly Brackets not closed properly\n");
