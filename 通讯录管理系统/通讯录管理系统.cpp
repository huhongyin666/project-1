#include <iostream>
using namespace std;
#include <string>
#define MAX 1000


struct Person//��ϵ�˽ṹ��
{
	string m_Name;
	int  m_Sex;//1����  2��Ů
	int m_Age;
	string m_phone;
	string m_Addr;
};


struct Addressbooks//ͨѶ¼�ṹ��
{
	struct Person personArray[MAX];//ͨѶ¼������ϵ������
	int m_Size;//ͨѶ¼��Ա���� 
};

int isExit(Addressbooks *abs,string name)
{
	for (int i = 0; i <abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
		else
			return -1;
	}
	
}
void addPerson(Addressbooks *abs)	//�����ϵ�˺���
{
	if (abs->m_Size== MAX)
	{
		cout << "ͨѶ¼����" << endl;
		return;
	}		
	else
	{
		//��Ӿ�����ϵ��

		//�������
		cout << " ���������� " << endl;
		string name;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//����Ա�
		cout << "�������Ա�" << endl;
		cout << "1----man" << endl;
		cout << "2----woamn" << endl;
		int sex = 0;
		while(true)//������ȷֵ������ѭ��ֱ����������ȷֵ
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;

		}

		//�������
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//����ֻ�����
		cout << "�������ֻ�����" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_phone = phone;

		//���סַ
		cout << "������סַ" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼����
		abs->m_Size++;

		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}//
void showPerson(Addressbooks *abs)
{
	if (abs->m_Size == 0)//���ͨѶ¼�Ƿ�Ϊ��
	{
		cout << "��ͨѶ¼Ϊ�գ�����Ӻ�鿴" << endl;
		system("pause");
		system("cls");
	}
		
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������ " << abs->personArray[i].m_Name << "\t";
			cout << "�Ա� " << (abs->personArray[i].m_Sex==1?"man":"woman")<< "\t";
			cout << "���䣺 " << abs->personArray[i].m_Age << "\t";
			cout << "�绰���룺 " << abs->personArray[i].m_phone << "\t";
			cout << "סַ�� " << abs->personArray[i].m_Addr << endl;
			
		}
	}
	system("pause");
	system("cls");
}
void deletePerson(Addressbooks *abs)
{
	cout << "������Ҫɾ������" << endl;
	
	string name;
	cin >> name;
	int ret = isExit(abs , name);
	if (ret != -1)
	{
		//�鵽���ˣ�Ҫ�������ɾ������
		for (int i = ret; i < abs->m_Size; i++)
		{
				abs->personArray[ret] = abs->personArray[ret + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "���޴���" << endl;
		system("pause");
		system("cls");
	}
}
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1)
	{
		cout << "������ " << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա� " <<( abs->personArray[ret].m_Sex?"man":"woman") << "\t";
		cout << "���䣺 " << abs->personArray[ret].m_Age << "\t";
		cout << "�绰���룺 " << abs->personArray[ret].m_phone << "\t";
		cout << "סַ�� " << abs->personArray[ret].m_Addr << endl;

		system("pause");
		system("cls");
	}
	else
	{
		cout << "û�������������ϵ��" << endl;
		system("pause");
		system("cls");

	}
}
void modifyPerson(Addressbooks *abs)
{
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExit(abs, name);
	if (ret != -1)
	{
		
		string name;//����
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "�������Ա�" << endl;//�Ա�
		cout << "1----man" << endl;
		cout << "2----woamn" << endl;
		int sex = 0;
		while (true)//������ȷֵ������ѭ��ֱ����������ȷֵ
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;

		}

		cout << "����������" << endl;//�޸�����
		int age;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		cout << "������Ҫ�޸ĵĵ绰����" << endl;//�޸��ֻ�����
		string phone;
		cin >> phone;
		abs->personArray[ret].m_phone = phone;

		cout << "������Ҫ�޸ĵ�סַ" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "��ӳɹ�" << endl;

		system("pause");
		system("cls");

	}
	else
	{
		cout << "���޴���" << endl;
		system("pause");
		system("cls");
	}
}
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼����գ�\t ��ӭ���´�ʹ��" << endl;
	system("pause");
	system("cls");
}
void ShowMeau()//�˵�
{
	cout << "**************************" << endl;
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;
}

int main()
{
	Addressbooks abs;		//����ͨѶ¼�ṹ�� ��������
	abs.m_Size = 0;			//��ʼ��ͨѶ¼�е�ǰ��Ա����
	
	int select = 0;			//�����û�ѡ������ı���
	
	while (true)
	{
		ShowMeau();//�˵�����
		cin >> select;
		switch (select)
	{
	case 1://1.�����ϵ��
		addPerson(&abs);
		break;
	case 2://2.��ʾ��ϵ��
		showPerson(&abs);
		break;
	case 3://3.ɾ����ϵ��

		//����ϵ���Ƿ����
	/*{
		cout << "������Ҫɾ������ϵ�������� " << endl;
		string name;
		cin >> name;

		if (isExit(&abs, name) == -1)
		{
				cout << "���޴���" << endl;
		}
			
		else
		{
				cout << "�ҵ�����" << endl;
		}
	}*/
		deletePerson(&abs);
		break;
	case 4://4.������ϵ��
		findPerson(&abs);
		break;
	case 5://5.�޸���ϵ��
		modifyPerson(&abs);
		break;
	case 6://6.�����ϵ��
		cleanPerson(&abs);
		break;
	case 0://0.�˳�ͨѶ¼
		cout << "��ӭ���´�ʹ��" << endl;
		system("pause");
		break;	
	default:
		break;
	}
	}
	system("pause");
	return 0;
}