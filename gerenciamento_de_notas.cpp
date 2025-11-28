/*
Matricula 1: 251008956
Nome 1: Grazielle Montinegro dos Santos

Matricula 2: 242004027
Nome 2: Olivia Helena Gomes Martins

Matricula 3: 251036280
Nome 3: Diana Xavier Vieira do Nascimento
*/

/*
INCLUDES E NAMESPACES
*/

/*
INCLUDES E NAMESPACES
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

/*
STRUCTS — devem bater com aluno.cpp
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
FUNÇÕES DO PROGRAMA - DECOMPOSIÇÃO FUNCIONAL
*/

// Verifica se um aluno existe pela matrícula
bool aluno_existe(vector<aluno>& alunos, int matricula) {
    for (const auto& a : alunos) {
        if (a.matricula == matricula) {
            return true;  // existe
        }
    }
    return false;  // não existe
}

// Verifica se uma nota já existe para matricula + referencia
bool nota_existe(vector<nota>& notas, int matricula, string referencia) {
    for (const auto& n : notas) {
        if (n.matricula == matricula && n.referencia == referencia) {
            return true;
        }
    }
    return false;
}

// Calcula a média do aluno
float calcular_media(vector<nota>& notas, int matricula) {
    float soma = 0;
    int count = 0;

    for (const auto& n : notas) {
        if (n.matricula == matricula) {
            soma += n.valor;
            count++;
        }
    }

    if (count == 0) return 0;
    return soma / count;
}

// Incluir nota
void incluir_nota(vector<nota>& notas, vector<aluno>& alunos) {
    int matricula;
    string referencia;
    float valor;

    cout << "\n INCLUIR NOTA" << endl;

    cout << "Matricula do aluno: ";
    cin >> matricula;

    if (!aluno_existe(alunos, matricula)) {
        cout << "\n[ERRO] Aluno não encontrado!\n";
        return;
    }

    cout << "Referencia (ex.: P1, P2, P1A): ";
    cin >> referencia;

    if (nota_existe(notas, matricula, referencia)) {
        cout << "\n[ERRO] Já existe uma nota com essa referência!\n";
        return;
    }

    cout << "Valor da nota: ";
    cin >> valor;

    nota nova = { matricula, referencia, valor };
    notas.push_back(nova);

    cout << "\n[SUCESSO] Nota cadastrada!\n";
}

// Alterar nota
void alterar_nota(vector<nota>& notas) {
    int matricula;
    string referencia;
    float novo_valor;

    cout << "\n ALTERAR NOTA" << endl;

    cout << "Matricula: ";
    cin >> matricula;
    cout << "Referencia: ";
    cin >> referencia;

    for (auto& n : notas) {
        if (n.matricula == matricula && n.referencia == referencia) {
            cout << "Nota atual: " << fixed << setprecision(2) << n.valor << endl;
            cout << "Novo valor: ";
            cin >> novo_valor;

            n.valor = novo_valor;

            cout << "\n[SUCESSO] Nota alterada!\n";
            return;
        }
    }

    cout << "\n[ERRO] Nota não encontrada!\n";
}

// Apagar nota
void apagar_nota(vector<nota>& notas) {
    int matricula;
    string referencia;

    cout << "\n APAGAR NOTA" << endl;

    cout << "Matricula: ";
    cin >> matricula;
    cout << "Referencia: ";
    cin >> referencia;

    for (auto it = notas.begin(); it != notas.end(); it++) {
        if (it->matricula == matricula && it->referencia == referencia) {
            notas.erase(it);
            cout << "\n[SUCESSO] Nota removida!\n";
            return;
        }
    }

    cout << "\n[ERRO] Nota não encontrada!\n";
}

// Listar todos os alunos com notas
void listar_alunos(vector<aluno>& alunos, vector<nota>& notas) {

    cout << "\n LISTAGEM DE ALUNOS + NOTAS" << endl;

    if (alunos.empty()) {
        cout << "Nenhum aluno cadastrado.\n";
        return;
    }

    for (const auto& a : alunos) {
        cout << "\nMatricula: " << a.matricula << endl;
        cout << "Nome: " << a.nome << endl;
        cout << "Notas:" << endl;

        bool tem_nota = false;

        for (const auto& n : notas) {
            if (n.matricula == a.matricula) {
                cout << "- " << n.referencia << ": " 
                     << fixed << setprecision(2) << n.valor << endl;
                tem_nota = true;
            }
        }

        if (!tem_nota) {
            cout << "(Nenhuma nota cadastrada)" << endl;
        } else {
            float media = calcular_media(notas, a.matricula);
            cout << "Média: " << fixed << setprecision(2) << media << endl;
        }
    }
}

// Listar apenas 1 aluno
void listar_1aluno(vector<aluno>& alunos, vector<nota>& notas) {

    int matricula;
    cout << "\n CONSULTAR ALUNO" << endl;
    cout << "Matricula: ";
    cin >> matricula;

    for (const auto& a : alunos) {

        if (a.matricula == matricula) {

            cout << "\nMatricula: " << a.matricula << endl;
            cout << "Nome: " << a.nome << endl;
            cout << "Notas:" << endl;

            bool tem_nota = false;

            for (const auto& n : notas) {
                if (n.matricula == matricula) {
                    cout << "- " << n.referencia << ": "
                         << fixed << setprecision(2) << n.valor << endl;
                    tem_nota = true;
                }
            }

            if (!tem_nota) {
                cout << "(Nenhuma nota cadastrada)\n";
            } else {
                float media = calcular_media(notas, matricula);
                cout << "Média: " << fixed << setprecision(2) << media << endl;
            }

            return;
        }
    }

    cout << "\n[ERRO] Aluno não encontrado!\n";
}
