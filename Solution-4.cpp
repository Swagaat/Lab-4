#include <iostream>
#include <iomanip> // For formatting output

class SavingsAccount {
private:
    static double annualInterestRate; 
    double savingsBalance; // Private data member for savings balance

public:
    // Constructor to initialize savings balance
    SavingsAccount(double balance) : savingsBalance(balance) {}

    // Calculate monthly interest and update savings balance
    void calculateMonthlyInterest() {
        double monthlyInterest = (savingsBalance * annualInterestRate) / 12.0;
        savingsBalance += monthlyInterest;
    }

    // Modify the annual interest rate
    static void modifyInterestRate(double newRate) {
        annualInterestRate = newRate;
    }

    // Print the current savings balance
    void printBalance() const {
        std::cout << "Current balance: $" << std::fixed << std::setprecision(2) << savingsBalance << std::endl;
    }
};

double SavingsAccount::annualInterestRate = 0.03; // Default rate of 3%

int main() {
    // Create two SavingsAccount objects
    SavingsAccount saver1(2000.00);
    SavingsAccount saver2(3000.00);

    std::cout << "Initial balances:" << std::endl;
    std::cout << "Saver 1: ";
    saver1.printBalance();
    std::cout << "Saver 2: ";
    saver2.printBalance();

    // Set initial interest rate to 3%
    SavingsAccount::modifyInterestRate(0.03);

    // Calculate and print balances for the first month
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    std::cout << "\nMonth 1 at 3% interest rate:" << std::endl;
    std::cout << "Saver 1: ";
    saver1.printBalance();
    std::cout << "Saver 2: ";
    saver2.printBalance();

    // Set interest rate to 4%
    SavingsAccount::modifyInterestRate(0.04);

    // Calculate and print balances for the second month
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    std::cout << "\nMonth 2 at 4% interest rate:" << std::endl;
    std::cout << "Saver 1: ";
    saver1.printBalance();
    std::cout << "Saver 2: ";
    saver2.printBalance();

    return 0;
}
