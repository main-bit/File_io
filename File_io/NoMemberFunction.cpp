#include "LFile.h"

using namespace std;
using namespace Lin;


std::ostream& Lin::operator<<(std::ostream& _s, const Lin::LDate& _date)
{
	return _s << "[" << _date.ToString() << "]";
}

string Lin::IntToString(const int _number)
{
	if (_number < 10)
		return std::to_string(0) += std::to_string(_number);
	else
		return std::to_string(_number);
}

inline LDateStyle Lin::GetDateStyle()	noexcept
{
	return LDate::g_style;
}

inline void Lin::SetDateStyle(LDateStyle _style)	noexcept
{
	LDate::g_style = _style;
}

void Lin::LWriteFile(Lin::LFile* _pFile, const string& _Info, ios_base::openmode _Mode)
{
	_pFile->Write(_Info, _Mode);
}

string Lin::LReadFileLine(Lin::LFile* _pFile, unsigned int _len, ios_base::openmode _Mode)
{
	LFile::BeginRead(_pFile, _Mode);
	string str = _pFile->Read(_len, _Mode);
	LFile::EndRead(_pFile);
	return str;
}

string Lin::LReadFileLinePlus(Lin::LFile* _pFile, unsigned int _len, ios_base::openmode _Mode)
{
	return _pFile->Read(_len, _Mode);
}

void Lin::LReadFileAll(Lin::LFile* _pFile, std::ios_base::openmode _Mode)
{
	_pFile->ReadAll(_Mode);
}