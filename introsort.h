#ifndef SORTING_ALGORITHMS_INTROSORT_H
#define SORTING_ALGORITHMS_INTROSORT_H
#include <vector>
#include <algorithms/heapsort.h>
#include <algorithms/insertsort.h>
#include <algorithms/quicksort.h>

template <typename T>
class IntroSort{

public:

    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end){
    
        if(std::distance(start, end) <= 1) return;

        int size = std::distance(start, end);
        int recursive_depth = 2 * log(size);
        
        under_sort(start, end, recursive_depth);
        
    };

    void under_sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end, int recursive_depth){
    
        int distance = std::distance(start, end);

        if(distance < 16){
        
            InsertSort<T> sorting;
            sorting.sort(start, end);
            return;
            
        }
        
        if(recursive_depth == 0){
        
            HeapSort<T> sorting;
            sorting.sort(start, end);
            return;
            
        }

        auto pivot = partition(start, end - 1);
        under_sort(start, pivot, recursive_depth - 1);
        under_sort(pivot, end, recursive_depth - 1);
        
    }

    auto partition(typename std::vector<T>::iterator p, typename std::vector<T>::iterator q){
    
                auto pivot = p + std::distance(p, q) / 2;
                auto value = *pivot;
            
                while(p <= q){
                
                    while(*p < value) p++;
                    while(*q > value) q--;

                    if(p <= q){
                    
                        std::iter_swap(p, q);
                        p++;
                        q--;
                        
                    }
            
                }
                
                return p;
                
            };
            
};

#endif //SORTING_ALGORITHMS_INTROSORT_H
