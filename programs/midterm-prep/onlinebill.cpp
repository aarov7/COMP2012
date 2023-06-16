/* File: Date.h */
#include <iostream>
using namespace std;
class Date
{
public:
    Date(int d, int m) : dd(d), mm(m) {} // d is the day, m is the month
    int getdd() const { return dd; }
    int getmm() const { return mm; }
private:
    int dd; // day information
    int mm; // month information
};

class Bill{
private:
    Date date;
public:
    Bill(int dd, int mm): date(Date(dd,mm)){}
    void printBillDate() const{
        cout<<"Date: "<<date.getdd()<<"/"<<date.getmm()<<endl;
    }
    virtual float getOwedAmount() const = 0;
    virtual void pay(float p) = 0;
    virtual void print() const = 0;
};

class CreditCardBill : public Bill{
private:
    float billA, serviceC, paymentR;
public:
    CreditCardBill(float billA, float serviceC, int dd, int mm)
        : Bill(dd, mm), billA(billA), serviceC(serviceC), paymentR(0){
    }
    virtual float getOwedAmount() const override{
        return billA+serviceC-paymentR;
    }
    virtual void pay(float p) override{
        paymentR+=p;
    }
    virtual void print() const override{
        cout<<"Credit card bill"<<endl;
        printBillDate();
        cout<<"You owe: $"<<billA<<endl;
        cout<<"Service charge: $"<<serviceC<<endl;
        cout<<"You have totally paid $"<<paymentR<<" and you owe the bank $"<<getOwedAmount()<<" net."<<endl<<endl;
    }
};
class OnlineBill : public Bill{
private:
    float amount;
public:
    OnlineBill(float amount, int dd, int mm)
        : Bill(dd,mm), amount(amount){}
    virtual float getOwedAmount() const override{
        return amount;
    }
    virtual void pay(float p) override{
        if(p==amount){
            amount=0;
        }
    }
    virtual void print() const override{
        cout<<"Online bill"<<endl;
        printBillDate();
        cout<<"You owe: $"<<amount<<endl;
    }
};
/* main.cpp */

int main()
{
    Bill* bills[2];
    bills[0] = new CreditCardBill(2000.00, 200.00, 25, 3);
    bills[1] = new OnlineBill(2017.00, 25, 3);
    cout << endl << "-------The Bills are -------" << endl;
    bills[0]->print();
    bills[1]->print();
    cout << endl << "-------After paying back the bills are-------" << endl;
    bills[0]->pay(2000);
    bills[1]->pay(2000);
    bills[0]->print();
    bills[1]->print();
    cout << endl << "-------After paying the exact bill for the OnlineBill-------" <<endl;
    bills[1]->pay(2017);
    bills[1]->print();
    for(Bill* bill:bills){
        delete bill;
    }
}
