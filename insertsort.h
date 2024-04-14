#ifndef SORTING_ALGORITHMS_INSERTSORT_H
#define SORTING_ALGORITHMS_INSERTSORT_H
#include <vector>

template <typename T>
class InsertSort{

public:

    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
    {

        if (std::distance(start, end) <= 1) return;

        for (auto i = start + 1; i < end; i++) {

            auto temp = *i;
            auto comparison = i - 1;

            while (*comparison > temp && comparison >= start) {

                *(comparison + 1) = *comparison;
                comparison--;

            }

            *(comparison + 1) = temp;

        }

    };
    
};

#endif //SORTING_ALGORITHMS_INSERTSORT_H
