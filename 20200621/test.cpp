#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <vector>
using namespace std;

void test() {
	ifstream fin("test.txt");
	if (!fin.is_open()) {
		cout << "打开文件失败" << endl;
	}
	char str[100];
	/*fin >> str;
	cout << str << endl;*/
	fin.getline(str, 3);
	cout << str << endl;

}

void test2() {
	ofstream fout("new.test.txt");
	if (!fout.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}
	fout << "123456 567" << endl;
	fout.close();
	ifstream fin("new.test.txt");
	if (!fin.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}
	char str[100];
	fin >> str;
	cout << str << endl;
	fin.clear();
	fin >> str;
	cout << str << endl;
	fin.close();
}
struct Student {

	int _age;
	char _name[40];
};
//二进制文件读写:效率高.读写性差
void writeFile(const char* filename) {
	ofstream fout(filename);
	if (!fout.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}
	Student st;
	st._age = 20;
	strcpy(st._name, "zhangxiaoyin");
	fout.write((char*)&st, sizeof(Student));
	fout.close();
}
void readFile(const char* filename) {
	ifstream fin(filename);
	if (!fin.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}
	Student st;
	fin.read((char*)&st, sizeof(Student));
	fin.close();
}

//文本文件读写:效率低.读写性好
void writeTxtFile(const char* filename) {
	ofstream fout(filename);
	if (!fout.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}
	Student st;
	st._age = 20;
	strcpy(st._name, "zhangxiaoyin");
	fout << st._age << endl;
	fout << st._name << endl;
	fout.close();
}
void readTxtFile(const char* filename) {
	ifstream fin(filename);
	if (!fin.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}
	Student st;
	fin >> st._age;
	fin >> st._name;
	fin.close();
}
void test3() {
	/*writeFile("test.binary.txt");
	readFile("test.binary.txt");*/

	writeTxtFile("test.text.txt");
	readTxtFile("test.text.txt");
}
void test4()
{
	char str[100];
	itoa(100, str, 10);
	itoa(100, str, 16);
	itoa(100, str, 2);
	itoa(100, str, 8);

	sprintf(str, "%d", 100);
	float f = 1.2;
	sprintf(str, "%0.1f", f);
	//把非字符串数据转成字符串形式的数据
	stringstream ss;
	ss << f;
	string ret = ss.str();
	cout << ret << endl;
	int a = 120;
	//ss.str("");  
	ss.clear();  //clear: 情况流中的状态位
	ss << "123\n";
	ss << a;
	ret = ss.str();  
	ss >> ret;
	cout << ret << endl;
}
int main() {
	test3();
	return 0;
}