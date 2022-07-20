# SM3-rho-attack
原理很简单，我们只需要从一个初始值出发，不断计算SM3值，就可能成环（前n bit），在代码中可以参考Floyd判环法：

代码简述：
x=rand()
h1 = SM3(x)
h2 = SM3(h1)
while(true)
    h1=SM3(h1)
    h2=SM3(SM3(h2)) //计算两次，因为如果成环，那么两倍速一定能追上一倍速的
    if h1 == h2:
        break
