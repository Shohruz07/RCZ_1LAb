#include <iostream>

class Ilog {
public:
    virtual void logging(std::string log) = 0;
};

class Logger : public Ilog {
public:
    void logging(std::string log) override {
        std::cout << "Logging in logtxt" << std::endl;
    }
};

class SMTP {
    Ilog * logger;
public:
    SMTP(Ilog *o_logger) { 
        logger = o_logger;
    }

    void log(std::string msg) {
        logger->logging(msg);
    }
};

int main() {
    Ilog * logger = new Logger;
    SMTP mail(logger);
    mail.log("new msg");
    logger = nullptr;
    return 0;
}
