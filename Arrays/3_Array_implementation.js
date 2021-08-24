class Array
{
    // length=0;
    // data={};
    constructor()
    {
        this.length=0;
        this.data={};
    }

    at(index)
    {
        return this.data[index];
    }

    push(element)
    {
        this.data[this.length] = element;
        this.length++;
    }

    pop()
    {
        if(this.length==0)console.log("\n[-]Empty Array\n");
        else
        {
            delete this.data[this.length-1];
            this.length--;
            //last index = length-1
        }
    }

    shift(index)
    {
        for(var i=index; i<this.length-1;i++)
        {
            this.data[i] = this.data[i+1];
        }
        delete this.data[this.length-1] ;
    }

    delete(index)
    {
        if(this.length<index+1)
        {
            console.log("\n[-]Undefined\n");
            return;

        }
        this.shift(index);
        this.length--;
    }
  
}

myArray = new Array();
myArray.push(1);
myArray.push(2);
myArray.push(3);
myArray.push(4);
console.log(myArray); //after push

myArray.pop();
console.log(myArray); //after pop

myArray.delete(1); //delete from index 2
console.log(myArray);