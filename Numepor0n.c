#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM1 4
#define NUM2 45

void genRandomNumber(void);
void checkEachDigits();
void item(void);
int HIGHLOW(void);
int TARGET(void);
int SLASH(void);
void result(void);

int a,b,c;
char recode[NUM2];//今までの記録を表示

int main(void){
    printf("！チャレンジは7回！\n");
    printf("数値入力してください。アイテム[a]/入力履歴[r]/強制終了[f]\n\n");
    printf("\t\t\t\t 1回目の入力>>");

    genRandomNumber();

    return 0;
}

void genRandomNumber(void){
    srand((unsigned)time(NULL));

    a=rand()%10+0;
    b=rand()%10+0;
    while(b==a){
        b=rand()%10+0;
    }
    c=rand()%10+0;
    while(c==a || c==b){
        c=rand()%10+0;
    }

    checkEachDigits(a,b,c);

}

void checkEachDigits(int x, int y, int z){
    int i=0,j=0,r=1,t=1,k=0,l=0;

    char str[NUM1];
    char e,f,g;

    for(r=1;r<=7;r++){

            scanf("%s", str);

            if(str[1]=='\0'){//一桁の数値を入力したときの対処
                if(str[0]=='a') {
                    item();//アイテム使用
                    printf("                     もう一度%d回目の入力>>",r);
                    r--;
                    continue;
                }
                else if(str[0]=='f') {//終了選択
                    r=10;
                    break;
                }
                else if(str[0]=='r') {
                    result();//今までの履歴を表示
                    printf("\t\t\t もう一度%d回目の入力>>",r);
                    r--;
                    continue;
                }
                else {
                    printf("⚠︎桁数⚠︎\t\t\t もう一度%d回目の入力>>", r);
                    r--;//tとrの数を合わせる為にディクリメントしています
                    continue;
                }
            }
            else if(str[2]=='\0'){//二桁の数値を入力したときの対処
                if(str[0]==str[1]){
                    printf("⚠︎桁数/重複⚠︎\t\t もう一度%d回目の入力>>", r);//二桁かつ重複の場合の対処
                    r--;
                    continue;
                }
                printf("⚠︎桁数⚠︎\t\t\t もう一度%d回目の入力>>", r);
                r--;
                continue;
            }

            else if((str[0]==str[1] || str[1]==str[2] || str[2]==str[0]) && str[3]=='\0'){//三桁で重複の場合の対処
                printf("⚠︎重複⚠︎\t\t\t もう一度%d回目の入力>>", r);
                r--;
                continue;
            }
            else if(str[3]!='\0'){//四桁で重複の場合の対処
                if(str[0]==str[1] || str[0]==str[2] || str[0]==str[3]|| str[1]==str[2] || str[1]==str[3] || str[2]==str[3]){
                    printf("⚠︎桁数/重複⚠︎\t\t もう一度%d回目の入力>>", r);//四桁かつ重複の場合の対処
                    r--;
                    continue;
                }
                else{
                    printf("⚠︎桁数⚠︎\t\t\t もう一度%d回目の入力>>", r);
                    r--;
                    continue;
                }
            }
            //ここまでが入力値の桁や重複についての処理。以下は数値（＝文字）比較の処理。
            e='0'+ x;
            f='0'+ y;//数値a,b,cを文字型の数字に変換
            g='0'+ z;//以下は文字としての数字比較をの処理　''は要らない

            if(str[0]==e){
                    i++;
            }
            else if(str[0]!=e && (str[0]==f || str[0]==g)){
                    j++;
            }

            if(str[1]==f){
                    i++;
            }
            else if(str[1]!=f && (str[1]==e || str[1]==g)){
                    j++;
            }

            if(str[2]==g){
                    i++;
            }
            else if(str[2]!=g && (str[2]==e || str[2]==f)){
                    j++;
            }
            printf("%c%c%c\t%dE %dB\t(%-d回目)",str[0],str[1],str[2],i,j,r);

            for(k=0;k<3;k++){//数値の記録
                recode[l]=str[k];
                l++;
            }
            //EとBの記録
            recode[l]='0'+i;
            l++;
            recode[l]='0'+j;
            l++;
            recode[l]='0'+r;
            l++;

            if(i==3)break;
        for(;t==r && t<7;t++){//10回目を入力後は表示させないためにt<10としている
            printf("\t\t%2d回目の入力>>",t+1);//t+1に注意
        }
            i=0;
            j=0;
    }

    if (r<=7)printf("\n正解です！！\n答えは%d%d%d！(･ω･)bｸﾞｯ\n", x,y,z);
    else if(r==8){
        printf("\n残念。。。\n答えは%d%d%dでした。(･ω･)bｸﾞｯ\n", x,y,z);
    }else{
        printf("チャレンジ終了を選択しました。　答えは%d%d%dでした。(･ω･)bｸﾞｯ\n", x,y,z);
    }

}

void item(void)
{
    int h=1, t=1, s=1;
    static int l, m, n;//staticをつけて記憶寿命を伸ばした→関数を呼ぶたびに初期化されないようにした。本当のグローバル関数とは異なる。
    char ch;

    printf("\nHIGH&LOW(%d)/TARGET(%d)/SLASH(%d)\n", h-l, t-m, s-n);

    if((h-l)+(t-m)+(s-n)!=0){
        printf("どのアイテムを使いますか？\n");
        printf("HIGH&LOW→[h] /TARGET→[t] /SLASH→[s] /戻る→[h][t][s]以外を入力してください。> ");

        rewind(stdin);//前回の入力に改行コードが自動的に入っているので、これで抜け出す
        scanf("%c", &ch); //putchar(ch);ch=getchar();でも可能


        if(ch=='h' && l!=1){
            l=HIGHLOW();
        }
        else if(ch=='t' && m!=1){
            m=TARGET();
        }
        else if(ch=='s' && n!=1){
            n=SLASH();
        }
        else{
            printf("戻りました。\n");
        }
    }else{
        printf("アイテムは使用できません。 戻ります。\n");
    }
}

int HIGHLOW(void)
{
    int h=0,l=0;

    if(a>=5){
        h++;
    }else{
        l++;
    }

    if(b>=5){
        h++;
    }else{
        l++;
    }

    if(c>=5){
        h++;
    }else{
        l++;
    }
    printf("\n%dHIGH %dLOW\n\n", h, l);

    return 1;//アイテムは１つにつき1回までとした
}

int TARGET(void)
{
    int t;

    printf("\nどの桁を調べますか？\n");
    printf("調べたい数値を入力してください。>");
    scanf("%d", &t);

    if(t==a){
        printf("%d は100の桁にあります。",t);
    }else if(t==b){
        printf("%d は10の桁にあります。",t);
    }else if(t==c){
        printf("%d は1の桁にあります。",t);
    }else{
        printf("%d は含まれていません。",t);
    }

    return 1;//アイテムは１つにつき1回までとした
}

int SLASH(void)
{
    int sla[3];
    int i,j;
    int tmp;

    sla[0]=a;
    sla[1]=b;
    sla[2]=c;

    for(i=0;i<3;i++){
        for(j=i;j<3;j++){
            if(sla[i]<sla[j]){
                tmp=sla[i];
                sla[i]=sla[j];
                sla[j]=tmp;
            }
        }
    }
    printf("\nSLASHナンバーは「%d」です。",sla[0]-sla[2]);

    return 1;
}

void result(void)
{
    int l;

    printf("\n<結果履歴>\n");

    for(l=1;l<NUM2;l++){
            if(recode[l-1]=='\0'){
                break;
            }
            else if(l%6==1 || l%6==2){
                printf("%c",recode[l-1]);
            }
            else if(l%6==3){
                printf("%c",recode[l-1]);
            }
            else if(l%6==4){
                printf("\t%cE ",recode[l-1]);
            }
            else if(l%6==5){
                printf("%cB\t",recode[l-1]);
            }
            else if(l%6==0){
                printf("(%-c回目)",recode[l-1]);
                printf("\n");
            }
    }
}
