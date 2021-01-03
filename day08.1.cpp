#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>


int main(int argc, const char * argv[]) {
   
    std::ifstream stream("/Users/naplava/Downloads/input.txt");
    std::string str;
    std::vector<std::string> instructions;
    
    while(std::getline(stream, str)){
        instructions.push_back(str);
    }

    std::set<int> visitedInstructions;
    long long acc = 0;
    int current = 0;
    
    do{
        visitedInstructions.insert(current);
        str = instructions[current];
        if(str.find("nop") == 0){
            current++;
        }
        else if(str.find("jmp") == 0){
            current += atoi(&str[0] + 4);
        }
        else if(str.find("acc") == 0){
            acc += atoi(&str[0] + 4);
            current++;
        }

    }while(visitedInstructions.find(current) == visitedInstructions.end());
    
    printf("acc: %lld\n", acc);
    return 0;
}

