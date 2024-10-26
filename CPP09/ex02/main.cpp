#include "PmergeMe.hpp"

int checkDigit(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        if (!isdigit(str[i]))
            return 1;
    }
    long num = std::atol(str);
    if (num >= std::numeric_limits<int>::max() || num <= std::numeric_limits<int>::min())
        return 1;
    return 0;
}
template <typename T>
T FordJohnson(T &cont)
{
    if (cont.size() < 2)
        return cont;
    T sValues;
    T bValues;
    for(size_t i = 0; i < (cont.size() / 2); i++)
    {
        if (cont[2 * i] < cont[2 * i + 1])
        {
            sValues.push_back(cont[2 * i]);
            bValues.push_back(cont[2 * i + 1]);
        }
        else
        {
            sValues.push_back(cont[2 * i + 1]);
            bValues.push_back(cont[2 * i]);
        }
    }
    
    if (cont.size() % 2 != 0)
        sValues.push_back(cont[cont.size() - 1]);

    sValues = FordJohnson(sValues);
    bValues = FordJohnson(bValues);

    cont.clear();
    size_t i = 0, j = 0;
    while (i < sValues.size() && j < bValues.size())
    {
        if (sValues[i] < bValues[j])
            cont.push_back(sValues[i++]);
        else
            cont.push_back(bValues[j++]);
    }
    while (i < sValues.size()) cont.push_back(sValues[i++]);
    while (j < bValues.size()) cont.push_back(bValues[j++]);
    return cont;
}

int main(int ac, char **av)
{
    if (ac < 2)
        return (std::cerr << "[ERROR] wrong usage" << std::endl, 1);
    else
    {
        std::vector<int> vec;
        std::deque<int> deq;
        {
            for (int i = 1; av[i]; i++)
            {
                if (checkDigit(av[i]))
                    return (std::cerr << "[ERROR]: Invalid number" << std::endl, 1);
                int value = std::atoi(av[i]);
                vec.push_back(value);
                deq.push_back(value);
            }
        }

        std::cout << "[Unsorted vector] -> ";
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << vec[i] << " ";
        std::cout << std::endl;
        std::cout << "[Unsorted deque] -> ";
        for (size_t i = 0; i < deq.size(); i++)
            std::cout << deq[i] << " ";
        std::cout << std::endl;

        clock_t vec_start= clock();
        FordJohnson(vec);
        clock_t vec_end = clock();

        clock_t deq_start = clock();
        FordJohnson(deq);
        clock_t deq_end= clock();
        std::cout << "[Sorted vector] -> ";
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << vec[i] << " ";
        std::cout << std::endl;
        std::cout << "[Sorted deque] -> ";
        for (size_t i = 0; i < deq.size(); i++)
            std::cout << deq[i] << " ";
        std::cout << std::endl;
        double vec_time = double(vec_end - vec_start);
        std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << std::fixed
              << vec_time << std::setprecision(5) << " us" << std::endl;
        double deq_time = double(deq_end - deq_start);
        std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << std::fixed
              << deq_time << std::setprecision(5) << " us" << std::endl;
    }
}