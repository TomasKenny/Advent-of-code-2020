#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>


typedef std::vector<std::pair<int,std::string>> BagContent;

bool ParseLine(const std::string & str, std::string & bag, BagContent & bagContent){
    bagContent.clear();
    /*
     dark orange bags contain 3 bright white bags, 4 muted yellow bags.
     bright white bags contain 1 shiny gold bag.
     faded blue bags contain no other bags.
     */
    size_t pos = str.find(" bags contain ");
    if(pos == std::string::npos){
        return false;
    }
    bag.assign(str.c_str(), pos);
    if(str.find("no other bags.") != std::string::npos){
        return true;
    }
    int bagCount;
    std::string bagColor;
    std::string contentStr(str.begin() + pos + strlen(" bags contain "), str.end());
    char* c = strtok(&contentStr[0], ",.");
    while(c){
        while(isspace(*c))c++;
        bagCount = atoi(c);
        *(strstr(c, " bag")) = '\0';
        bagColor = strstr(c, " ") + 1;
        bagContent.push_back({bagCount, bagColor});
        c = strtok(nullptr, ",.");
    }
    return true;
}

int main(int argc, const char * argv[]) {
   
    std::ifstream stream("/Users/naplava/Downloads/input.txt");
    std::string line, bag;
    BagContent bagContent;
    std::map<std::string, BagContent> allBags;
    
    while(std::getline(stream, line)){
        ParseLine(line, bag, bagContent);
        allBags[bag] = bagContent;
    }
    
    std::set<std::string> parentBags;
    std::set<std::string> visitedBags;
    parentBags.insert("shiny gold");
    
    for(auto it = parentBags.begin(); it != parentBags.end(); ){
        if(std::find(visitedBags.begin(), visitedBags.end(), *it) != visitedBags.end()){
            it++;
            continue;
        }
        
        for(const auto & bag: allBags){
            std::string key = *it;
            auto comp = [key](const std::pair<int,std::string> & item){ return item.second == key; };
            if(std::find_if(bag.second.begin(), bag.second.end(), comp) != bag.second.end()){
                parentBags.insert(bag.first);
            }
        }
        
        visitedBags.insert(*it);
        it = parentBags.begin();
    }
    
    printf("bags containing shiny gold bag: %lu\n", parentBags.size() - 1);
    return 0;
}
