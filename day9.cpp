#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <stdlib.h>
#include <numeric>


int main(int argc, const char * argv[]) {
   
    std::ifstream stream("/Users/naplava/Downloads/input.txt");
    std::string str;
    std::vector<long long> numbers;
    
    while(std::getline(stream, str)){
        numbers.push_back(strtoll(str.c_str(), nullptr, 10));
    }
    
    const int preambleLen = 25;
    long long notMatching = 0;
    
    for(int i = preambleLen; i < numbers.size(); i++){
        
        bool found = false;
        for(int j = i - preambleLen; j < i; j++){
            for(int k = i - preambleLen; k < i; k++){
                if(j == k){
                    continue;
                }
                if(numbers[j] + numbers[k] == numbers[i]){
                    found = true;
                    break;
                }
            }
            if(found){
                break;
            }
        }
        if(!found){
            printf("not matching: %lld\n", numbers[i]);
            notMatching = numbers[i];
            break;
        }
    }
    
    //----------------------------------------------------
    long long lastSum = 0;
    bool found = false;
    for(int i = 0; i < numbers.size(); i++){
        for(int j = i + 1; (j < numbers.size()) && (lastSum < notMatching); j++){
            lastSum = std::accumulate(numbers.begin() + i, numbers.begin() + j + 1, 0LL);
            if(lastSum == notMatching){
                found = true;
                auto minMax = std::minmax_element(numbers.begin() + i, numbers.begin() + j + 1);
                printf("sum of min and max: %lld\n", *(minMax.first) + *(minMax.second));
                break;
            }
        }
        lastSum = 0;
        if(found){
            break;
        }
    }
    
    return 0;
}

