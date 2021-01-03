#include <iostream>
#include <sstream>
#include <fstream>
#include <regex>


int Divide(int min, int max, const char* input){
    while(min != max){
        if(*input == 'F' || *input == 'L'){
            max = (min + max) / 2;
        }
        else{
            min = (min + max + 1) / 2;
        }
        input = input + 1;
    }
    return min;
}

int main(int argc, const char * argv[]) {

    int max = 0;
    std::ifstream stream("/Users/naplava/Downloads/input.txt");
    std::string line;
    std::set<int> allSeats;
    for(int i = 0; i < 8*128; i++){
        allSeats.insert(i);
    }
    
    while(std::getline(stream, line)){
        int row = Divide(0, 127, line.c_str());
        int column = Divide(0, 7, line.c_str() + 7);
        int ticketId = row * 8 + column;
        if(ticketId > max){
            max = ticketId;
        }
        allSeats.erase(ticketId);
    }
    
    printf("max ticket: %d\n", max);
    
    for(auto it = allSeats.begin(); it != allSeats.end(); it++){
        printf("%d\n", *it);
    }
    return 0;
}
