int a[] = {1,2,3,4};
    printf("%d\n",sizeof(a));//16  整个数组的字长
    printf("%d\n",sizeof(a+0));//4  第一个元素地址的字长
    printf("%d\n",sizeof(*a)); //4 *a==*(a+0)==a[0] 第一个元素的字长
    printf("%d\n",sizeof(a+1));//4  第二个元素的地址
    printf("%d\n",sizeof(a[1]));//4  第二个元素地址字长
    printf("%d\n",sizeof(&a));  //4    整个数组地址的字长(地址是4个字长)
    printf("%d\n",sizeof(*&a)); //16   &a取整个数组地址的地址 然后*(&a)等于*p 表示里面所存的值, 所以是里面值的字长16 
    printf("%d\n",sizeof(&a+1));//4 跳过此数组后的地址的字长
    printf("%d\n",sizeof(&a[0]));//4 第1个元素的地址字长
    printf("%d\n",sizeof(&a[0]+1));//4 第二个元素的地址字长
char arr[] = {'a','b','c','d','e','f'};

printf("%d\n", strlen(arr));//随机值   首元素地址往后数数组有\0才表示结束 这里不知道在哪结束

 printf("%d\n", strlen(arr+0));//随机值

 printf("%d\n", strlen(*arr));//err    strlen(这里面传的是地址呀) 

 // *arr解引用后是一个值"a"的ASII(98) 98这个地址你是不能随便访问的

 printf("%d\n", strlen(arr[1]));//err   同上不过换成b的ASII码

 printf("%d\n", strlen(&arr));//随机值    这里是整个数组的地址,不过也是首个元素的地址

printf("%d\n", strlen(&arr+1));//随机值   从整个数组地址+1后的地址开始往后数

 printf("%d\n", strlen(&arr[0]+1));       //随机值从第二个元素的地址开始往后数

printf("%d\n", sizeof(arr));//6       一个 char 1个字节  sizof(单独的数组名表示整个数组长度)

printf("%d\n", sizeof(arr+0));//4     a首元素的地址 4个字节

printf("%d\n", sizeof(*arr));//1       解引用 表示第一个元素'a' 长度是1

printf("%d\n", sizeof(arr[1]));//1      同上 不过是'b'

printf("%d\n", sizeof(&arr));//4         整个数组的地址 ,地址长度4个字节

printf("%d\n", sizeof(&arr+1));//4           整个数组的地址后面一个地址的 地址长度

printf("%d\n", sizeof(&arr[0]+1));//4       第二个元素地址的长度 
char arr[] = "abcdef";

printf("%d\n", strlen(arr));//6     //字符串默认后面有\0   表示首元素地址往后数

printf("%d\n", strlen(arr+0));//6     和上面一样  注意strlen 和size of的区别!!!

printf("%d\n", strlen(*arr));//err     错  不可能访问的内存地址

printf("%d\n", strlen(arr[1]));//err   错  同上

printf("%d\n", strlen(&arr));//6          整个元素的地址     其实也是第一个元素的地址 数到\0 刚好6个

printf("%d\n", strlen(&arr+1));//随机值   跳出数组地址了(也跳出了\0)

printf("%d\n", strlen(&arr[0]+1));//5   从第二个元素地址开始数 数到\0 5个

 printf("%d\n", sizeof(arr));//7          全部字长字符串默认包含 \0

 printf("%d\n", sizeof(arr+0));//4      首地址

 printf("%d\n", sizeof(*arr));//1       'a'

 printf("%d\n", sizeof(arr[1]));//1   ' b'

 printf("%d\n", sizeof(&arr));//4       整个数组的地址 的地址字长

 printf("%d\n", sizeof(&arr+1));//4     整个数组的地址下一个地址 的地址字长

 printf("%d\n", sizeof(&arr[0]+1));//4    'b'的地址 的字长  4个