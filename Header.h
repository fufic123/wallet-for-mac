//
//  Header.h
//  test
//
//  Created by Mark Semenov on 26.12.2022.
//

#ifndef Header_h
#define Header_h

#include <iostream>
#include <fstream>
#include <vector>


//main loop FOR, for read files
#define FOR for (short i = 0; i < vector.size(); i++)
//main path to assets file
#define assetspath "files/assets.txt"

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

//realisation
bool add_asset() {
    ///loop and if control variable
    bool switcher = 0;
    
    vector<string> vector;
    ofstream file;
    file.open (assetspath, ios::app);
    string asset;
    short choise;

    cout << "šŖšŖ Name of your new asset:\t";
    cin >> asset;
    
    read_file(vector, assetspath);
    FOR {
        if (asset == vector[i]) {
            cout << "\nš„š„š„š„š„š„š„š„š„š„š„š„š„š„\n";
            cout << "š„ This asset already exist š„\n";
            cout << "š„š„š„š„š„š„š„š„š„š„š„š„š„š„\n\n";
            while (1) {
                if (!switcher) {
                    cout << "\nšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖ\n";
                    cout << "šŖšŖ 1. Try again šŖšŖ\n";
                    cout << "šŖšŖ 2. Back      šŖšŖ\n";
                    cout << "šŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖ\n\n";
                }
                    ///loop and if control variable
                    switcher = 0;
                    cout << "šŖšŖ Your choise: ";
                    cin >> choise;

                switch (choise) {
                    case 1:
                        add_asset();
                        break;
                    case 2:
                        check_wallet();
                        break;
                    default:
                        error();
                        switcher = 1;
                        break;
                    }
            }
        }
    }
    
    file << asset << endl;
    file.close();
    
    while (1) {
        if (!switcher) {
            cout << "šŖšŖ Do you want to add new transaction?\n";
            cout << "\nšŖšŖšŖšŖšŖšŖšŖšŖ\n";
            cout << "šŖšŖ 1. Yes šŖšŖ\n";
            cout << "šŖšŖ 2. No  šŖšŖ\n";
            cout << "šŖšŖšŖšŖšŖšŖšŖšŖ\n\n";

        }
            ///loop and if control variable
            switcher = 0;
            cout << "šŖšŖ Your choise: ";
            cin >> choise;

        switch (choise) {
            case 1:
                transaction();
                break;
            case 2:
                first_screen();
                break;
            default:
                error();
                switcher = 1;
                break;
            }
        }
    return 0;
}

bool transaction() {
    vector<string> vector;
    read_file(vector, assetspath);
    string filepath;
    string mystring;
    string reverse_string;
    ///loop and if control variable
    short counter = 0;
    
    short choise = 0;
    
    ///loop and if control variable
    bool switcher = 0;
    cout << "\nšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖ\n";
    cout << "šŖšŖ         Enter path to your asset          šŖšŖ\n";
    cout << "šŖšŖ  Example: 'files/NAME-OF-YOUR-ASSET.dat'  šŖšŖ\n";
    cout << "šŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖ\n\n";

    cin >> filepath;
    
    mystring = filepath.substr(6);
    reverse_string = reverseF(mystring);
    mystring = reverse_string.substr(4);
    reverse_string = reverseF(mystring);
    mystring = reverse_string;
    
    FOR {
        if(strcmp(vector[i].c_str(), mystring.c_str()) == 0) {
            counter = 1;
        }
    }
    if (counter != 1) {
        cout << "\nš„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„\n";
        cout << "š„This asset is not exist. You have to use one\t  š„\nš„that already exist or create new one.\t\t\t  š„\n";
        cout << "š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„\n";
        
        while (1) {
            if (!switcher) {
                cout << "\nšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖ\n";
                cout << "šŖ 1. Try again\t\t\t\tšŖ\nšŖ 2. Create new asset\t\tšŖ\nšŖ 3. Back\t\t\t\t\tšŖ\n";
                cout << "šŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖ\n";
            }
                ///loop and if control variable
                switcher = 0;
                cout << "šŖšŖ Your choise: ";
                cin >> choise;

            switch (choise) {
                case 1:
                    transaction();
                    break;
                case 2:
                    add_asset();
                    break;
                case 3:
                    check_wallet();
                    break;
                default:
                    error();
                    switcher = 1;
                    break;
                }
            }
    }
    
    ofstream file;
    file.open (filepath, ios::app);
    
    while (!file.is_open()) {
        cout << "\nš„š„š„š„š„š„š„š„š„š„š„š„\n";
        cout << "š„Wrong path. Try again.š„\n";
        cout << "š„š„š„š„š„š„š„š„š„š„š„š„\n";
        cout << "\nšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖ\n";
        cout << "šŖšŖ         Enter path to your asset          šŖšŖ\n";
        cout << "šŖšŖ  Example: 'files/NAME-OF-YOUR-ASSET.dat'  šŖšŖ\n";
        cout << "šŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖ\n\n";
        cin >> filepath;
        file.open (filepath, ios::app | ios::out);
    }

    double n;
    while (1) {
        if (!switcher) {
            cout << "\nšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖ\n";
            cout << "šŖ1. Add\t\t\t\t\t  šŖ\nšŖ2. Subtract\t\t\t\t  šŖ\nšŖ3. Back\t\t\t\t\t  šŖ\n";
            cout << "šŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖ\n";
        }
            ///loop and if control variable
            switcher = 0;
            cout << "šŖšŖ Your choise: ";
            cin >> choise;

    switch (choise) {
        case 1:
            cout << "šŖšŖ How much: ";
            cin >> n;
            file << n << endl;
            first_screen();
            break;
        case 2:
            cout << "šŖšŖ How much: ";
            cin >> n;
            n *= -1;
            file << n << endl;
            check_wallet();
            break;
        case 3:
            first_screen();
            break;

        default:
            error();
            switcher = 1;
            break;
    }
//    adding history
    history(mystring, n);
    file.close();
    return 0;
    }
}

bool counter(string filepath) {
    ifstream file(filepath);
    int counter = 0;
    int n;
        
    while (file >> n) {
        counter += n;
    }
    
    string mystring;
    string reverse_string;
    
//    convert from filepath name of asset
    mystring = filepath.substr(6);
    reverse_string = reverseF(mystring);
    mystring = reverse_string.substr(4);
    reverse_string = reverseF(mystring);
    mystring = reverse_string;
    
    cout << "šŖ\t\t" << mystring << "= " << counter << "\t\t\t\tšŖ" << endl;
    
    file.close();
    return 0;
}

bool remove_asset() {
    vector<string> vector;
    read_file(vector, assetspath);
    string choise;
    short counter = 0;
    short n = 0;
    cout << "šŖšŖ Name of asset which you want to delete: ";
    cin >> choise;
    
    FOR {
        if(strcmp(vector[i].c_str(), choise.c_str()) == 0) {
            counter = 1;
            n = i;
        }
    }
    if (counter != 1) {
        cout << "\nš„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„\n";
        cout << "š„This asset is not exist. You have to use one\t  š„\nš„that already exist or create new one.\t\t\t  š„\n";
        cout << "š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„\n";
    }
    else {
//        delete asset from vector
        vector.erase(vector.begin() + n);
    }
    
    ofstream file;
    file.open (assetspath, ios::out);
    
    FOR {
        file << vector[i] << endl;
    }
    file.close();
    string filepath = "files/" + choise + ".dat";
    remove(filepath.c_str());
    
    return 0;
}

bool history(string name, double n) {
    string filepath = "files/history.txt";
    ofstream file;
    file.open(filepath, ios::app);
    
    string n_str = to_string(n);
    
    name = name + "= " + n_str;
    file << name << endl;
    
    file.close();
    return 0;
}

void show_history() {
    string filepath = "files/history.txt";
    vector<string> vector;
    read_file(vector, filepath);
    
    FOR {
        cout << "šŖ\t\t" << vector[i]  << "\t\t\t\tšŖ" << endl;
    }
}

bool sign_up() {
    ofstream file;
    string filepath = "files/login_info.txt";
    file.open (filepath, ios::app);
    
    string password = "none";
    string username = "none";
    string username_confirmation;
    string password_confirmation;
    int choise = 0;
    
    if (password == "none" & username == "none") {
        cout << "ā¬ļøā¬ļøā¬ļøā¬ļøā¬ļøā¬ļøā¬ļøā¬ļøā¬ļøā¬ļøā¬ļøā¬ļø\n";
        cout << "ā¬ļø  Create your accout āÆā¬ļø\nā¬ļø        1. OK         ā¬ļø\nā¬ļø        2. NO         ā¬ļø\nā¬ļøAnother symbol == QUITā¬ļø\n";
        cout << "ā¬ļøā¬ļøā¬ļøā¬ļøā¬ļøā¬ļøā¬ļøā¬ļøā¬ļøā¬ļøā¬ļøā¬ļø\n\n";
        cout << "ā¬ļøā¬ļø Your choise: ";
        cin >> choise;
        }
        if (choise == 1) {
            cout << "ā¬ļøā¬ļø Create your own username: ";
            cin >> username;
            cout << "ā¬ļøā¬ļø Confirm your new username: ";
            cin >> username_confirmation;
            while (strcmp(username_confirmation.c_str(), username.c_str()) != 0) {
                error();
                cout << "ā¬ļøā¬ļø Create your own username: ";
                cin >> username;
                cout << "ā¬ļøā¬ļø Confirm your new username: ";
                cin >> username_confirmation;
            }
            
            cout << "Rules:\n- min 16 symbols\n\n";
            cout << "ā¬ļøā¬ļø Create your own passwrod: ";
            cin >> password;
            cout << "ā¬ļøā¬ļø Confirm your new password: ";
            cin >> password_confirmation;

            while (strcmp(password_confirmation.c_str(), password.c_str()) != 0) {
                error();
                cout << "ā¬ļøā¬ļø Create your own passwrod: ";
                cin >> password;
                cout << "ā¬ļøā¬ļø Confirm your new password: ";
                cin >> password_confirmation;
            }
            if (password.length() != 16) {
                error();
                cout << "ā¬ļøā¬ļø Create your own passwrod: ";
                cin >> password;
                cout << "ā¬ļøā¬ļø Confirm your new password: ";
                cin >> password_confirmation;
            }
            else {
                cout << "\n\nāāā SUCCESS āāā\n\n\n";
                file << password << endl;
                file << username << endl;
            }
    
        cout << "šŖšŖ Please enter your username: ";
        cin >> username;
        cout << "šŖšŖ Please enter your password: ";
        cin >> password;
        
        while (strcmp(username.c_str(), username_confirmation.c_str()) != 0 || strcmp(password.c_str(), password_confirmation.c_str()) != 0) {
            error();
            cout << "šŖšŖ Please enter your username: ";
            cin >> username;
            cout << "šŖšŖ Please enter your password: ";
            cin >> password;
        }
    }
    else if (choise == 2) {
        cout << "\nš„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„\n";
        cout << "š„ Create your account now, because you won't have an access to wallet š„\n";
        cout << "š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„š„\n\n";

        sign_up();
    }
    else {
        remove(filepath.c_str());
        return 0;
    }
    file.close();
    first_screen();
    return 0;
}

bool sign_in() {
    string filepath = "files/login_info.txt";
    vector<string> vector;
    read_file(vector, filepath);
    
    string username;
    string password;

    while (1)
         {
            cout << "šŖšŖ Username:\t";
            cin >> username;
            cout << "šŖšŖ Password:\t";
            cin >> password;
            if ((strcmp(vector[1].c_str(), username.c_str()) == 0) && (strcmp(vector[0].c_str(), password.c_str()) == 0)) {
                break;
            }
         }
    first_screen();
    return 0;
}

void error() {
    cout << "\n\nš„š„š„š„š„š„š„š„š„š„š„š„š„š„\n";
    cout << "š„  Error: resend request   š„\n";
    cout << "š„š„š„š„š„š„š„š„š„š„š„š„š„š„\n\n\n";
}

string reverseF(string const &s)
{
    string rev;
    for (int i = s.size() - 1; i >= 0; i--) {
        rev = rev.append(1, s[i]);
    };
 
    return rev;
}
 

bool read_file(vector<string> &vector, string filepath) {
    ifstream file(filepath, ios::in);
        
    char buffer[20];
    while (!file.eof()) {
        file.getline(buffer, 20);
        vector.push_back(buffer);
    }
    
    file.close();
    return 0;
}


bool first_screen() {
///user choise variable
    int choise = 0;
///control loop variable
    bool switcher = 0;
    while (1) {
        if (!switcher) {
            cout << "šŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖ\n";
            cout << "šŖ  \tWelcome to your wallet\tšŖ\n";
            cout << "šŖ  \t1. Check Wallet\t\t\tšŖ\n";
            cout << "šŖ  \t2. History\t\t\t\tšŖ\n";
            cout << "šŖ  \t3. About Us\t\t\t\tšŖ\n";
            cout << "šŖ  \t4. Quit\t\t\t\t\tšŖ\n";
            cout << "šŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖ\n\n";
        }
        switcher = 0;
        cout << "šŖšŖ Your choise: ";
        cin >> choise;

        switch (choise) {
            case 1:
                check_wallet();
                break;

            case 2:
                show_history();
                break;

            case 3:
                about_us();
                break;

            case 4:
                cout << "\n\nš¤š¤š¤š¤š¤š¤š¤š¤š¤š¤š¤š¤š¤š¤\n";
                cout << "š¤  Goodbye! See you later! š¤\n";
                cout << "š¤š¤š¤š¤š¤š¤š¤š¤š¤š¤š¤š¤š¤š¤\n\n";
                return 0;
                break;

            default:
                error();
                switcher = 1;
        }
    }
}

void about_us() {
///control loop var
    int switcher = 3;
    while(1) {
        if (switcher == 1) {
            cout << "\nš¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦\n";
            cout << "š¦Hello, we are team āThe Boysā. That project  š¦\nš¦is a work for the āIT STEP ACADEMYā. In whichš¦\nš¦Mark, Svyatoslav and Veronica took part.";
            cout << "(1/3)š¦\n";
            cout << "š¦Enter random symbol to go back to main menu  š¦\n";
            cout << "š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦\n";

            cout << "\nš¦š¦ Enter number: ";
            cin >> switcher;
        }
        else if (switcher == 2) {
            cout << "\nš¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦\n";
            cout << "š¦This project is about to create a financial  š¦\nš¦wallet on the MAC OS system. In which we usedš¦\nš¦such technologies: pseudographics,vectors,   š¦\nš¦file system, pointers, preprocessors, stringsš¦\n";
            cout << "š¦(2/3) \t\t\t\t\t\t\t\t\t   š¦\n";
            cout << "š¦Enter random symbol to go back to main menu  š¦\n";
            cout << "š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦\n";
            
            cout << "\nš¦š¦ Enter number: ";
            cin >> switcher;
        }
        else if (switcher == 3) {
            cout << "\nš¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦\n";
            cout << "š¦Please enter all paths wich program ask you  š¦\nš¦correctly. If you want to support us '5168   š¦\nš¦7559 0605 5138' - PrivatBank UA. If you want š¦\nš¦to advise something or contact  \t\t\t   š¦\nš¦us --> semenovmark07@gmail.com \t\t";
            cout << "(3/3)  š¦\n";
            cout << "š¦Enter random symbol to go back to main menu  š¦\n";
            cout << "š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦š¦\n";
            
            cout << "\nš¦š¦ Enter number: ";
            cin >> switcher;
        }
        else {
            first_screen();
        }
    }
    
}


bool check_wallet() {
    ofstream file;
    file.open (assetspath, ios::app);
    string new_filepath;
    vector<string> vector;
    string filepath;

    read_file(vector, assetspath);

    cout << "\nšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖ\n";
    cout << "šŖ\t\tYour assets:\t\tšŖ\n";
    for(short i = 0; i < vector.size() - 1; i++) {
        new_filepath = "files/" + vector[i] + ".dat";
        filepath = new_filepath;
        counter(filepath);
    }
    
///user choise
    int choise = 0;
//    control loop var
    bool switcher = 0;
    while (1) {
        if (!switcher) {
            cout << "šŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖ\n";
            cout << "šŖ   \t1. Add asset\t\tšŖ\n";
            cout << "šŖ   \t2. Add transaction  šŖ\n";
            cout << "šŖ   \t3. History\t\t\tšŖ\n";
            cout << "šŖ   \t4. Back\t\t\t\tšŖ\n";
            cout << "šŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖšŖ\n\n";
        }
        switcher = 0;
        cout << "šŖšŖ Your choise: ";
        cin >> choise;

        switch (choise) {
            case 1:
                add_asset();
                break;

            case 2:
                transaction();
                break;

            case 3:
                show_history();
                break;

            case 4:
                first_screen();
                break;

            default:
                error();
                switcher = 1;
        }
    }
    
    return 0;
}


#endif /* Header_h */
