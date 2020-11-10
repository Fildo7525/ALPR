#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Nahrady(char *str);
int Vymen(char *s1,char *s2);
void pr3();
void pr4();
void pr5();
void pr3_sifra(char sprava[500],size_t len_s);

int main(){
    char n[500], s1[100], s2[100];    
    int p;     
    printf("zadanie 1:\nretazec pre funkciu nahrady:");     
    scanf("%s",n );
    Nahrady(n);     
    printf("vysledok zadania 1: %s\n", n  );   
    printf("zadanie 2\n");     
    printf("prvy  retazec :");  
    scanf( "%s",  s1 );    
    printf("druhy retazec :");  
    scanf( "%s",  s2);   
    p = Vymen(s1,s2);
    printf("výsledok zadania 2:\n");    
    printf("pocet vymen: %d \n",p);    
    printf("prvy  retazec : %s\n", s1);     
    printf("druhy retazec : %s \n", s2);
    pr3();
    pr4();
    pr5();
    return 0;
}

void Nahrady(char *str){
    int len = 0;
    while(*str != '\0'){
        len++;
        str++;
    }
    str-=len;
    str++;
    for(int i = len;i>=-1;i--){
        if(str[i]=='*'){
            for(int j=i;j<len;j++){
                str[j] = str[j+1];
            }
            len--;
        } else if(str[i] == '.'){
            for(int j=len;j>i;j--){
                str[j+2] = str[j];
            }
            len+=3;
            for(int j = i;j<i+3;j++)str[j] = '$';
        } else continue;
    }
}
int Vymen(char *s1,char *s2){
    int vymeny = 0;
    char temp;
    while(*s1!='\0' && *s2!='\0'){
        temp = *s1;
        *s1 = *s2;
        *s2 = temp;
        vymeny++;
        s1++;
        s2++;
    }
    s1-=(vymeny-1);
    s2-=(vymeny-1);
    return vymeny;
}
void pr3(){
    char key[500],sprava[500];
    size_t len_k,len_s,idx_s = 0,idx_k = 0;
    int rozdiel;
    printf("Zadajte heslo: ");
    scanf("%s",key);
    printf("Zadajte spravu: ");
    scanf("%s",sprava);
    len_k = strlen(key);
    len_s = strlen(sprava);
    while(sprava[idx_s]!='\0'){
        if(idx_k>(len_k-1))idx_k = 0;
        rozdiel = key[idx_k]-'A' +1;
        if(sprava[idx_s]==' ' || sprava[idx_s]=='\n')idx_s++;
        else{
            if((sprava[idx_s] + rozdiel)>'Z')sprava[idx_s] += rozdiel -('Z'-'A'+1);
            else sprava[idx_s] += rozdiel;
            idx_s++;
            idx_k++;
        }
    }
    printf("%s\n",sprava);
}
void pr3_sifra(char sprava[500],size_t len_s){
    char key[500];
    size_t len_k,idx_s = 0,idx_k = 0;
    int rozdiel;
    printf("Zadajte heslo: ");
    scanf("%s",key);
    printf("Zadajte spravu: ");
    scanf("%s",sprava);
    len_k = strlen(key);
    len_s = strlen(sprava);
    while(sprava[idx_s]!='\0'){
        if(idx_k>(len_k-1))idx_k = 0;
        rozdiel = key[idx_k]-'A' +1;
        if(sprava[idx_s]==' ' || sprava[idx_s]=='\n')idx_s++;
        else{
            if((sprava[idx_s] + rozdiel)>'Z')sprava[idx_s] += rozdiel -('Z'-'A'+1);
            else sprava[idx_s] += rozdiel;
            idx_s++;
            idx_k++;
        }
    }
}
void pr4(){
    FILE *fn,*fs;
    int c,len;
    char subor[40],heslo[500],m[100],*file=NULL;
    printf("Zadajte meno suboru (aj s priponou *.txt), ktory chcete zasifrovat: ");
    scanf("%s",subor);
    if((fn = fopen(subor,"r"))==NULL)printf("Subor sa nepodarilo otvorit.\n");
    else{
        if((fs = fopen("sifrovany_subor.txt","w"))==NULL)printf("Subor sa nepodarilo otvorit.\n");
        else{
            fseek(fn,0,SEEK_END);
            len = ftell(fn);
            rewind(fn);
            if((file = (char*)malloc(c*sizeof(char)))==NULL){
                printf("Nepodarilo sa pridelit pamat.\n");
                fclose(fn);
                fclose(fs);
                exit(1);
                }
            strcpy(file," ");
            while((fscanf(fn,"%s",m))!=EOF){
                if((c=fgetc(fn))=='\n'){
                    strcat(m,"\n");
                    ungetc(c,fn);
                }else if(c==' '){
                    strcat(m," ");
                    ungetc(c,fn);
                } else ungetc(c,fn);
                strcat(file,m);
            }
            fclose(fn);
            pr3_sifra(file,len);
            fprintf(fs,"%s",file);
            free(file);
            file = NULL;
        }
    }
}
void pr5(){
    char key[500],sprava[500];
    size_t len_k,len_s,idx_s = 0,idx_k = 0;
    int rozdiel;
    printf("Zadajte heslo: ");
    scanf("%s",key);
    printf("Zadajte spravu: ");
    scanf("%s",sprava);
    len_k = strlen(key);
    len_s = strlen(sprava);
    while(sprava[idx_s]!='\0'){
        if(idx_k>(len_k-1))idx_k = 0;
        rozdiel = key[idx_k]-'A' +1;
        if(sprava[idx_s]==' ' || sprava[idx_s]=='\n')idx_s++;
        else{
            if((sprava[idx_s] -rozdiel)<'A')sprava[idx_s] +=('Z'-'A'+1) -rozdiel;
            else sprava[idx_s] -= rozdiel;
            idx_s++;
            idx_k++;
        }
    }
    printf("%s",sprava);
}