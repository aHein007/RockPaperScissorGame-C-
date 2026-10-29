#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int userType=0; 
    char items[3][10]={"グー","パー","チョキ"}; // rock , paper ,scissor
                                                // 1     // 2    // 3
    int length =sizeof(items) / sizeof(items[0]);
    int exitCond=0; 
   

    printf("じゃんけんをします\n");

    while (1)
    {
        printf("じゃんけん・・・\n");
        printf("何を出す？\n");

        printf("グー：1\nパー：2\nチョキ：3\n");
        while(1){
            printf(">");
            int ret =scanf("%d",&userType); // it will return 0 or 1;
            // 0 is false , 1 is true


            if(ret != 1){
                int c;
                while((c=getchar()) != '\n' && c != EOF);
                printf("不正値です。。再入力してください\n");
                continue;
            }

            while(userType < 1 || userType > 3 ){
                printf("不正値です。。再入力してください\n");
                continue;
            }

        break;
        }
        system("cls");

        int i =0;
        

        int randomCpu = rand() % length+1;
        char *rCpu=items[randomCpu-1]; // -1 is for array index

        //user text
        char *u_choice = items[userType-1];

        printf("あなた：%s\n",u_choice);
        printf("相手　：%s\n",rCpu);

        // rock
            //rock            // scissor
        if(userType == 1 && randomCpu == 3  ){
            printf("あなたの勝ちです！\n");
        }else if(userType == 3 && randomCpu == 1){
            printf("あなたの負けです。。\n");
        }

        //paper
         if(userType == 2 && randomCpu == 1){
            printf("あなたの勝ちです！\n");
        }else if(userType == 1 && randomCpu == 2){
            printf("あなたの負けです。。\n");
        }


        //scissor
         if(userType == 3 && randomCpu == 2){
            printf("あなたの勝ちです！\n");
        }else if(userType == 2 && randomCpu == 3){
            printf("あなたの負けです。。\n");
        }

        if(userType == randomCpu){
            printf("あいこで・・・\n");
            continue;
        }else{
            printf("もう一度しますか？\n");
            printf("はい：1\n");
            printf("いいえ：0\n");
            while(1){
                printf(">");
                int ret =scanf("%d",&exitCond);

                if(ret != 1){
                    int c;
                    while((c=getchar()) != '\n' && c != EOF);
                    printf("不正値です。。再入力してください\n");
                    continue;
                }

                while (userType < 1 || userType > 3)
                {
                     printf("不正値です。。再入力してください\n");
                    continue;
                }
             break;
            }
          system("cls");
        }

        

        if(exitCond == 0 ){
            break;
        }

}
    



    return 0;
}


// ဒီအပိုင်းကို အဆင့်လိုက် ရှင်းပြမယ်။ ဥပမာ အနေနဲ့ user က abc လို့ ရိုက်ပြီး Enter နှိပ်တယ် ဆိုပါစို့။

// အဆင့် ၁။ scanf("%d") fail ဖြစ်တယ်

// Keyboard က ရိုက်ထားတာတွေက အရင်ဆုံး input buffer ထဲ ဝင်တယ်။

// buffer: a b c \n

// scanf("%d") က ဂဏန်း ရှာတယ်၊ ဒါပေမယ့် ပထမဆုံး စာလုံး a က ဂဏန်း မဟုတ်ဘူး။ ဒါကြောင့်:

// userType ထဲ ဘာမှ မထည့်ဘူး
// a ကို buffer ထဲမှာ ဒီအတိုင်း ချန်ထားတယ် (မဖတ်ဘူး)
// return value 0 ပြန်တယ် → ret != 1 မှန်သွားတယ်

// အဆင့် ၂။ ဘာလို့ buffer ကို ရှင်းရတာလဲ

// a b c \n က buffer ထဲမှာ ကျန်နေတုန်းပဲ။ ဒီအတိုင်း continue လုပ်ပြီး scanf ကို ပြန်ခေါ်ရင် scanf က a ကို ထပ်တွေ့ပြီး ထပ် fail ဖြစ်တယ်၊ ထပ်ခါထပ်ခါ ဖြစ်ပြီး အဆုံးမရှိ loop ဖြစ်သွားတယ်။ ဒါကြောင့် မကောင်းတဲ့ စာတွေကို ရှင်းထုတ်ရတယ်။

// အဆင့် ၃။ while loop က ရှင်းထုတ်တာ

// c
// int c;
// while ((c = getchar()) != '\n' && c != EOF);

// getchar() က buffer ထဲက စာလုံး တစ်လုံးချင်း ဖတ်ပြီး ယူသွားတယ် (ဖယ်ထုတ်တာနဲ့ အတူတူ)။

// getchar() → 'a'   (\n မဟုတ်ဘူး၊ ဆက်ပတ်)
// getchar() → 'b'   (ဆက်ပတ်)
// getchar() → 'c'   (ဆက်ပတ်)
// getchar() → '\n'  (\n ဖြစ်ပြီ → loop ရပ်)

// Loop ရဲ့ condition c != '\n' && c != EOF က “Enter (\n) သို့မဟုတ် input ကုန်ခြင်း (EOF) မတွေ့မချင်း ဆက်ဖတ်ပြီး ပစ်ပါ” လို့ ဆိုလိုတယ်။ Loop body က ; တစ်ခုတည်း (ဘာမှမလုပ်ဘူး)၊ ဖတ်ပြီး ပစ်တာကိုက condition ထဲမှာ ပြီးသွားတာ။

// ပြီးရင် buffer က ဗလာ ဖြစ်သွားတယ်။

// အဆင့် ၄။ error ပြပြီး ပြန်စ

// c
// printf("不正値です。再入力してください\n");
// continue;

// Message ပြပြီး continue နဲ့ validation loop ရဲ့ အစကို ပြန်သွားတယ်။ scanf ကို ပြန်ခေါ်တဲ့အခါ buffer ဗလာဖြစ်နေလို့ user ရဲ့ အသစ်ရိုက်တာကို စောင့်ပါတယ်။