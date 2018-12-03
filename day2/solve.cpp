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
    int twos = 0;
    int threes = 0;

    for (std::string id : ids) {
        int samecount = 0;
        /*for(int i=0; i<id.length()-1; i++) {
            for(int z=i+1; z<id.length(); z++) {
                if(z!=i && id[i] == id[z]) {
                    samecount++;
                }
            }    
        }*/
        std::map<std::string, int> string_set;
        
        for (char c: id)
        {   
            string_set[std::string{c}] = 0;
        }
         

        for (auto const& x : string_set) {
            for (int i=0; i<id.length(); i++) {
                if(id[i] == x.first[0]) {
                    string_set[x.first] +=1;
                }
            }
        }

        for (auto const& x : string_set) {
            if (x.second == 3) {
                threes++;
                break;
            }
        }
        for (auto const& x : string_set) {
            if (x.second == 2) {
                twos++;
                break;
            }
        }
    } 

    std::cout << twos*threes;

    return 0;
}