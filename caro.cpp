// Author: Pham Le Tien Dat MSSV: 2310687
// Date: 27/5/2025

#include "Caro.h"


Caro::Caro(){
    stop = false;
    for(int i = 0; i < 10; ++i){
        for (int j = 0; j < 10; ++j){
            status[i][j] = n;
        }
    }
}

void Caro::X_step(){
    cout << "Enter coordinate for user 1 - x:\n";
    int x_i, y_i;
    cout << "Please enter the X coordinate - vertical axis (Integer): ";
    cin >> x_i;
    while (x_i >= 10 || x_i <= -1){
        cout << "X is invalid\n";
        cout << "Please enter the X coordinate (vertical axis) again: ";
        cin >> x_i;
    }
    cout << "Please enter the Y coordinate - horizontal axis (Integer): ";
    cin >> y_i;
    while (y_i >= 10 || y_i <= -1){
        cout << "Y is invalid\n";
        cout << "Please enter the Y coordinate (horizontal axis) again: ";
        cin >> y_i;
    }
    if(status[x_i][y_i] != n){
        cout << "Coordinate is invalid\n";
        X_step();
    }
    else {
    status[x_i][y_i] = x;
    if(check_win(x_i, y_i)) {
        cout << "User 1 (x) win the match!\n";
        stop = true;
    }
    }

}

void Caro::O_step(){
    cout << "Enter coordinate for user 2 - o:\n";
    int x_i, y_i;
    cout << "Please enter the X coordinate - vertical axis (Integer): ";
    cin >> x_i;
    while (x_i >= 10 || x_i <= -1){
        cout << "X is invalid\n";
        cout << "Please enter the X coordinate (vertical axis) again: ";
        cin >> x_i;
    }
    cout << "Please enter the Y coordinate - horizontal axis (Integer): ";
    cin >> y_i;
    while (y_i >= 10 || y_i <= -1){
        cout << "Y is invalid\n";
        cout << "Please enter the Y coordinate (horizontal axis) again: ";
        cin >> y_i;
    }
    if(status[x_i][y_i] != n){
        cout << "Coordinate is invalid\n";
        O_step();
    }
    else {
    status[x_i][y_i] = o;
    if(check_win(x_i, y_i)) {
        cout << "User 2 (o) win the match!\n";
        stop = true;
    }
    }
}

bool Caro::getStop(){
    return stop;
}

bool Caro::check_win(int i, int j){
    // check duong cheo
    if(check_ngang(i, j) || check_doc(i, j) || check_cheo_p(i , j) || check_cheo_t(i, j)) return true;
    return false;
}

bool Caro::check_ngang(int i, int j){
    C_Status temp = status[i][j];
    int j_move = j - 1;
    int dem = 0;
    while (j_move >= 0 && dem != 4 && status[i][j_move] == temp) {
        ++dem;
        j_move--;
    }
    if (dem == 4) return true;
    j_move = j + 1;
    while (j_move <= 9 && dem != 4 && status[i][j_move] == temp){
        ++dem;
        j_move++;
    }
    if(dem == 4) return true;
    return false;
}

bool Caro::check_doc(int i, int j){
    C_Status temp = status[i][j];
    int i_move = i - 1;
    int dem = 0;
    while (i_move >= 0 && dem != 4 && status[i_move][j] == temp) {
        ++dem;
        i_move--;
    }
    if (dem == 4) return true;
    i_move = i + 1;
    while (i_move <= 9 && dem != 4 && status[i_move][j] == temp){
        ++dem;
        i_move++;
    }
    if(dem == 4) return true;
    return false;
}

bool Caro::check_cheo_p(int i, int j){
    C_Status temp = status[i][j];
    int i_move = i - 1;
    int j_move = j + 1;
    int dem = 0;
    while (i_move >= 0 && j_move <= 9 && dem != 4 && status[i_move][j_move] == temp) {
        ++dem;
        i_move--;
        j_move++;
    }
    if (dem == 4) return true;
    i_move = i + 1;
    j_move = j - 1;
    while (i_move <= 9 && j_move >= 0 && dem != 4 && status[i_move][j_move] == temp){
        ++dem;
        i_move++;
        j_move--;
    }
    if(dem == 4) return true;
    return false;
}

bool Caro::check_cheo_t(int i, int j){
    C_Status temp = status[i][j];
    int i_move = i - 1;
    int j_move = j - 1;
    int dem = 0;
    while (i_move >= 0 && j_move >= 0 && dem != 4 && status[i_move][j_move] == temp) {
        ++dem;
        i_move--;
        j_move--;
    }
    if (dem == 4) return true;
    i_move = i + 1;
    j_move = j + 1;
    while (i_move <= 9 && j_move <= 9 && dem != 4 && status[i_move][j_move] == temp){
        ++dem;
        i_move++;
        j_move++;
    }
    if(dem == 4) return true;
    return false;
}

void Caro::print_status(){
        cout <<"  ";
        for(int i = 0; i < 10; ++i){
            cout << i << " ";
        }
        cout << "\n";
        for (int i = 0; i < 10; ++i){
            cout << i << " ";
            for (int j = 0; j < 10; ++j){
                if(status[i][j] == n) cout << "- ";
                else if (status[i][j] == x) cout << "x ";
                else cout << "o ";
            }
            cout << endl;
        }
}

void Caro::run(){
    cout << "Welcome to Dat-Caro game!\n";
    cout << "-------------------------\n";  
    while(true){
        this->print_status();
        this->X_step();
        if(this->getStop()) break;
        this->print_status();
        this->O_step();
        if(this->getStop()) break; 
    }
    this->print_status();
    cout << "-----------END-----------\n"; 
}
