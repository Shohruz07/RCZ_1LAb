#include <iostream>

class Product {
private:
    int price;

public:
    Product(int price) : price(price) {}

    int getPrice() const {
        return price;
    }

    void setPrice(int price) {
        if (price >= 0) { 
            this->price = price;
        } else {
            std::cerr << "Error: Price cannot be negative." << std::endl;
        }
    }
};

class IProductValidator {
public:
    virtual bool IsValid(const Product& product) const = 0;
};

class CustomerServiceProductValidator : public IProductValidator {
public:
    bool IsValid(const Product& product) const override {
        return product.getPrice() > 100000;
    }
};

int main() {
    Product product1(50);
    Product product2(150000);

    CustomerServiceProductValidator customerServiceValidator;

    std::cout << "\nCustomer Service Validator:" << std::endl;
    std::cout << "Product 1 is " << (customerServiceValidator.IsValid(product1) ? "valid" : "invalid") << std::endl;
    std::cout << "Product 2 is " << (customerServiceValidator.IsValid(product2) ? "valid" : "invalid") << std::endl;

   
    product1.setPrice(-10); 
    product1.setPrice(200000); 

    std::cout << "Updated Product 1 is " << (customerServiceValidator.IsValid(product1) ? "valid" : "invalid") << std::endl;

    return 0;
}
