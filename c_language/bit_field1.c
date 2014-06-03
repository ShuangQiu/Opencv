//http://ivanf8e62.iteye.com/blog/1323534
//2014-06-03
//shaokc
int main(void) {  
     struct  x_entry {  
           unsigned int  type:2;  
           unsigned int :2;   //跳过int中的2个位  
           unsigned int  omg:4;  
           unsigned int :0;          //作为位边界, 下面的字段会存放到下一个int中  
           unsigned int newBit:2;  
     }; 

     struct x_entry  s_entry;  
     unsigned int *prt = (unsigned int*) &s_entry; //这里将prt指向s_entry,所以可以把一个整数值设置给prt指向的位置, 最终可以看出位字段在内存中的关系.  
     *prt = 35 ; // 35 = 0010 0011   
     printf("s_entry.type=%i, s_entry.omg=%i\n", s_entry.type, s_entry.omg); //结果为s_entry.type=3,s_entry.omg=2   这是在我的机器上的结果,赋值顺序是从左到右  
     //这里对prt下一位进行操作,将操作到newBit的内存,原因是因为那个0长度的无名字段.  
     *(prt + 1) = 3; // 3= 0000 0011  
     printf("s_entry.newBit=%i", s_entry.newBit); //值为3  
     printf("s_entry.type=%i, s_entry.omg=%i\n", s_entry.type, s_entry.omg); //结果为s_entry.type=3,s_entry.omg=2   这是在我的机器上的结果,赋值顺序是从左到右  
}
