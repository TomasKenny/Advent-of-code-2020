#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


int main(int argc, const char * argv[]) {
   
    std::ifstream stream("/Users/naplava/Downloads/input.txt");
    std::string line, str;
    int totalPart1 = 0;
    int totalPart2 = 0;
    int peopleInGroup = 0;
    
    std::getline(stream, line);
    while(true){
        if(line == "" || line == "\n"){
            str.erase(std::remove_if(str.begin(), str.end(), [](char c){ return isspace(c); }), str.end());
            std::sort(str.begin(), str.end());
            char current = 0;
            int counterPart1 = 0, counterPart2 = 0;
            for(char c: str){
                if(c > current){
                    current = c;
                    if(std::count(str.begin(), str.end(), c) == peopleInGroup){
                        counterPart2++;
                    }
                    counterPart1++;
                }
            }
            totalPart1 += counterPart1;
            totalPart2 += counterPart2;
            
            peopleInGroup = 0;
            str.clear();
            if(stream.eof()){
                break;
            }
        }
        else{
            str += line;
            peopleInGroup++;
        }
        line.clear();
        std::getline(stream, line);
    }
    
    printf("yes answers part 1: %d, part 2: %d\n", totalPart1, totalPart2);
    return 0;
}
