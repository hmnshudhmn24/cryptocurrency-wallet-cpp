#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <openssl/sha.h>
#include <openssl/aes.h>

using namespace std;

// Function to generate SHA-256 hash
string sha256(const string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)data.c_str(), data.size(), hash);
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << (int)hash[i];
    }
    return ss.str();
}

// Transaction structure
struct Transaction {
    string sender;
    string receiver;
    double amount;
    time_t timestamp;
    string hash;

    Transaction(string s, string r, double amt) {
        sender = s;
        receiver = r;
        amount = amt;
        timestamp = time(0);
        hash = sha256(sender + receiver + to_string(amount) + to_string(timestamp));
    }
};

// Wallet class
class Wallet {
private:
    string owner;
    double balance;
    vector<Transaction> transactions;

public:
    Wallet(string ownerName, double initialBalance) {
        owner = ownerName;
        balance = initialBalance;
    }

    void sendMoney(Wallet &receiver, double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!\n";
            return;
        }
        balance -= amount;
        receiver.receiveMoney(*this, amount);
        transactions.push_back(Transaction(owner, receiver.getOwner(), amount));
        cout << "Transaction successful!\n";
    }

    void receiveMoney(Wallet &sender, double amount) {
        balance += amount;
        transactions.push_back(Transaction(sender.getOwner(), owner, amount));
    }

    void showTransactions() {
        cout << "Transaction history for " << owner << ":\n";
        for (const auto& t : transactions) {
            cout << "From: " << t.sender << " To: " << t.receiver << " Amount: " << t.amount << " Timestamp: " << t.timestamp << " Hash: " << t.hash << "\n";
        }
    }

    double getBalance() {
        return balance;
    }

    string getOwner() {
        return owner;
    }
};

int main() {
    Wallet alice("Alice", 1000);
    Wallet bob("Bob", 500);

    alice.sendMoney(bob, 200);
    bob.sendMoney(alice, 50);

    alice.showTransactions();
    bob.showTransactions();

    cout << "Alice's balance: " << alice.getBalance() << "\n";
    cout << "Bob's balance: " << bob.getBalance() << "\n";
    
    return 0;
}
