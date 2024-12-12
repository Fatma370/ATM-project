// ATMproject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


string const FileName = "clientsData.txt";


struct stClientInfo {
    string AccountNo;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};
enum enMainMenueOPtions {
    QuickWithdrawOP=1,
    NormalWithdrawOP=2,
    DepositOP=3,
    CheckBalanceOP=4,
    LogoutOP=5
};

stClientInfo Gclient;

//declerations 
void PerformQuickWithdraw();
void NormalWithdraw();
void PerFormMainMenueOption();
vector<stClientInfo> LoadDataFromFile();
void Login();
void DepositAmountInClientAcc(string AccountNo, double DepoistAmmount);


//output functions
void ShowLoginScreen() {
    system("cls");
    cout << "__________________________________\n";
    cout << "\t Login Screen\n";
    cout << "__________________________________\n\n";
}
void ShowQuickWithdrawMenue() {
    cout << "========================================\n";
    cout << "\t\t Quick Withdraw\n";
    cout << "========================================\n";
    cout << "\t [1] 20 \t [2] 50\n";
    cout << "\t [3] 100 \t [4] 200\n";
    cout << "\t [5] 400 \t [6] 600\n";
    cout << "\t [7] 800 \t [8] 1000\n";
    cout << "\t [9] Exist\n";
    cout << "========================================\n";
    PerformQuickWithdraw();
}
void ShowNormalWithdrawScreen() {
    system("cls");
    cout << "========================================\n";
    cout << "\t\t Normal Withdraw screen \n";
    cout << "========================================\n";
    NormalWithdraw();
}
void showDepositScreen() {
    system("cls");
    cout << "========================================\n";
    cout << "\t\t Deposit Screen \n";
    cout << "========================================\n";
}
void ShowCheckBalanceScreen()
{
    system("cls");
    cout << "=======================================\n";
    cout << "\t Check Balance Screen \n";
    cout << "=======================================\n";


}
void ShowMainMenueScreen() {
    system("cls");
    cout << "=======================================\n";
    cout << "\t\t ATM Main Menue Screen \n";
    cout << "=======================================\n";
    cout << "\t [1] Quick Withdraw\n";
    cout << "\t [2] Normal withdraw\n";
    cout << "\t [3] Depoist\n";
    cout << "\t [4] Check Balance\n";
    cout << "\t [4] Logout\n";
    cout << "=======================================\n";
    PerFormMainMenueOption();

}

//Read input funstions
double ReadDepositAmount() {

    double amount;
    cout << "Enter a positive deposit Amount ?";
    cin >> amount;
    return amount;
    
}
int ReadAmount() {
    int amount;
    do {
        cout << "Enter an amount multiple of 5's? ";
        cin >> amount;
        

    } while (amount % 5 != 0);
    return amount;
}
string ReadAccountNumber() {
    string AccountNumber;
    cout << "Please enter an account number? ";
    getline(cin >> ws, AccountNumber);
    return AccountNumber;
}
int ReadQuickWithdrawOP() {
    int OP;
    cout << "Choose what to withdraw from [1] to [8]? ";
    cin >> OP;
    return OP;
}
string ReadPinCode() {
    string PinCode;
    cout << "Please enter Pin Code?";
    getline(cin >> ws, PinCode);
    return PinCode;


}
enMainMenueOPtions ReadUserOption() {
    int c;
    do {
        cout << "\nChoose what do you wnat to do ? [1 to 5]? ";
        cin >> c;
        if (c < 1 || c>5)
        {
            cout << "invalid number, Out Of Range.\n";
        }
    } while (c < 1 || c>5);
    return (enMainMenueOPtions)c;

}
//
void BackToMenue() {

    cout << "Press any key to go back to Menue....";
    system("pause>0");
    ShowMainMenueScreen();
}
    
void CheckBalance() {
    cout << "Your Balance is " << Gclient.AccountBalance << endl;
    
}
bool confirmTransaction() {
    char agree;
    cout << "Are you sure you want to perform this transaction? y/n? ";
    cin >> agree;
    if (tolower(agree) == 'y')
    {
        return 1;

    }
    else
        return 0; 
}
void NormalWithdraw() {

    int withdrawAmount = ReadAmount();
    if (withdrawAmount > Gclient.AccountBalance)
    {
        cout << "\nThe amount exceedds your balance . make another choice\n";
        NormalWithdraw();

    }
    else {
        vector<stClientInfo> vClients = LoadDataFromFile();
        DepositAmountInClientAcc(Gclient.AccountNo, withdrawAmount * -1);
        Gclient.AccountBalance -= withdrawAmount;
    }


}
void Deposit() {
    double Depositamount = ReadDepositAmount();
   
    if (confirmTransaction())
    {
        vector<stClientInfo>vClients = LoadDataFromFile();
        DepositAmountInClientAcc(Gclient.AccountNo, Depositamount);
        Gclient.AccountBalance += Depositamount;
        cout << "\n Done Sucessfully , New balance is: " << Gclient.AccountBalance << endl;

    }
}

string GetDataLine(stClientInfo client, string Delim="#//#")
{
    string DataLine;
    DataLine = client.AccountNo + Delim + client.PinCode + Delim + client.Name + Delim + client.Phone + Delim + to_string(client.AccountBalance);
    return DataLine;

}
void LoadDataFromVectorToFile(vector<stClientInfo>vClientsData)
{
    fstream file;
    file.open(FileName, ios::out);
    if (file.is_open())
    {
        for (stClientInfo& client : vClientsData)
        {
            if (client.MarkForDelete == false) {
                file << GetDataLine(client) << endl;
            }

        }
        file.close();
    }

}
void DepositAmountInClientAcc(string AccountNo, double DepoistAmmount)
{
    vector<stClientInfo>vClientsData = LoadDataFromFile();
    for (stClientInfo& client : vClientsData)
    {
        if (client.AccountNo == AccountNo)
        {
            char agree = 'n';
            cout << "Are You sure you want to perform this transaction? y/n?";
            cin >> agree;
            if (toupper(agree) == 'Y')
            {
                client.AccountBalance += DepoistAmmount;
                cout << "Done Successfully , new balance is :" << client.AccountBalance << endl;
                LoadDataFromVectorToFile(vClientsData);
                return;
            }
            else {
                cout << "transaction Process is cancelled!!";
            }

        }
    }
}
int getWithdrawAmount() {
    int OP = ReadQuickWithdrawOP();
    switch (OP)
    {
    case 1:
        return 20;
    case 2:
        return 50;
    case 3:
        return 100;
    case 4:
        return 200;
    case 5:
        return 500;
    case 6:
        return 600;
    case 7:
        return 800;
    case 8:
        return 1000;

    }
}
void PerformQuickWithdraw() {
    
    int withdrawAmount = getWithdrawAmount();
    if (withdrawAmount > Gclient.AccountBalance)
    {
        cout << "\nThe amount exceedds your balance . make another choice\n";
        PerformQuickWithdraw();

    }
    else {
        vector<stClientInfo> vClients = LoadDataFromFile();
        DepositAmountInClientAcc(Gclient.AccountNo, withdrawAmount * -1);
        Gclient.AccountBalance -= withdrawAmount;
    }
   
}
//
bool FindClientByAccountNo(string AccountNo, stClientInfo& client1) {
    vector<stClientInfo>vClientsData = LoadDataFromFile();
    for (stClientInfo& client : vClientsData)
    {
        if (client.AccountNo == AccountNo)
        {
            client1 = client;
            return 1;
        }
    }
    return 0;
}
vector<string> Split(string DataLine, string Delim = "#//#")
{
    int pos;
    vector<string> vData;
    string S1;

    while ((pos = DataLine.find(Delim)) != std::string::npos)
    {
        S1 = DataLine.substr(0, pos);
        if (S1 != "")
        {
            vData.push_back(S1);
        }
        DataLine.erase(0, pos + Delim.length());


    }
    if (DataLine != "")
    {
        vData.push_back(DataLine);
    }
    return vData;
}
stClientInfo GetClientInfoStruct(string DataLine) {
    vector<string>vClientData = Split(DataLine);
    stClientInfo client;
    client.AccountNo = vClientData[0];
    client.PinCode = vClientData[1];
    client.Name = vClientData[2];
    client.Phone = vClientData[3];
    client.AccountBalance = stod(vClientData[4]);
    return client;

}
vector<stClientInfo> LoadDataFromFile()
{
    vector<stClientInfo>vFileData;
    fstream file;
    file.open(FileName, ios::in);
    if (file.is_open())
    {
        string DataLine;
        while (getline(file, DataLine))
        {
            if (DataLine.empty())
            {
                continue;
            }
            vFileData.push_back(GetClientInfoStruct(DataLine));

        }
        file.close();
    }
    return vFileData;
}
bool chechAccountNumberAndPincode(string AccountNumber, string Pincode)
{
    vector<stClientInfo> vClients = LoadDataFromFile();
    for (stClientInfo client : vClients)
    {
        if (client.AccountNo == AccountNumber)
        {
            if (client.PinCode == Pincode)
                return 1;
        }
        else
            return 0;
    }
    return 0;

}
void PerFormMainMenueOption()
{
    enMainMenueOPtions UserOption = ReadUserOption();
    switch (UserOption)
    {
    case QuickWithdrawOP:
    {
        system("cls");
        ShowQuickWithdrawMenue();
        BackToMenue();
        
    }
    case NormalWithdrawOP:
    {
        system("cls");
        ShowNormalWithdrawScreen();
        BackToMenue();

    }
    case DepositOP: {
        showDepositScreen();
        Deposit();
        BackToMenue();

        break;
    }
    case CheckBalanceOP:
    {
        system("cls");
        ShowCheckBalanceScreen();
        CheckBalance();
        BackToMenue();
    }
    case LogoutOP:
    {
        Login();

        break;
    }
    default:
        break;
    }
}
void Login() {
    ShowLoginScreen();
    string AccountNumber;
    string PinCode;
    bool invalid = 0;
    do {
        invalid = 0;
        AccountNumber = ReadAccountNumber();
        PinCode = ReadPinCode();
        if (!chechAccountNumberAndPincode(AccountNumber, PinCode))
        {
            invalid = 1;
            cout << "Invalis Username/PassWord!\n";
        }
        
    } while (invalid);
    FindClientByAccountNo(AccountNumber, Gclient);
    ShowMainMenueScreen();


}





int main()
{
    Login();
}

