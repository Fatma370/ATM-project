
# ATM system
This is a simple ATM system implemented in C++ that allows users to perform basic banking operations such as withdrawing funds, checking balances, and depositing money. The system includes user authentication via a login page, and each user is associated with an account that has a unique account number, PIN code, and account balance.


## Featuers
**1- User Authentication:**

The system requires users to log in by entering their account number and PIN code. If the credentials are valid, users gain access to the main menu.

**2- Main Menu Operations:**

` Quick Withdraw: `
Users can choose to withdraw preset amounts (e.g., 20, 50, 100, etc.).

`Normal Withdraw:` Users can specify an amount (multiple of 5) to withdraw, ensuring it does not exceed the account balance.

`Deposit:` Users can deposit a specified amount into their account, which is added to their balance.
Check Balance: Displays the current balance of the user's account.

`Logout:` Logs out the current user and prompts for another login.

**3-Data Management:** User data (account number, PIN, balance, etc.) is stored in a text file (clientsData.txt). All changes to accounts (such as deposits or withdrawals) are reflected in this file, ensuring persistence.

**4-User Interface:** The system features a simple text-based interface with screens for login, withdrawals, deposits, balance checks, and a main menu.

**5-File Handling:** The system reads and writes user data from/to the text file. It supports operations like adding, updating, and finding users in the file.

## How it Works

The` Login` function authenticates users by checking their credentials against the data stored in `clientsData.txt.`


Once logged in, users can perform any of the operations available in the main menu.

User transactions are confirmed with a prompt for approval, ensuring that actions like deposits and withdrawals are intentional.

After each transaction, the updated data is written back to the file.

**Files:**

`clientsData.txt`: Stores the client information, such as account number, PIN code, name, phone number, and account balance.

**How to Run:**

Compile the `ATMproject.cpp` file using a C++ compiler (e.g., `g++ ATMproject.cpp -o ATMproject`).
Run the executable (`ATMproject.exe` or `./ATMproject`).
Follow the prompts to log in and perform various operations.
