#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

unsigned bitsNCount(unsigned count, unsigned bitscnt, ...);

int main()
{
   bitsNCount(4, 2, 0x0a, 0xff, 0, 1);
   bitsNCount(3, 8, 0xff, 0x13f1, 0xaaaa);
   bitsNCount(5, 10, 0x0a, 0xa0ff, 0, 10, 0b101111111);

    return 0;
}

unsigned bitsNCount(unsigned count, unsigned bitscnt,...){

int cnt = 0;
va_list args;
va_start(args,count);

    for (int i = 0; i < count; i++){
        
    
             int bit = 1;
             int lastbit=0;
             int onescnt = 0;
             

             int args1 = va_arg(args, int);

             while(args1!=0){

                 lastbit = args1 & bit;

                 if (lastbit == 1){
                     onescnt++;
                 }

               args1 = args1 >> 1;

            if (onescnt >= bitscnt){
                cnt++;
            }
             }
             }
             printf("%d\n", cnt);
    
        va_end(args);
}
