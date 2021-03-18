#include "per_alg.hpp"
#include <vector>
#include <string>
#include <iostream>
#define CELLSIZE 100
#define DEBUG true

namespace my {

    void shrinkLeadNulls(TVeryLong& ptb) {
        for (size_t i = ptb.len; i > 0; --i) {
            if (i > 1 && ptb.cells[i - 1] == 0) {
                ptb.cells.pop_back();
                ptb.len--;
            }
            else {
                break;
            }
        }
    }

    my::TVeryLong operator+(const my::TVeryLong& lhs, const my::TVeryLong& rhs)
    {
        my::TVeryLong res = my::sum(lhs, rhs);
        my::shrinkLeadNulls(res);
        return res;
    }

    my::TVeryLong operator-(const my::TVeryLong& lhs, const my::TVeryLong& rhs)
    {
        if (lhs < rhs) {
            throw (-1);
        }

        my::TVeryLong res = my::dif(lhs, rhs);
        my::shrinkLeadNulls(res);
        return res;
    }

    my::TVeryLong operator*(const my::TVeryLong& lhs, const my::TVeryLong& rhs)
    {
        my::TVeryLong res = my::comp(lhs, rhs);
        my::shrinkLeadNulls(res);
        return res;
    }

    my::TVeryLong operator^(const my::TVeryLong& lhs, const my::TVeryLong& rhs)
    {
        if (lhs == my::TVeryLong(std::vector<long long>({ 0 })) && rhs == my::TVeryLong(std::vector<long long>({ 0 }))) {
            throw (-1);
        }

        //my::TVeryLong res = my::TVeryLong(std::vector<long long>({ 1 }));
        my::TVeryLong res = my::TVeryLong(std::vector<long long>({ 1 }));
        my::TVeryLong pre = lhs;
        my::TVeryLong deg = rhs;
        
        while (deg > my::TVeryLong(std::vector<long long>({ 0 }))) {
            /*printf("res\t"); my::print(res); printf("\n");
            printf("pre\t"); my::print(pre); printf("\n");
            printf("deg\t"); my::print(deg); printf("\n");*/
            if (deg.cells[0] % 2 == 1) {
                res = pre * res;
                deg = deg - my::TVeryLong(std::vector<long long>({ 1 }));
            }
            else {
                pre = pre * pre;
                deg = deg / 2;
            }

        }
        //if (rhs.len == 1) {
        //    long long st = rhs.cells[0];
        //    //printf("1st prot | %lld\n", st);
        //    for (int i = 0; i < st; ++i) {
        //        res = res * lhs;
        //    }
        //}
        //else {
        //    //printf("2st prot ");
        //    for (my::TVeryLong i = 0; i < rhs; i = i + 1) {
        //        res = res * lhs;
        //    }
        //}

        return res;
    }

    my::TVeryLong operator^(const my::TVeryLong& lhs, const long long& rhs)
    {
        if (lhs == my::TVeryLong(std::vector<long long>({ 0 })) && rhs == 0) {
            throw (-1);
        }

        my::TVeryLong res = lhs;

        for (int i = 1; i < rhs; ++i) {
            res = res * lhs;
        }

        return res;
    }

    my::TVeryLong operator/(const my::TVeryLong& lhs, const my::TVeryLong& rhs)
    {
        if (rhs == my::TVeryLong(std::vector<long long>({ 0 }))) {
            throw(-1);
        }

        if(DEBUG)printf("i\n");
        return longDiv(lhs, rhs);
    }

    my::TVeryLong operator/(const my::TVeryLong& lhs, const long long& rhs)
    {
        if (rhs == 0) {
            throw(-1);
        }

        printf("r\n");
        return div(lhs, rhs);
    }

    std::ostream& operator<< (std::ostream& out, const my::TVeryLong& ptb) {
        for (size_t i = ptb.len; i > 0; --i) {
            if ((ptb.cells[i - 1] < CELLSIZE / 10) && i != ptb.len) {
                long long mk = ptb.cells[i - 1];
                mk == 0 ? mk = 1 : mk = mk;
                while (mk < CELLSIZE/10) {
                    mk *= 10;
                    out << '0';
                }
            }
            out << ptb.cells[i - 1];
        }
        return out;
    }



    bool operator> (const my::TVeryLong& lhs, const my::TVeryLong& rhs) {
        if (lhs.len > rhs.len) {
            return true;
        }
        else {
            if (lhs.len < rhs.len) {
                return false;
            }
            else {
                for (int i = lhs.len; i > 0; --i) {
                    if (rhs.cells[i - 1] > lhs.cells[i - 1]) {
                        return false;
                    }

                    if (rhs.cells[i - 1] < lhs.cells[i - 1]) {
                        break;
                    }

                    if (i == 1 && rhs.cells[i - 1] >= lhs.cells[i - 1]) {
                        return false;
                    }
                }
                return true;
            }
        }
    }
 
    bool operator< (const my::TVeryLong& lhs, const my::TVeryLong& rhs) {
        if (lhs.len < rhs.len) {
            return true;
        }
        else {
            if (lhs.len > rhs.len) {
                return false;
            }
            else {
                for (int i = lhs.len; i > 0; --i) {
                    if (rhs.cells[i - 1] < lhs.cells[i - 1]) {
                        return false;
                    }

                    if (rhs.cells[i - 1] > lhs.cells[i - 1]) {
                        break;
                    }

                    if (i == 1 && rhs.cells[i - 1] <= lhs.cells[i - 1]) {
                        return false;
                    }
                }
                return true;
            }
        }
    }

    bool operator== (const my::TVeryLong& lhs, const my::TVeryLong& rhs) {
        if (rhs.len > lhs.len) {
            return false;
        }
        else {
            if (rhs.len < lhs.len) {
                return false;
            }
            else {
                for (int i = rhs.len; i > 0; --i) {
                    if (lhs.cells[i - 1] != rhs.cells[i - 1]) {
                        return false;
                    }
                }
                return true;
            }
        }
    }


    void print(const TVeryLong& ptb) {
        for (size_t i = ptb.len; i > 0; --i) {
            if ((ptb.cells[i - 1] < CELLSIZE / 10) && i != ptb.len) {
                long long mk = ptb.cells[i - 1];
                mk == 0 ? mk = 1 : mk = mk;
                while (mk < CELLSIZE/10) {
                    mk *= 10;
                    printf("0");
                }
            }
            printf("%lld|", ptb.cells[i - 1]);
        }
    }

    TVeryLong sum(const TVeryLong& left, const TVeryLong& right) {
        unsigned long maxof = left.len > right.len ? left.len : right.len;
        unsigned long minof = left.len > right.len ? right.len : left.len;
        TVeryLong res;
        long long pathadd = 0;
        for (unsigned int i = 0; i < maxof; ++i) {
            //printf("summing... %lld\n", (left.cells[i] + right.cells[i] + pathadd) % CELLSIZE);
            if (right.len > left.len) {
                res.cells.push_back(i < minof ? (left.cells[i] + right.cells[i] + pathadd) % CELLSIZE : right.cells[i] + pathadd);
                ++res.len;
            }
            else
            if (right.len < left.len) {
                res.cells.push_back(i < minof ? (left.cells[i] + right.cells[i] + pathadd) % CELLSIZE : left.cells[i] + pathadd);
                ++res.len;
            }
            else {
                //printf("summing sim\n");
                res.cells.push_back((left.cells[i] + right.cells[i] + pathadd) % CELLSIZE);
                ++res.len;
            }

            if (i < minof) {
                if (left.cells[i] + right.cells[i] + pathadd >= CELLSIZE) {
                    pathadd = 1;
                }
                else {
                    pathadd = 0;
                }

                if (i + 1 == maxof && pathadd > 0) {
                    res.cells.push_back(pathadd);
                    ++res.len;
                }
            }
            else {
                pathadd = 0;
            }
        }

        return res;
    }

    TVeryLong dif(const TVeryLong& left, const TVeryLong& right) {
        TVeryLong res(left.len);
        if (left.len > right.len || (left.len == right.len && left.cells[left.len - 1] >= right.cells[right.len - 1])) {
            for (unsigned int i = left.len; i > right.len; --i) {
                res.cells[i - 1] = left.cells[i - 1];
            }

            for (unsigned int i = right.len; i > 0; --i) {
                if (left.cells[i - 1] >= right.cells[i - 1]) {
                    res.cells[i - 1] = left.cells[i - 1] - right.cells[i - 1];
                }
                else {
                    res.cells[i - 1] = left.cells[i - 1] + CELLSIZE - right.cells[i - 1];
                    res.cells[i]--;
                }
            }
        }
        else {
            throw(-1);
        }

        res.cells.shrink_to_fit();
        res.len = res.cells.size();

        return res;
    }

    TVeryLong comp(const TVeryLong& left, const TVeryLong& right) {

        TVeryLong res(left.len + right.len);
        //printf("%d %d\n%d\n", left.cells.size(), right.cells.size(), res.cells.size());
        long long pathadd = 0;
        for (unsigned int i = 0; i < right.len; ++i) {
            for (size_t j = 0; j < left.len; ++j) {
                //printf("%d\n", i + j + 1);

                res.cells[j + i] += left.cells[j] * right.cells[i] % CELLSIZE;
                if (res.cells[j + i] >= CELLSIZE) {
                    res.cells[j + i + 1] += res.cells[j + i] / CELLSIZE;
                    res.cells[j + i] = res.cells[j + i] % CELLSIZE;
                }
                res.cells[j + i + 1] += left.cells[j] * right.cells[i] / CELLSIZE;

            }

        }

        res.cells.shrink_to_fit();
        res.len = res.cells.size();

        return res;
    }

    TVeryLong div(const TVeryLong& left, const TVeryLong& right) {
        TVeryLong res(left.len);
        res.len = left.len;
        long long rest = 0;
        if (right.len == 1) {
            for (unsigned int i = left.len; i > 0; --i) {
                res.cells[i - 1] = (left.cells[i - 1] + rest * CELLSIZE) / right.cells[0];
                rest = (left.cells[i - 1] + rest * CELLSIZE) % right.cells[0];
            }
        }

        return res;
    }

    TVeryLong div(const TVeryLong& left, const long long& right) {
        TVeryLong res(left.len);
        res.len = left.len;
        long long rest = 0;
        if (right < CELLSIZE) {
            for (unsigned int i = left.len; i > 0; --i) {
                res.cells[i - 1] = (left.cells[i - 1] + rest * CELLSIZE) / right;
                rest = (left.cells[i - 1] + rest * CELLSIZE) % right;
            }
        }

        return res;
    }

    long long uniteCells(long long first, long long second) {
        return first * CELLSIZE + second;
    }

    TVeryLong sTake(const TVeryLong& wich, const TVeryLong& with) { //возыращает первые T ячеек wich, таких что число составленно из них > with
        int optNum = with.len;

        if (with > wich) {
            return TVeryLong(std::vector <long long>({ 0 }));
        }

        std::vector<long long> prom;
        for (int i = wich.len - 1; i >= wich.len - optNum; i--) {
            prom.push_back(wich.cells[i]);
            if (DEBUG)printf("\t\t sTake: pushed: %lld\n", wich.cells[i]);
        }

        TVeryLong mod(prom);

        if (DEBUG)printf("main part done |"); my::print(mod); printf("--|--"); my::print(with); printf("\n");
        int i = 1;
        while (with > mod && wich.len >= optNum + i) {
            prom.push_back(wich.cells[wich.len - optNum - i]);
            if (DEBUG)printf("\t\t sTake: afterpushed: %lld\n", wich.cells[wich.len - optNum - 1]);
            mod = TVeryLong(prom);
        }

        return mod;
    }

    long long findMult(const TVeryLong& res, const TVeryLong& by) {

        if (res == TVeryLong(std::vector <long long>({ 0 }))) {
            return 0;
        }

        TVeryLong r0 = res;

        if (DEBUG)printf("\t\t expected: %lld \n", uniteCells(r0.cells[r0.len - 1], r0.cells[r0.len - 2]));

        if (res.len > by.len) { //если by на одну ячейку меньше res, то надо объеденить две последние ячейки r0 (xelllen должен быть вдвое меньше max(long long)
            r0.cells[r0.len - 2] = uniteCells(r0.cells[r0.len - 1],r0.cells[r0.len - 2]);
            r0.cells.pop_back();
            r0.len--;
        }

        if (DEBUG)printf("\t\t posM: %lld\n", r0.cells[r0.cells.size() - 1]);

        long long mult = r0.cells[r0.len - 1] / by.cells[by.len - 1];

        if ((by * TVeryLong(std::vector<long long>({ mult })) < res || (by * TVeryLong(std::vector<long long>({ mult })) == res)) && by * TVeryLong(std::vector<long long>({ mult + 1 })) > res) {
            return mult;
        }


        while (!(((by * TVeryLong(std::vector<long long>({ mult })) < res) || ((by * TVeryLong(std::vector<long long>({ mult })) == res ))) && (by * TVeryLong(std::vector<long long>({ mult + 1 })) > res))) {
            if (DEBUG) { printf("\t\t|findMult: %lld,", mult); my::print(by * TVeryLong(std::vector<long long>({ mult }))); printf(" --|-- "); my::print(res); printf("\n"); }
            if (by * TVeryLong(std::vector<long long>({ mult })) < res) {
                mult++;
            }
            else {
                mult--;
            }
        }

        return mult;
    }

    TVeryLong longDiv(const TVeryLong& left, const TVeryLong& right) {
        long long pos = left.len;
        TVeryLong del = left;
        std::vector<long long> preRes;

        if (DEBUG) { printf("del = "); my::print(del); printf("\n"); }
        while(pos > 0) {
            TVeryLong pr = sTake(del, right); //находим первую делимую часть

            if (DEBUG) { printf("\t step unk. s = "); my::print(pr); printf("\n"); } 

            long long multPR = findMult(pr, right); //находим число, на которое надо умножить right чтобы получить максимально число что меньше pr

            if (DEBUG) {
                printf("\t  dividing... %lld", multPR); printf("\n");
                my::print(my::TVeryLong(std::vector<long long>({ multPR })) * right); printf("\n");
                printf("\t min (%lld %lld) = ", pos, pr.len); my::print(my::TVeryLong(std::vector<long long>({ multPR })) * right * (my::TVeryLong(std::vector<long long>({ CELLSIZE })) ^ my::TVeryLong(std::vector<long long>({ (long long)(pos - pr.len) })))); printf("\n");
                printf("ch! > %lld\n", std::vector<long long>({ (long long)(pos - pr.len) })[0]);
                printf("ch! > "); my::print((my::TVeryLong(std::vector<long long>({ CELLSIZE })))); printf(" !||! "); my::print(my::TVeryLong(std::vector<long long>({ pos - pr.len }))); printf(" !||! "); my::print((my::TVeryLong(std::vector<long long>({ CELLSIZE })) ^ my::TVeryLong(std::vector<long long>({ pos - pr.len })))); printf("\n");
            }

            del = del - (my::TVeryLong(std::vector<long long>({ multPR })) * right * (my::TVeryLong(std::vector<long long>({ CELLSIZE })) ^ my::TVeryLong(std::vector<long long>({ (long long)(pos - pr.len) })))); //нахоидм остаток
            
            if (DEBUG) {
                printf("\t new del = "); my::print(del); printf("\n");
                printf("going to nexty step\n");
            }
            
            preRes.push_back (multPR);


            if (del < right) {
                if (DEBUG) {
                    printf("%lld |%lld %lld\n", pos, left.len, right.len);
                }
                /*while (pos < left.len) {
                    preRes.push_back(0);
                    pos ++;
                }
                break;*/
                TVeryLong finRes = TVeryLong(preRes);
                finRes = finRes * (my::TVeryLong(std::vector<long long>({ CELLSIZE })) ^ my::TVeryLong(std::vector<long long>({ (long long)(pos - pr.len) })));
                return finRes;
            }

            pos = del.len;
        }
        return TVeryLong(preRes);
    }

    
}


