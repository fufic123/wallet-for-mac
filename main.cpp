//
//  main.cpp
//  test
//
//  Created by Mark Semenov on 01.12.2022.
//
#include <iostream>
#include <fstream>
#include <vector>
#include "Header.h"

using namespace std;

// functions
/// function which adds your assets
bool add_asset();

/// function which reads project files
bool read_file(vector<string> &vector, string filepath);

/// function which adds transactions
bool transaction();

/// function which calls first screen
bool first_screen();

/// function which creating transactions history
bool history(string name, double n);

/// function which shows text about us
void about_us();

/// function which creats new user
bool sign_up();

/// function which logis user
bool sign_in();

/// function which shows your wallet with assets
bool check_wallet();

/// function which helps to transform path to name of asset
string reverseF(string const &s);

/// function which count all transactions
bool counter(string filepath);

/// function which deletes assets
bool remove_asset();

/// function which shows main error
void error();

/// function which shows history
void show_history();


// MAIN
int main() {
    string filepath = "files/login_info.txt";
    ifstream file;
    file.open(filepath);

    if (file.is_open()) {
        sign_in();
    }
    else {
        sign_up();
    }
}
