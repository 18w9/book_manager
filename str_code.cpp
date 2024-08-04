#include <iostream>
#include <string>
#include <codecvt> // codecvt_utf8
#include <locale>  // wstring_convert

using namespace std;
/*
* 宽字节转utf8
*/
string wstring_2_utf8(wstring& wide_string) {
    static wstring_convert<std::codecvt_utf8<wchar_t>> utf8_conv;
    return utf8_conv.to_bytes(wide_string);
}

/*
* uft8转宽字节
*/
wstring wstring_from_utf8(string& bype_string) {
    static std::wstring_convert<std::codecvt_utf8<wchar_t>> utf8_conv;
    return utf8_conv.from_bytes(bype_string);
}


string StringToUTF8( string& gbkData)
{
    const char* GBK_LOCALE_NAME = "CHS";  //GBK在windows下的locale name(.936, CHS ), linux下的locale名可能是"zh_CN.GBK"
    std::wstring_convert<std::codecvt<wchar_t, char, mbstate_t>>
        conv(new std::codecvt<wchar_t, char, mbstate_t>(GBK_LOCALE_NAME));
    std::wstring wString = conv.from_bytes(gbkData);    // string => wstring
    std::wstring_convert<std::codecvt_utf8<wchar_t>> convert;
    std::string utf8str = convert.to_bytes(wString);     // wstring => utf-8
    return utf8str;
}

/*
* 多字节转宽字节
* 本函数会返回new分配的outStr，需要手动调用delete[]释放内存.
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
* 宽字节转多字节
* 本函数会返回new分配的outStr，需要手动调用delete[]释放内存.
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
   
