#include <unordered_map>
#include <stack>
#include <iostream>
#include <list>


template <typename T>
struct Node
{
    Node* next = nullptr;
    T data;

    Node() noexcept
    {
    }

    Node(T value) noexcept
        :data(value)
    {
    }

};

template <typename T>
class CircularList
{
protected:
    Node<T>* _Begin = nullptr;
    Node<T>* _End = nullptr;

    int _Count = 0;

public:
    CircularList() noexcept
    {

    }

    ~CircularList()
    {
        if (_Begin != nullptr)
        {
            Node<T>* node = nullptr;
            while (_Count > 0)
            {
                Node<T>* next_node = node->next;
                delete node;
                node = next_node;

                --_Count;
            }
        }
    }

public:
    void Insert(T value)
    {
        Node<T>* new_node = new Node<T>(value);

        if (_Begin == nullptr)
        {
            new_node->next = new_node;

            _Begin = new_node;
            _End = new_node;
        }
        else
        {
            new_node->next = _End->next;
            _End->next = new_node;
            _End = new_node;
        }

        ++_Count;
    }

    bool Remove(T value)
    {
        if (_Count <= 0)
            return false;

        Node<T>* node = _Begin;
        Node<T>* prev_node = _End;
        do
        {
            if (node->data == value)
            {
                prev_node->next = node->next;

                if (node == _Begin)
                {
                    _Begin = node->next;
                }

                if (node == _End)
                {
                    _End = prev_node;
                }

                delete node;
                --_Count;
                return true;
            }
            prev_node = node;
            node = node->next;

        } while (prev_node->next != _Begin);

        return false;
    }

    Node<T>* GetBegin() const { return _Begin; }

    bool IsEmpty() const { return _Count <= 0; }
    int GetCount() const { return _Count; }
};

int main()
{
    int count, interval;
    std::cin >> count >> interval;

    CircularList<int> list;
    for (int i = 1; i <= count; ++i)
    {
        list.Insert(i);
    }

    std::cout << "<";

    auto node = list.GetBegin();
    int elapsed = 0;

    // 순환 리스트 순회하면서 간격별로 노드 제거
    while (list.IsEmpty() == false)
    {
        ++elapsed;

        if (elapsed >= interval)
        {
            elapsed = 0;

            std::cout << node->data;

            auto next_node = node->next;
            list.Remove(node->data);
            node = next_node;

            if (list.IsEmpty() == false)
            {
                std::cout << ", ";
            }

            continue;
        }

        node = node->next;
    }

    std::cout << ">";

    return 0;
}