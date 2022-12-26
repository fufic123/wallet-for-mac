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

    cout << "🟪🟪 Name of your new asset:\t";
    cin >> asset;
    
    read_file(vector, assetspath);
    FOR {
        if (asset == vector[i]) {
            cout << "\n🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥\n";
            cout << "🟥 This asset already exist 🟥\n";
            cout << "🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥\n\n";
            while (1) {
                if (!switcher) {
                    cout << "\n🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪\n";
                    cout << "🟪🟪 1. Try again 🟪🟪\n";
                    cout << "🟪🟪 2. Back      🟪🟪\n";
                    cout << "🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪\n\n";
                }
                    ///loop and if control variable
                    switcher = 0;
                    cout << "🟪🟪 Your choise: ";
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
            cout << "🟪🟪 Do you want to add new transaction?\n";
            cout << "\n🟪🟪🟪🟪🟪🟪🟪🟪\n";
            cout << "🟪🟪 1. Yes 🟪🟪\n";
            cout << "🟪🟪 2. No  🟪🟪\n";
            cout << "🟪🟪🟪🟪🟪🟪🟪🟪\n\n";

        }
            ///loop and if control variable
            switcher = 0;
            cout << "🟪🟪 Your choise: ";
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
    cout << "\n🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪\n";
    cout << "🟪🟪         Enter path to your asset          🟪🟪\n";
    cout << "🟪🟪  Example: 'files/NAME-OF-YOUR-ASSET.dat'  🟪🟪\n";
    cout << "🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪\n\n";

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
        cout << "\n🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥\n";
        cout << "🟥This asset is not exist. You have to use one\t  🟥\n🟥that already exist or create new one.\t\t\t  🟥\n";
        cout << "🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥\n";
        
        while (1) {
            if (!switcher) {
                cout << "\n🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪\n";
                cout << "🟪 1. Try again\t\t\t\t🟪\n🟪 2. Create new asset\t\t🟪\n🟪 3. Back\t\t\t\t\t🟪\n";
                cout << "🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪\n";
            }
                ///loop and if control variable
                switcher = 0;
                cout << "🟪🟪 Your choise: ";
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
        cout << "\n🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥\n";
        cout << "🟥Wrong path. Try again.🟥\n";
        cout << "🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥\n";
        cout << "\n🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪\n";
        cout << "🟪🟪         Enter path to your asset          🟪🟪\n";
        cout << "🟪🟪  Example: 'files/NAME-OF-YOUR-ASSET.dat'  🟪🟪\n";
        cout << "🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪\n\n";
        cin >> filepath;
        file.open (filepath, ios::app | ios::out);
    }

    double n;
    while (1) {
        if (!switcher) {
            cout << "\n🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪\n";
            cout << "🟪1. Add\t\t\t\t\t  🟪\n🟪2. Subtract\t\t\t\t  🟪\n🟪3. Back\t\t\t\t\t  🟪\n";
            cout << "🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪\n";
        }
            ///loop and if control variable
            switcher = 0;
            cout << "🟪🟪 Your choise: ";
            cin >> choise;

    switch (choise) {
        case 1:
            cout << "🟪🟪 How much: ";
            cin >> n;
            file << n << endl;
            first_screen();
            break;
        case 2:
            cout << "🟪🟪 How much: ";
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
    
    cout << "🟪\t\t" << mystring << "= " << counter << "\t\t\t\t🟪" << endl;
    
    file.close();
    return 0;
}

bool remove_asset() {
    vector<string> vector;
    read_file(vector, assetspath);
    string choise;
    short counter = 0;
    short n = 0;
    cout << "🟪🟪 Name of asset which you want to delete: ";
    cin >> choise;
    
    FOR {
        if(strcmp(vector[i].c_str(), choise.c_str()) == 0) {
            counter = 1;
            n = i;
        }
    }
    if (counter != 1) {
        cout << "\n🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥\n";
        cout << "🟥This asset is not exist. You have to use one\t  🟥\n🟥that already exist or create new one.\t\t\t  🟥\n";
        cout << "🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥\n";
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
        cout << "🟪\t\t" << vector[i]  << "\t\t\t\t🟪" << endl;
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
        cout << "⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️\n";
        cout << "⬜️  Create your accout  ⬜️\n⬜️        1. OK         ⬜️\n⬜️        2. NO         ⬜️\n⬜️Another symbol == QUIT⬜️\n";
        cout << "⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️\n\n";
        cout << "⬜️⬜️ Your choise: ";
        cin >> choise;
        }
        if (choise == 1) {
            cout << "⬜️⬜️ Create your own username: ";
            cin >> username;
            cout << "⬜️⬜️ Confirm your new username: ";
            cin >> username_confirmation;
            while (strcmp(username_confirmation.c_str(), username.c_str()) != 0) {
                error();
                cout << "⬜️⬜️ Create your own username: ";
                cin >> username;
                cout << "⬜️⬜️ Confirm your new username: ";
                cin >> username_confirmation;
            }
            
            cout << "Rules:\n- min 16 symbols\n\n";
            cout << "⬜️⬜️ Create your own passwrod: ";
            cin >> password;
            cout << "⬜️⬜️ Confirm your new password: ";
            cin >> password_confirmation;

            while (strcmp(password_confirmation.c_str(), password.c_str()) != 0) {
                error();
                cout << "⬜️⬜️ Create your own passwrod: ";
                cin >> password;
                cout << "⬜️⬜️ Confirm your new password: ";
                cin >> password_confirmation;
            }
            if (password.length() != 16) {
                error();
                cout << "⬜️⬜️ Create your own passwrod: ";
                cin >> password;
                cout << "⬜️⬜️ Confirm your new password: ";
                cin >> password_confirmation;
            }
            else {
                cout << "\n\n✅✅✅ SUCCESS ✅✅✅\n\n\n";
                file << password << endl;
                file << username << endl;
            }
    
        cout << "🟪🟪 Please enter your username: ";
        cin >> username;
        cout << "🟪🟪 Please enter your password: ";
        cin >> password;
        
        while (strcmp(username.c_str(), username_confirmation.c_str()) != 0 || strcmp(password.c_str(), password_confirmation.c_str()) != 0) {
            error();
            cout << "🟪🟪 Please enter your username: ";
            cin >> username;
            cout << "🟪🟪 Please enter your password: ";
            cin >> password;
        }
    }
    else if (choise == 2) {
        cout << "\n🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥\n";
        cout << "🟥 Create your account now, because you won't have an access to wallet 🟥\n";
        cout << "🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥\n\n";

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
            cout << "🟪🟪 Username:\t";
            cin >> username;
            cout << "🟪🟪 Password:\t";
            cin >> password;
            if ((strcmp(vector[1].c_str(), username.c_str()) == 0) && (strcmp(vector[0].c_str(), password.c_str()) == 0)) {
                break;
            }
         }
    first_screen();
    return 0;
}

void error() {
    cout << "\n\n🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥\n";
    cout << "🟥  Error: resend request   🟥\n";
    cout << "🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥\n\n\n";
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
            cout << "🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪\n";
            cout << "🟪  \tWelcome to your wallet\t🟪\n";
            cout << "🟪  \t1. Check Wallet\t\t\t🟪\n";
            cout << "🟪  \t2. History\t\t\t\t🟪\n";
            cout << "🟪  \t3. About Us\t\t\t\t🟪\n";
            cout << "🟪  \t4. Quit\t\t\t\t\t🟪\n";
            cout << "🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪\n\n";
        }
        switcher = 0;
        cout << "🟪🟪 Your choise: ";
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
                cout << "\n\n🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍\n";
                cout << "🤍  Goodbye! See you later! 🤍\n";
                cout << "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍\n\n";
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
            cout << "\n🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦\n";
            cout << "🟦Hello, we are team “The Boys”. That project  🟦\n🟦is a work for the “IT STEP ACADEMY”. In which🟦\n🟦Mark, Svyatoslav and Veronica took part.";
            cout << "(1/3)🟦\n";
            cout << "🟦Enter random symbol to go back to main menu  🟦\n";
            cout << "🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦\n";

            cout << "\n🟦🟦 Enter number: ";
            cin >> switcher;
        }
        else if (switcher == 2) {
            cout << "\n🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦\n";
            cout << "🟦This project is about to create a financial  🟦\n🟦wallet on the MAC OS system. In which we used🟦\n🟦such technologies: pseudographics,vectors,   🟦\n🟦file system, pointers, preprocessors, strings🟦\n";
            cout << "🟦(2/3) \t\t\t\t\t\t\t\t\t   🟦\n";
            cout << "🟦Enter random symbol to go back to main menu  🟦\n";
            cout << "🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦\n";
            
            cout << "\n🟦🟦 Enter number: ";
            cin >> switcher;
        }
        else if (switcher == 3) {
            cout << "\n🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦\n";
            cout << "🟦Please enter all paths wich program ask you  🟦\n🟦correctly. If you want to support us '5168   🟦\n🟦7559 0605 5138' - PrivatBank UA. If you want 🟦\n🟦to advise something or contact  \t\t\t   🟦\n🟦us --> semenovmark07@gmail.com \t\t";
            cout << "(3/3)  🟦\n";
            cout << "🟦Enter random symbol to go back to main menu  🟦\n";
            cout << "🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦\n";
            
            cout << "\n🟦🟦 Enter number: ";
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

    cout << "\n🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪\n";
    cout << "🟪\t\tYour assets:\t\t🟪\n";
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
            cout << "🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪\n";
            cout << "🟪   \t1. Add asset\t\t🟪\n";
            cout << "🟪   \t2. Add transaction  🟪\n";
            cout << "🟪   \t3. History\t\t\t🟪\n";
            cout << "🟪   \t4. Back\t\t\t\t🟪\n";
            cout << "🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪\n\n";
        }
        switcher = 0;
        cout << "🟪🟪 Your choise: ";
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
