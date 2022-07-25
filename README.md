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
        
        
        
        
        
# PY运行结果

当为8bit时


![image](https://user-images.githubusercontent.com/75195549/179913684-1daf638a-d713-4787-99d7-1a0ead4e6456.png)


当为24bit时


![image](https://user-images.githubusercontent.com/75195549/179913755-3a8ddf84-9df3-4a85-bcc6-d042b369cab4.png)




当为32bit时



![image](https://user-images.githubusercontent.com/75195549/179913847-d0e58925-c4b9-428d-adef-28dc7f8482b2.png)




# C++运行结果

![image](https://user-images.githubusercontent.com/75195549/180800968-10396aca-6bf7-4593-ad79-4d2d214c9e7b.png)



