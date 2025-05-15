#include <iostream>
#include <exception>

class DatabaseException : public std::exception {
public:
    const char* what() const noexcept override {
        return "A database error occurred.";
    }
};

class ConnectionFailedException : public DatabaseException {};
class QueryTimeoutException : public DatabaseException {};

template <typename T>
class DatabaseConnector {
public:
    void connect(T dbName) {
        if (dbName == "invalid_db") {
            throw ConnectionFailedException();
        }
        if (dbName == "slow_db") {
            throw QueryTimeoutException();
        }
    }
};

int main() {
    DatabaseConnector<std::string> db;

    try {
        std::cout << "Attempting to connect to invalid_db...\n";
        db.connect("invalid_db");
    } catch (const ConnectionFailedException& e) {
        std::cout << "Caught ConnectionFailedException - what(): " << e.what() << "\n";
    }

    try {
        std::cout << "Attempting to connect to slow_db...\n";
        db.connect("slow_db");
    } catch (const DatabaseException& e) {
        std::cout << "Caught a general DatabaseException - what(): " << e.what() << "\n";
    }

    return 0;
}
