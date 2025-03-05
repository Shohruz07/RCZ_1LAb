
#include <iostream>
#include <memory>

class AbstractEntity {
public:
    virtual ~AbstractEntity() = default;
};

class AccountEntity : public AbstractEntity {
};

class RoleEntity : public AbstractEntity {
};

class IRepository {
public:
    virtual void save(const std::shared_ptr<AbstractEntity>& entity) = 0;
    virtual ~IRepository() = default;
};

class AccountRepository : public IRepository {
public:
    void save(const std::shared_ptr<AbstractEntity>& entity) override {
        if (auto account = std::dynamic_pointer_cast<AccountEntity>(entity)) {
            std::cout << "Saving AccountEntity" << std::endl;
        } else {
            std::cerr << "Error: Invalid entity type for AccountRepository" << std::endl;
        }
    }
};

class RoleRepository : public IRepository {
public:
    void save(const std::shared_ptr<AbstractEntity>& entity) override {
        if (auto role = std::dynamic_pointer_cast<RoleEntity>(entity)) {
            std::cout << "Saving RoleEntity" << std::endl;
        } else {
            std::cerr << "Error: Invalid entity type for RoleRepository" << std::endl;
        }
    }
};

int main() {
    auto account = std::make_shared<AccountEntity>();
    auto role = std::make_shared<RoleEntity>();

    AccountRepository accountRepo;
    RoleRepository roleRepo;

    accountRepo.save(account);
    roleRepo.save(role);

    accountRepo.save(role);

    return 0;
}