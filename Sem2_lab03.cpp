#include <iostream>
#include <string>
using namespace std;

class account{
protected:
    string FIO;
    int startsum;
    int percent;
    int exist;
public:
    account(string FIO, int startsum, int percent, int exist){  // Конструктор для инициализации полей
        this->FIO = FIO;
        this->startsum = startsum;
        this->percent = percent;
        this->exist = exist;
    }
    int doaccountsum(int startsum, int percent, int exist){  // Функция для вычисления суммы на счете
        int accountsum = startsum;
        for (int i=0; i<=exist; i++){
            accountsum += (accountsum*percent)/100;
        }
        return accountsum;
    }
    virtual void print(){  // Функция для печати параметров счета
        cout<<FIO<<endl;
        cout<<startsum<<endl;
        cout<<percent<<endl;
        cout<<exist<<endl;
    }
};

class pro_account: public account{
protected:
    int credit_percent;
public:
    pro_account(string FIO, int startsum, int percent, int exist, int credit_percent): account(FIO, startsum, percent, exist){  // Конструктор
        this->credit_percent = credit_percent;
    }
    int do_credit_percent(int startsum, int percent, int exist, int credit_percent){  // Переопределенная функция для вычисления суммы на счете с учетом доступного кредита
        int accountsum = doaccountsum(startsum, percent, exist);
        accountsum += (accountsum*credit_percent)/100;
        return accountsum;
    }
    void print(){  // Переопределенная функция для печати параметров счета
        account::print();
        cout<<credit_percent<<endl;
    }
};

int main()
{
    account ac1("ABC", 100, 20, 2);
    pro_account ac2("ABC", 100, 20, 2, 50);
    account *a;
    a = &ac1;
    a->print();
    cout<<ac1.doaccountsum(100, 20, 2)<<endl;
    a = &ac2;
    a->print();
    cout<<ac2.do_credit_percent(100, 20, 2, 50)<<endl;
}

