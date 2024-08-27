#include <iostream>


namespace sy {
    template <typename T>
    class list
    {
    public:
        struct Node
        {
            Node* Prev;
            T Data;
            Node* Next;
        };
        list()
        {
            mHead = nullptr;
            mTail = nullptr;
        }
        ~list()
        {
          
        }

        void pushback(T _data)
        {
            if (mHead == nullptr) //초기값
            {
                mHead = new Node();
                mHead->Data = _data;
                mHead->Next = nullptr;
                mHead->Prev = nullptr;

                mTail = mHead;
            }
            else
            {
                mTail->Next = new Node();
                mTail->Next->Data = _data;

                mTail->Next->Next = nullptr;
                mTail->Next->Prev = this->mTail;

                mTail = mTail->Next;
            }
        }

        void erase()
        {
            if (mTail->Prev == nullptr) // 노드가 첫 노드부분일때?
                return;
            else
            {
                Node* mDel = mTail;
                mTail = mTail->Prev;
                mTail->Next = nullptr;

                delete mDel;
                mDel = nullptr;
            }
        }

    private:
        Node* mHead;
        Node* mTail;
    };
}
int main()
{
    sy::list<int> mList;
    mList.pushback(1);
    mList.pushback(2);
    mList.pushback(3);
    int a = 0;

    mList.erase();
    mList.erase();
    mList.erase();
    
  
}

