#include<stdio.h>
#include<stdlib.h>

/*
Filip Lobpreis, 111124 cvicenie c.3
*/

void pr1();
void pr2();
void pr3();
void pr4();
void pr5();
void pr6();
void pr7();

int main()
{
    pr1();
    //pr2();
    //pr3();

    printf("==================\n");
    //Nepovinne

    //pr4();
    //pr5();
    //pr6();
    //pr7();
}

void pr1(){
    int a, neg = 0;
    float n, max_n = -10000, min_n = 10000, avg_n = 0;
    printf("Zadajte pocet realnych cisel: ");
    scanf("%d",&a);
    for (int i = 1; i<=a;i++){
        printf("Zadajte %d.: ",i);
        scanf("%f",&n);
        printf("%f\n",n);
        if(n>max_n)max_n = n;
        if(n<min_n)min_n = n;
        if(n<0)neg++;
        avg_n+=n;
        printf("Minimum: %.2f\nMaximum: %.2f\nPriemer: %.2f\nZaporne: %f\n",min_n,max_n,avg_n/i,neg);
    }
    printf("Minimum: %.2f\nMaximum: %.2f\nPriemer: %.2f\nZaporne: %f\n",min_n,max_n,avg_n/a,neg);
}
void pr2(){
    int a, n, parne = 0, kladne = 0, sucin = 1;
    printf("Zadajte pocet celych cisel: ");
    scanf("%d",&a);
    for (int i = 1; i<=a;i++){
        printf("Zadajte %d.: ",i);
        scanf("%d",&n);
        if(n%2==0)parne++;
        if(n>0)kladne++;
        sucin*=n;
    }
    printf("Parne: %d\nKladne: %d\nSucin: %d\n",parne,kladne,sucin);
}
void pr3(){
    char c;
    int flag = 1, low = 0, upper = 0, num = 0, spec = 0;
    printf("Zadajte retazec: ");
    do{
        c = getchar();
        if(c == ' ') flag = 0;
        else{
            if(c>='a' && c<='z') low++;
            if(c>='A' && c<='Z') upper++;
            if(c>='0' && c<='9') num++;
            switch(c){
                case '*':
                case '+':
                case '/':
                case '-':
                    spec++;
                default:
                    continue;
            }
        }
    }while(flag);
    printf("Pocet malych pismen je %d\nPocet velkych pismen je %d\nPocet cislic je %d\nPocet specialnych je %d\n",low,upper,num,spec);
}
void pr4(){
    char ent;
    int f, g;
    printf("Zadajte hranice interalu: ");
    ent = getchar();
    scanf("%d %d",&f,&g);
    int i = f;
    printf("V intervale <%d, %d> su delitelne 3mi:",f,g);
    while(i <= g){
        if(i%3 == 0){
            printf(" %d",i);
            i+=3;
        }
        else if(i%3 == 1)i+=2;
        else i++;
    }
    printf("\n");
}
void pr5(){
    int f, g, d;
    printf("Zadajte hranice interalu a delitel: ");
    scanf("%d %d %d",&f,&g, &d);
    int i = f;
    printf("V intervale <%d, %d> su delitelne %dmi:",f,g,d);
    while(i <= g){
        if(i%d == 0){
            printf(" %d",i);
            i+=d;
        }
        else i++;
    }
    printf("\n");
}
void pr6(){
    float a,b;
    char c,ent;
    int flag = 1;
    printf("Zadajte dve realne cisla: ");
    scanf("%f %f",&a, &b);
    do{
        ent = getchar();
        printf("Zadajte operaciu: ");
        scanf("%c",&c);
        switch(c){
            case('*'):
                printf("Vysledok %f * %f je %f\n",a,b,a*b);
                break;
            case('/'):
                printf("Vysledok %f / %f je %f\n",a,b,a/b);
                break;
            case('+'):
                printf("Vysledok %f + %f je %f\n",a,b,a+b);
                break;
            case('-'):
                printf("Vysledok %f - %f je %f\n",a,b,a-b);
                break;
            case('%'):
                printf("Vysledok %f %% %f je %f\n",a,b,(int)a%(int)b);
                break;
            case('a'):
                printf("Autorom programu je Filip Lobpreis\n");
                break;
            default:
                flag = 0;
        }
    }while(flag);
    printf("Koniec\n");
}
void pr7(){
    float m, kg,bmi;
    int podv = 0,norm = 0,nadv = 0,obez = 0;
    for(int i = 0; i<3; i++){
        printf("Zadajte vysku v centimetroch a hmotnost v kilogramoch oddelenych medzerou pre %d. osobu: ",i+1);
        scanf("%f %f",&m, &kg);
        //m = 58;
        //kg = 89;
        m/=100;
        bmi = kg/(m*m);
        if(bmi<=18.5) podv++;
        else if(bmi<=25)norm++;
        else if(bmi<=30)nadv++;
        else obez++;   
    }
    printf("Statistika:\nPodvaha: %d\nNormalna hmotnost: %d\nNadvaha: %d\nObezita: %d\n",podv,norm,nadv,obez);
}
