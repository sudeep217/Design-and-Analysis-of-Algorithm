#include <stdio.h>
#include <math.h>

int isArmstrong(int num, int order);

int main() {
    int num, originalNum, digits, result = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    originalNum = num;
    digits = (int)log10(num) + 1;

    if (isArmstrong(num, digits) == num) {
        printf("%d is an Armstrong number.", originalNum);
    } else {
        printf("%d is not an Armstrong number.", originalNum);
    }

    return 0;
}

int isArmstrong(int num, int order) {
    if (num == 0) {
        return 0;
    } else {
        return (int)pow(num % 10, order) + isArmstrong(num / 10, order);
    }
}
