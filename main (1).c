/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
//nó da lsita de adjacencia
typedef struct No {
    int numVertices;
    struct No* prox;
}No;
//Estrutura do grafo
typedef struct {
    int numVertices;
    No* listaAdj[MAX];
}Grafo;
//criar grafo
Grafo* criarGrafo(int vertices){
    Grafo* g=(Grafo*)malloc(sizeof(Grafo));
    if(g==NULL){
        printf("erro de memoria\n");
        exit(1);
    }
    g->numVertices=vertices;
    
    //inicializa listas como NULL
    for (int i = 0; i<vertices; i++){
        g->listaAdj[i]=NULL;
        
    }
    return g;
    }
    //criar novo nó
    No*criarNo(int v){
       No*novo = (No*)malloc(sizeof(No));
       novo->vertices=v;
       novo->prox=NULL;
       return novo;
       
    } 
    //adicionar aresta(orientado: só um sentido)
    void adicionarAresta(Grafo*g,int v1, int v2){
        if(v1>=g->numVertices||v2>=g->numVertices){
            printf("vertices invalido!\n");
            return;
            
        }
        No*novo=criarNo(v2);
        novo->prox=g->listaAdj[v1];
        g->listaAdj[v1]=novo;
    }
    //imprimir Grafo
    void imprimirGrafo(Grafo*g){
        printf("\nLista de adjacencia:\n");
        for(int i = 0;i<g->numVertices;i++){
            prinft("%d->",i);
            No*temp=g->listaAdj[i];
            while(temp!=NULL){
                prinft("%d->",temp->vertices);
                temp=temp->prox;
                
            }
            printf("NULL\n");
        }
    }
    //liberar memoria
    void liberarGrafo(Grafo*g){
        for(int i=0;i<g->numVertices;i++){
            No*temp=g->listaAdj[i];
            while(temp!=NULL){
                No*aux=temp;
                temp=temp->prox;
                free(aux);
                
            }
        }
        free(g);
    }
    int main(){
        int vertices,arestas;
        int v1,v2;
        printf("numero de vertices: ");
        scanf("%d",&vertices);
        
        Grafo*g=criarGrafo(vertices);
        
        printf("numero de arestas: ");
        scanf("%d",&arestas);
        
        for(int i=0;i<arestas;i++){
            printf("Aresta %d(origem destino):",i+1);
            scanf("%d %d", &v1, &v2);
            
            adicionarAresta(g, v1, v2);
            
        }
        imprimirGrafo(g);
        liberarGrafo(g);
        return 0;
    }



