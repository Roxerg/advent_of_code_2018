#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <regex>



//#1 @ 704,926: 5x4


int main() {

    std::ifstream input;
    input.open("input.txt");
    std::string line;
    std::map<int, std::vector<int>> claims;

    if (input.is_open()) {
        while (getline(input, line)) {
            char c = line[1];
            int i = 1;
            std::string index = "";
            while(c != ' ') {
                c = line[i];
                i++;
                index += c;
            }
            i+=2;
            c = line[i];
            std::string coord1 = "";
            std::string coord2 = ""; 
            while(c != ',') {
                coord1 += c;
                i++;
                c = line[i];
            }
            i++;
            c = line[i];
            while(c != ':') {
                coord2 += c;
                i++;
                c = line[i];
            }
            i+=2;
            std::string x = "";
            std::string y = "";
            c = line[i];
            while(c != 'x') {
                x += c;
                i++;
                c = line[i];
            }
            i++;
            c = line[i];
            while(i<line.length()) {
                
                c = line[i];
                y += c;
                i++;
            }
            //std:: cout << coord1 << "," <<coord2 << " " << x << "x" << y << "\n";
            int arr[] = {stoi(coord1), stoi(coord2), stoi(x), stoi(y)};
            std::vector<int> vals (arr, arr + sizeof(arr) / sizeof(arr[0]) );;
            claims.insert(std::make_pair(stoi(index), vals)); 
        }
    }

    

    std::map<std::string, int> used;
    //std::cout << "maxsize: " << used.max_size() << "\n";
    //#954 @ 821,729: 18x16
    // int arr[] = {stoi(coord1), stoi(coord2), stoi(x), stoi(y)};
    std::cout << "claims size: " << claims.size() << "\n";
    for(int i=1; i<=claims.size(); i++) {
        std::vector<int> claim = claims[i];
    
        for(int y=claim[0]; y<claim[0]+claim[2]; y++) {
            for (int x=claim[1]; x<claim[1]+claim[3]; x++) {
                std::string zoop = std::to_string(x) + "x" + std::to_string(y);
                if (used.find(zoop) == used.end()) {
                    used.insert(std::make_pair(zoop, 0));
                }
                else {
                    used[zoop] += 1;
                }
            }
        }
        
    }
    int res = 0;
    for (const auto& point : used) {
        int j = point.second;   
        if (j > 0) {
            res++;
        }
    }
    int theone;
    for(int i=1; i<=claims.size(); i++) {
        std::vector<int> claim = claims[i];
        bool the_one = true;
        for(int y=claim[0]; y<claim[0]+claim[2]; y++) {
            for (int x=claim[1]; x<claim[1]+claim[3]; x++) {
                std::string zoop = std::to_string(x) + "x" + std::to_string(y);
                if (used[zoop] > 0) {
                    the_one = false;
                }

            }
        }
        if (the_one) {
            theone = i;
        }
    }


    std::cout << "res: " << res << "\n";
    std::cout << "no overlap: " <<theone; 

    return 0;


}