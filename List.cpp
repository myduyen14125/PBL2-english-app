#include <iostream>
#include <fstream>
 
using namespace std;
 
typedef class node* Node;
class node
{
    private:
        int data;
        Node next;
        Node prev;
    public:
        node (int data, Node next, Node prev)
        {
            this->data = data;
            this->next = next;
            this->prev = prev;
        }
 
        void setData (int data)
        {
            this->data = data;
        }
 
        int getData ()
        {
            return data;
        }
 
        void setNext (Node next)
        {
            this->next = next;
        }
 
        Node getNext ()
        {
            return next;
        }
 
        void setPrev (Node prev)
        {
            this->prev = prev;
        }
 
        Node getPrev ()
        {
            return prev;
        }
 
        void print ()
        {
            cout << getData() << endl;
        }
 
        friend class linkedlist;
};
 
 
typedef class linkedlist* Linkedlist;
 
class linkedlist
{
    private:
        Node head;
        Node tail;
        int size;
    public:
 
        linkedlist ()
        {
            head = NULL;
            tail = NULL;
            size = 0;
        }
        void setTail (Node tail)
        {
            this->tail = tail;
        }
 
        Node get (int index)
        {
            if (index<0 || index > size)
                return NULL;
            Node tmp = head;
            for (int i = 0; i < index; i ++)
                tmp = tmp->getNext();
            return tmp;
        }
 
        int getSize ()
        {
            return size;
        }
        void creatList (const char* filename)
        {
            fstream _read;
            _read.open (filename, ios::in);
            cout << _read.good () << endl << endl;
 
            int data;
            Node tmp;
            while (!_read.eof ())
            {
                _read >> data;
                tmp = new node (data, NULL, NULL);
                size ++;
 
                if (head == NULL)
                    head = tail = tmp;
                else
                {
                    tail->setNext(tmp);
                    tmp->setPrev(tail);
                    setTail(tmp);
                }
            }
        }
 
        void printNext ()
        // in ra theo chieu next
        {
            Node tmp = head;
            while (tmp!= NULL)
            {
                tmp->print ();
                tmp = tmp->getNext();
            }
 
        }
 
        void printPrev ()
        // in ra theo chieu prev
        {
            Node tmp = tail;
            while (tmp!= NULL)
            {
                tmp->print ();
                tmp = tmp->getPrev();
            }
        }
 
        void sortBN ()
        // sap xep noi bot theo chieu next
        {
            Node bsh;
            int data;
            bool _bit = false;
            while (!_bit)
            {
                _bit = true;
                for (bsh = head; bsh->getNext() != NULL; bsh = bsh->getNext())
                    if (bsh->getData () < bsh->getNext()->getData())
                    {
                        data = bsh->getData ();
                        bsh->setData(bsh->getNext()->getData());
                        bsh->getNext()->setData (data);
                        _bit = false;
                    }
            }
        }
 
        void addTail1 (int data)
        {
            Node tmp = new node (data, NULL, NULL);
            if (head == NULL)
            {
                head = tail = tmp;
                return;
            }
            tmp->setPrev(tail);
            tail->setNext(tmp);
            setTail(tmp);
            size ++;
        }
 
        void addTail2 (int data)
        {
            Node n = new node(data, NULL, NULL);
            Node tmp = get (size - 1);
            n->setPrev(tmp);
            tmp->setNext(n);
            setTail(n);
            size ++;
        }
 
};
 
int main ()
{
    Linkedlist l = new linkedlist ();
    l->creatList("hung.txt");
 
    l->addTail2(100);
    l->printNext();
    cout << endl;
    l->printPrev ();
    return 0;
}