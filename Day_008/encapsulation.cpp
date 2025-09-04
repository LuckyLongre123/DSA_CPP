/*
 * Day 8: Encapsulation in C++
 * This file demonstrates data hiding and controlled access to class members
 * Encapsulation is a fundamental principle of object-oriented programming
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * SECTION 1: Basic Encapsulation Example
 */

class Employee {
private:
    string name;
    int employeeId;
    double salary;
    string department;
    bool isActive;
    
public:
    // Constructor
    Employee(string n, int id, double sal, string dept) {
        name = n;
        employeeId = id;
        setSalary(sal);  // Use setter for validation
        department = dept;
        isActive = true;
    }
    
    // Getter methods (const to indicate they don't modify object)
    string getName() const { return name; }
    int getEmployeeId() const { return employeeId; }
    double getSalary() const { return salary; }
    string getDepartment() const { return department; }
    bool getIsActive() const { return isActive; }
    
    // Setter methods with validation
    void setName(const string& n) {
        if (!n.empty()) {
            name = n;
        } else {
            cout << "Error: Name cannot be empty" << endl;
        }
    }
    
    void setSalary(double sal) {
        if (sal >= 0) {
            salary = sal;
        } else {
            cout << "Error: Salary cannot be negative" << endl;
            salary = 0;
        }
    }
    
    void setDepartment(const string& dept) {
        if (!dept.empty()) {
            department = dept;
        } else {
            cout << "Error: Department cannot be empty" << endl;
        }
    }
    
    void setActive(bool active) {
        isActive = active;
    }
    
    // Business logic methods
    void giveRaise(double percentage) {
        if (percentage > 0 && percentage <= 50) {  // Max 50% raise
            double oldSalary = salary;
            salary += salary * (percentage / 100.0);
            cout << name << " received a " << percentage << "% raise" << endl;
            cout << "Salary increased from $" << oldSalary << " to $" << salary << endl;
        } else {
            cout << "Invalid raise percentage" << endl;
        }
    }
    
    void displayInfo() const {
        cout << "Employee ID: " << employeeId << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: $" << salary << endl;
        cout << "Status: " << (isActive ? "Active" : "Inactive") << endl;
    }
};

/*
 * SECTION 2: Advanced Encapsulation with Private Helper Methods
 */

class BankAccount {
private:
    string accountNumber;
    string holderName;
    double balance;
    double interestRate;
    vector<string> transactionHistory;
    
    // Private helper methods
    void logTransaction(const string& transaction) {
        transactionHistory.push_back(transaction);
        if (transactionHistory.size() > 10) {
            transactionHistory.erase(transactionHistory.begin());  // Keep only last 10
        }
    }
    
    bool validateAmount(double amount) const {
        return amount > 0 && amount <= 1000000;  // Max transaction limit
    }
    
    void calculateInterest() {
        if (balance > 0) {
            double interest = balance * (interestRate / 100.0) / 12;  // Monthly interest
            balance += interest;
            logTransaction("Interest credited: $" + to_string(interest));
        }
    }
    
public:
    // Constructor
    BankAccount(const string& accNum, const string& name, double initialBalance = 0.0) {
        accountNumber = accNum;
        holderName = name;
        balance = initialBalance;
        interestRate = 2.5;  // Default 2.5% annual interest
        logTransaction("Account opened with balance: $" + to_string(initialBalance));
    }
    
    // Public interface methods
    string getAccountNumber() const { return accountNumber; }
    string getHolderName() const { return holderName; }
    double getBalance() const { return balance; }
    double getInterestRate() const { return interestRate; }
    
    void setInterestRate(double rate) {
        if (rate >= 0 && rate <= 10) {  // Reasonable interest rate range
            interestRate = rate;
            cout << "Interest rate updated to " << rate << "%" << endl;
        } else {
            cout << "Invalid interest rate" << endl;
        }
    }
    
    bool deposit(double amount) {
        if (validateAmount(amount)) {
            balance += amount;
            logTransaction("Deposit: $" + to_string(amount));
            cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
            return true;
        } else {
            cout << "Invalid deposit amount" << endl;
            return false;
        }
    }
    
    bool withdraw(double amount) {
        if (validateAmount(amount) && amount <= balance) {
            balance -= amount;
            logTransaction("Withdrawal: $" + to_string(amount));
            cout << "Withdrew $" << amount << ". New balance: $" << balance << endl;
            return true;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds" << endl;
            return false;
        }
    }
    
    void applyMonthlyInterest() {
        calculateInterest();
        cout << "Monthly interest applied. New balance: $" << balance << endl;
    }
    
    void displayTransactionHistory() const {
        cout << "Transaction History (Last " << transactionHistory.size() << " transactions):" << endl;
        for (size_t i = 0; i < transactionHistory.size(); i++) {
            cout << (i + 1) << ". " << transactionHistory[i] << endl;
        }
    }
    
    void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << holderName << endl;
        cout << "Current Balance: $" << balance << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

/*
 * SECTION 3: Encapsulation with Data Validation
 */

class Product {
private:
    string name;
    string category;
    double price;
    int quantity;
    string sku;
    bool isActive;
    
    // Private validation methods
    bool isValidPrice(double p) const {
        return p >= 0 && p <= 10000;
    }
    
    bool isValidQuantity(int q) const {
        return q >= 0 && q <= 1000;
    }
    
    bool isValidSKU(const string& s) const {
        return s.length() >= 3 && s.length() <= 20;
    }
    
public:
    // Constructor with validation
    Product(const string& n, const string& cat, double p, int q, const string& s) {
        setName(n);
        setCategory(cat);
        setPrice(p);
        setQuantity(q);
        setSKU(s);
        isActive = true;
    }
    
    // Getters
    string getName() const { return name; }
    string getCategory() const { return category; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    string getSKU() const { return sku; }
    bool getIsActive() const { return isActive; }
    
    // Setters with validation
    void setName(const string& n) {
        if (!n.empty() && n.length() <= 100) {
            name = n;
        } else {
            cout << "Invalid product name" << endl;
        }
    }
    
    void setCategory(const string& cat) {
        if (!cat.empty()) {
            category = cat;
        } else {
            cout << "Invalid category" << endl;
        }
    }
    
    void setPrice(double p) {
        if (isValidPrice(p)) {
            price = p;
        } else {
            cout << "Invalid price. Must be between $0 and $10,000" << endl;
        }
    }
    
    void setQuantity(int q) {
        if (isValidQuantity(q)) {
            quantity = q;
        } else {
            cout << "Invalid quantity. Must be between 0 and 1000" << endl;
        }
    }
    
    void setSKU(const string& s) {
        if (isValidSKU(s)) {
            sku = s;
        } else {
            cout << "Invalid SKU. Must be 3-20 characters" << endl;
        }
    }
    
    void setActive(bool active) {
        isActive = active;
    }
    
    // Business methods
    bool sellProduct(int amount) {
        if (amount > 0 && amount <= quantity && isActive) {
            quantity -= amount;
            cout << "Sold " << amount << " units of " << name << endl;
            cout << "Remaining quantity: " << quantity << endl;
            return true;
        } else {
            cout << "Cannot sell " << amount << " units" << endl;
            return false;
        }
    }
    
    void restockProduct(int amount) {
        if (amount > 0 && (quantity + amount) <= 1000) {
            quantity += amount;
            cout << "Restocked " << amount << " units of " << name << endl;
            cout << "New quantity: " << quantity << endl;
        } else {
            cout << "Invalid restock amount" << endl;
        }
    }
    
    double calculateTotalValue() const {
        return price * quantity;
    }
    
    void displayProductInfo() const {
        cout << "Product: " << name << endl;
        cout << "Category: " << category << endl;
        cout << "SKU: " << sku << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Total Value: $" << calculateTotalValue() << endl;
        cout << "Status: " << (isActive ? "Active" : "Inactive") << endl;
    }
};

int main() {
    cout << "=== Encapsulation Demonstration ===" << endl;
    
    /*
     * SECTION 4: Employee Class Usage
     */
    
    cout << "\n=== Employee Management System ===" << endl;
    
    Employee emp1("John Doe", 1001, 50000.0, "Engineering");
    emp1.displayInfo();
    
    cout << "\nUpdating employee information..." << endl;
    emp1.setName("John Smith");  // Valid update
    emp1.setSalary(55000.0);     // Valid update
    emp1.setName("");            // Invalid - should show error
    emp1.setSalary(-1000.0);     // Invalid - should show error
    
    cout << "\nAfter updates:" << endl;
    emp1.displayInfo();
    
    cout << "\nGiving raise..." << endl;
    emp1.giveRaise(10.0);  // 10% raise
    emp1.giveRaise(60.0);  // Invalid - too high
    
    /*
     * SECTION 5: Bank Account Class Usage
     */
    
    cout << "\n=== Banking System ===" << endl;
    
    BankAccount account("ACC12345", "Alice Johnson", 1000.0);
    account.displayAccountInfo();
    
    cout << "\nPerforming transactions..." << endl;
    account.deposit(500.0);
    account.withdraw(200.0);
    account.withdraw(2000.0);  // Should fail - insufficient funds
    
    cout << "\nApplying interest..." << endl;
    account.applyMonthlyInterest();
    
    cout << "\nTransaction history:" << endl;
    account.displayTransactionHistory();
    
    /*
     * SECTION 6: Product Class Usage
     */
    
    cout << "\n=== Inventory Management System ===" << endl;
    
    Product product1("Laptop", "Electronics", 999.99, 50, "LAP001");
    product1.displayProductInfo();
    
    cout << "\nTesting product operations..." << endl;
    product1.sellProduct(5);
    product1.restockProduct(10);
    product1.sellProduct(100);  // Should fail - not enough quantity
    
    cout << "\nTrying invalid updates..." << endl;
    product1.setPrice(-100.0);   // Invalid price
    product1.setQuantity(2000);  // Invalid quantity
    product1.setSKU("AB");       // Invalid SKU
    
    cout << "\nFinal product state:" << endl;
    product1.displayProductInfo();
    
    /*
     * SECTION 7: Multiple Objects Demonstration
     */
    
    cout << "\n=== Multiple Objects Demo ===" << endl;
    
    vector<Employee> employees;
    employees.push_back(Employee("Alice Brown", 2001, 60000.0, "Marketing"));
    employees.push_back(Employee("Bob Wilson", 2002, 55000.0, "Sales"));
    employees.push_back(Employee("Carol Davis", 2003, 65000.0, "Engineering"));
    
    cout << "All employees:" << endl;
    for (size_t i = 0; i < employees.size(); i++) {
        cout << "\nEmployee " << (i + 1) << ":" << endl;
        employees[i].displayInfo();
    }
    
    // Give raises to all employees
    cout << "\nGiving 5% raise to all employees:" << endl;
    for (size_t i = 0; i < employees.size(); i++) {
        employees[i].giveRaise(5.0);
    }
    
    cout << "\n=== Encapsulation Complete! ===" << endl;
    
    return 0;
}

/*
 * ENCAPSULATION KEY CONCEPTS:
 * 
 * 1. DATA HIDING:
 *    - Make data members private
 *    - Control access through public methods
 *    - Protect internal implementation details
 * 
 * 2. ACCESS CONTROL:
 *    - private: Only accessible within the class
 *    - public: Accessible from outside the class
 *    - protected: Accessible in derived classes
 * 
 * 3. GETTER METHODS:
 *    - Provide read access to private data
 *    - Usually const methods
 *    - Return copy or const reference
 * 
 * 4. SETTER METHODS:
 *    - Provide controlled write access
 *    - Include validation logic
 *    - Maintain data integrity
 * 
 * 5. VALIDATION:
 *    - Check data before setting
 *    - Maintain business rules
 *    - Prevent invalid states
 * 
 * 6. PRIVATE HELPER METHODS:
 *    - Internal utility functions
 *    - Not part of public interface
 *    - Support public methods
 * 
 * BENEFITS OF ENCAPSULATION:
 * - Data protection and integrity
 * - Controlled access to data
 * - Easier maintenance and debugging
 * - Implementation can change without affecting users
 * - Better code organization
 * 
 * BEST PRACTICES:
 * - Make data members private by default
 * - Provide minimal necessary public interface
 * - Validate all input in setters
 * - Use const for methods that don't modify state
 * - Group related functionality in classes
 * - Keep classes focused on single responsibility
 */
