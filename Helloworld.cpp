/* 
Banking System 구현 
*/

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void show_menu(void);	//메뉴 출력
void make_account(void);	//계좌 계설을 위한 변수
void deposit_money(void);	//입금
void withdraw_money(void);	//출금
void show_all_accinfo(void);	//잔액 조회
enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct {
	int account_ID;	//계좌번호
	int balance;	//잔액
	char customer_name[NAME_LEN];	//고객 이름
}Account;

Account account_arr[100];	// Account 저장을 위한 배열
int account_num = 0;	//저장된 Account 수

void show_menu(void) {
	cout << "----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void make_account(void) {
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌계설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << endl;
}

void deposit_money(void) {
	int money;
	int id;
	cout << "[입 금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;
	
	for (int i = 0; i < account_num; i++) {
		if (account_arr[i].account_ID == id) {
			account_arr[i].balance += money;
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다." << endl << endl;
}

void withdraw_money(void) {
	int money;
	int id;
	cout << "[출 금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> money;

	for (int i = 0; i < account_num; i++) {
		if (account_arr[i].account_ID == id) {
			if (account_arr[i].balance < money) {
				cout << "잔액부족" << endl << endl;
				return;
			}
			account_arr[i].balance = money;
			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유호하지 않은 ID입니다." << endl << endl;
}

void show_all_accinfo(void) {
	for (int i = 0; i < account_num; i++) {
		cout << "계좌ID: " << account_arr[i].account_ID << endl;
		cout << "이 름: " << account_arr[i].customer_name << endl;
		cout << "잔 액: " << account_arr[i].balance << endl << endl;
	}
}

int main() {
	int choice;

	while (1) {
		show_menu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice) {
			case MAKE:
				make_account(); break;
			case DEPOSIT:
				deposit_money(); break;
			case WITHDRAW:
				withdraw_money(); break;
			case INQUIRE:
				show_all_accinfo(); break;
			case EXIT:
				return 0;
			default:
				cout << "Illegal selection..." << endl;

		}
	}
	return 0;
}