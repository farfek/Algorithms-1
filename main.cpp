#include <iostream>
#include <chrono>
#include <addons/generator.h>
#include <addons/percentage.h>
#include <algorithms/quicksort.h>
#include <algorithms/mergesort.h>
#include <algorithms/introsort.h>
#include <algorithms/insertsort.h>
#include <algorithms/heapsort.h>

typedef std::chrono::high_resolution_clock::time_point TimeVar;
#define duration(a) std::chrono::duration_cast<std::chrono::microseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

std::vector<size_t> inputs = {10000, 50000, 100000, 500000, 1000000};

int main(int argc, char* argv[]){

    for(auto SIZE : inputs){
    
        std::cout << SIZE << std::endl << std::endl;

        Percentage<int> percentage;

        QuickSort<int> quick_sort;
        MergeSort<int> merge_sort;
        IntroSort<int> intro_sort;

        TimeVar start;
        TimeVar end;

        size_t time_quicksort = 0;
        size_t time_mergesort = 0;
        size_t time_introsort = 0;

        for(uint8_t i = 0; i < 100; i++){
        
            Generator gen;
            std::vector<int> data = gen.generate_int(SIZE);
            
            //we can choose what to do by uncommenting or commenting the lines here
            //percentage.sort_perc(data.begin(), data.end(), 95); // 25, 50, 75, 95, 99, 99.7
            //percentage.sort_reverse(data.begin(), data.end());

            std::vector<int> temp_data = data;

            start = timeNow();
            quick_sort.sort(temp_data.begin(), temp_data.end());
            end = timeNow();
            time_quicksort += duration(end - start);

            temp_data = data;
            start = timeNow();
            merge_sort.sort(temp_data.begin(), temp_data.end());
            end = timeNow();
            time_mergesort += duration(end - start);

            temp_data = data;
            start = timeNow();
            intro_sort.sort(temp_data.begin(), temp_data.end());
            end = timeNow();
            time_introsort += duration(end - start);
            
        }

        std::cout << "QuickSort:  " << time_quicksort / 100 << "us" << std::endl;
        std::cout << "MergeSort:  " << time_mergesort / 100 << "us" << std::endl;
        std::cout << "IntroSort:  " << time_introsort / 100 << "us" << std::endl;
        std::cout << std::endl;
        
    }
    
    return 0;
    
}
