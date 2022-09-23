
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

