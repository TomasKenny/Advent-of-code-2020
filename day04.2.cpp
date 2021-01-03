#include <iostream>
#include <sstream>
#include <fstream>
#include <regex>


bool IsPassportValid(const std::string & str){
    static const std::regex heightRegex(R"((\d+)(cm|in))");
    static const std::regex hairColorRegex(R"(#[0-9a-f]{6})");
    static const std::regex eyeColorRegex(R"(amb|blu|brn|gry|grn|hzl|oth)");
    static const std::regex passportIdRegex(R"(\d{9})");
    
    typedef std::function<bool(const std::string &)> Validator;
    
    /*
     byr (Birth Year) - four digits; at least 1920 and at most 2002.
     iyr (Issue Year) - four digits; at least 2010 and at most 2020.
     eyr (Expiration Year) - four digits; at least 2020 and at most 2030.
     hgt (Height) - a number followed by either cm or in:
     If cm, the number must be at least 150 and at most 193.
     If in, the number must be at least 59 and at most 76.
     hcl (Hair Color) - a # followed by exactly six characters 0-9 or a-f.
     ecl (Eye Color) - exactly one of: amb blu brn gry grn hzl oth.
     pid (Passport ID) - a nine-digit number, including leading zeroes.
     cid (Country ID) - ignored, missing or not.
     
     */
    static const std::vector<std::pair<std::string, Validator>> rules = {
        { "byr:", [](const std::string & str){ int num = atoi(str.c_str()); return (strlen(str.c_str()) == 4) && num >= 1920 && num <= 2002; } },
        { "iyr:", [](const std::string & str){ int num = atoi(str.c_str()); return (strlen(str.c_str()) == 4) && num >= 2010 && num <= 2020; } },
        { "eyr:", [](const std::string & str){ int num = atoi(str.c_str()); return (strlen(str.c_str()) == 4) && num >= 2020 && num <= 2030; } },
        { "hgt:", [](const std::string & str){
            std::cmatch matches;
            if(!std::regex_match(str.c_str(), matches, heightRegex)){
                return false;
            }
            int num = atoi(matches[1].str().c_str());
            if(matches[2].str() == "cm"){
                return num >= 150 && num <= 193;
            }
            return num >= 59 && num <= 76;
        } },

        { "hcl:", [](const std::string & str){ return std::regex_match(str.c_str(), hairColorRegex); } },
        { "ecl:", [](const std::string & str){ return std::regex_match(str.c_str(), eyeColorRegex); } },
        { "pid:", [](const std::string & str){ return std::regex_match(str.c_str(), passportIdRegex); } }
    };
    
    for(const auto & rule: rules){
        size_t pos = str.find(rule.first);
        if(pos == std::string::npos){
            return false;
        }
        std::string tmp(str.begin() + pos + strlen(rule.first.c_str()), str.end());
        std::stringstream ss(tmp);
        ss >> tmp;
        if(!rule.second(tmp)){
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
   
    std::ifstream stream("/Users/naplava/Downloads/input.txt");
    std::string line, str;
    int counter = 0;
     
    std::getline(stream, line);
    while(true){
        if(line == "" || line == "\n"){
            if(IsPassportValid(str)){
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
