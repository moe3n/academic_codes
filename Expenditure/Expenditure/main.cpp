//
//  main.cpp
//  Expenditure
//
//  Created by Mahmud on 16/9/19.
//  Copyright © 2019 Mahmud. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main() {
    // insert code here...
    char provider;
    int day, month,amount;
    printf("Enter  date(dd/mm):\n");
    scanf("%d %d", &day, &month);
    printf("Provider:\n");
    scanf("%s", &provider);
    printf("Enter amount\n");
    scanf("%d", &amount);
    FILE* input;
    input = fopen("/Users/mahmudmoeen/Documents/TextEdit/Expenditure.txt", "a");
    fprintf(input, "%d-%d\t\t %.11s\t\t\t%d\n", day,month,&provider,amount);

    fclose(input);
    return 0;
}
