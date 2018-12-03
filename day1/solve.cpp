#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
//using namespace std;



int main () {

    std::ifstream input;
    input.open("input.txt");
    std::string line;
    int res = 0;
    bool is_in = false; 
    std::set<int> allfreq;
    std::vector<int> nums;



    if (input.is_open()) {
        while (getline(input, line)) {
            nums.push_back(std::stoi(line));
            //std::cout << line <<"\n";
        }
    }
    std::cout << "done\n";
    input.close();

    while(!is_in) {
    for (int i=0; i<nums.size(); i++) {
        res += nums[i];
        is_in = (allfreq.count(res) >= 1 );
        if (is_in) {
            std::cout << res;
            break;
        }
        allfreq.insert(res);
        }
    }
    //std::cout << res;
    return 0;

    
    



    
}
