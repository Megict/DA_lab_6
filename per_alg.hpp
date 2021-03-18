#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#define CELLLEN 2
const long long CELLSIZE = (long long)pow(10, CELLLEN);

namespace my {
    class TVeryLong {
    public:
        std::vector<long long> cells;
        size_t len;

        TVeryLong() {
            len = 0;
        }

        TVeryLong(size_t preSize) {
            len = 0;
            cells = std::vector<long long>(preSize);
        }


        TVeryLong(std::vector<long long> inp) {
            //cells = inp; 
            for (int i = 0; i < inp.size(); ++i) {
                cells.push_back(inp[inp.size() - 1 - i]);
            }
            len = inp.size();
        }


        //friend std::ofstream& const operator<< (std::ofstream& out, const my::TVeryLong& ptb);
        friend my::TVeryLong operator+ (const my::TVeryLong& lhs, const my::TVeryLong& rhs);
        friend my::TVeryLong operator- (const my::TVeryLong& lhs, const my::TVeryLong& rhs);
        friend my::TVeryLong operator* (const my::TVeryLong& lhs, const my::TVeryLong& rhs);
        friend my::TVeryLong operator^ (const my::TVeryLong& lhs, const my::TVeryLong& rhs);
        friend my::TVeryLong operator^ (const my::TVeryLong& lhs, const long long& rhs);
        friend my::TVeryLong operator/ (const my::TVeryLong& lhs, const my::TVeryLong& rhs);
        friend my::TVeryLong operator/ (const my::TVeryLong& lhs, const long long& rhs);
        friend std::ostream& operator<< (std::ostream& out, const my::TVeryLong& ptb);

        friend bool operator> (const my::TVeryLong& lhs, const my::TVeryLong& rhs);
        friend bool operator< (const my::TVeryLong& lhs, const my::TVeryLong& rhs);
        friend bool operator== (const my::TVeryLong& lhs, const my::TVeryLong& rhs);
    };



    void print(const TVeryLong& ptb);
    void shrinkLeadNulls(TVeryLong& ptb);
    TVeryLong sum(const TVeryLong& left, const TVeryLong& right);
    TVeryLong dif(const TVeryLong& left, const TVeryLong& right);
    TVeryLong comp(const TVeryLong& left, const TVeryLong& right);
    TVeryLong div(const TVeryLong& left, const TVeryLong& right);
    TVeryLong div(const TVeryLong& left, const long long& right); 
    TVeryLong longDiv(const TVeryLong& left, const TVeryLong& right);
    //TVeryLong del(const TVeryLong& left, const TVeryLong& right) {

    //}
}

