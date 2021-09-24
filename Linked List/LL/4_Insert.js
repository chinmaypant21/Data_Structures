class Node
{
    constructor(value=0)
    {
        this.data=value
        this.next = null
    }
}

class List
{
    constructor(value=0)
    { 
        const firstNode = new Node(value)
        this.head = firstNode
        this.tail = firstNode
        this.length = 1
    }

    push(value)
    {
        const newNode = new Node(value)
        this.tail.next = newNode
        this.tail = newNode
        newNode.next = null
        this.length++
    }

    display()
    {
        var current = this.head;
        while(current != null)
        {
            console.log(current.data); 
            current = current.next;
        }
    }

    insert(value,index)
    {
        if(index > this.length || index<0){
            console.log("\nInvalid index for insert method\n")
            return;
        }

        const newNode = new Node(value);
        var index_pointer = this.head;
        if (index==this.length) this.tail=newNode;

        this.length++;
        /*If we have to insert at head, in that case there is no element before that
        so we have to change the statement for this case*/
        if(index==0) 
        {
            newNode.next=this.head;
            this.head=newNode;
            return;
        }

        for(let i=0;i<index-1;i++)
        {
            index_pointer = index_pointer.next;
        }
        newNode.next=index_pointer.next;
        index_pointer.next=newNode;
    }
}

l = new List(5)
l.push(6)
l.push(7)
l.push(8)
l.insert(0,4)
l.display()