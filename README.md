# Cryptocurrency Wallet

A digital wallet in C++ that allows users to send, receive, and track transactions securely with SHA-256 hashing.

## Features
- Secure transaction tracking
- SHA-256 hashing for transaction integrity
- Wallet balance management

## Requirements
- g++ compiler
- OpenSSL library (for SHA-256 hashing)

## Installation & Usage

### 1. Compile the Program
```sh
g++ cryptocurrency_wallet.cpp -o wallet -lssl -lcrypto
```

### 2. Run the Program
```sh
./wallet
```

## How It Works
- Each transaction is recorded with SHA-256 hashing.
- Wallets maintain balance and track transaction history.
- Transactions are stored securely and can be verified.

## Future Enhancements
- Implement encryption for private keys.
- Add a user authentication mechanism.
- Integrate a network-based peer-to-peer transfer system.

## License
This project is open-source and can be modified freely.
