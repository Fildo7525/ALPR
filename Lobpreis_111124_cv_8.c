#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void pr1();
void pr2();
void strinsert(char s[], int d, char s2[], int i);
void pr4();
int *Alokuj(int n);
void Napln(int pole[],int n);
void Vypis(int *pole,int n);
void riadok(int r,  char sriadok[]);
void frprint(FILE *f,char *str,int d);
void replace_all_spaces(char *str,char c);

int main(){
    pr1();
    // pr2();
    // char str[3][10]={"priradi","nepriradi","priradi"},str2[500];
    // int idxs[3] = {1,500,250};
    // for(int j=0;j<3;j++){
    //     strinsert(str2, 500, str[j], idxs[j]);
    // }
    // pr4();
}
void pr1(){
    FILE *fr;
    int PISMENA = 0,c,riadok = 0, *ZNAKY=NULL;
    if((fr = fopen("vstup.txt","r"))==NULL){
        printf("Subor sa nepodarilo otvorit.\n");
        exit(1);
    }
    while((c = fgetc(fr))!=EOF){
        if(c>='A' && c<='Z')PISMENA++;
    }
    rewind(fr);
    if((ZNAKY = (int *)malloc(PISMENA*sizeof(int)))==NULL){
        printf("Nepodarilo sa alokovat pamat.\n");
        fclose(fr);
        exit(1);
    }
    ZNAKY+=PISMENA-1;
    
    while((c = fgetc(fr))!=EOF){
        if(c>='A' && c<='Z'){
            *ZNAKY = c;
            ZNAKY--;
        }
    }
    fclose(fr);
    c = 0;

    for(int i = 0;i<=PISMENA;i+=3){
        if(c==0)c++;
        else if(riadok==20){
            printf("\n%c",ZNAKY[i]);
            riadok = 1;
        }
        else{
            printf("%c",ZNAKY[i]);
            riadok++;
        }
    }
    putchar('\n');
    free(ZNAKY);
    ZNAKY = NULL;
}
void pr2(){
    int N,*p=NULL;
    printf("Zadajte cele cislo: ");
    scanf("%d",&N);
    if((p = Alokuj(N))==NULL){printf("Nepodatrilo sa pridelit pamat.\n");exit(1);}
    Napln(p,N);
    Vypis(p,N);
    free(p);
    p=NULL;
}
void strinsert(char s[], int d, char s2[], int i){
    if(d<(i+strlen(s2)))printf("Retazec sa nepodarilo priradit na %d. poziciu.\n",i);
    else{
        strcpy((s+i),s2);
        printf("%s\n",s+i);
    }
}
void pr4(){
    FILE *fr,*fw;
    int c,riadok_n = 1;
    char str[40],rstr[4];
    if((fr = fopen("vstup.txt","r"))==NULL){
        printf("Subor sa nepodarilo otvorit.\n");
        exit(1);
    }
    if((fw = fopen("vystup.txt","w"))==NULL){
        printf("Subor sa nepodarilo otvorit.\n");
        fclose(fr);
        exit(1);
    }
    while(fgets(str,80,fr)){
        riadok(riadok_n,rstr);
        fprintf(fw,"%3s ",rstr);
        if(riadok_n%2 == 0){
            if(riadok_n%3 == 0){
                replace_all_spaces(str,'*');
            }
            frprint(fw,str,strlen(str));
        }
        else{
            if(riadok_n%3 == 0){
                replace_all_spaces(str,'*');
            }
            fprintf(fw,"%s",str);
        }
        riadok_n++;
        if(*str==EOF)exit(1);
    }
        printf("Dalsi");
    fclose(fr);
    fclose(fw);
}
int *Alokuj(int n){
    return ((int *)malloc(n*sizeof(int)));
}
void Napln(int pole[],int n){
    for(int i = 0; i<n;i++){
        pole[i] = i+1;
    }
}
void Vypis(int *pole,int n){
    int i =0;
    while(i<n){
        printf("%d ",*(pole+i++));
    }
    printf("\n");
}
void riadok(int r, char sriadok[]){
    if(r<=0){printf("Riadok je zaporny alebo nulovy.\n");exit(1);}
    strcpy(sriadok,"000");
    char pomoc[3]="";
    int idx = 0;
    sprintf(pomoc,"%d",r);
    if(r<10)idx=2;
    else if(r>9 && r<100)idx=1;
    else idx=0;
    strinsert(sriadok,3,pomoc,idx);
}
void frprint(FILE *f,char *str,int d){
    for(int i=d-2;i>=0;i--){
        fputc(str[i],f);
    }
    fputc('\n',f);
}
void replace_all_spaces(char *str,char c){
    int i = 0;
    while(str[i]!='\0'){
        if(str[i]==' '){
            str[i]=c;
        }
        i++;
    }
}