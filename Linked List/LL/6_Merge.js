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

    //Merging two Sorted LinkedList
    merge(l2)
    {
        /**
         * Initially Pointer first will point to the head of current LinkedList
         * Initially Pointer second will point to the head of second LinkedList.
         */
        var first = this.head;
        var second = l2.head;

        /**
         * Because we are merging sorted Lists, so our current head should point
         * to the element which is smaller in the of the two elements of both Lists.
         */
        if(first.data < second.data)  first = first.next;
        else
        {
            this.head = second;
            second = second.next;
        }
        //This last pointer will point to the element before 'first' or 'second' pointer and 
        //it will help to make nodes point in such a way that the resultant list is all sorted
        var last = this.head;
        last.next = null;
        
        while(first != null && second != null)
        {
            /*If value at the Node to which first pointer is pointing is 
            greater that the value for second, then the node after the last node should be 
            the second one because its value is smaller than the first one.
            And after this, the 'last' pointer will point to the second Node and
            'second' pointer will point to the next node of current node.*/
            if(first.data>second.data)
            {
                last.next=second;
                last = second;
                second = second.next;
            }

            else
            {
                last.next=first;
                last = first;
                first = first.next;
            }
        }
        
        last.next = null;
        /*Now, if any of the pointers pointing first or second list are not null,
        It means that some values are still remaining in that List.
        So we point out next pointer of out last node to that Node(because definitely, the value(s))
        that are remaining in that node are greater that the value at last node and all Lists are sorted.*/
        if(first!=null) last.next=first;
        else if(second!=null) last.next=second;
    }
}

l = new List(5)
l.push(6)
l.push(7)
l.push(8)

l2 = new List(1);
l2.push(3);
l2.push(5);
l2.push(7);

l.merge(l2);
l.display();