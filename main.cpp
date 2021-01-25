#include <iostream>
using std::cout;
using std::cin;

#include <list>
using std::list;

#include <vector>
using std::vector;


class Aresta{
private:
    unsigned int v1, v2;
    unsigned int peso;
public:
    Aresta ():v1(0),v2(0),peso(0){}
    Aresta (unsigned int v1, unsigned int v2, unsigned int peso):v1(v1),v2(v2),peso(peso){}
    unsigned int getV1() const{
        return v1;
    }
    void setV1(unsigned int value){
        this->v1 = value;
    }
    unsigned int getV2() const{
        return v2;
    }
    void setV2(unsigned int value){
        this->v2 = value;
    }

    unsigned int getPeso() const{
        return peso;
    }
    void setPeso(unsigned int value){
        this->peso = value;
    }
};


class Grafo {
private:
    int n;
    vector<Aresta> vetorDeArestas;
public:
    Grafo(int n):n(n){}

    int getN() const{
        return n;
    }
    void setN(int value){
        this->n = value;
    }

    void AddAresta (int va, int vb, int peso){
        Aresta objAresta(va,vb,peso);
        vetorDeArestas.push_back(objAresta);
    }

    //Reliza uma busca no vetor de controle inicializado com -1, com isso
    //Torna-se possivel determinar, se exitem ou não ciclos vetor auxiliar
    int buscaAresta (int vetor[], int v){
        if (vetor[v]==-1){
            return v;
        }
        return buscaAresta(vetor, vetor[v]);
    }

    vector<Aresta>  Kruskal (){
        int * vetorAux = new int[n];
        for (int i = 0; i < n; i++){
            vetorAux[i] = -1;
        }
        vector<Aresta> vetorArvore;

        for (int j = 0; j < n; j++){
            Aresta v1 = vetorDeArestas[j];
            Aresta v2 = vetorDeArestas[j];
            int va = buscaAresta(vetorAux, v1.getV1());
            int vb = buscaAresta(vetorAux, v2.getV2());
            //Se forem iguais possui ciclo
            if (va!=vb){
                int va1 = buscaAresta(vetorAux, va);
                int vb1 = buscaAresta(vetorAux, vb);
                vetorAux[va1] = vb1;
                vetorArvore.push_back(vetorDeArestas[j]);
                vetorAux[va] = vb;
            }
        }
        return vetorArvore;
    }

    void arvoreMinima (Aresta raiz){
        int VS = new int [n];
        bool controle = new bool[n];
        for (int i = 0; i < n; i++){
            VS[i] = i+1;
            controle[i] = false;
        }
        VS[0] = raiz.getV1();

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (VS[i] == vetorDeArestas[j]){

                }
            }
        }
    }

    vector<Aresta> getVetorDeArestas() const{
        return vetorDeArestas;
    }
    void setVetorDeArestas(const vector<Aresta> &value){
        vetorDeArestas = value;
    }
};

int main (){
    Grafo objGrafo(5);
    objGrafo.AddAresta(1,2,2);
    objGrafo.AddAresta(1,3,1);
    objGrafo.AddAresta(3,4,1);
    objGrafo.AddAresta(3,4,4);
    objGrafo.AddAresta(3,2,5);


    vector<Aresta> vetor = objGrafo.Kruskal();

    for (int i = 0; i < vetor.size(); i ++){
        Aresta v1 =  vetor[i];
        cout<<"("<<v1.getV1()<<","<<v1.getV2()<<")"<<" Peso: "<<v1.getPeso()<<"\n";
    }





}
