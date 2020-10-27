#include<stdio.h>

void pr1();
void pr2();
void pr3();
void pr4();
void pr5();
void pr6();
void pr7();
void pr8();
void pr9();
void pr10();
void pr11();
void pr12();
void pr13();
void pr14();

int main(){
    //pr1();
    //pr2();
    //pr3();
    //pr4();
    //pr5();
    //pr6();
    //pr7();
    //pr8();
    //pr9();
    //pr10();
    //pr11();
    //pr12();
    //pr13();
    //pr14();
    return 0;
}

void pr1(){
    int c;
    FILE* fw;
    printf("Zadajte cele cislo z intervalu 1 az 1000: ");
    scanf("%d",&c);
    if(c<1 || c>1000)printf("Zly vstup.\n");
    else{
        if((fw=fopen("vystup.txt","w"))==NULL)printf("Subor sa neda otvorit.\n");
        else{
            for(int i=1;i<=c;i++)fprintf(fw,"Toto je %d. veta z %d za odmenu\n",i,c);
        }
        fclose(fw);
    }
}
void pr2(){
    int last = 0, c, male = 0, velke = 0, medzery = 0, cisla = 0, riadky = 0, medzery_bonus = 0;
    FILE* fr;
    if((fr=fopen("vstup.txt","r+"))==NULL)printf("Subor sa neda otvorit\n");
    else{
        while((c=fgetc(fr))!=EOF){
            if(c>='a' && c<='z')male++;
            else if(c>='0' && c<='9')cisla++;
            else if(c>='A' && c<='Z')velke++;
            else if (c=='\n')riadky++;
            else{
                if(c==' '){
                    medzery++;
                    if(last==' '){
                        medzery_bonus++;
                    }
                    last = c;
                }
            }
        }
        fclose(fr);
        printf("velke: %d\nmale: %d\ncisla: %d\nriadky: %d\nmedzery: %d\nmedzery_bonus: %d\n",velke,male,cisla,riadky,medzery,medzery-medzery_bonus);
    }
}
void pr3(){
    double num;
    FILE* nasobky;
    if((nasobky = fopen("nasobky.txt","w"))==NULL)printf("Subor sa nepodarilo otvorit.\n");
    else{
        printf("Zadajte jedno realne cislo: ");
        scanf("%lf",&num);
        for(int i = 1;i<=10;i++){
            fprintf(nasobky,"%d * %.2lf = %.2lf\n",i,num,num*i);
        }
        fclose(nasobky);
    }
}
void pr4(){
    char c;
    int p;
    FILE *file1,*file2,*f;
    printf("Zadajte znak: ");
    scanf("%c",&c);
    if((file1=fopen("znak.txt","r"))==NULL)printf("Subor sa nepodatilo otvorit.\n");
    if(c=='s'){
        if((file2 = fopen("novy.txt","w"))==NULL){
            fclose(file1);
            printf("Subor sa nepodarilo otvorit.\n");
        }
        else{
            f = file2;
        }
    }
    else f = stdout;
    while((p = fgetc(file1))!=EOF){
        fputc(p,f);
    }
    if(f!=stdout)fclose(f);
    fclose(file1);
}
void pr5(){
    FILE *one,*two;
    int c,d,diff = 0,iter,rozd = 0;
    long d_1,d_2;
    if((one = fopen("prvy.txt","r"))==NULL) printf("Prvy subor sa nepodarilo otvorit.\n");
    else{
        d_1 = fseek(one,0,SEEK_END);
        d_1 = ftell(one);
        rewind(one);
        if((two = fopen("druhy.txt","r"))==NULL){
            printf("Druhy subor sa nepodarilo otvorit.\n");
            fclose(one);
            
        } else{
            d_2 = fseek(two,0,SEEK_END);
            d_2 = ftell(two);
            rewind(two);
            
            if(d_1 < d_2){
                diff = (int)d_2- (int)d_1;
                iter = (int)d_1;
                printf("Prvy subor je kratsi o %d znakov.\n",diff);
            } else {
                diff = (int)d_1 - (int)d_2;
                iter = (int)d_2;
                printf("Druhy subor je kratsi o %d znakov.\n",diff);
            }
            while (iter>0)
            {
                c = fgetc(one);
                d = fgetc(two);
                iter--;
                if(c!=d){
                    rozd++;
                    //printf("%d. c -%c d - %c\n",c,c,d);
                }
            }
            if(rozd==0)printf("Subory su rovnake.\n");
            else printf("Subory su roddielne v %d pismenach.\n",rozd);
            fclose(one);
            fclose(two);
        }
    }
}
void pr6(){
    int a,b = 0;
    FILE *vstup, *cisla;
    if((vstup=fopen("vstup.txt","r"))==NULL)printf("Subor sa nepodarilo otvorit.\n");
    else{
        if((cisla = fopen("cisla.txt","a+"))==NULL){
            printf("Subor sa nepodarilo otvorit.\n");
            fclose(vstup);
        } else{
            while((a = fgetc(vstup))!=EOF){
                if(a=='\n'){
                    fprintf(cisla,"\n%d\n",b);
                    b=0;
                }
                else{
                    fputc(a,cisla);
                    if(a>='a' && a<='z')b++;
                }
            }
            fclose(vstup);
            fclose(cisla);
        }
    }

}
void pr7(){
    int a,m = 0;
    FILE *t;
    if((t=fopen("text.txt","r"))==NULL)printf("Subor sa nepodarilo otvorit.\n");
    else{
        while((a=fgetc(t))!='*'){
            switch(a){
                case 'x':
                case 'X':
                    printf("Precital som X.\n");
                    break;
                case 'y':
                case 'Y':
                    printf("Precital som Y.\n");
                    break;
                case '#':
                case '&':
                case '$':
                    printf("Precital som riadiaci znak.\n");
                    break;
                case ' ':
                    m++;
                    break;
                default:
                    ;
            }
        }
        printf("Koniec.\nPocet precitanych medzier: %d\n",m);
        fclose(t);
    }
}
void pr8(){
   int a;
   FILE *vy;
   if((vy = fopen("vystup.txt","w"))==NULL)printf("Subor sa neda otvorit.\n");
   else{
       printf("Zadajte znaky: ");
       while((a=getchar())!='*'){
           if(a>='a' && a<='z'){
               a-=('a'-'A');
               fputc(a,vy);
           } else if(a=='\t' || a=='\n'){
               fputc(' ',vy);
           } else if(a>='A' && a<='Z')fputc(a,vy);
           else fputc('-',vy);
       }
       fprintf(vy,"*\n");
       fclose(vy);
   }
}
void pr9(){
    double a ,b;
    int d,e,c = 0,cmp = 1;
    printf("Zadajte dve cele cisla oddelene medzerou: ");
    scanf("%lf %lf",&a,&b);
    d = (int)a;
    e = (int)b;
    a++;
    b++;
    if(((a-d)>cmp) || (((b-e)>cmp)))printf("Neda sa vypocitat.\n");
    else{
        a--;
        b--;
        if(a>b){
            d = a;
            a = b;
            b = d;
        }
        for(int i=(int)a+1;i<(int)b;i++){
            c+=i;
        }
        printf("%d\n",c);
    }
}
void pr10(){
    int a,f = 1;
    printf("Zadajte cele cislo: ");
    scanf("%d",&a);
    if(a<=0)printf("%d",1);
    else{
        for(int i = 1;i<=a;i++)f*=i;
        printf("%d\n",f);
    }

}
void pr11(){
    int a,b;
    printf("Zadajte dve cele cisla: ");
    scanf("%d %d",&a,&b);
    for(int i=1;i<=a;i++){
        if(i%b == 0)printf("-- ");
        else printf("%2d ",i);
    }
    printf("\n");
}
void pr12(){
    int i  = 0;
    while(i<10){
        printf("%d. \n",i+1);
        i++;
    }
}
void pr13(){
    int a,f;
    printf("Zadajte cele cislo z intervalu <0,10>: ");
    scanf("%d",&a);
    if(a<0 || a>10)printf("Zly vstup.\n");
    else{
        int b[a],c[a];
        printf("Zadavajte cele cisla s enterom:\n");
        for(int i = 0;i<a;i++){
            scanf("%d",&b[i]);
            if(i==0){
                c[0]=1;
            }
            else if(b[i]>(2*b[i-1]) || b[i]<(b[i-1]/2)){
                c[i]=0;
                //printf("Postupnost je nespravna.\n");
                //nevedel som ze kde som to mal napisat ci po poruseni pravidla alebo az nakonci
            }
            else c[i] = 1;
        }
        for(int i = 0;i<a;i++){
            if(c[i]==0){
                printf("Postupnost je nespravna.\n");
                f = 0;
                break;
            }
            else f=1;
        }
        if(f)printf("Postupnost je spravna.\n");
    }
}
void pr14(){
    int a,b,c;
    printf("Zadajte tri cele cisla rozdele medzerami: ");
    scanf("%d %d %d",&a,&b,&c);
    for(int x = 0;x<c;x++){
        for(int i = 1;i<=(2*a-1);i++){
            if(i<=a){
                for(int y = 0;y<b;y++){
                    for(int j = 1;j<=i;j++){
                        printf("%d",i);
                    }
                    for(int j= i+1;j<=a;j++){
                        printf("-");
                    }
                }
            } else{
                for(int y = 0;y<b;y++){
                    for(int j=1;j<=(a-(i-a));j++){
                        printf("%d",(a-(i-a)));
                    }
                    for(int j= (a-(i-a))+1;j<=a;j++){
                        printf("-");
                    }
                }
            }
            printf("\n");
        }
    }
}
