/* 
Banking System ���� 
*/

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void show_menu(void);	//�޴� ���
void make_account(void);	//���� �輳�� ���� ����
void deposit_money(void);	//�Ա�
void withdraw_money(void);	//���
void show_all_accinfo(void);	//�ܾ� ��ȸ
enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct {
	int account_ID;	//���¹�ȣ
	int balance;	//�ܾ�
	char customer_name[NAME_LEN];	//�� �̸�
}Account;

Account account_arr[100];	// Account ������ ���� �迭
int account_num = 0;	//����� Account ��

void show_menu(void) {
	cout << "----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void make_account(void) {
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[���°輳]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << endl;
}

void deposit_money(void) {
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;
	
	for (int i = 0; i < account_num; i++) {
		if (account_arr[i].account_ID == id) {
			account_arr[i].balance += money;
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�." << endl << endl;
}

void withdraw_money(void) {
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��ݾ�: "; cin >> money;

	for (int i = 0; i < account_num; i++) {
		if (account_arr[i].account_ID == id) {
			if (account_arr[i].balance < money) {
				cout << "�ܾ׺���" << endl << endl;
				return;
			}
			account_arr[i].balance = money;
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȣ���� ���� ID�Դϴ�." << endl << endl;
}

void show_all_accinfo(void) {
	for (int i = 0; i < account_num; i++) {
		cout << "����ID: " << account_arr[i].account_ID << endl;
		cout << "�� ��: " << account_arr[i].customer_name << endl;
		cout << "�� ��: " << account_arr[i].balance << endl << endl;
	}
}

int main() {
	int choice;

	while (1) {
		show_menu();
		cout << "����: ";
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