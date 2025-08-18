#include<iostream>
using namespace std;

class Queue
{
    public:
        int * arr;
        int queueufront;
        int rear;
        int size;

        Queue(int size)
        {
            this->size=size;
            arr = new int[size];
            queueufront = 0;
            rear = 0;
        }

        bool empty()
        {
            if(queueufront == rear)
            {
                return true;
            }
            return false;
        }

        void enqueue(int num)
        {
            if(rear == size)
            {
                cout<<"Queue is full";
            }
            else
            {
                arr[rear] = num;
                rear++;
            }
        }

        int dequeue()
        {
            if(queueufront == rear)
            {
                return -1;
            }
            else
            {
                int ans = arr[queueufront];
                arr[queueufront] = -1;
                queueufront++;
                if(queueufront == rear)
                {
                    queueufront = 0;
                    rear = 0;
                }
                return ans;
            }
        }

        int front()
        {
            if(queueufront == rear)
            {
                return -1;
            }
            else
            {
                return arr[queueufront];
            }
        }
};

int main()
{
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.front()<<endl;
}
