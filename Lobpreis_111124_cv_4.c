#include<stdio.h>

/*
    Filip Lobpreis
    111124
    Cvicenie 4
    1B_RK/3
*/

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
    return 0;
}

void pr1(){
    int a;
    printf("Zadajte cislo medzi 1 a 9: ");
    scanf("%d",&a);
    if(a>0 && a<10){
        for(int i = 1; i<=a;i++){
            for(int j = i; j<=a;j++){
                printf("%d ",j);
            }
            printf("\n");
        }
    } else{
        printf("Zadali ste zly znak.\n");
    }
}
void pr2(){
    char c,ent,p = 0;
    printf("Zadajte velke pismeno medzi A a Z: ");
    //ent = getchar();
    c = getchar();
    if(c>='A' && c<='Z'){
        for(int i = c; i>='A';i--){
            printf("%d = ",i-64);
            for(int j = c; j>='A'+p;j--){
                printf("%c ",j);
            }
            p++;
            printf("\n");
        }
    } else{
        printf("Zadali ste zle pismeno.\n");
    }
}
void pr3(){
    int a,c = 0;
    printf("Zadajte cislo z intervalu <1,10>: ");
    scanf("%d",&a);
    if(a>=1 && a<=10){
        printf("Floydov trojuholnik pre %d riadkov je:\n",a);
        for(int i = 1; i<=a;i++){
            for(int j = 1;j<=i;j++){
                c++;
                printf("%d ",c);
            }
            printf("\n");
        }
    } else{
        printf("Nespravny vstup\n");
    }
}
void pr4(){
    int r,p = 0;
    printf("Zadajte pocet riadkov ako cislo v intervale (1,15): ");
    scanf("%d",&r);
    if(r>15 || r<1)printf("Cislo nie je z daneho intervalu\n");
    else{
        for(int i = 1; i<=r;i++){
            printf("%2d: ",i);
            for(int j = 1; j<=r-p;j++){
                printf("%2d ",j);
            }
            p++;
            printf("\n");
        }
    }
}
void pr5(){
    int r;
    printf("Zadajte pocet riadkov ako cislo v intervale (1,15): ");
    scanf("%d",&r);
    if(r>15 || r<1)printf("Cislo nie je z daneho intervalu\n");
    else{
        for(int i = r; i>=1;i--){
            printf("%2d: ",i);
            for(int j = i; j>=1;j--){
                printf("%2d ",j);
            }
            printf("\n");
        }
    }
}
void pr6(){
    int k, ans = 1,celk = 0;
    printf("Zadajte cele cislo k v intervale (0,9): ");
    scanf("%d",&k);
    if(k>=0 && k<=9){
        for(ans; ans<=k;ans++){
            celk+=ans;
            if(celk%3 == 0){
                printf("%d",ans);
                if(ans!=k)printf(", ");
            }
        }
        printf("\n");
    } else{
        printf("Nespravny vstup\n");
    }
}
void pr7(){
    int a;
    printf("Zadajte neparne cislo od 1 do 15: ");
    scanf("%d",&a);
    if(a<1 || a>15 || ((a%2)==0)){
        printf("Zly vstup\n");
    } else {
        for(int i = 0;i < a;i++){
            for(int j = 0;j<=i;j++){
                printf("*");
            }
            for(int j = i+1;j<a;j++){
                printf("-");
            }
            printf("\n");
        }
        for(int i = 1;i <= a-1 ;i++){
            for(int j = a-i;j>0;j--){
                printf("*");
            }
            for(int j = 0; j<i;j++){
                printf("-");
            }
            printf("\n");
        }
    }
}
void pr8(){
    int a;
    printf("Zadajte neparne cislo od 1 do 15: ");
    scanf("%d",&a);
    if(a<1 || a>15 || ((a%2)==0)){
        printf("Zly vstup\n");
    } else {
        int middle = (a-1)/2;
        int posun = 0;
        for(int i = 0; i<a;i++){
            if(i < middle || i>middle){
                for(int j= 0;j<a;j++){
                    if(j == 0+posun || j==a-posun-1 || j == middle){
                        printf("*");
                    }
                    else printf("-");
                }
                printf("\n");
            }
            else {
                for(int j = 0;j<a;j++){
                    printf("*");
                }
                printf("\n");
            }
            posun++;
        }
    }
}
void pr9(){
    int a,b;
    printf("Zadajte neparne cislo od 1 do 15 a jedno cele cislo v intervale <1,5>: ");
    scanf("%d %d",&a,&b);
    if( (a<1 || a>15 || ((a%2)==0) ) || (b<1 || b>5)){
        printf("Zly vstup\n");
    } else {
        //v zadani bolo dane ze velkost hviezdy ma byt n*n ale nakreslene molo s tymnto parametrom n
        //v mojom pripade a
        //a = a*2-1;
        int middle = (a-1)/2;
        int posun;
        for(int k =0;k<b;k++){
            posun = 0;
            for(int i = 0; i<a;i++){
                if(i < middle || i>middle){
                    for(int j= 0;j<a;j++){
                        if(j == 0+posun || j==a-posun-1 || j == middle) printf("*");
                        else printf("-");
                    }
                    printf("\n");
                }
                else {
                    for(int j = 0;j<a;j++) printf("*");
                    printf("\n");
                }
                posun++;
            }
        }
    }
}
void pr10(){
    int a,b;
    printf("Zadajte neparne cislo od 1 do 15 a jedno cele cislo v intervale <1,5>: ");
    scanf("%d %d",&a,&b);
    if( (a<1 || a>15 || ((a%2)==0) ) || (b<1 || b>5)){
        printf("Zly vstup\n");
    } else {
        int middle = (a-1)/2;
        int posun = 0;
        for(int i = 0; i<a;i++){
            if(i < middle || i>middle){
                for(int k = 0; k<b;k++){
                    for(int j= 0;j<a;j++){
                        if(j == 0+posun || j==a-posun-1 || j == middle){
                            printf("*");
                        }
                        else printf("-");
                    }
                }
                printf("\n");
            }
            else {
                for(int k = 0; k<b;k++){
                    for(int j = 0;j<a;j++){
                        printf("*");
                    }
                }
                printf("\n");
            }
            posun++;
        }
    }
}
