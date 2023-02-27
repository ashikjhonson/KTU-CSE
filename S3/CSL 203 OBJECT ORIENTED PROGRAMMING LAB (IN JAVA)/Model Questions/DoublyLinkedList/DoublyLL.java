package DoublyLinkedList;

public class DoublyLL 
{
    class Node
    {
        int data;
        Node Llink=null, Rlink=null;
        Node(int data)
        {
            this.data = data;
        }
    }   
    Node head = null;

    void insertBegin(int data)
    {
        Node n = new Node(data);
        if(head!=null)
        {
            head.Llink = n;
            n.Rlink = head;
        }
        head = n;
    }

    void insertSpecific(int data, int key)
    {
        Node n = new Node(data);
        if(head!=null)
        {
            Node ptr = head;
            while(ptr.Rlink!=null&&ptr.data!=key)
                ptr = ptr.Rlink;
            if(ptr.data!=key)
            {
                System.out.println("Key not found");
            }
            else
            {
                if(ptr.Rlink==null)
                    insertEnd(data);
                else
                {
                    n.Rlink = ptr.Rlink;
                    ptr.Rlink = n;
                    n.Llink = ptr;
                }
            }
        }
    }

    void insertEnd(int data)
    {
        Node n = new Node(data);
        if(head==null)
            head = n;
        else
        {
            Node ptr = head;
            while(ptr.Rlink!=null)  
                ptr = ptr.Rlink;
            ptr.Rlink = n;
            n.Llink = ptr;
        }
    }

    void deleteFront()
    {
        if(head!=null&&head.Rlink!=null)
        {
            head.Rlink.Llink = null;
            head = head.Rlink; 
        }
        else if(head!=null)
            head = null;
    }

    void deleteSpecific(int key)
    {
        if(head!=null)
        {
            Node ptr = head, prev = null;
            while(ptr.Rlink!=null &&ptr.data!=key)
            {
                prev = ptr;
                ptr = ptr.Rlink;
            }
            if(ptr.data!=key)
            {
                System.out.println("Key not found");
            }
            else
            {
                if(prev==null)
                {   
                    head = head.Rlink;
                    head.Llink = null;
                }
                else if(ptr.Rlink==null)
                {
                    deleteEnd();
                }
                else
                {
                    prev.Rlink = ptr.Rlink;
                    ptr.Rlink.Llink = prev;
                }
            }
        }
    }

    void deleteEnd()
    {
        if(head!=null)
        {
            if(head.Rlink == null)
                head = null;
            else
            {
                if(head.Rlink.Rlink==null)
                {
                    head.Rlink = null;
                }
                else
                {
                    Node ptr = head, prev=null;
                    while(ptr.Rlink!=null)
                    {
                        prev = ptr;
                        ptr = ptr.Rlink;
                    }
                    prev.Rlink = null;
                }
            }
        }
    }

    void display()
    {
        Node ptr = head;
        while(ptr!=null)
        {
            System.out.print(ptr.data+" ");
            ptr = ptr.Rlink;
        }
        System.out.println();
    }
    public static void main(String[] args) {
        DoublyLL dll = new DoublyLL();

        System.out.println("Initial List");
        dll.insertBegin(30);
        dll.insertBegin(20);
        dll.insertBegin(10);
        dll.insertEnd(40);        
        dll.insertSpecific(25, 20);
        dll.insertSpecific(15, 10);
        dll.insertSpecific(35, 30);
        dll.display();

        System.out.println("\nAfter deleting");
        //dll.deleteFront();
        dll.deleteSpecific(10);
        dll.deleteSpecific(40);
        //dll.deleteEnd();
        dll.display();
    }
}
