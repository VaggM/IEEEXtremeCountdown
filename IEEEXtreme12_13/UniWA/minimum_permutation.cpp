#include <iostream>
#include <vector>
#include <set>

int main()
{
    unsigned n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a; 
    std::set<unsigned> s;

    a.reserve(n + m);

    for (auto i = 0ul; i < n; ++i)
    {
        unsigned input;
        std::cin >> input;
        a.push_back(input);
    }

    for(auto i = 0ul; i < m; ++i)
    {
        unsigned input;
        std::cin >> input;
        s.insert(input);
    }

    auto s_it = s.begin();
    auto a_it = a.begin();

    while (a_it != a.end() and s_it != s.end())
    {
        if (*s_it < *a_it)
            a.insert(a_it, *s_it++);
        else
            ++a_it;
    }

    for (; s_it != s.end(); ++s_it)
        a.push_back(*s_it);

    for (unsigned item: a)
        std::cout << item << ' ';
    std::cout << '\n';

    return 0;
}
