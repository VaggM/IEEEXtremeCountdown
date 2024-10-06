#include<iostream>
#include<string>
#include<sstream>
#include<unordered_map>

// 0: MATCH, 1: values
int query(unsigned i, unsigned j, unsigned& k, unsigned& l)
{
    std::cout << i << ' ' << j << std::endl;
    std::string s;
    std::getline(std::cin >> std::ws, s);
    if (s == "-1")
        exit(0);
    if (s == "MATCH")
        return 0;
    std::istringstream iss(s);
    iss >> k >> l;
    return 1;
}

int main()
{
    unsigned n;
    std::cin >> n;

    std::unordered_map<unsigned, std::pair<unsigned, unsigned>> m;

    for (unsigned i = 1; i < 2 * n; i += 2)
    {
        unsigned k, l;
        int r = query(i, i + 1, k, l);
        if (r == 0)
            continue;
        if (m.contains(k))
            m[k].second = i;
        else
            m[k].first = i;
        if (m.contains(l))
            m[l].second = i + 1;
        else
            m[l].first = i + 1;
    }

    unsigned k, l;
    for (auto& [_, v] : m)
        query(v.first, v.second, k, l);
    std::cout << "-1" << std::endl;

    return 0;
}
