#ifndef SORTING_ALGORITHMS_MERGESORT_H
#define SORTING_ALGORITHMS_MERGESORT_H
#include <vector>

template <typename T>
class MergeSort{

    public:
    
        void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end){
                
                if(std::distance(start, end) <= 1) return; 

                auto pivot = start + std::distance(start, end) / 2;
                
                sort(start, pivot);
                sort(pivot, end); 
                merge(start, pivot, end);
                
            };

        void merge(typename std::vector<T>::iterator start, typename std::vector<T>::iterator pivot, typename std::vector<T>::iterator end){

                auto i1 = start;
                auto i2 = pivot;
                auto j1 = pivot;
                auto j2 = end;
                
                std::vector<T> temporary(std::distance(start, end));
                int iterator = 0;

                while(i1 != i2 && j1 != j2){
                
                    if(*i1 < *j1){
                    
                        temporary[iterator] = *i1;
                        iterator++;
                        i1++;
                        
                    }
                    else{
                    
                        temporary[iterator] = *j1;
                        iterator++;
                        j1++;;
                        
                    }
                    
                }
                
                std::copy(i1, i2, &temporary[iterator]);
                std::copy(j1, j2, &temporary[iterator]);
                std::copy(temporary.begin(), temporary.end(), start);
        };

};

#endif //SORTING_ALGORITHMS_MERGESORT_H
