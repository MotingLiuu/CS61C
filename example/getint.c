# include <ctype.h>
# include<stdio.h>

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void) { // 先查缓冲区，没有就从标准输入读
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) { // 把字符“退回”缓冲区
    if (bufp < BUFSIZE)
        buf[bufp++] = c;
    else
        printf("ungetch: too many characters\n");
}


int getint(int *pn) {
    int c, sign;
    while (isspace(c = getch())); // filter all of the space
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') { // if c is not a decimal num or EOF or + -, then return c to buffer
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1; // get the sign
    if (c == '+' || c == '-') {
        c = getch();
    }
    if (!isdigit(c)) {
        ungetch(c);
        return c;
    }
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn +(c - '0');
    }
    *pn *= sign;

    if (c != EOF) {
        ungetch(c);
    }
    return c;
}

int getfloat(float *pn) {
    int c, sign;
    float tmp = 0;
    while (isspace(c = getch())); // filter all of the space
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') { // if c is not a decimal num or EOF or + -, then return c to buffer
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1; // get the sign
    if (c == '+' || c == '-') {
        c = getch();
    }
    if (!isdigit(c)) {
        ungetch(c);
        return c;
    }
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn +(c - '0');
    }
    if (c == '.') {
        c = getch();
        for (int i = 10; isdigit(c); i = i * 10) {
            tmp += (c - '0') / (float)i;
            c = getch();
        }
    }
    *pn += tmp;
    *pn *= sign;

    if (c != EOF) {
        ungetch(c);
    }
    return c;
}

int main() {
    float a = 0;
    int result = getfloat(&a);
    printf("The num you inputted i %f\n", a);
    printf("getfloat returns: %d\n", result);
}