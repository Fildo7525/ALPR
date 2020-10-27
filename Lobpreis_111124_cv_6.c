#include<stdio.h>
#include<string.h>

#define RANGE 127-' '

void vypis(int cisla[],int dlzka);
void pr2();
void pr3();
void pr4();
void pr5();
void pr6();
void pr7();
void pr8();
int  najdlhsie_opakovanie(char  x[],  int  pocet, char *znak);
void pr9();

int main(){
    int arr[21]{};
    //vypis(arr,21);
    pr2();
    //pr3();
    //pr4();
    //pr5();
    //pr6();
    //pr7();
    //pr8();
    //pr9();
}
void vypis(int cisla[],int dlzka){
    for(int i = 0; i<dlzka;i++){
        printf("%4d ",cisla[i]);
        if((((i+1)%10)==0 )&& (i!=0))printf("\n");
    }
    printf("\n");
}
void pr2(){
    FILE *fr;
    int pivot,c,arr[500],idx=0,pred_prid = 0,neg = 0,mensie[32768],mensie_idx=0,vacsie[32768],vacsie_idx=0;
    if((fr=fopen("vstup.txt","r"))==NULL)printf("Subor neexistuje alebo sa neda otvorit!\n");
    else{
        printf("Zadajte cislo: ");
        scanf("%d",&pivot);
        //printf("%d\n",arr[0]);
        while((fscanf(fr,"%d ",&c))!=EOF){
            arr[idx]=c;
            idx++;
        }
        fclose(fr);
        printf("Nacital som:\n");
        vypis(arr,idx);
        int n=0;
        while(n<idx){
            if(arr[n]==0)n++;//tento riadok zabezpeci ze sa nebudu vypisovat nuly
            else{
                if(arr[n]<pivot){
                    mensie[mensie_idx]=arr[n];
                    mensie_idx++;
                }
                if(arr[n]>pivot){
                    vacsie[vacsie_idx]=arr[n];
                    vacsie_idx++;
                }
                n++;
            }
        }
        printf("Mensie cisla ako cislo %d su:\n",pivot);
        vypis(mensie,mensie_idx);
        printf("Vacsie cisla ako cislo %d su:\n",pivot);
        vypis(vacsie,vacsie_idx);
    }
}
void pr3(){
    char str[21],front=0,temp;
    int dlzka = 0,idx = 0;
    printf("Zadajte do 20 znakov: ");
    scanf("%20s",str);
    //strcpy(str,"abcdefghijklmnopqrs");
    while(str[idx] != '\0'){
        dlzka++;
        idx++;    
    }
    idx--;
    dlzka = ((dlzka%2)==0)?dlzka/2 : (dlzka-1)/2;
    for(int i = 0;i<dlzka;i++,front++,idx--){
        temp = str[front];
        str[front] = str[idx];
        str[idx] = temp;
    }
    printf("%s\n",str);
}
void pr4(){
    char str[11];
    printf("Zadajte retazec znakov (max. 10): ");
    scanf("%10s",str);
    //strcpy(str,"12*34*5678");
    for(int i = 9;i>=0;i--){
        if(str[i]=='*'){
            int t=9;
            if(i==10)str[10]='+';
            else{
                for(int j = 7;j>i;j--,t--){
                    str[t] = str[j];
                }
                str[i] = '+';
                if(++i<10)str[i] = '*';
                if(++i<10)str[i] = '-';
                i-=2;
            }
        }
    }
    printf("%10s\n",str);
}
void pr5(){
    int pos,str_len = 0,red_len = 0;
    char str[31],redukcia[16];
    printf("Zadajte retazec (max 30 znakov): ");
    scanf("%30s",str);
    printf("Zadajte podretazec pocet znakov min 3 max 15: ");
    scanf("%15s",redukcia);
    //strcpy(str,"psasasansnsnsp");
    //strcpy(redukcia,"sans");
    while(str[str_len]!='\0')str_len++;
    while(redukcia[red_len]!='\0')red_len++;
    for(int i = 0;i<str_len;i++){
        if(str[i]==redukcia[0]){
            int r = 1;
            for(int j = i+1;j<i+red_len;j++){
                if(str[j]==redukcia[r]){
                    r++;
                }
                else break;
            }
            if(r==red_len){
                int k =i;
                for(int j = k+r;j<str_len+1;j++){
                    str[k] = str[j];
                    k++;
                }
                str_len-=red_len;
                i-=red_len;
            }

        }
    }
    printf("%s\n",str);
}
void pr6(){
    char str[50];
    int c,parne = 1,idx=0;
    FILE *vstup,*vystup;
    if((vstup=fopen("vstup.txt","r"))==NULL)printf("Subor sa nepodarilo otvorit.\n");
    else{
        if((vystup=fopen("vystup.txt","w"))==NULL){
            printf("Subor sa nepodarilo otvorit.\n");
            fclose(vstup);
        }else{
            while(fscanf(vstup,"%s",str)!=EOF){
                if(parne%2==0){
                    fprintf(vystup,"%s ",str);
                }
                parne++;
            }
            fputc('\n',vystup);
            fclose(vstup);
            fclose(vystup);
        }
    }
}
void pr7(){
    char cc;
    FILE *prvy,*druhy,*treti;
    int parnost_slova=1,p,d,subor;
    long d_1,d_2,dlzka;
    if((prvy = fopen("prvy.txt","r"))==NULL)printf("Subor sa nepodarilo otvorit.\n");
    else{
        if((druhy = fopen("druhy.txt","r"))==NULL){
            printf("Subor sa nepodarilo otvorit.\n");
            fclose(prvy);
        }else{
            if((treti = fopen("treti.txt","w"))==NULL){
                printf("Subor sa nepodarilo otvorit.\n");
                fclose(prvy);
                fclose(druhy);
            }else{
                d_1 = fseek(prvy,0,SEEK_END);
                d_1 = ftell(prvy);
                rewind(prvy);
                d_2 = fseek(druhy,0,SEEK_END);
                d_2 = ftell(druhy);
                rewind(druhy);
                while(d_1>0 && d_2>0){
                    if(parnost_slova == 1){
                        fprintf(treti,"+");
                        while((p = fgetc(prvy))!=' '&& p!='\n' && p!=EOF){
                            cc=p;
                            fputc(p,treti);
                            --d_1;
                        }
                        if(p==' ')d_1--;
                        fprintf(treti," ");
                        parnost_slova=0;
                    }else{
                        fprintf(treti,"-");
                        while((d = fgetc(druhy))!=' '&& d!='\n'&& d!=EOF){
                            cc=d;
                            fputc(d,treti);
                            --d_2;
                        }
                        if(d==' ')d_2--;
                        fprintf(treti," ");
                        parnost_slova = 1;
                    }
                }
                if(d_1<=0){
                    fprintf(treti,"-");
                        while((d = fgetc(druhy))!=EOF){
                            if(d==' ')fprintf(treti," -");
                            else{
                                cc=d;
                                fputc(d,treti);
                            }
                        }
                    fprintf(treti," ");
                } else{
                    fprintf(treti,"+");
                        while((p = fgetc(prvy))!=EOF){
                            cc=p;
                            fputc(p,treti);
                        }
                    fprintf(treti," "); 
                }
                fclose(prvy);
                fclose(druhy);
                fclose(treti);
            }  
        }
    }
}
int  najdlhsie_opakovanie(char  x[],  int  pocet, char *znak){
    int ascii[RANGE],max = 0;
    char cznak = 0;
    for(int i = 0;i<RANGE;i++)ascii[i]=0;
    for(int i = 0; i<pocet;i++){
        cznak = x[i]-' ';
        ascii[cznak]++;
    }
    for(int i = 0;i<RANGE;i++){
        if(ascii[i]>max){
            max = ascii[i];
            cznak = i+' ';
        }
    }
    *znak = cznak;
    return max;
}
void pr8(){
    char str[31],c;
    int opakovania;
    printf("Zadajte retazec: ");
    scanf("%30s",str);
    //strcpy(str,"aaaAabBbbbbc144444");
    opakovania = najdlhsie_opakovanie(str,30,&c);
    printf("Najviac opakujuce pismeno je \'%c\', opakuje sa %d-krat\n",c,opakovania);
}
void pr9(){
    size_t l;
    char retazec[50],podret[4];
    printf("Zadajte retazec: ");
    scanf("%50s",retazec);
    printf("Zadajte podretazec: ");
    scanf("%3s",podret);
    //strcpy(retazec,"xababccy");
    //strcpy(podret,"abc");
    l = strlen(retazec);
    int c = 0;
    for(int i = 0;i<l;i++){
        while(retazec[c]!='\0'){
            if(retazec[c]==podret[0]){
                if(retazec[c+1]==podret[1] && retazec[c+2]==podret[2]){
                    for(int j = c+3;j<=l;j++){
                        retazec[j-3] = retazec[j];
                    }
                    l-=3;
                }
            }
            ++c;
        }
        c=0;
    }
    printf("%s\n",retazec);
}