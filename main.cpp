
/*
Matricula 1: 251008956
Nome 1: Grazielle Montinegro dos Santos

Matricula 2: 242004027
Nome 2: Olivia Helena Gomes Martins

Matricula 3: 251036280
Nome 3: Diana Xavier Vieira do Nascimento
 
arquivo main.cpp
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

/* ============================
   IMPORTA AS STRUCTS
=============================== */

struct aluno {
    int matricula;
    string nome;
};

struct nota { 
    int matricula;
    string referencia;
    float valor;
};

/* ============================
   DECLARA AS FUNÇÕES DA PESSOA 1 E 2
=============================== */

// aluno.cpp
void cadastrar(vector<aluno> &lista, int matricula, string nome);
void atualizar(vector<aluno> &lista, int matricula, string anome);
void apagar(vector<aluno> &lista, int matricula);
void listar(vector<aluno> &lista);
void listarum(vector<aluno> &lista, int matricula);

// gerenciamento_de_notas.cpp
bool nota_existe(vector<nota>& notas, string matricula, string referencia);
float calcular_media(vector<nota>& notas, string matricula);
void incluir_nota(vector<nota>& notas, vector<aluno>& alunos);
void alterar_nota(vector<nota>& notas);
void apagar_nota(vector<nota>& notas);
void listar_alunos (vector<aluno>& alunos, vector<nota>& notas);
void listar_1aluno(vector<aluno>& alunos, vector<nota>& notas);

/* ============================
   LEITURA DE CSV
=============================== */

void carregar_alunos(vector<aluno>& alunos) {
    ifstream arq("alunos.csv");
    if (!arq.is_open()) {
        cout << "[ERRO] Não consegui abrir alunos.csv!\n";
        return;
    }

    string linha;
    getline(arq, linha); // pula cabeçalho

    while (getline(arq, linha)) {
        stringstream ss(linha);
        string matriculaStr, nome;

        getline(ss, matriculaStr, ',');
        getline(ss, nome, ',');

        aluno a;
        a.matricula = stoi(matriculaStr);
        a.nome = nome;

        alunos.push_back(a);
    }
    cout << "[OK] alunos.csv carregado!\n";
}

void carregar_notas(vector<nota>& notas) {
    ifstream arq("notas.csv");
    if (!arq.is_open()) {
        cout << "[ERRO] Não consegui abrir notas.csv!\n";
        return;
    }

    string linha;
    getline(arq, linha); // pula cabeçalho

    while (getline(arq, linha)) {
        stringstream ss(linha);
        string matriculaStr, ref, valorStr;

        getline(ss, matriculaStr, ';');
        getline(ss, ref, ';');
        getline(ss, valorStr, ';');

        nota n;
        n.matricula = stoi(matriculaStr);
        n.referencia = ref;
        n.valor = stof(valorStr);

        notas.push_back(n);
    }
    cout << "[OK] notas.csv carregado!\n";
}

/* ============================
   GRAVAÇÃO DE CSV
=============================== */

void salvar_alunos(vector<aluno>& alunos) {
    ofstream arq("alunos.csv");

    arq << "matricula,nome\n";

    for (auto& a : alunos) {
        arq << a.matricula << "," << a.nome << "\n";
    }

    cout << "[OK] alunos.csv salvo!\n";
}

void salvar_notas(vector<nota>& notas) {
    ofstream arq("notas.csv");

    arq << "matricula;referencia;valor\n";

    for (auto& n : notas) {
        arq << n.matricula << ";" << n.referencia << ";" << n.valor << "\n";
    }

    cout << "[OK] notas.csv salvo!\n";
}

int main() {
    vector<aluno> alunos;
    vector<nota> notas;

    // Carrega os CSV ao iniciar
    carregar_alunos(alunos);
    carregar_notas(notas);

    int opcao;

    do {
        cout << "\n==============================\n";
        cout << "        MENU PRINCIPAL        \n";
        cout << "==============================\n";
        cout << "1 - Cadastrar aluno\n";
        cout << "2 - Atualizar aluno\n";
        cout << "3 - Apagar aluno\n";
        cout << "4 - Listar todos os alunos\n";
        cout << "5 - Listar 1 aluno\n";
        cout << "6 - Incluir nota\n";
        cout << "7 - Alterar nota\n";
        cout << "8 - Apagar nota\n";
        cout << "9 - Listar alunos com notas\n";
        cout << "10 - Listar notas de 1 aluno\n";
        cout << "0 - Salvar e sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        cout << "\n";

        switch(opcao) {
            case 1: {
                int m;
                string n;
                cout << "Matricula: ";
                cin >> m;
                cout << "Nome: ";
                cin.ignore();
                getline(cin, n);

                cadastrar(alunos, m, n);
                break;
            }
            case 2: {
                int m;
                string n;
                cout << "Matricula para atualizar: ";
                cin >> m;
                cout << "Novo nome: ";
                cin.ignore();
                getline(cin, n);

                atualizar(alunos, m, n);
                break;
            }
            case 3: {
                int m;
                cout << "Matricula para apagar: ";
                cin >> m;

                apagar(alunos, m);
                break;
            }
            case 4:
                listar(alunos);
                break;

            case 5: {
                int m;
                cout << "Matricula a listar: ";
                cin >> m;
                listarum(alunos, m);
                break;
            }

            case 6:
                incluir_nota(notas, alunos);
                break;

            case 7:
                alterar_nota(notas);
                break;

            case 8:
                apagar_nota(notas);
                break;

            case 9:
                listar_alunos(alunos, notas);
                break;

            case 10:
                listar_1aluno(alunos, notas);
                break;

            case 0:
                cout << "Salvando arquivos...\n";
                salvar_alunos(alunos);
                salvar_notas(notas);
                cout << "Finalizado!\n";
                break;

            default:
                cout << "Opcao invalida!\n";
        }

    } while (opcao != 0);

    return 0;
}

