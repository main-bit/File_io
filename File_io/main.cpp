#include "LFile.h"
using namespace Lin;
using namespace std;

int main()
{

#pragma region ʱ�����
	LDate time1;
	cout << "��ǰʱ�䣺" << time1 << endl << "���س�������..." << endl;
	getchar();
	LDate time2;
	cout << LPackage("��ǰʱ�䣺", time2);
	cout << LPackage("2��ʱ��", time2 - time1);
#pragma endregion

	cout << "���س�������..." << endl;
	getchar();

	//���ļ�
	LFile* pFile1 = LFile::AddToFilePool("test1.txt");
	LFile* pFile2 = LFile::AddToFilePool("test2.txt");

#pragma region ���ļ�д������
	cout << "���ļ�д������..." << endl;
	LWriteFile(pFile1, "this is test1.txt");
	LFile::BeginWrite(pFile2);
	for (int i = 0; i < 10; ++i)
		pFile2 << LPackage(time2, i, "this is test2.txt");		//��text2.txtд��10������
	LFile::EndWrite(pFile2);
#pragma endregion

	cout << "���ļ��ж�ȡ���ݣ����س�������..." << endl;
	getchar();

#pragma region ��ȡ�ļ�ָ������������
	string line4 = LReadFileLine(pFile2, 4);			//��ȡ�ļ���4������
	cout << LPackage("test2.txt�ļ���4�����ݣ�", line4);
	LFile::BeginRead(pFile2);
	string line5 = LReadFileLinePlus(pFile2, 5);
	string line7 = LReadFileLinePlus(pFile2, 7);
	string line9 = LReadFileLinePlus(pFile2, 9);		//��ȡ�ļ�5��7��9������
	LFile::EndRead(pFile2);
	cout << LPackage("text2.txt�ļ���5�����ݣ�", line5);
	cout << LPackage("text2.txt�ļ���7�����ݣ�", line7);
	cout << LPackage("text2.txt�ļ���9�����ݣ�", line9);
#pragma endregion

	cout << "text2.txt�ļ��������ݣ�" << endl << "���س�������..." << endl;
	getchar();

#pragma region ��ȡ�ļ��������ݲ�ʹ��cout��ӡ
	LReadFileAll(pFile2);			//��ȡ�ļ�ȫ�����ݲ��ڿ���̨�ϴ�ӡ
#pragma endregion

	cout << "��ȡ�ļ�����vector���ڴ�ӡ" << endl << "���س�������..." << endl;
	getchar();

#pragma region ��ȡ���ݴ���vector��������ӡ
	vector<string> Vector;
	LReadFileAll(pFile1, Vector);
	cout << "text1.txt�ļ��������ݣ�����vector�ٴ�ӡ����" << endl;
	for (auto item : Vector)
	{
		cout << item << endl;
	}

	Vector.clear();
	cout << "text2.txt�ļ��������ݣ�����vector�ٴ�ӡ����" << endl;
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