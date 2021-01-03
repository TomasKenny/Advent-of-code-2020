#include <iostream>
#include <sstream>
#include <fstream>


int main(int argc, const char * argv[]) {
   
    std::ifstream stream("/Users/naplava/Downloads/input.txt");
    std::string line, str;
    int counter = 0;
    std::vector<std::string> keyWords = {
        "byr:",
        "iyr:",
        "eyr:",
        "hgt:",
        "hcl:",
        "ecl:",
        "pid:"
    };
    
    std::getline(stream, line);
    while(true){
        if(line == "" || line == "\n"){
            bool isValid = true;
            for(const auto & k: keyWords){
                if(str.find(k) == str.npos){
                    isValid = false;
                    break;
                }
            }
            if(isValid){
                counter++;
            }
            str.clear();
            if(stream.eof()){
                break;
            }
        }
        else{
            str += " ";
            str += line;
        }
        line.clear();
        std::getline(stream, line);
    }
    
    printf("valid: %d\n", counter);
    return 0;
}
