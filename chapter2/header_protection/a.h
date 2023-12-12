//在B和C中都包含了A，如果没有头文件保护，那么在编译B时，会先编译A，然后编译B，这时候i会被定义两次，编译器会报错
#ifndef A_H
#define A_H
int i;
#endif 