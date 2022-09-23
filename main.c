void inputNumber(char _myinput[DIGIT_SIZE]){
    bool isValid = false;
    while(!isValid){
        scanf(" %s", _myinput);
        isValid = isValidInput(_myinput);
        if (!isValid) continue;
    }
}

bool isValidInput(char _inputNum[]){
    if(_inputNum[0] == 'a' && _inputNum[1] == '\0') return true;
    if(isdigit(_inputNum[0]) && isdigit(_inputNum[1]) && isdigit(_inputNum[2]) && _inputNum[3] == '\0') return true;

    printf("入力が正しくありません > ");
    return false;
}

void useItem(struct number *number, struct item *item)
{
    if(!(item->hlFlag || item->slashFlag || item->tgFlag)){
        printf("アイテムをすべて使用しました\n");
        return;
    }
    // アイテムは数値で計算を行う
    int nums[DIGIT_SIZE];
    for(int i = 0; i < DIGIT_SIZE; i++){
        nums[i] = number->answer[i] - '0';
    }

    char itemType[TEMP_INPUT_SIZE];
    do{
        printf("どのアイテムを使いますか？\n");
        if(item->hlFlag)printf("HIGH&LOWを使用する → \th\n");
        if(item->slashFlag)printf("SLASHを使用する → \ts\n");
        if(item->tgFlag)printf("TARGETを使用する → \tt\n");
        printf("戻る場合は上記以外を入力してください > ");

        scanf(" %s", itemType);
    }while(!isValidItem(itemType));

    switch (itemType[0]){
        case 'h':
            item->_highLow(nums);
            item->hlFlag=false;
            break;
        case 's':
            item->_slash(nums);
            item->slashFlag=false;
            break;
        case 't':
            item->_target(nums);
            item->tgFlag=false;
            break;
    }
}

bool isValidItem(char _inputAlp[]){
    if( _inputAlp[1] == '\0') return true;
    return false;
}

//5以上をHigh，5未満をLowとしてカウントして出力
void highLow(int nums[DIGIT_SIZE]){
    for(int i = 0; i < DIGIT_SIZE; i++){
        if(nums[i] >= 5)printf("HIGH ");
        else printf("LOW ");
    }
    printf("\n");
}

//ナンバーの最大値ー最小値の値を出力する
void slash(int nums[DIGIT_SIZE]){
    int max = -1, min = 10;
    for(int i = 0; i < DIGIT_SIZE; i++){
        if(max < nums[i])max = nums[i];
        if(min > nums[i])min = nums[i];
    }

    printf("\nSLASHナンバーは「%d」です\n", max - min);
}

//選択した数字が何番目にあるかを出力
void target(int nums[DIGIT_SIZE]){
    char tempTargetNum[TEMP_INPUT_SIZE];
    do{
        printf("調べたい数字（１桁）を入力してください >");
        scanf(" %s", tempTargetNum);
        printf("%s\n", tempTargetNum);
    }while((!isValidItem(tempTargetNum) || (!isdigit(tempTargetNum[0]))));

    int targetNum = tempTargetNum[0] - '0';
    for(int i = 0; i < DIGIT_SIZE; i++){
        if(nums[i] == targetNum){
            printf("%d は左から%d番目です\n", targetNum, i + 1);
            return;
        }
    }
    printf("%d は含まれていません\n",targetNum);
}
