#include<stdio.h>
#include<stdlib.h>

/*
Filip Lobpreis, 111124, cvicenie 2
*/

void pr1();
void pr2();
void pr3();
void pr4();
void pr5();
void pr6();
void pr7();
void pr8();

int main()
{
    //pr1();
    pr2();
    //pr3();

    //Dalsie priklady su nebodovane
    printf("==================================\n");

    //pr4();
    //pr5();
    //pr6();
    //pr7();
    //pr8();
}

void pr1(){
    int a,b,v,m;
    printf("Zadajte dve realne cisla rozdelene medzerou: ");
    scanf("%d %d",&a,&b);
    v = (a>b)? a:b;
    if(a<b)m = a;
    else m=b;
    printf("a) Vacsie z cisel je: %d \nb) Mensie z cisel je: %d\n",v,m);//(a>b)? a,b:b,a);Toto som spravil ako prve, ale podla zadania je asi to momentalne fungujuce spravne
    
}
void pr2(){
    char c;
    printf("Zadajte jeden znak: ");
    c = getchar();
    if(c>='0' && c<='9') printf("Na vstupe je: cislo\n");
    else if(c >='A' && c <='Z') printf("Na vstupe je: Velke pismeno\n");
    else if(c >= 'a' && c <='z') printf("Na vstupe je: male pismeno\n");
    else printf("Na vstupe je: iny znak\n");
}
void pr3(){
    char c;
    printf("Zadaj jeden znak: ");
    c = getchar();
    if(c >= 97 && c<=122){
        printf("Znak %c ma v ASCII hodnotu %d alebo aj %x Hexa\nMale psimeno bolo zmenene na velke %c,\nktore ma ASCII hodnotu %d alebo %x Hex.\n",c,c,c,toupper(c),toupper(c),toupper(c));
    } else if(c>=65 && c<=90){
        printf("Znak %c ma v ASCII hodnotu %d alebo aj %x Hexa\nVelke psimeno bolo zmenene na male %c,\nktore ma ASCII hodnotu %d alebo %x Hex.\n",c,c,c,tolower(c),tolower(c),tolower(c));
    } else{
        printf("Znak %c ma v ASCII hodnotu %d alebo aj %x Hexa\n",c,c,c);
    }
}
void pr4(){
    float t;
    printf("Zadajte teplotu vo Fahrenheitoch: ");
    scanf("%f",&t);
    t = (t-32)*5/9;
    (t>=100)? printf("Teplota vstupňoch celzia: %.2f\nVrie\n",t):
    (t<=0)? printf("Teplota vstupňoch celzia: %.2f\nMrzne\n",t):
    printf("Teplota vstupňoch celzia: %.2f\n",t);   
}
void pr5(){
    int a,b,c;
    printf("Zadajte tri cele cisla oddelene medzerou: ");
    scanf("%d %d %d",&a,&b,&c);
    if(a<b && a<c){
        printf("Najmensie cislo z %d %d %d je: %d\n",a,b,c,a);
    } else if(b<a && b<c){
        printf("Najmensie cislo z %d %d %d je: %d\n",a,b,c,b);
    } else if(c<b && c<a){
        printf("Najmensie cislo z %d %d %d je: %d\n",a,b,c,c);
    } 
}
void pr6(){
    int a,b,c,min,mid,max;
    printf("Zadajte 3 cele cisla: ");
    scanf("%d %d %d",&a,&b,&c);
    if(a==b || a==c || b==c){
        if(a==b && a==c && b==c)min = a,mid = c, max = b;
        if(a==b && a<c) min = a,mid = b,max = c;
        if(a==c && a<b) min = a,mid = c,max = b;
        if(c==b && c<a) min = b,mid = c,max = a;
        if(a==b && a>c) min = c,mid = a,max = b;
        if(a==c && a>b) min = b,mid = a,max = c;
        if(c==b && c>a) min = a,mid = b,max = c;
    } else{
        if(a>b && a>c) max = a;
        if(b>a && b>c) max = b;
        if(c>a && c>b) max = c;
        if(a<b && a<c) min = a;
        if(b<a && b<c) min = b;
        if(c<a && c<b) min = c;
        if(min == a && max==b) mid = c;
        else if(min==a && max == c) mid = b;
        else if(min == b && max==a) mid = c;
        else if(min==c && max == a) mid = b;
        else mid = a;
    }
    printf("Usporiadany vysledok: %d %d %d\n",min,mid,max);
}
void pr7(){
    char c,d,f;
    printf("Zadajte tri pismena oddelene medzerami: ");
    scanf("%c %c %c",&c, &d, &f);
    if(c==d && c==f && d==f) printf("Vsetky pismena su rovnake\n");
    else if(c!=d && c!=f && d!=f) printf("Vsetky pismena su rozne\n");
    else if(c==d || c==f || d==f) printf("Dve pismena su rovnake\n");
}
void pr8(){
    float m, kg,bmi;
    printf("Zadajte vysku v centimetroch: ");
    scanf("%f",&m);
    m/=100;
    printf("Zadajte hmotnost v kilogramoch: ");
    scanf("%f",&kg);
    bmi = kg/(m*m);
    if(bmi<=18.5) printf("Podvaha\n");
    else if(bmi<=25) printf("Normalna vaha\n");
    else if(bmi<=30) printf("Nadvaha\n");
    else printf("Obezita\n");
}