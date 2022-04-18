#include <iostream>
#include <assert.h>
#include <queue>

// 결합시 돈을 기준으로 부모를 결정함
// 유니온파인드에 돈을 기준으로 하는 기능들 추가
class UnionFinder_Money
{
protected:
    int _max_size = 0;
    int* _data = nullptr;
    int* _money = nullptr;

public:
    void Initialize(int* money)
    {
        Release();

        if (_max_size > 0 && _data == nullptr)
        {
            _data = new int[_max_size];
            _money = money;

            for (int i = 0; i < _max_size; ++i)
            {
                _data[i] = i;
            }
        }
    }

    void Release()
    {
        if (_data != nullptr)
        {
            delete[] _data;
            _data = nullptr;
        }
    }

public:
    UnionFinder_Money(int max_size)
    {
        _max_size = max_size;
    }

    ~UnionFinder_Money()
    {
        Release();
    }

    // 모든 집합을 결합하면서 최종 돈을 계산
    int UnionForCalcMoney()
    {
        int total = _money[Find(0)];

        for (int i = 0; i < _max_size; ++i)
        {
            int lhs = Find(0);
            int rhs = Find(i);

            if (lhs != rhs)
            {
                total += _money[rhs];
                Union(lhs, rhs);
            }
        }

        return total;
    }

    int Find(int value)
    {
        assert(_max_size > value);

        if (_max_size <= value)
            return -1;

        // 최상위 루트 부모가 자기 자신
        if (_data[value] == value)
        {
            return value;
        }
        // 부모가 있을 경우 부모값 참조
        else
        {
            int top_parent = Find(_data[value]);
            _data[value] = top_parent;

            return top_parent;
        }

        return -1;
    }

    void Union(int lhs, int rhs)
    {
        assert(_max_size > lhs && _max_size > rhs);

        int lhs_parent = Find(lhs);
        int rhs_parent = Find(rhs);

        // 최상위 부모가 다르면
        if (lhs_parent != rhs_parent)
        {
            // 좀 더 저렴한 친구를 부모로 결합
            if (_money[lhs_parent] > _money[rhs_parent])
            {
                _data[lhs_parent] = rhs_parent;
            }
            else
            {
                _data[rhs_parent] = lhs_parent;
            }
        }
    }

    bool EqualRoot(int lhs, int rhs) { return Find(lhs) == Find(rhs); }
};

int main()
{
    int friends, friendship_count, money;

    std::cin >> friends >> friendship_count >> money;

    int* need_money = new int[friends];

    for (int i = 0; i < friends; ++i)
    {
        std::cin >> need_money[i];
    }

    UnionFinder_Money money_finder(friends);
    money_finder.Initialize(need_money);

    for (int i = 0; i < friendship_count; ++i)
    {
        int lhs, rhs;
        std::cin >> lhs >> rhs;
        
        // 결합시 가격이 낮은 친구를 루트로 결정
        money_finder.Union(lhs - 1, rhs - 1);
    }

    // 모든 집합을 결합하면서 최종 돈을 계산
    int total = money_finder.UnionForCalcMoney();

    if (total <= money)
    {
        std::cout << total;
    }
    else
    {
        std::cout << "Oh no";
    }

    delete[] need_money;

    return 0;
}