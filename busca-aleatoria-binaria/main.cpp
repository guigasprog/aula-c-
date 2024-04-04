#include <iostream>

using namespace std;

struct dados
{
    int codigo;
    string nome;
    string endereco;
    string cidade;
    string uf;
};

int inserindoDados(dados dados[], int maximo, int i)
{
    char opcao;
    cout << "Deseja inserir um novo dado? "; cin >> opcao;
    while(opcao == 's' || opcao == 'S')
    {
        if(i < maximo-1) {
            i++;
            cout << "Informe o codigo do usuario: ";
            cin >> dados[i].codigo;
            cout << "Informe o nome do usuario: ";
            cin >> dados[i].nome;
            cout << "Informe o endereco do usuario: ";
            cin >> dados[i].endereco;
            cout << "Informe o cidade do usuario: ";
            cin >> dados[i].cidade;
            cout << "Informe o UF do usuario: ";
            cin >> dados[i].uf;
            system("cls");
            cout << "Deseja inserir um novo dado? "; cin >> opcao;
        } else {
            cout << "Numero maximo de pessoas inseridas atingido\n\n";
            opcao = 'n';
        }
    }
    return i;
}
void organizandoDados(dados dadosArray[], int i)
{
    dados aux;
    if(i > -1)
    {
        for(int j = 0; j < i+1; j++)
        {
            for(int k = 0; k < i+1; k++)
            {
                if(dadosArray[j].codigo < dadosArray[k].codigo)
                {
                    aux = dadosArray[k];
                    dadosArray[k] = dadosArray[j];
                    dadosArray[j] = aux;
                }
            }
        }
    }
}
void exibindoDados(dados dados[], int i)
{
    if(i > -1)
    {
        cout << "Codigo\t|\tNome\t|\tEndereco\t|\tCidade\t|\tUF\n";
        for(int j = 0; j < i+1; j++)
        {
            cout << dados[j].codigo << "\t|\t" << dados[j].nome << "\t|\t" << dados[j].endereco << "\t|\t" << dados[j].cidade << "\t|\t" << dados[j].uf << endl;
        }
    }
}
void buscandoDadosExpecifico(dados dados[], int fim)
{
    if(fim > -1)
    {
        int codigo, inicio = 0, meio = (inicio+fim)/2;
        cout << "Informe um codigo para buscar: "; cin >> codigo;
        while(codigo != dados[meio].codigo && inicio < fim+1)
        {
            if(codigo > dados[meio].codigo) {
                inicio = meio+1;
            }
            else
            {
                fim = meio-1;
            }
            meio = (inicio+fim)/2;
        }
        if(dados[meio].codigo == codigo)
        {
            cout << "\nO dado achado esta aqui: \n";
            cout << "Codigo\t|\tNome\t|\tEndereco\t|\tCidade\t|\tUF\n";
            cout << dados[meio].codigo << "\t|\t" << dados[meio].nome << "\t|\t" << dados[meio].endereco << "\t|\t" << dados[meio].cidade << "\t|\t" << dados[meio].uf << endl;
        } else cout << "Codigo inserido nao foi encontrado na tabela";
    }
}

int main()
{
    const int maximo = 3;
    int posicaoAtual = -1;
    dados dados[maximo];
    posicaoAtual = inserindoDados(dados, maximo, posicaoAtual);
    exibindoDados(dados,posicaoAtual);
    organizandoDados(dados,posicaoAtual);
    exibindoDados(dados,posicaoAtual);
    buscandoDadosExpecifico(dados,posicaoAtual);
    return 0;
}
