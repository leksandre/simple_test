#include <iostream>

using namespace std;
#include <set>

using IPAddress = uint32_t;
using Range = std::pair<IPAddress, IPAddress>;
using Pool = std::set<Range>;

Pool find_diff(const Pool& old_pool, const Pool& new_pool)
{
    Pool result;

    for (const auto& old_range : old_pool) {
        bool found = false;

        for (const auto& new_range : new_pool) {
            if (old_range.first >= new_range.first && old_range.second <= new_range.second) {
                found = true;
                break;
            }
        }

        if (!found) {
            result.insert(old_range);
        }
    }

    return result;
}



int main()
{
    Pool old_pool = { { 10, 20 }, { 30, 40 }, { 50, 60 } };
    Pool new_pool = { { 5, 15 }, { 35, 45 }, { 55, 65 } };

    Pool result = find_diff(old_pool, new_pool);

    // Ожидаемый результат: { { 30, 40 }, { 50, 60 } }
    for (const auto& range : result) {
        std::cout << range.first << " - " << range.second << std::endl;
    }

    return 0;
}