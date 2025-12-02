#include <iostream>
#include <vector>
using namespace std;

class IPayment{
    protected:
    int amount;
    public:
    IPayment(){}
    virtual ~IPayment(){}
    void virtual pay(int amount) = 0;   //순수가상함수

};

class CardPayment : public IPayment {
    public:
    CardPayment(): IPayment(){};
    ~ CardPayment(){}
    void pay(int amount) override {
        cout << "카드로 $" << amount << "이 결제되었습니다." << endl;
    }
};

class CashPayment : public IPayment {
    public:
    CashPayment(): IPayment(){};
    ~ CashPayment(){}
    void pay(int amount) override {
        cout << "현금으로 $" << amount << "이 결제되었습니다." << endl;
    }

};

class KakaopayPayment : public IPayment{
    public:
    KakaopayPayment(): IPayment(){};
    ~ KakaopayPayment(){}
    void pay(int amount) override {
        cout << "카카오페이로 $" << amount << "이 결제되었습니다." << endl;
    }
};

int main(){
    //객체생성
    vector<IPayment*> payments;
    payments.push_back(new CardPayment());
    payments.push_back(new CashPayment());
    payments.push_back(new KakaopayPayment());

    int choice;
    int amount; 
    int sum;

    while(1){
        cout << "어떤 수단으로 결제하시겠습니까? \n (프로그램 종료를 원하시면 1, 2, 3을 제외한 다른 수를 입력하세요.)" << endl;
        cout << "1) Card" << endl;
        cout << "2) Cash" << endl;
        cout << "3) KakaoPay" << endl;
        cin >> choice;

        if(choice == 1 || choice == 2 || choice == 3){
            cout << "얼마를 계산하시겠습니까?" << endl;
            cin >> amount;

            switch (choice){
                case 1:
                payments[0]->pay(amount);
                break;
                case 2:
                payments[1]->pay(amount);
                break;
                case 3:
                payments[2]->pay(amount);
                break;
            }
            cout << "--------------------" << endl;
        } else{
            break;
        }
    }

    return 0;
}