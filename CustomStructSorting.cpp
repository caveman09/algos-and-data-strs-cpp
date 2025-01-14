#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

struct P
{
    int x, y;
    bool operator<(const P &p) const
    {
        if (this->x != p.x)
        {
            return (this->x < p.x);
        }
        else
        {
            return (this->y < p.y);
        }
    }
};

int main()
{
    std::vector<P> vec(10);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);
    for (auto &elem : vec)
    {
        elem.x = dist(gen);
        elem.y = dist(gen);
    }
    std::for_each(vec.begin(), vec.end(), [](P elem)
                  { std::cout << "(" << elem.x << "," << elem.y << ")" << "  "; });

    std::cout << std::endl;
    std::cout << std::endl;

    std::sort(vec.begin(), vec.end());
    std::cout << "SORTED" << std::endl
              << std::endl;
    std::for_each(vec.begin(), vec.end(), [](P elem)
                  { std::cout << "(" << elem.x << "," << elem.y << ")" << "  "; });

    return 0;
}