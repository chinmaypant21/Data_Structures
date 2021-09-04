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

    /* For removing Node from a given index we have to assign the next pointer of the previous node
    from the index node to the next node of the index node, due to which index node will be thrown out
    of the linked list.
    previous.next = index.next  ::: -. previous. next = previous.next.next
    */
    remove(index)
    {
        if(index > this.length-1 || index<0){
            console.log("\nInvalid index for remove method\n")
            return;
        }

        this.length--;
        if(index==0)
        {
            this.head=this.head.next;
            return;
        }

        var index_pointer = this.head;
        for(var i=0;i<index-1;i++) index_pointer = index_pointer.next;
        index_pointer.next = index_pointer.next.next;
    }
}

l = new List(5)
l.push(6)
l.push(7)
l.push(8)
l.remove(2)
l.display()