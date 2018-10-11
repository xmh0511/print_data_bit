#include <iostream>
#include <vector>
#include <string>
bool is_big()
{
    int c = 1;
    const char* ptr = (char*)&c;
    if(*ptr){
        return false;
    }
    return true;
}
std::string printbit(const char* src,std::size_t n)
{
    std::vector<char> buff;
    if(is_big()){  //大端
        for(std::size_t i = 0;i<n;i++){
            buff.push_back(*src);
            ++src;
        }
    }else{ //小端
        src = src+n-1;
        for(std::size_t i = 0;i<n;i++){
            buff.push_back(*src);
            src--;
        }
    }

    std::string bit_show;
    for(auto& iter:buff)
    {
        char c = 1;
        for(int count=1;count <= 8;count++){
            char tmp = iter >> (8-count);
            tmp = (tmp & c) + '0';
            bit_show.append({tmp});
        }
        bit_show.append(" ");
    }
    return bit_show;
}

template<typename T>
std::string printbit(std::vector<T> v)
{
    std::string result;
    for(auto& iter:v)
    {
        auto r = printbit((char*)&iter, sizeof(T));
        result.append(r);
        result.append(" ");
    }
    return result;
}
template<typename T>
std::string printbit(T t)  //内置类型 二进制显示
{
    auto r = printbit((char*)&t, sizeof(T));
    return r;
}
int main()
{
//    char c = 2;
    std::vector<char> test = {'0','1','2','3'};
    std::cout<<printbit(test)<<std::endl;

    char c = 128;
    std::cout<<int(c)<<std::endl;
    std::cout<<printbit(int(c))<<std::endl;

    return 0;
}