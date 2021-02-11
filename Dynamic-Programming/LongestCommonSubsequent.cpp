#include <iostream>
int max(int a, int b){
    return (a>b)? a: b;
}
int main() {
    std::string a = "aggtab";
    std::string b = "gxtxayb";

    int l1 = a.length();
    int l2 = b.length();

    int** lcs = new int*[l2+1];
    for (int k = 0; k <= l2; ++k) {
        lcs[k] = new int[l1+1];
    }

    for (int l = 0; l < l2+1 ; ++l) {
        for (int i = 0; i < l1+1 ; ++i) {
            lcs[l][i] = 0;
        }
    }

    for (int i = 1; i < l2+1; ++i) {
        for (int j = 1; j < l1+1; ++j) {
            if(a[j-1]!=b[i-1])
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
            else
                lcs[i][j] = 1 + lcs[i-1][j-1];
        }
    }


    std::cout<<lcs[l2][l1]<<std::endl;
    return 0;
}
