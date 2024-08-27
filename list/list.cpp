#include <iostream>


namespace sy {
    template <typename T>
    class list
    {
    public:
        struct Node
        {
            Node* pPrev;
            T data;
            Node* pNext;
        };
        list()
        {
            head_ = nullptr;
            tail_ = nullptr;
        }
        ~list()
        {
          
        }

        void pushback(T _data)
        {
            if (head_ == nullptr) //초기값
            {
                head_ = new Node();
                head_->data = _data;
                head_->pNext = nullptr;
                head_->pPrev = nullptr;

                tail_ = head_;
            }
            else
            {
                tail_->pNext = new Node();
                tail_->pNext->data = _data;

                tail_->pNext->pNext = nullptr;
                tail_->pNext->pPrev = this->tail_;

                tail_ = tail_->pNext;
            }
        }

        void erase()
        {
            if (tail_->pPrev == nullptr) // 노드가 첫 노드부분일때?
                return;
            else
            {
                Node* pDel = tail_;
                tail_ = tail_->pPrev;
                tail_->pNext = nullptr;

                delete pDel;
                pDel = nullptr;
            }
        }

    private:
        Node* head_;
        Node* tail_;
    };
}
int main()
{
    sy::list<int> list;
    list.pushback(1);
    list.pushback(2);
    list.pushback(3);
    int a = 0;

    list.erase();
    list.erase();
    list.erase();
    
  
}

