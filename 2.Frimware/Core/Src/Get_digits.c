#include <main.h>
#include <math.h>

//==================================================================
//函 数 名：Get_digits
//功能描述：将浮点数类型的数据取小数点后几位
//输入参数：float Input:输入所需处理的浮点数;float Digits：需要得到后面第几位
//返 回 值：Out
//作    者：蒋欣桐
//日    期：2022/12/05
//版    本：0.0
//==================================================================
int Get_digits(float Input, float Digits)
{
    float Temp;
    float Ten=10;
    uint32_t Out=0;

    Temp=pow(Ten,Digits);
    Temp=Input*Temp;
    Out=(int)Temp/1%10;

    return Out;
}
