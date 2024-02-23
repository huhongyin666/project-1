#include <iostream>
using namespace std;
#include <string>
#define MAX 1000


struct Person//联系人结构体
{
	string m_Name;
	int  m_Sex;//1：男  2：女
	int m_Age;
	string m_phone;
	string m_Addr;
};


struct Addressbooks//通讯录结构体
{
	struct Person personArray[MAX];//通讯录保存联系人数组
	int m_Size;//通讯录人员个数 
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
void addPerson(Addressbooks *abs)	//添加联系人函数
{
	if (abs->m_Size== MAX)
	{
		cout << "通讯录已满" << endl;
		return;
	}		
	else
	{
		//添加具体联系人

		//添加姓名
		cout << " 请输入姓名 " << endl;
		string name;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//添加性别
		cout << "请输入性别" << endl;
		cout << "1----man" << endl;
		cout << "2----woamn" << endl;
		int sex = 0;
		while(true)//输入正确值，否则循环直至你输入正确值
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误请重新输入" << endl;

		}

		//添加年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//添加手机号码
		cout << "请输入手机号码" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_phone = phone;

		//添加住址
		cout << "请输入住址" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录人数
		abs->m_Size++;

		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}//
void showPerson(Addressbooks *abs)
{
	if (abs->m_Size == 0)//检查通讯录是否为空
	{
		cout << "此通讯录为空，请添加后查看" << endl;
		system("pause");
		system("cls");
	}
		
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名： " << abs->personArray[i].m_Name << "\t";
			cout << "性别： " << (abs->personArray[i].m_Sex==1?"man":"woman")<< "\t";
			cout << "年龄： " << abs->personArray[i].m_Age << "\t";
			cout << "电话号码： " << abs->personArray[i].m_phone << "\t";
			cout << "住址： " << abs->personArray[i].m_Addr << endl;
			
		}
	}
	system("pause");
	system("cls");
}
void deletePerson(Addressbooks *abs)
{
	cout << "请输入要删除的人" << endl;
	
	string name;
	cin >> name;
	int ret = isExit(abs , name);
	if (ret != -1)
	{
		//查到此人，要对其进行删除操作
		for (int i = ret; i < abs->m_Size; i++)
		{
				abs->personArray[ret] = abs->personArray[ret + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "查无此人" << endl;
		system("pause");
		system("cls");
	}
}
void findPerson(Addressbooks* abs)
{
	cout << "请输入你要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1)
	{
		cout << "姓名： " << abs->personArray[ret].m_Name << "\t";
		cout << "性别： " <<( abs->personArray[ret].m_Sex?"man":"woman") << "\t";
		cout << "年龄： " << abs->personArray[ret].m_Age << "\t";
		cout << "电话号码： " << abs->personArray[ret].m_phone << "\t";
		cout << "住址： " << abs->personArray[ret].m_Addr << endl;

		system("pause");
		system("cls");
	}
	else
	{
		cout << "没有您所输入的联系人" << endl;
		system("pause");
		system("cls");

	}
}
void modifyPerson(Addressbooks *abs)
{
	cout << "请输入要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExit(abs, name);
	if (ret != -1)
	{
		
		string name;//姓名
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "请输入性别" << endl;//性别
		cout << "1----man" << endl;
		cout << "2----woamn" << endl;
		int sex = 0;
		while (true)//输入正确值，否则循环直至你输入正确值
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误请重新输入" << endl;

		}

		cout << "请输入年龄" << endl;//修改年龄
		int age;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		cout << "请输入要修改的电话号码" << endl;//修改手机号码
		string phone;
		cin >> phone;
		abs->personArray[ret].m_phone = phone;

		cout << "请输入要修改的住址" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "添加成功" << endl;

		system("pause");
		system("cls");

	}
	else
	{
		cout << "查无此人" << endl;
		system("pause");
		system("cls");
	}
}
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空！\t 欢迎你下次使用" << endl;
	system("pause");
	system("cls");
}
void ShowMeau()//菜单
{
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;
}

int main()
{
	Addressbooks abs;		//创建通讯录结构体 “变量”
	abs.m_Size = 0;			//初始化通讯录中当前人员个数
	
	int select = 0;			//创建用户选择输入的变量
	
	while (true)
	{
		ShowMeau();//菜单调用
		cin >> select;
		switch (select)
	{
	case 1://1.添加联系人
		addPerson(&abs);
		break;
	case 2://2.显示联系人
		showPerson(&abs);
		break;
	case 3://3.删除联系人

		//此联系人是否存在
	/*{
		cout << "请输入要删除的联系人姓名： " << endl;
		string name;
		cin >> name;

		if (isExit(&abs, name) == -1)
		{
				cout << "查无此人" << endl;
		}
			
		else
		{
				cout << "找到此人" << endl;
		}
	}*/
		deletePerson(&abs);
		break;
	case 4://4.查找联系人
		findPerson(&abs);
		break;
	case 5://5.修改联系人
		modifyPerson(&abs);
		break;
	case 6://6.清空联系人
		cleanPerson(&abs);
		break;
	case 0://0.退出通讯录
		cout << "欢迎您下次使用" << endl;
		system("pause");
		break;	
	default:
		break;
	}
	}
	system("pause");
	return 0;
}