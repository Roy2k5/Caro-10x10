// Author: Pham Le Tien Dat MSSV: 2310687
// Date: 27/5/2025

#ifndef CARO_H
#define CARO_H

#include <iostream>
#include <string>
using namespace std;
enum C_Status{
    n = 0,
    x = 1,
    o = 2
};
class Caro {
    private:
        C_Status status[10][10];
        bool stop;
    public:
        Caro();
    private:
        void X_step();
        void O_step();
        bool getStop();
        bool check_win(int i, int j);
        bool check_ngang(int i, int j);
        bool check_doc(int i, int j);
        bool check_cheo_p(int i, int j);
        bool check_cheo_t(int i, int j);
    public:
        void print_status();
        void run();
};

#endif