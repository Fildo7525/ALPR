#include <stdio.h>
#include <stdlib.h>
/*
* Filip Lobpreis, 111124, cvicenie 1
*/

void pr1();
void pr2();
void pr3();
void pr4();
void pr5();
void pr6();

int main()
{
    pr1();
    pr2();
    pr3();
    pr4();
    pr5();
    pr6();
    return 0;
}
void pr1(){
    printf("\t\\*/\"Toto\" je na \'100%%\' zarucene\\*/\n\n");
}

void pr2(){
    int a, b, c;
    printf("Zadajte 3 cisla rozdelene medzerou:\n");
    scanf("%d %d %d", &a, &b, &c);
    printf("Vysledok %d x %d x %d je %d\n\n", a, b, c, a*b*c);
}

void pr3(){
    float r;
    printf("Zadajte jedno cislo:\n");
    scanf("%f",&r);
    printf("Kruh s polomerom %f: obvod = %f, obsah = %f\n\n", r, r*2*3.14, 3.14*r*r);
}

void pr4(){
    float k,l,m;
    printf("Zadajte tri realne cisla oddelene medzerami:\n");
    scanf("%f %f %f",&k,&l,&m);
    printf("Priemer cisel %f %f %f je %f\n\n",k,l,m,(k+l+m)/3.0);
}

void pr5(){
    int a;
    printf("Zadaj cislo: \n");
    scanf("%d",&a);
    float dph = 1.2*a;
    printf("Cena bez dane: %d\nPredajna cena s danou 20%%: %.2f\n\n",a,dph);
}

void pr6(){
    float m, kg,bmi;
    printf("Zadajte vysku v centimetroch: ");
    scanf("%f",&m);
    m/=100;
    printf("Zadajte hmotnost v kilogramoch: ");
    scanf("%f",&kg);
    bmi = kg/(m*m);
    printf("BMI: %f",bmi);
}
