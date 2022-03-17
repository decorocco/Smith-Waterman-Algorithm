#include<iostream>
#include<algorithm>
using namespace std;

struct item{
    int valor;
    int linha;
    int coluna;
    string tipo;
};


int main(){
    int n = 0;
    int m = 0;

    int diagonal = 0;
    int delecao = 0;
    int insercao = 0;

    int maximo;
    string tipo;

    int vMax = 0;
    int vMaxLinha;
    int vMaxColuna;

    string sequencia;

    string a;
    string b;

    cin >> n >> m;
    cin >> a >> b;

    //cout << n << m << endl;

    item H[n+1][m+1];
    //cout << H[0][0] << endl;

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            H[i][j].valor = 0;

            //cout << H[i][j].coluna << '-';
        }
        //cout << endl;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){

            if (a[i-1] == b[j-1]) {
                diagonal = H[i-1][j-1].valor + 2;
            }
            else {
                diagonal = H[i-1][j-1].valor - 1;
            }

            delecao = H[i-1][j].valor - 1;
            insercao = H[i][j-1].valor - 1;

            if (diagonal >= delecao && diagonal >= insercao && diagonal >= 0){
                maximo = diagonal;
                H[i][j].tipo = "D";
            }
            else if (delecao >= diagonal && delecao >= insercao && delecao >= 0){
                maximo = delecao;
                H[i][j].tipo = "d";
            }
            else if (insercao >= diagonal && insercao >= delecao && insercao >= 0){
                maximo = insercao;
                H[i][j].tipo = "I";
            }
            else {
                maximo = 0;
                H[i][j].tipo = "Z";
            }

            H[i][j].valor = maximo;
            H[i][j].tipo = tipo;

            if (H[i][j].valor > vMax)
            {
                vMax = H[i][j].valor;
                vMaxLinha = i;
                vMaxColuna = j;
            }
        }
    }

    //sequencia = ;

    //if (H[vMaxLinha][vMaxColuna].tipo == "D"){

    //}

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){

            cout << H[i][j].valor << '-';
        }
        cout << endl;
    }

    return 0;
}