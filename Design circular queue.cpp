class MyCircularQueue {
public:
    vector<int>q;
    int front, rear, size;
    MyCircularQueue(int k)
    {
        size = k;
        q.resize(size);
        front = rear = -1;
        
    }
    
    bool enQueue(int value) 
    {
        if(isFull())
        {
            return false;
        }
        if(isEmpty())
        {
            front = rear = 0;
            q[rear] = value;
            return true;
        }
        rear = (rear + 1) % size;
        q[rear] = value;
        return true;
    }
    
    bool deQueue() 
    {
        if(isEmpty())
        {
            return false;
        }
        if(front == rear)
        {
            front = rear = -1;
            return true;
        }
        front = (front + 1) % size;
        return true;
    }
    
    int Front() 
    {
        if(isEmpty())
        {
           return -1; 
        }
        return q[front];
    }
    
    int Rear()
    {
        if(isEmpty())
        {
           return -1; 
        }
        return q[rear];
    }
    
    bool isEmpty()
    {
        if(front == -1 && rear == -1)
        {
            return true;
        }
        return false;
    }
    
    bool isFull() 
    {
        if((rear + 1) % size == front)
        {
            return true;
        }
        return false;
    }
};
// tc o(1)
// sc o(n)
