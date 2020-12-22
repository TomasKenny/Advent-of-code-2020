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

    for(int i = 0; i < instructions.size(); i++){
        std::vector<std::string> instructionsPatched(instructions);
        str = instructionsPatched[i];
        if(str.find("nop") == 0){
            instructionsPatched[i].replace(0, 3, "jmp");
        }
        else if(str.find("jmp") == 0){
            instructionsPatched[i].replace(0, 3, "nop");
        }
        else{
            continue;
        }
        
        //-------------------------------------------------
        std::set<int> visitedInstructions;
        long long acc = 0;
        int current = 0;
        bool regularExit = false;
        
        while(true){
            if(visitedInstructions.find(current) != visitedInstructions.end()){
                break;
            }
            
            if(current == instructionsPatched.size()){
                regularExit = true;
                break;
            }
            
            visitedInstructions.insert(current);
            str = instructionsPatched[current];
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
        }
        
        if(regularExit){
            printf("acc: %lld\n", acc);
            return 0;
        }
    }
    
    printf("not found\n");
    return 0;
}

