#ifndef SORTING_ALGORITHMS_QUICKSORT_H
#define SORTING_ALGORITHMS_QUICKSORT_H
#include <vector>

template <typename T>
class QuickSort{

    public:
    
        void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end){
        
                if(std::distance(start, end) <= 1) return;

                auto pivot = partition(start, end - 1);
                sort(start, pivot);
                sort(pivot, end);
                
            };

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

#endif //SORTING_ALGORITHMS_QUICKSORT_H
