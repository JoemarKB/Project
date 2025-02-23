#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <cctype>
#include <set>
#include <cstdlib> 
#include <ctime> 

using namespace std;

struct Account {
    string username;
    string email;
    string password;
    string status;
};

struct Product {
    string name;
    string category;
    string animal;
    string description;
    double price;
    int stock;
    string status;
};

vector<Account> accounts;
vector<Product> products;

bool loginStatus = false;
string loginEmail = "";

//declaration of functions
void displayMenu();
void menuAdmin(string choose);
void login();
void registration();
void accountProfile();
void homeAdmin();
void searchAdmin();
void viewAccounts();
void editAccount(int accNumber);
void viewInventory();
void addItem();
void editItem(int p_num);
void viewCheckouts();
void menuCustomer(string choose);
void homeCustomer();
void searchCustomer();
void foods();
void equipments();
void medicine();
void viewItem(int p_num);
void cart();
void checkout();
bool checkAccount(string accountType);
string checkInput(string choose);
int getRandomNumber(const vector<Product>& vec);
void invalidInput();

int main() {

    // Add the admin account to the vector
    accounts.push_back({"admin", "admin", "admin", "Active"});
    accounts.push_back({"gab", "gabrielleramos@gmail.com", "gab", "Active"});

    // Add products for "cat" to the vector
    products.push_back({"Maxime (1 kilo)", "Food", "Cat", "5-6 weeks old higher", 90, 30, "Display"});
    products.push_back({"Whiskas (1 kilo)", "Food", "Cat", "5-6 weeks old higher", 155, 30, "Not Display"});
    products.push_back({"Cuties (1 kilo)", "Food", "Cat", "5-6 weeks old higher", 130, 30, "Display"});
    products.push_back({"Smartheart (1 kilo)", "Food", "Cat", "5-6 weeks old higher", 165, 30, "Display"});
    products.push_back({"Kitcat (1 kilo)", "Food", "Cat", "5-6 weeks old higher", 52, 30, "Display"});
    products.push_back({"Whiskas (400 g)", "Food", "Cat", "1 Years above", 99, 30, "Display"});
    products.push_back({"Goodest (85 g)", "Food", "Cat", "6 Months above", 28, 30, "Display"});
    products.push_back({"Aozi (430 g)", "Food", "Cat", "7 Months above", 82, 30, "Display"});
    products.push_back({"Lc Vit Plus (120ml)", "Medicine", "Cat", "12 weeks higher", 150, 30, "Display"});
    products.push_back({"Pneumex (60ml)", "Medicine", "Cat", "3 months", 167, 30, "Display"});
    products.push_back({"Advocate (4 kg)", "Medicine", "Cat", "9 weeks higher", 499, 30, "Display"});
    products.push_back({"Wormeze (8 oz)", "Medicine", "Cat", "6 months higher", 719, 30, "Display"});
    products.push_back({"Drontal (18.2 mg)", "Medicine", "Cat", "1 month higher", 313, 30, "Display"});
    products.push_back({"Capstar (57 mg)", "Medicine", "Cat", "4 weeks higher", 475, 30, "Display"});
    products.push_back({"Capaction (11.4 mg)", "Medicine", "Cat", "4 weeks higher", 137, 30, "Display"});
    products.push_back({"Flea Guard (2.5 ml)", "Medicine", "Cat", "8 weeks higher", 125, 30, "Display"});
    products.push_back({"Litter Box", "Equipment", "Cat", "Splash proof cat litter box", 260, 30, "Display"});
    products.push_back({"Bed", "Equipment", "Cat", "Cat Bed House", 120, 30, "Display"});
    products.push_back({"Scratching Posts", "Equipment", "Cat", "Cat Scratch Post ", 66, 30, "Display"});
    products.push_back({"Toy Bell", "Equipment", "Cat", "Wiggly Ball Cat Bells", 57, 30, "Display"});
    products.push_back({"Food/Water Bowl", "Equipment", "Cat", "2 in 1 Cat Bowl", 119, 30, "Display"});
    products.push_back({"Collar ", "Equipment", "Cat", "Adjustable w/ bell", 48, 30, "Display"});
    products.push_back({"Cage", "Equipment", "Cat", "Collapsible cage", 399, 30, "Display"});
    products.push_back({"Litter Sand (10 L)", "Equipment", "Cat", "Lavender scent", 250, 30, "Display"});

    // Add products for "dog" to the vector
    products.push_back({"Nutrichunks (500 g)", "Food", "Dog", "", 250, 30, "Display"});
    products.push_back({"Vitalamb (1kg)", "Food", "Dog", "", 102, 30, "Display"});
    products.push_back({"Pedigree (1kg)", "Food", "Dog", "", 146, 30, "Display"});
    products.push_back({"Top Breed (1kg)", "Food", "Dog", "", 99, 30, "Display"});
    products.push_back({"Royal Canin (500g)", "Food", "Dog", "", 179, 30, "Display"});
    products.push_back({"Pedigree Pouch (30g)", "Food", "Dog", "", 32, 30, "Display"});
    products.push_back({"Jerhigh Pouch (120g)", "Food", "Dog", "", 50, 30, "Display"});
    products.push_back({"SmartHeart Pouch (80g)", "Food", "Dog", "", 39, 30, "Display"});
    products.push_back({"Himalayan (100ml)", "Medicine", "Dog", "", 265, 30, "Display"});
    products.push_back({"Multivitamins (120 ml)", "Medicine", "Dog", "", 118, 30, "Display"});
    products.push_back({"Nematocide (15ml)", "Medicine", "Dog", "", 115, 30, "Display"});
    products.push_back({"Papi Doxy (60 ml)", "Medicine", "Dog", "", 107, 30, "Display"});
    products.push_back({"Nexgard (260 g)", "Medicine", "Dog", "", 419, 30, "Display"});
    products.push_back({"Wormgard (150 mg)", "Medicine", "Dog", "", 165, 30, "Display"});
    products.push_back({"Simparica trio (120 mg)", "Medicine", "Dog", "", 495, 30, "Display"});
    products.push_back({"Bravecto (98 mg)", "Medicine", "Dog", "", 394, 30, "Display"});
    products.push_back({"Dog bowl", "Equipment", "Dog", "", 75, 30, "Display"});
    products.push_back({"Dog bed", "Equipment", "Dog", "", 181, 30, "Display"});
    products.push_back({"Dog backpack ", "Equipment", "Dog", "", 189, 30, "Display"});
    products.push_back({"Dog collar", "Equipment", "Dog", "", 98, 30, "Display"});
    products.push_back({"Clothes", "Equipment", "Dog", "", 125, 30, "Display"});
    products.push_back({"Diaper", "Equipment", "Dog", "", 65, 30, "Display"});
    products.push_back({"Muzzles", "Equipment", "Dog", "", 89, 30, "Display"});
    products.push_back({"Dog crate", "Equipment", "Dog", "", 120, 30, "Display"});

    // Add products for "fish" to the vector
    products.push_back({"Fish flakes (20 g)", "Food", "Fish", "", 160, 30, "Display"});
    products.push_back({"Fish pellets (50 g)", "Food", "Fish", "", 67, 30, "Display"});
    products.push_back({"Pimafix (16 oz)", "Medicine", "Fish", "", 370, 30, "Display"});
    products.push_back({"Aqua Guard (1L)", "Medicine", "Fish", "", 93, 30, "Display"});
    products.push_back({"API Melafix (16 oz)", "Medicine", "Fish", "", 350, 30, "Display"});
    products.push_back({"Paracidol-Fw (100ml)", "Medicine", "Fish", "", 124, 30, "Display"});
    products.push_back({"Air pump", "Equipment", "Fish", "", 135, 30, "Display"});
    products.push_back({"Aquarium (5 gal)", "Equipment", "Fish", "", 290, 30, "Display"});
    products.push_back({"Aquarium heater (50w)", "Equipment", "Fish", "", 199, 30, "Display"});

    // Add products for "bird" to the vector
    products.push_back({"Bird seed mix (1k)", "Food", "Bird", "", 30, 30, "Display"});
    products.push_back({"African mix (1k)", "Food", "Bird", "", 75, 30, "Display"});
    products.push_back({"Parakeet (500 g)", "Food", "Bird", "", 245, 30, "Display"});
    products.push_back({"Premium mix (1k)", "Food", "Bird", "", 68, 30, "Display"});
    products.push_back({"Mynah bird food (1kg)", "Food", "Bird", "", 195, 30, "Display"});
    products.push_back({"Baytril (12,5 ml)", "Medicine", "Bird", "", 240, 30, "Display"});
    products.push_back({"Amtyl (500 g)", "Medicine", "Bird", "", 150, 30, "Display"});
    products.push_back({"Enrofloxacin (20 ml)", "Medicine", "Bird", "", 279, 30, "Display"});
    products.push_back({"Pikoy BACTI Bird (10 ml)", "Medicine", "Bird", "", 148, 30, "Display"});
    products.push_back({"Aviator Harness & Leash", "Equipment", "Bird", "", 143, 30, "Display"});
    products.push_back({"Bird cage", "Equipment", "Bird", "", 500, 30, "Display"});
    products.push_back({"Bird feeder", "Equipment", "Bird", "", 113, 30, "Display"});


    homeCustomer();
}

void displayMenu() {
    system("cls");
    SetConsoleOutputCP(CP_UTF8);

    if (loginEmail == "admin") {//menu of admin-----+---------------+
        cout << "+-----------------------------------------------------------------------------------------------+" << endl;
        cout << "|\t\t\t [S] Search\t\t|\t\t[A] Account\t\t\t|" << endl;
        cout << "+-----------------------------------------------------------------------------------------------+" << endl;
        cout << "|\t\t[C] Accounts \t|\t   [I] Products    \t|\t[O] Checkouts\t\t|" << endl;
        cout << "+-----------------------------------------------------------------------------------------------+" << endl;
        
    } else {//menu of  customer
        cout << "+-----------------------------------------------------------------------------------------------+" << endl;
        cout << "|\t[H] Home   \t|\t[S] Search\t|\t[A] Account\t|\t[C] Cart   \t|" << endl;
        cout << "+-----------------------------------------------------------------------------------------------+" << endl;
        cout << "|\t\t[F] Foods    \t|\t    [Q] Equipment    \t|\t[M] Medicine \t\t|" << endl;
        cout << "+-----------------------------------------------------------------------------------------------+" << endl;
    }
}

void login() {
    string email, password;
    int choose;

    displayMenu();
    
    cout << "|\t\t\t\t    [R] No Account? Register Now!    \t\t\t\t|" << endl;
    cout << "|\t\t\t\t\t\tLOGIN\t\t\t\t\t\t|" << endl;
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;

    cout << "\t\t\t\t(action) Email: ";
    cin >> email;

    if (email == "R" || email == "r") {
        registration();

    } else if (email.length() == 1) {
        menuCustomer(email);
        login();

    } else {
        cout << "\t\t\t\t      Password: ";
        cin >> password;
        cout << "+-----------------------------------------------------------------------------------------------+" << endl;
        cout << "|\t\t\t[1] Login\t\t|\t\t[0] Clear\t\t\t|" << endl;
        cout << "+-----------------------------------------------------------------------------------------------+" << endl;

        cout << "\t\t\t\t  Input action: ";
        cin >> choose;

        //check if string is inputted in an int variable
        if (cin.fail()) {
            invalidInput();

            cout << "Clearing fields...";
            Sleep(2000);

            cin.clear();//clear input
            cin.ignore(LONG_MAX, '\n');//ignore any error

            login();

        } else {
            switch(choose) {
                case 0:
                    cout << "+-----------------------------------------------------------------------------------------------+" << endl;
                    cout << "Clearing fields...";
                    Sleep(3000);

                    login();
                    break;
                    
                case 1:
                    {
                        cout << "+-----------------------------------------------------------------------------------------------+" << endl;
                        cout << "Logging In..." << endl;
                        Sleep(3000);

                        // Iterate over registered users to find a match
                        bool found = false;
                        string status;
                        for (const auto& account : accounts) {
                            if (email == account.email && password == account.password) {
                                found = true;
                                status = account.status;//check account's status
                                break;
                            }
                        }

                        if (!found) {
                            // User's credentials did not match any registered users
                            cout << "Invalid email address or password." << endl;
                            Sleep(2000);

                            login();

                        } else if (status == "Banned") {
                            // User's account is banned
                            cout << "Cannot login, your account is banned." << endl;
                            Sleep(2000);

                            login();
                            
                        } else {
                            loginStatus = true;
                            loginEmail = email;

                            cout << "Login successful!";
                            Sleep(2000);

                            if (loginEmail == "admin") homeAdmin();
                            else homeCustomer();
                        }
                    }
                    break;
                    
                default:
                    invalidInput();

                    cout << "Clearing fields...";
                    Sleep(2000);

                    login();
                    break;
            }
        }
    }
}

void registration() {
    string email, username, password;
    int choose;

    cout << username;

    displayMenu();

    cout << "|\t\t\t\t\t    REGISTRATION    \t\t\t\t\t|" << endl;
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;

    cout << "\t\t\t(action) Username: ";
    cin >> username;

    if (username.length() == 1) {
        menuCustomer(username);
        registration();

    } else {
        cout << "\t\t\t\t    Email: ";
        cin >> email;

        cout << "\t\t\t\t Password: ";
        cin >> password;
        
        cout << "+-----------------------------------------------------------------------------------------------+" << endl;
        cout << "|\t\t\t[1] Register\t\t|\t\t[0] Clear\t\t\t|" << endl;
        cout << "+-----------------------------------------------------------------------------------------------+" << endl;

        cout << "\t\t\t     Input action: ";
        cin >> choose;

        cout << "+-----------------------------------------------------------------------------------------------+" << endl;

        //check if string is inputted in an int variable
        if (cin.fail()) {
            invalidInput();
            
            cout << "Clearing fields...";
            Sleep(2000);

            cin.clear();//clear input
            cin.ignore(LONG_MAX, '\n');//ignore any error

            registration();

        } else {
            switch(choose) {
                case 0:
                    cout << "Clearing fields...";
                    Sleep(3000);

                    registration();
                    break;
                
                case 1:
                    {
                        cout << "Registering..." << endl;
                        Sleep(3000);

                        // Check if the email address is already registered
                        bool found = false;
                        for (const auto& account : accounts) {
                            if (email == account.email) {
                                // Email address is already registered
                                cout << "That email address is already registered. Please try again." << endl;
                                found = true;
                                break;
                            }
                        }

                        if (!found) {
                            // Add the user's information to the vector
                            accounts.push_back({username, email, password, "Active"});

                            cout << "Registration successful!";
                            Sleep(2000);

                            login();

                        } else {
                            Sleep(2000);
                            registration();
                        }
                    }
                    break;
                
                default:
                    invalidInput();

                    cout << "Clearing fields...";
                    Sleep(2000);

                    registration();
                    break;
            }
        }
    }
}

void accountProfile() {
    string choose, temp;
    int accNumber, choose1;

    displayMenu();

    cout << "|\t\t\t\t\t\tPROFILE\t\t\t\t\t\t|" << endl;
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;

    for (int i = 0; i < accounts.size(); i++) {
        if (loginEmail == accounts[i].email) {

            cout << "\t\t\t\t         Email: " << accounts[i].email << endl;
            cout << "\t\t\t\t  [0] Username: " << accounts[i].username << endl;
            cout << "\t\t\t\t  [1] Password: " << accounts[i].password << endl;

            accNumber = i;
            break;
        }
    }
    
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;

    if (loginEmail == "admin") cout << "|\t\t\t\t\t    [L] Logout    \t\t\t\t\t|" << endl;
    else cout << "|\t\t  [+] Add In-Store Money  \t\t|\t\t  [L] Logout  \t\t|" << endl;

    cout << "+-----------------------------------------------------------------------------------------------+" << endl;

    cout << "\t\t\t\t Input action: ";
    cin >> choose;

    if (loginEmail != "admin" || choose == "+") {
        //add in-store money
        
    } else if (checkInput(choose) == "alpha" && choose.length() == 1) {
        if (choose == "L" || choose == "l") {//logout
            cout << "Logging out...";
            Sleep(3000);

            loginStatus = false;
            loginEmail = "";

            homeCustomer();

        } else {
            if (loginEmail == "admin") menuAdmin(choose);
            else menuCustomer(choose);

            accountProfile();
        }

    } else if (checkInput(choose) == "number" && stoi(choose) <= 1 && stoi(choose) >= 0) {
        cout << "+-----------------------------------------------------------------------------------------------+" << endl;

        switch(stoi(choose)) {
            case 0:
                cout << "\t\t\t Edit Username" << endl;
                cout << "Old username:" << accounts[accNumber].username << endl;
                cout << "Enter new username: ";
                break;

            case 1:
                cout << "\t\t\t Edit Password" << endl;
                cout << "Old password:" << accounts[accNumber].password << endl;
                cout << "Enter new password: ";
                break;
        }

        cin >> temp;

        cout << "+-----------------------------------------------------------------------------------------------+" << endl;
        cout << "\t\t [1] Save \t [0] Cancel" << endl;

        cout << "\t\t\t\t Input action: ";
        cin >> choose1;

        cout << "+-----------------------------------------------------------------------------------------------+" << endl;

        //check if string is inputted in an int variable
        if (cin.fail()) {
            invalidInput();
            
            cout << "Canceling process...";
            Sleep(2000);

            cin.clear();//clear input
            cin.ignore(LONG_MAX, '\n');//ignore any error

            accountProfile();

        } else {
            switch(choose1) {
                case 0:
                    cout << "Canceling process...";
                    Sleep(3000);

                    accountProfile();
                    break;
                
                case 1:
                    if (stoi(choose) == 0) {
                        //change username
                        accounts[accNumber].username = temp;

                    } else if (stoi(choose) == 1) {
                        //change password
                        accounts[accNumber].password = temp;
                    }

                    cout << "Applying changes...";
                    Sleep(3000);

                    accountProfile();
                    break;
                
                default:
                    invalidInput();

                    cout << "Canceling process...";
                    Sleep(2000);

                    accountProfile();
                    break;
            }
        }

    } else {
        invalidInput();

        accountProfile();
    }
}

void menuAdmin(string choose) {

    if (choose == "S" || choose == "s") {
        searchAdmin();

    } else if (choose == "A" || choose == "a") {
        accountProfile();

    } else if (choose == "C" || choose == "c") {
        viewAccounts();

    } else if (choose == "I" || choose == "i") {
        viewInventory();

    } else if (choose == "O" || choose == "o") {
        viewCheckouts();

    } else {
        invalidInput();
    }
}

void homeAdmin() {
    viewAccounts();
}

void searchAdmin() {
    displayMenu();

    cout << "search"; 

}

void viewAccounts() {
    string choose;

    displayMenu();

    cout << "|\t\t\t\t\tLIST OF ACCOUNTS\t\t\t\t\t|" << endl;
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;
    cout << "|\t\t\tEmail\t\t\t|\t\t\tStatus\t\t\t|" << endl;
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;

    if (accounts.size() > 1) {
        for (int i = 1; i < accounts.size(); i++) {
            cout << "|\t[" << i << "] " << accounts[i].email << "\t\t|\t\t\t" << accounts[i].status << "\t\t\t|" << endl;
        }

    } else {
        cout << "No account is registered yet!" << endl;
    }

    cout << "+-----------------------------------------------------------------------------------------------+" << endl;

    cout << "\t\t\t\t*To edit account, choose a number.\t\t\t\t" << endl;
    cout << "\t\t\t\t Input action: ";
    cin >> choose;

    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        menuAdmin(choose);
        viewAccounts();

    } else if (checkInput(choose) == "number" && stoi(choose) < accounts.size() && stoi(choose) > 0) {

        editAccount(stoi(choose));

    } else {
        invalidInput();
        
        viewAccounts();
    }
}

void editAccount(int accNumber) {
    string choose, temp;
    int choose1;

    displayMenu();

    cout << "\t\tEditing account with an email: " << accounts[accNumber].email << endl << endl;
    cout << "\t\t\t\t[0] Username: " << accounts[accNumber].username << endl;
    cout << "\t\t\t\t[1] Password: " << accounts[accNumber].password << endl;
    cout << "\t\t\t\t[2]   Status: " << accounts[accNumber].status << endl;
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;

    cout << "\t\t\t\tInput action: ";
    cin >> choose;

    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        menuAdmin(choose);
        editAccount(accNumber);

    } else if (checkInput(choose) == "number" && stoi(choose) <= 2 && stoi(choose) >= 0) {
        
        cout << "+-----------------------------------------------------------------------------------------------+" << endl;

        switch(stoi(choose)) {
            case 0:
                cout << "|\t\t\t\t\t    Edit Username    \t\t\t\t\t|" << endl;
                cout << "+-----------------------------------------------------------------------------------------------+" << endl;

                cout << "\t\t\t\tOld username: " << accounts[accNumber].username << endl;
                cout << "\t\t\t  Enter new username: ";

                cin >> temp;
                break;

            case 1:
                cout << "|\t\t\t\t\t    Edit Password    \t\t\t\t\t|" << endl;
                cout << "+-----------------------------------------------------------------------------------------------+" << endl;

                cout << "\t\t\t\tOld password: " << accounts[accNumber].password << endl;
                cout << "\t\t\t  Enter new password: ";

                cin >> temp;
                break;

            case 2:
                cout << "|\t\t\t\t\t    Edit Status    \t\t\t\t\t|" << endl;
                cout << "+-----------------------------------------------------------------------------------------------+" << endl;
                cout << "|\t\t\t\t      Status: " << accounts[accNumber].status;
                
                if (accounts[accNumber].status == "Active") temp = "Banned";
                else temp = "Active";

                cout << " -> " << temp << "  \t\t\t\t|" << endl;

                break;

            default:
                invalidInput();
                
                cout << "Canceling process...";
                Sleep(2000);

                editAccount(accNumber);
                break;
        }

        cout << "+-----------------------------------------------------------------------------------------------+" << endl;
        cout << "|\t\t\t[1] Save\t\t|\t\t[0] Cancel\t\t\t|" << endl;
        cout << "+-----------------------------------------------------------------------------------------------+" << endl;

        cout << "\t\t\t\tInput action: ";
        cin >> choose1;

        //check if string is inputted in an int variable
        if (cin.fail()) {
            invalidInput();
            
            cout << "Canceling process...";
            Sleep(2000);

            cin.clear();//clear input
            cin.ignore(LONG_MAX, '\n');//ignore any error

            viewAccounts();

        } else {
            switch(choose1) {
                case 0:
                    cout << "+-----------------------------------------------------------------------------------------------+" << endl;
                    cout << "Canceling process...";
                    Sleep(3000);

                    viewAccounts();
                    break;
                
                case 1:
                    if (stoi(choose) == 0) {
                        //change username
                        accounts[accNumber].username = temp;

                    } else if (stoi(choose) == 1) {
                        //change password
                        accounts[accNumber].password = temp;

                    } else if (stoi(choose) == 2) {
                        //change status
                        accounts[accNumber].status = temp;
                    }

                    cout << "Applying changes...";
                    Sleep(3000);

                    viewAccounts();
                    break;
                
                default:
                    invalidInput();

                    cout << "Canceling process...";
                    Sleep(2000);

                    viewAccounts();
                    break;
            }
        }

    } else {
        invalidInput();

        editAccount(accNumber);
    }


}

void viewInventory() {
    string choose;

    displayMenu();

    cout << "|\t\t\t\t\tLIST OF PRODUCTS\t\t\t\t\t|" << endl;
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;
    cout << "|\t\tProduct Name\t\t\t|\tAnimal\t\t|\tPrice\t\t|" << endl;
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;

    if (products.size() > 0) {
        for (int i = 0; i < products.size(); i++) {
            cout << "|\t[" << i << "] " << products[i].name << "\t\t";

            if (products[i].name.length() <= 10) {
                cout << "\t\t";

            } else if (products[i].name.length() <= 19 && i < 10) {
                cout << "\t";
                
            } else if (products[i].name.length() <= 18 && i >= 10) {
                cout << "\t";
            }

            cout << "|\t" << products[i].animal << "\t\t|\t" << products[i].price << " php\t\t|" << endl;
        }

    } else {
        cout << "No product is added yet!" << endl;
    }

    cout << "+-----------------------------------------------------------------------------------------------+" << endl;
    cout << "|\t\t\t\t\t    [+] Add Product    \t\t\t\t\t|" << endl;
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;

    cout << "\t\t\t\t*To edit account, choose a number.\t\t\t\t" << endl;
    cout << "\t\t\t\t Input action: ";
    cin >> choose;

    if (choose == "+") {
        addItem();

    } else if (checkInput(choose) == "alpha" && choose.length() == 1) {
        menuAdmin(choose);

    } else if (checkInput(choose) == "number" && stoi(choose) < products.size() && stoi(choose) <= 0) {
        editItem(stoi(choose));

    } else {
        cout << "+-----------------------------------------------------------------------------------------------+" << endl;
        invalidInput();

        viewInventory();
    }
}

void addItem() {

}

void editItem(int p_num) {
    string choose;

    displayMenu();

    cout << products[p_num].name << endl;

    cout << "\t\t\t\t Input action: ";
    cin >> choose; 

    menuAdmin(choose);
}

void viewCheckouts() {
    string choose;

    displayMenu();

    cout << "|\t\t\t\t\tLIST OF CHECKOUTS\t\t\t\t\t|" << endl;
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;

    // if (products.size() > 0) {
    //     for (int i = 0; i < products.size(); i++) {
    //         cout << "[" << i << "] " << products[i].name << endl;
    //     }

    // } else {
    //     cout << "No checkouts yet!" << endl;
    // }

    cout << "+-----------------------------------------------------------------------------------------------+" << endl;

    cout << "\t\t\t\t Input action: ";
    cin >> choose;
    
    menuAdmin(choose);
}

void menuCustomer(string choose) {

    if (choose == "H" || choose == "h") {
        homeCustomer();

    } else if (choose == "S" || choose == "s") {
        searchCustomer();

    } else if (choose == "A" || choose == "a") {
        if (!loginStatus) login();
        else accountProfile();

    } else if (choose == "C" || choose == "c") {
        if (!loginStatus) login();
        else cart();

    } else if (choose == "F" || choose == "f") {
        foods();

    } else if (choose == "Q" || choose == "q") {
        equipments();

    } else if (choose == "M" || choose == "m") {
        medicine();

    } else {
        invalidInput();

        // homeCustomer();
    }
}

void searchCustomer() {
    displayMenu();

    cout << "search"; 

}

void homeCustomer() {
    string choose;

    displayMenu();

    srand(time(nullptr));
    set<int> selected;

    cout << "|\t\t\t\t\t\tHOME\t\t\t\t\t\t|" << endl;
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;
    cout << "|\t\tProduct Name\t\t\t|\tAnimal\t\t|\tPrice\t\t|" << endl;
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;

    for (int i = 0; i < 10; ++i) {
        int index = getRandomNumber(products);
        
        while (selected.count(index) > 0) {
            index = getRandomNumber(products);
        }

        selected.insert(index);

        if (products[index].status == "Display") {
            cout << "|\t[" << index << "] " << products[index].name << "\t\t";

            if (products[index].name.length() <= 10) {
                cout << "\t\t";

            } else if (products[index].name.length() <= 19 && index < 10) {
                cout << "\t";
                
            } else if (products[index].name.length() <= 18 && index >= 10) {
                cout << "\t";
            }

            cout << "|\t" << products[index].animal << "\t\t|\t₱ " << products[index].price << "\t\t|" << endl;
        }
    }

    cout << "+-----------------------------------------------------------------------------------------------+" << endl;

    cout << "\t\t\t\t Input action: ";
    cin >> choose;

    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        if (loginEmail == "admin") menuAdmin(choose);
        else menuCustomer(choose);

        homeCustomer();

    } else if (checkInput(choose) == "number" && products.size() > stoi(choose)) {

        viewItem(stoi(choose));

    } else {
        invalidInput();

        homeCustomer();
    }
}

void foods() {
    string choose;

    displayMenu();
    cout << "|\t\t\t\t\t\tFOODS\t\t\t\t\t\t|" << endl;
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;
    cout << "|\t\tProduct Name\t\t\t|\tAnimal\t\t|\tPrice\t\t|" << endl;
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;

    for (int i = 0; i < products.size(); i++) {
        if (products[i].category == "Food" && products[i].status == "Display") {
            cout << "|\t[" << i << "] " << products[i].name << "\t\t";

            if (products[i].name.length() <= 10) {
                cout << "\t\t";

            } else if (products[i].name.length() <= 19 && i < 10) {
                cout << "\t";
                
            } else if (products[i].name.length() <= 18 && i >= 10) {
                cout << "\t";
            }

            cout << "|\t" << products[i].animal << "\t\t|\t₱ " << products[i].price << "\t\t|" << endl;
        }
    }

    cout << "+-----------------------------------------------------------------------------------------------+" << endl;

    cout << "\t\t\t\t Input action: ";
    cin >> choose; 

    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        if (loginEmail == "admin") menuAdmin(choose);
        else menuCustomer(choose);

        foods();

    } else if (checkInput(choose) == "number" && products.size() > stoi(choose) && products[stoi(choose)].category == "Food") {

        viewItem(stoi(choose));

    } else {
        invalidInput();

        homeCustomer();
    }
}

void equipments() {
    string choose;

    displayMenu();
    
    cout << "|\t\t\t\t\t    EQUIPMENTS    \t\t\t\t\t|" << endl;
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;
    cout << "|\t\tProduct Name\t\t\t|\tAnimal\t\t|\tPrice\t\t|" << endl;
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;

    for (int i = 0; i < products.size(); i++) {
        if (products[i].category == "Equipment" && products[i].status == "Display") {
            cout << "|\t[" << i << "] " << products[i].name << "\t\t";

            if (products[i].name.length() <= 10) {
                cout << "\t\t";

            } else if (products[i].name.length() <= 19 && i < 10) {
                cout << "\t";
                
            } else if (products[i].name.length() <= 18 && i >= 10) {
                cout << "\t";
            }

            cout << "|\t" << products[i].animal << "\t\t|\t₱ " << products[i].price << "\t\t|" << endl;
        }
    }

    cout << "+-----------------------------------------------------------------------------------------------+" << endl;

    cout << "\t\t\t\t Input action: ";
    cin >> choose; 

    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        if (loginEmail == "admin") menuAdmin(choose);
        else menuCustomer(choose);
        
        equipments();

    } else if (checkInput(choose) == "number" && products.size() > stoi(choose) && products[stoi(choose)].category == "Food") {
        viewItem(stoi(choose));

    } else {
        invalidInput();

        homeCustomer();
    }
}

void medicine() {
    string choose;

    displayMenu();

    cout << "|\t\t\t\t\t    MEDICINE    \t\t\t\t\t|" << endl;
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;
    cout << "|\t\tProduct Name\t\t\t|\tAnimal\t\t|\tPrice\t\t|" << endl;
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;

    for (int i = 0; i < products.size(); i++) {
        if (products[i].category == "Medicine" && products[i].status == "Display") {
            cout << "|\t[" << i << "] " << products[i].name << "\t\t";

            if (products[i].name.length() <= 10) {
                cout << "\t\t";

            } else if (products[i].name.length() <= 19 && i < 10) {
                cout << "\t";
                
            } else if (products[i].name.length() <= 18 && i >= 10) {
                cout << "\t";
            }

            cout << "|\t" << products[i].animal << "\t\t|\t₱ " << products[i].price << "\t\t|" << endl;
        }
    }

    cout << "+-----------------------------------------------------------------------------------------------+" << endl;

    cout << "\t\t\t\t Input action: ";
    cin >> choose; 

    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        if (loginEmail == "admin") menuAdmin(choose);
        else menuCustomer(choose);

        medicine();

    } else if (checkInput(choose) == "number" && products.size() > stoi(choose) && products[stoi(choose)].category == "Food") {
        viewItem(stoi(choose));

    } else {
        invalidInput();

        homeCustomer();
    }
}

void viewItem(int p_num) {
    string choose;

    displayMenu();

    cout << products[p_num].name << endl;

    cout << "\t\t\t\t Input action: ";
    cin >> choose; 

    menuCustomer(choose);
}

void cart() {
    displayMenu();

    cout << "cart"; 

}

void checkout() {
    displayMenu();

    cout << "checkout"; 

}

string checkInput(string choose) {
    bool only_alpha = false, only_digit = false;

    for (char c : choose) {
        if (isalpha(c)) only_alpha = true;  // The character is not alphabetical
        else if (isdigit(c)) only_digit = true;  // The character is not a digit
    }

    if (only_alpha) return "alpha";
    else if (only_digit) return "number";

    return "invalid";
}

int getRandomNumber(const vector<Product>& vec) {
    return rand() % vec.size();
}

void invalidInput() {

    cout << "+-----------------------------------------------------------------------------------------------+" << endl;
    cout << "Invalid input, please try again" << endl;
    Sleep(3000);
}