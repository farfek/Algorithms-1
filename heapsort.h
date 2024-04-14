#ifndef SORTING_ALGORITHMS_HEAPSORT_H
#define SORTING_ALGORITHMS_HEAPSORT_H
#include <vector>

template <typename T>
class HeapSort{

    public:
    
        void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end){
        
            if(std::distance(start, end) <= 1) return;

            auto size = end - start;
            
            for (auto i = size / 2 - 1; i >= 0; --i) {
            
                heap(start, end, start + i);
                
            }

            for (auto i = end - 1; i > start; --i) {
            
                std::swap(*start, *i);
                heap(start, i, start);
                
            }
            
        };

        void heap(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end, typename std::vector<T>::iterator root){
        
            auto size = end - start;
            auto lch = 2 * (root - start) + 1;
            auto rch = lch + 1;
            auto top = root;

            if (*(start + lch) > *top && lch < size) top = start + lch;
            if (*(start + rch) > *top && rch < size) top = start + rch;
            
            if (top != root) {
            
                std::swap(*root, *top);
                heap(start, end, top);
                
            }

        };
};

#endif //SORTING_ALGORITHMS_HEAPSORT_H
