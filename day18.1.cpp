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
#include <stack>
#include <regex>


std::string GetExprFromRight(const std::string & str){
    if(str.empty()){
        throw std::logic_error("unexpected input");
    }
    if(isdigit(str[str.size() - 1])){
        size_t pos = str.size() - 1;
        while(isdigit(str[pos])) pos--;
        return std::string(str.begin() + pos + 1, str.end());
    }
    // (2 + (13) + (3 * 65))
    if(str[str.size() - 1] == ')'){
        int counter = 1;
        size_t pos = str.size() - 1;
        while(counter != 0){
            pos--;
            if(pos < 0){
                throw std::logic_error("non matching parenthesis");
            }
            if(str[pos] == ')'){
                counter++;
            }
            else if(str[pos] == '('){
                counter--;
            }
        }
        return std::string(str.begin() + pos, str.end());
    }
    throw std::logic_error("unexpected input");
}


long long Eval(const std::string & str){

    if(std::regex_match(str.c_str(), std::regex(R"(\d+)"))){
        return strtoull(str.c_str(), nullptr, 10);
    }
    else if(str.size() >= 2 &&
       str[0] == '(' &&
       str[str.size() - 1] == ')' &&
       GetExprFromRight(str).size() == str.size())
    {
        return Eval(std::string(str.begin() + 1, str.end() - 1));
    }
    
    std::string rightExp = GetExprFromRight(str);
    size_t operatorPos = str.size() - rightExp.size() - 1;
    std::string leftExp = std::string(str.begin(), str.begin() + operatorPos);
    
    if(str[operatorPos] == '+'){
        return Eval(leftExp) + Eval(rightExp);
    }
    else if(str[operatorPos] == '*'){
        return Eval(leftExp) * Eval(rightExp);
    }
    else{
        throw std::logic_error("unexpected input");
    }
}


int main(int argc, const char * argv[]) {
   
    std::ifstream stream("/Users/naplava/Downloads/input.txt");
    std::string expr;
    long long temp, sum = 0;
    
    for(int i = 0; std::getline(stream, expr); i++){
        expr = std::string(expr.begin(), std::remove(expr.begin(), expr.end(), ' '));
        temp = Eval(expr);
        sum += temp;
        printf("(%d): %lld\n", i, temp);
    }
       
    printf("sum: %lld\n", sum);
        
    return 0;
}
