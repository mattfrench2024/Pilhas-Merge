#include <iostream>
using namespace std;

// ----------------- Pilha com Lista Encadeada -------------------
struct Node {
    int data;
    Node* next;
};

class PilhaLista {
private:
    Node* topo;

public:
    PilhaLista() {
        topo = nullptr;
    }

    void push(int valor) {
        Node* novo = new Node;
        novo->data = valor;
        novo->next = topo;
        topo = novo;
    }

    int pop() {
        if (topo == nullptr) {
            cerr << "Pilha vazia!" << endl;
            return -1;
        }
        int valor = topo->data;
        Node* temp = topo;
        topo = topo->next;
        delete temp;
        return valor;
    }

    bool isEmpty() {
        return topo == nullptr;
    }

    void exibirDecrescente() {
        while (!isEmpty()) {
            cout << pop() << " ";
        }
        cout << endl;
    }
};

// ----------------- Pilha com Vetor -------------------
class PilhaVetor {
private:
    int topo;
    int dados[30];

public:
    PilhaVetor() {
        topo = -1;
    }

    void push(int valor) {
        if (topo >= 29) {
            cerr << "Pilha cheia!" << endl;
            return;
        }
        dados[++topo] = valor;
    }

    int pop() {
        if (topo < 0) {
            cerr << "Pilha vazia!" << endl;
            return -1;
        }
        return dados[topo--];
    }

    bool isEmpty() {
        return topo == -1;
    }

    void exibirDecrescente() {
        while (!isEmpty()) {
            cout << pop() << " ";
        }
        cout << endl;
    }
};

// ----------------- Função Principal -------------------
int main() {
    int numero;
    int anterior = -2147483648; // menor int possível

    PilhaLista paresLista, imparesLista;
    PilhaVetor paresVetor, imparesVetor;

    cout << "Digite 30 numeros inteiros em ordem crescente:\n";

    for (int i = 0; i < 30; ++i) {
        do {
            cout << "Numero [" << i + 1 << "]: ";
            cin >> numero;
            if (numero <= anterior) {
                cout << "Erro: o numero deve ser maior que o anterior (" << anterior << ").\n";
            }
        } while (numero <= anterior);

        anterior = numero;

        if (numero % 2 == 0) {
            paresLista.push(numero);
            paresVetor.push(numero);
        } else {
            imparesLista.push(numero);
            imparesVetor.push(numero);
        }
    }

    cout << "\n--- Desempilhando com LISTA ENCADEADA ---";
    cout << "\nPares (decrescente): ";
    paresLista.exibirDecrescente();

    cout << "Impares (decrescente): ";
    imparesLista.exibirDecrescente();

    cout << "\n--- Desempilhando com VETOR ---";
    cout << "\nPares (decrescente): ";
    paresVetor.exibirDecrescente();

    cout << "Impares (decrescente): ";
    imparesVetor.exibirDecrescente();

    return 0;
}
