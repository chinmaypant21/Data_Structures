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

    // N elements copied from LL to array, then N elements copied from array to LL,
    // thus Time Complexity = O(2n) = O(n)
    reverse_data()
    {
        var data_array = [];
        var current=this.head;
        while(current!=null)
        {
            data_array.push(current.data);
            current=current.next;
        }

        current=this.head;
        while(current!=null)
        {
            current.data=data_array.pop();
            current=current.next;
        }
    }

    /**
     * Reversing using slider Poers method.
     * @brief In this method, we create thiree poers, one poing to the
     * current element we are working on, one on the previous element, and one on the next element
     * At starting prev and curr poer are poing to null, and after poer to head
     * then we slide poers to next location and while doing it, we po the 'next' of current to 
     * previous. We do this untill 'after' poer gets to null.
    */
    reverse_nodes()
    {
        var previous = null;
        var current = null;
        var after = this.head;
        while(after!=null)
        {
            previous=current;
            current=after;
            after=after.next;
            current.next=previous;
        }
        this.head=current;
    }

    reverse_recursive(previous=null,current=this.head)
    {
        if(current==null)
        {
            this.head=previous;
            return;
        }
        this.reverse_recursive(current,current.next);
        current.next=previous;
    }
}

l = new List(5)
l.push(6)
l.push(7)
l.push(8)
l.reverse_recursive()
// l.reverse_data()
// l.reverse_nodes()
l.display();