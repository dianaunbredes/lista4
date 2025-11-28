/*
Matricula 1: 251008956
Nome 1: Grazielle Montinegro dos Santos
*/

/*
INCLUDES E NAMESPACES
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
STRUCTS, CONSTS E TIPOS NECESSÁRIOS
*/
struct aluno {
    int matricula;
    string nome;
};

struct nota { 
    int matricula;
    string referencia;
    float valor;
};

/*
FUNÇÕES_DO_PROGRAMA
*/

//Cadastra aluno 
void cadastrar(vector<aluno> &lista, int matricula, string nome) {

// Verifica se a matrícula já existe
    for (int i=0; i < lista.size(); i++) {
        if (lista[i].matricula == matricula) {
            
          cout << "Matricula ja cadastrada no sistema!" << endl;
}}

// adiciona aluno no final do vetor
    aluno a;
    a.matricula = matricula;
    a.nome = nome;

    lista.push_back(a);

    cout << "Aluno cadastrado!" << endl;
}

// Atualiza o nome 
void atualizar(vector<aluno> &lista, int matricula, string anome) {

    for (int i=0; i <lista.size(); i++) {
        if (lista[i].matricula == matricula) {

          lista[i].nome = anome;
          
          cout << "Atualizado!" << endl;
          return;
}}
		  cout << "Nao encontrado!" << endl;
}

// Função que apaga aluno
void apagar(vector<aluno> &lista, int matricula) {

    int pos = - 1;  // procura indice do aluno

    for (int i=0; i <lista.size(); i++) {
        if (lista[i].matricula == matricula) {
            pos = i;   break;
}}

    if (pos == - 1) {
        cout << "Nao encontrado!" << endl;
}

    // "Empurra" outros alunos para organizar a lista
    for (int n = pos; n < lista.size() - 1; n++) {
        lista[n] = lista[n+1];
    }
    
    lista.pop_back();    // Remove o último

    cout << "Removido!" << endl;
}

// Lista os alunos
void listar(vector<aluno> &lista) {

    for (int i=0; i<lista.size(); i++) {
        cout << "Matricula: " << lista[i].matricula << " — " << "Nome: " << lista[i].nome << endl;
}}

// Listar um aluno pela matrícula
void listarum(vector<aluno> &lista, int matricula) {

    for (int i=0; i <lista.size(); i++) {
        if (lista[i].matricula == matricula) {
            
         cout << "Matricula: " << lista[i].matricula << " — " << "Nome: " << lista[i].nome << endl;
         return;
}}
    	 cout << "nao encontrado!" << endl;
}