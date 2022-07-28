# SM3-rho-attack
原理很简单，我们只需要从一个初始值出发，不断计算SM3值，就可能成环（前n bit），在代码中可以参考Floyd判环法


![image](https://user-images.githubusercontent.com/75195549/180798636-473eb919-4214-4648-b23f-630955c4fc2f.png)




在实验中，我们可以调节碰撞的比特数，8bit时，计算十分快速，而当比特数到达24bit时，受我们添加的随机的字符串的影响就比较大了，有些很快，有些很慢，当比特数到达32bit时，运行就有些缓慢了

# 简要思路
x=rand()


h1 = SM3(x)


h2 = SM3(h1)


while(true)


    h1=SM3(h1)
    
    
    h2=SM3(SM3(h2))
    
    
    if h1 == h2:
    
    
        break
        
      
# 代码分析
# SM3_RhoAttack
首先对h1做hash，然后对h2做两次哈希，如果两次hash相遇，就成为了环


![image](https://user-images.githubusercontent.com/75195549/181446080-18c42e16-df16-461c-b09a-7054c303a58e.png)


# main
一开始的随机数十分重要，随机的不好的话很影响碰撞的时间，随后设置时间变量进行计时。

        
        
![image](https://user-images.githubusercontent.com/75195549/181446458-1cbe6926-3dbc-4db5-8a38-b7a93a80ef38.png)



        
        
# Python运行结果

当为8bit时


![image](https://user-images.githubusercontent.com/75195549/179913684-1daf638a-d713-4787-99d7-1a0ead4e6456.png)


当为24bit时


![image](https://user-images.githubusercontent.com/75195549/179913755-3a8ddf84-9df3-4a85-bcc6-d042b369cab4.png)




当为32bit时



![image](https://user-images.githubusercontent.com/75195549/179913847-d0e58925-c4b9-428d-adef-28dc7f8482b2.png)




# C++运行结果

![image](https://user-images.githubusercontent.com/75195549/181447438-e421ea81-5d2c-42c3-b993-63c75ab06e80.png)


