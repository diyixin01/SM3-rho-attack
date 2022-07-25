#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<string>
int Collisionlen = 24;

int SM3_RhoAttack()
{
    uint mask = (int)pow(2,Collisionlen)-1;
    uint m = rand()&mask;
    uchar h1[SM3_OUTLEN];
    uchar h2[SM3_OUTLEN];
    SM3(to_string(m),h1);
    SM3(h1,SM3_OUTLEN,h2);
    while(true)
    {
        SM3(h1,SM3_OUTLEN,h1);

        SM3(h2,SM3_OUTLEN,h2);
        SM3(h2,SM3_OUTLEN,h2);
        if(!memcmp(h1,h2,Collisionlen/8))
        {
            cout<<"find"<<Collisionlen<<"bit collision"<<endl;
               cout<<"hash1:";
            print_Hashvalue(h1,SM3_OUTLEN);
            cout<<"hash2:";
            print_Hashvalue(h2,SM3_OUTLEN);
            return 0;
        }
    }
    return 1;
}

int main()
{
    srand(time(NULL)); //初始随机数会直接影响到找到环路的时间，好的时候只需要几秒，不好的时候要几分钟（对于24bit，32bit要更久）
    clock_t start,end;//定义clock_t变量
    start = clock();  //开始时间
    SM3_RhoAttack();
    end = clock();   //结束时间
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;  //输出时间（单位：ｓ）
    return 0;
}
   
