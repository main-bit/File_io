#include "LFile.h"
using namespace Lin;
using namespace std;

int main()
{

#pragma region 时间测试
	LDate time1;
	cout << "当前时间：" << time1 << endl << "按回车键继续..." << endl;
	getchar();
	LDate time2;
	cout << LPackage("当前时间：", time2);
	cout << LPackage("2个时间差：", time2 - time1);
#pragma endregion

	cout << "按回车键继续..." << endl;
	getchar();

	//打开文件
	LFile* pFile1 = LFile::AddToFilePool("test1.txt");
	LFile* pFile2 = LFile::AddToFilePool("test2.txt");

#pragma region 向文件写入数据
	cout << "向文件写入数据..." << endl;
	LWriteFile(pFile1, "this is test1.txt");
	LFile::BeginWrite(pFile2);
	for (int i = 0; i < 10; ++i)
		pFile2 << LPackage(time2, i, "this is test2.txt");		//向text2.txt写入10行数据
	LFile::EndWrite(pFile2);
#pragma endregion

	cout << "从文件中读取数据，按回车键继续..." << endl;
	getchar();

#pragma region 读取文件指定行数的内容
	string line4 = LReadFileLine(pFile2, 4);			//读取文件第4行内容
	cout << LPackage("test2.txt文件第4行内容：", line4);
	LFile::BeginRead(pFile2);
	string line5 = LReadFileLinePlus(pFile2, 5);
	string line7 = LReadFileLinePlus(pFile2, 7);
	string line9 = LReadFileLinePlus(pFile2, 9);		//读取文件5，7，9行数据
	LFile::EndRead(pFile2);
	cout << LPackage("text2.txt文件第5行内容：", line5);
	cout << LPackage("text2.txt文件第7行内容：", line7);
	cout << LPackage("text2.txt文件第9行内容：", line9);
#pragma endregion

	cout << "text2.txt文件所有内容：" << endl << "按回车键继续..." << endl;
	getchar();

#pragma region 读取文件所有内容并使用cout打印
	LReadFileAll(pFile2);			//读取文件全部内容并在控制台上打印
#pragma endregion

	cout << "读取文件存入vector中在打印" << endl << "按回车键继续..." << endl;
	getchar();

#pragma region 读取数据存入vector容器并打印
	vector<string> Vector;
	LReadFileAll(pFile1, Vector);
	cout << "text1.txt文件所有内容（存入vector再打印）：" << endl;
	for (auto item : Vector)
	{
		cout << item << endl;
	}

	Vector.clear();
	cout << "text2.txt文件所有内容（存入vector再打印）：" << endl;
	LReadFileAll(pFile2, Vector);
	for (auto item : Vector)
	{
		cout << item << endl;
	}
#pragma endregion


	LFile::MoveOutFilePool("D:\\360\\test1.txt");
	LFile::MoveOutFilePool("D:\\360\\test2.txt");
	return 0;
}