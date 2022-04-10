#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void func(char* p, int x){
    printf("p is \"%s\" and x is %i\n",p,x);
}

int main(){
    
    printf("Hello World!\n");

    //1166
    char* f = "Hello";
    char* s = "World";
    //1172
    printf("%s %s!\n",f,s);

    func("foo",10);
}