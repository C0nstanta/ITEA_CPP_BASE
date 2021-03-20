//
//  main.cpp
//  1561. Maximum Number of Coins You Can Get_2
//
//  Created by admin on 20.03.2021.
//https://leetcode.com/problems/maximum-number-of-coins-you-can-get/submissions/
//Success
//Details
//Runtime: 116 ms, faster than 69.47% of C++ online submissions for Maximum Number of Coins You Can Get.
//Memory Usage: 53.4 MB, less than 71.54% of C++ online submissions for Maximum Number of Coins You Can Get.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {

    
    vector<int> piles  {4,4,17,7,16,16,16,15,2,3,1,17,6,12,9};
    
    int Alice = 0;
    int Im = 0;
    int Bob = 0;

    sort(piles.begin(), piles.end());
    
    int i = 0;
    while (true)
    {
        Alice += piles[static_cast<int>(piles.size()-1)];
        piles.pop_back();
        if(!piles.size()) break;
        
        Im += piles[static_cast<int>(piles.size()-1)];
        piles.pop_back();
        if(!piles.size() || i >= static_cast<int>(piles.size()-1)) break;

        Bob += piles[i++];
        piles[i] = 0;
        if(!piles.size()) break;
        
    }
    
    cout << Alice << " : " << Im << " : " << Bob << endl;

    
    return 0;
}
