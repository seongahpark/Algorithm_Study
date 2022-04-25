#include <iostream>
#include <vector>
#include <queue>
#include <functional>

class IOHelper
{
protected:
    template <typename T>
    static void Read_Internal(int start_idx, int loop_count, T* arg)
    {
        for (int i = 0; i < loop_count; ++i)
        {
            std::cin >> (*(arg + start_idx + i));
        }
    }
public:
    template <typename T>
    static void Read(int start_idx, int loop_count, T* arg)
    {
        Read_Internal(start_idx, loop_count, arg);
    }

    template <typename T, typename ... Types>
    static void Read(int start_idx, int loop_count, T* arg, Types* ... args)
    {
        for (int i = 0; i < loop_count; ++i)
        {
            Read_Internal(i, 1, arg);
            Read(i, 1, args...);
        }
    }

    template <typename Proc>
    static void Read(int loop_count, Proc add_proc)
    {
        int value;
        for (int i = 0; i < loop_count; ++i)
        {
            std::cin >> value;
            add_proc(value);
        }
    }

    template <typename T>
    static void Print(int loop_count, T arg)
    {
        std::cout << (arg);
    }

    template <typename T, typename ... Types>
    static void Print(int loop_count, T arg, Types ... args)
    {
        Print(loop_count, arg);
        Print(loop_count, args...);
    }
};

class OrderRecorder
{
protected:
    const static unsigned int MAX_COUNT = 101;
    int _usage_record[MAX_COUNT] = { 0 };
    int _size = 0;

    int _read_pos = 0;
public:
    OrderRecorder(int size)
        :_size(size)
        , _read_pos(0)
    {
        IOHelper::Read(0, size, _usage_record);
    }

    bool IsEmpty() const
    {
        return _read_pos >= _size;
    }

    int Read()
    {
        return _usage_record[_read_pos++];
    }

    const int* begin() const
    {
        return _usage_record + _read_pos;
    }

    const int* end() const
    {
        return _usage_record + _size;
    }
};

class PowerStrip
{
protected:
    std::vector<int> _connections;
    int _max_connection = 0;

    int _count = 0;
public:
    void SetMaxConnection(int max_connection)
    {
        _max_connection = max_connection;
    }

    bool IsFully() const
    {
        return _connections.size() == _max_connection;
    }

    bool AddConnection(int object_idx)
    {
        for (auto idx : _connections)
        {
            if (idx == object_idx)
                return true;
        }

        if (IsFully() == false)
        {
            _connections.push_back(object_idx);
            return true;
        }

        return false;
    }

    void OptimalRemove(const OrderRecorder& recorder)
    {
        auto current_connections = _connections;

        int remove_target = _connections[0];

        for (auto record : recorder)
        {
            for (auto iter = current_connections.begin(); iter != current_connections.end(); ++iter)
            {
                if (record == *iter)
                {
                    current_connections.erase(iter);
                    break;
                }
            }

            if (current_connections.size() == 1)
            {
                remove_target = current_connections[0];
                break;
            }
        }

        for (auto iter = _connections.begin(); iter != _connections.end(); ++iter)
        {
            if (*iter == remove_target)
            {
                _connections.erase(iter);
                return;
            }
        }
    }

};


int main()
{
    int hole_count = 0, usage_count = 0;
    IOHelper::Read(0, 1, &hole_count, &usage_count);

    OrderRecorder recorder(usage_count);
    PowerStrip strip;

    strip.SetMaxConnection(hole_count);

    int total = 0;
    while (recorder.IsEmpty() == false)
    {
        int record = recorder.Read();

        if (strip.AddConnection(record) == false)
        {
            strip.OptimalRemove(recorder);
            strip.AddConnection(record);

            ++total;
        }
    }

    IOHelper::Print(1, total);

    return 0;
}