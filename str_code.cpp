#include <iostream>
#include <string>
#include <codecvt> // codecvt_utf8
#include <locale>  // wstring_convert

using namespace std;
/*
* ���ֽ�תutf8
*/
string wstring_2_utf8(wstring& wide_string) {
    static wstring_convert<std::codecvt_utf8<wchar_t>> utf8_conv;
    return utf8_conv.to_bytes(wide_string);
}

/*
* uft8ת���ֽ�
*/
wstring wstring_from_utf8(string& bype_string) {
    static std::wstring_convert<std::codecvt_utf8<wchar_t>> utf8_conv;
    return utf8_conv.from_bytes(bype_string);
}


string StringToUTF8( string& gbkData)
{
    const char* GBK_LOCALE_NAME = "CHS";  //GBK��windows�µ�locale name(.936, CHS ), linux�µ�locale��������"zh_CN.GBK"
    std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>>
        conv(new std::codecvt<wchar_t, char, mbstate_t>(GBK_LOCALE_NAME));
    std::wstring wString = conv.from_bytes(gbkData);    // string => wstring
    std::wstring_convert<std::codecvt_utf8<wchar_t>> convert;
    std::string utf8str = convert.to_bytes(wString);     // wstring => utf-8
    return utf8str;
}

/*
* ���ֽ�ת���ֽ�
* �������᷵��new�����outStr����Ҫ�ֶ�����delete[]�ͷ��ڴ�.
*/
void _CA2W(wchar_t** outStr, size_t& outLen, const char* inStr, int inLen)
{
    size_t len = inLen + 1;
    size_t converted = 0;
    *outStr = new wchar_t[len * sizeof(wchar_t)];
    mbstowcs_s(&converted, *outStr, len, inStr, _TRUNCATE);
    outLen = converted;
    (*outStr)[len - 1] = L'\0';
}

/*
* ���ֽ�ת���ֽ�
* �������᷵��new�����outStr����Ҫ�ֶ�����delete[]�ͷ��ڴ�.
*/
void _W2CA(char** outStr, size_t& outLen, const wchar_t* inStr, int inLen)
{
    size_t len = inLen + 1;
    size_t converted = 0;
    *outStr = new char[len * sizeof(char)];
    wcstombs_s(&converted, *outStr, len, inStr, _TRUNCATE);
    outLen = converted;
    (*outStr)[len - 1] = '\0';
}
   
