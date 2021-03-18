#pragma warning(disable : 4996)
#include <vector>
#include <string>
#include <iostream>
#include "per_alg.hpp"

my::TVeryLong configurate(std::string inp) {
    std::vector<long long> rv;
    long long part = 0;

    int cdn = inp.size() % CELLLEN;
    std::cout << inp << std::endl;
    printf("%d|%d\n",inp.size(),cdn);
    int ii = 0;
    for (int i = 0; i < inp.size(); ++i, ++ii) {
        printf("foc st %d | %c\n", i, inp[i]);

        part *= 10;
        part += ((long long)inp[i] - '0');
        
        if ((i + 1) == cdn) {
        //    printf("first point reached\n");
            rv.push_back(part);
            ii = -1;
            part = 0;
            cdn = -1;
            continue;
        }

        if ((ii + 1) % CELLLEN == 0) {
          //  printf("flush\n");
            rv.push_back(part);
            part = 0;
        }
    }


    my::TVeryLong res(rv);
    return res;
}

int main() {


    char inpC;
    int mode = 0;
    my::TVeryLong op1;
    my::TVeryLong op2;
    my::TVeryLong res;
    std::string former;

    //goto a;

    printf(">");
    while (scanf("%c", &inpC) != EOF) {

        if (mode == 0) {

            if (inpC >= '0' && inpC <= '9') {
                former.push_back(inpC);
            }
            else 
            if (inpC == '\n') {
                mode = 1;
                op1 = configurate(former);
                my::shrinkLeadNulls(op1);
                printf("\t"); my::print(op1); printf("\n");
                std::cout << op1 << "\n";
                former.clear();
            }
        }
        else 
        if (mode == 1) {
            if (inpC >= '0' && inpC <= '9') {
                former.push_back(inpC);
            }
            else
            if (inpC == '\n') {
                mode = 2;
                op2 = configurate(former);
                my::shrinkLeadNulls(op2);
                printf("\t"); my::print(op2); printf("\n");
                std::cout << op2 << "\n";
                former.clear();
            }
        }
        else 
        if (mode == 2) {
            if (inpC == '+') {
                res = op1 + op2;
            }
            else
            if (inpC == '-') {
                try {
                    res = op1 - op2;
                }
                catch (int err) {
                    scanf("%c", &inpC);
                    printf("error\n");
                    mode = 0;
                    continue;
                }
            }
            else
            if (inpC == '*') {
                res = op1 * op2;
            }
            else
            if (inpC == '/') {

                printf("\n");

                try {
                    res = op1 / op2;
                }
                catch (int err) {
                    scanf("%c", &inpC);
                    printf("error\n");
                    mode = 0;
                    continue;
                }
            }
            else
            if (inpC == '^') {
                try {
                    res = op1 ^ op2;
                }
                catch (int err) {
                    scanf("%c", &inpC);
                    printf("error\n");
                    mode = 0;
                    continue;
                }
            }
            else
            if (inpC == '>') {
                if (op1 > op2) {
                    printf("true\n");
                }
                else {
                    printf("false\n");
                }
                scanf("%c", &inpC);
                mode = 0;
                continue;
            }
            else
            if (inpC == '<') {
                if (op1 < op2) {
                    printf("true\n");
                }
                else {
                    printf("false\n");
                }
                scanf("%c", &inpC);
                mode = 0;
                continue;
            }
            else
            if (inpC == '=') {
                if (op1 == op2) {
                    printf("true\n");
                }
                else {
                    printf("false\n");
                }
                scanf("%c", &inpC);
                mode = 0;
                continue;
            }
            else {
                scanf("%c", &inpC);
                printf("error\n");
                mode = 0;
                continue;
            }

            scanf("%c", &inpC);

            my::shrinkLeadNulls(res);
            printf("\t"); my::print(res); printf("\n");
            std::cout << res << "\n";
            mode = 0;

        }
        printf(">");
    }
    return 0;
    
a:


    std::vector<long long> form;
    printf("start| sum\n");
    form.push_back(1);
    form.push_back(23);
    my::TVeryLong test1(form);
    form.clear();
    form.push_back(9);
    form.push_back(45);
    form.push_back(11);
    my::TVeryLong test2(form);
    printf("print\n");
    my::print(test1);
    printf("\n");
    my::print(test2);
    printf("\n");
    my::print(my::sum(test1,test2));
    printf("\n");
    my::print(test1 + test2);
    printf("\n");
    printf("\n");

    printf("start| diff\n");
    form.clear();
    form.push_back(9);
    form.push_back(49);
    form.push_back(11);
    my::TVeryLong test5(form);
    form.clear();
    form.push_back(9);
    form.push_back(49);
    form.push_back(11);
    my::TVeryLong test6(form);
    printf("print\n");
    my::print(test5);
    printf("\n");
    my::print(test6);
    printf("\n");
    my::TVeryLong test11(my::dif(test5, test6));
    my::shrinkLeadNulls(test11);
    my::print(test11);
    printf("\n");
    my::print(test5 - test6);
    printf("\n");
    printf("\n");

    printf("start| comp\n");
    form.clear();
    form.push_back(90);
    form.push_back(10);
    my::TVeryLong test3(form);
    form.clear();
    form.push_back(10);
    my::TVeryLong test4(form);
    printf("print\n");
    my::print(test3);
    printf("\n");
    my::print(test4);
    printf("\n");
    my::print(my::comp(test3, test4));
    printf("\n");
    my::print(test3 * test4);

    my::TVeryLong test10 = my::comp(test3, test4);
    printf("\n");


    printf("start| div\n");
    form.clear();
    form.push_back(90);
    form.push_back(10);
    my::TVeryLong test8(form);
    form.clear();
    form.push_back(10);
    my::TVeryLong test9(form);
    printf("print\n");
    my::print(test8);
    printf("\n");
    my::print(test9);
    printf("\n");
    my::print(my::div(test8, test9));
    printf("\n");
    my::print(my::div(test8, 10));
    printf("\n");
    my::print(test8 / test9);
    printf("\n");
    my::print(test8 / 10);
    printf("\n-\n");
    
    
    std::cout << configurate("100431");
    printf("\n-\n");


    my::print( (configurate("1023") ^ (long long)1) );
    printf("\n-\n");
    my::print((configurate("1023") ^ (long long)2));
    printf("\n-\n");
    my::print((configurate("1023") ^ (long long)3));
    printf("\n-\n");
    my::print((configurate("1023") ^ (long long)10));
    printf("\n-\n");


    my::print(configurate("100431"));
    printf("\n-");
}