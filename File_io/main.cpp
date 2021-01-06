#include "LFile.h"
using namespace Lin;
using namespace std;

int main()
{
	LDate time1;
	cout << "��ǰʱ�䣺" << time1 << endl << "��ȴ�2��..." << endl;
	Sleep(2000);
	LDate time2;
	cout << LPackage("��ǰʱ�䣺", time2);
	cout << LPackage("ʱ��", time2 - time1);

	//���ļ�
	LFile* pFile1 = LFile::AddToFilePool("test1.txt");
	LFile* pFile2 = LFile::AddToFilePool("test2.txt");

	//���ļ�д������
	cout << "���ļ�д������..." << endl;
	LWriteFile(pFile1, "this is test1.txt");
	LFile::BeginWrite(pFile2);
	for (int i = 0; i < 10; ++i)
		pFile2 << LPackage(time2, i, "this is test2.txt");		//��text2.txtд��10������
	LFile::EndWrite(pFile2);


	cout << "���ļ��ж�ȡ���ݣ���ȴ�2��..." << endl;
	Sleep(2000);
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

	cout << "text2.txt�ļ��������ݣ�" << endl << "��ȴ�2��..." << endl;
	Sleep(2000);
	LReadFileAll(pFile2);			//��ȡ�ļ�ȫ������

	LFile::MoveOutFilePool("D:\\360\\test1.txt");
	LFile::MoveOutFilePool("D:\\360\\test2.txt");
	return 0;
}