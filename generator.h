#ifndef GENERATOR_H
#define GENERATOR_H

#include <string>
#include <vector>
#include <random>
#include <chrono>

#define RAND_GEN_MAX INT32_MAX // aby nie przekroczyć przedziału inta w losowo generowanych wartościach

class Generator{

    private:
    
        int random(size_t low, size_t high){
        
        return rand() % high + low;
        
        }

    public:
    
        Generator(){
        
            srand(time(NULL));
            
        };
      
        std::vector<int> generate_int(size_t size){
        
            std::vector<int> end_vector;
            int ending = 0;
            
            while(ending < size){
            
                end_vector.push_back(random(0, RAND_GEN_MAX));
                ending++;
                
            }

            return end_vector;
            
        };
        
        
};


#endif
