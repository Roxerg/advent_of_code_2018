#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>

int main() {


    std::ifstream input;
    input.open("input.txt");
    std::string id_string;

    std::vector<std::string> ids;


     if (input.is_open()) {
        while (getline(input, id_string)) {
            ids.push_back(id_string);
            //std::cout << line <<"\n";
        }
    }

    std::string str1;
    std::string str2;

    for (std::string id : ids) {
        for(std::string otherid :ids) {
            int matches = 0;
            for(int i=0; i<id.length(); i++) {
                if(id[i] == otherid[i]) {
                    matches++;
                }
            }
            if ((id.length() - matches) == 1) {
                str1 = id;
                str2 = otherid;
                std::string res = "";
                for(int z=0; z<str1.length(); z++) {
                    if(str1[z] == str2[z]) {
                        res += str1[z];
                    }
                }
                std::cout <<"\n" << res <<"\n"; 
            }

        }

    }
    return 0;
}