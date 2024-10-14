#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tranform2decimal(char *hex_string) {
    int res=0, n=strlen(hex_string);
    for (int i=0;i<n;i++) {
        if (hex_string[i]>='0' && hex_string[i]<='9') {
            res += hex_string[i]-'0';
        }
        else if (hex_string[i]>='A' && hex_string[i]<='F') {
            res += hex_string[i]-'A'+10;
        }
        else if (hex_string[i]>='a' && hex_string[i]<='f') {
            res += hex_string[i]-'a'+10;
        }
    }
    return res;
}

char* tranform2hex(int decimal) {
    char *res = (char *)malloc(20);
    memset(res, 0, 20);
    if (!decimal) {
        res[0] = '0';
        res[1] = '\0';
        return res;
    }
    int idx = 0;
    while (decimal) {
        int cur = decimal % 16;
        if (cur < 10) {
            res[idx++] = cur + '0';
            res[idx] = '\0';
        }
        else {
            res[idx++] = cur - 10 + 'a';
            res[idx] = '\0';
        }
        decimal /= 16;
    }
    for (int i=0;i<idx/2;i++) {
        char tmp = res[i];
        res[i] = res[idx-1-i];
        res[idx-1-i] = tmp;
    }
    res[idx] = '\0';
    return res;
}



void dfs(char *buffer) {
    int len = strlen(buffer);
    if (len <= 1) {
        printf("%s", buffer);
        return;
    }
    char odd[len/2+5], even[len/2+5];
    for (int i=0;i<len;i++) {
        if (i%2) {
            odd[i/2] = buffer[i];
            odd[i/2+1] = '\0';
        }
        else {
            even[i/2] = buffer[i];
            even[i/2+1] = '\0';
        }
    }
    int odd_decimal = tranform2decimal(odd);
    int even_decimal = tranform2decimal(even);
    char *odd_hex = tranform2hex(odd_decimal);
    char *even_hex = tranform2hex(even_decimal);
    dfs(even_hex);
    dfs(odd_hex);
    free(odd_hex);
    free(even_hex);
}

int main() {
    char buffer[10005];
    memset(buffer, 0, 10005);
    scanf("%s", buffer);
    dfs(buffer);
    return 0;
}

// 55