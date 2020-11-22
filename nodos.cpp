#include "iostream"

using namespace std;

class nodo{
    public:
        int valor;
        nodo* next; //enlace al siguiente nodo
        nodo(int v, nodo* n);
        
};
nodo::nodo(int v, nodo* n=nullptr){
    valor=v;
    next=n;
}

class LE{
    
    public:
        nodo* head=nullptr;
        void print();
        bool find(int v, nodo*& pos);
        void add(int v);
        void del(int v);
        ~LE();

};

void LE::print(){
    cout << "HEAD->";
    for(nodo* p=head; p; p=p->next){
        cout << p->valor << "->";
    }
    cout << "NULL" << endl;
}

bool LE::find(int v, nodo*& pos){
    bool encontrado = false;
    pos = nullptr;

    for(nodo* p=head; p && p->valor<=v; p=p->next){
        if(p->valor == v){
            encontrado = true;
            break;
        }
        pos = p;
    }
    return encontrado;
}

void LE::add(int v){
    nodo* pos_ant; //t
    if(!find(v, pos_ant)){
        if(pos_ant){
            pos_ant->next = new nodo(v, pos_ant->next);
        }
        else{
            head = new nodo(v, head);   
        }
    }
}

void LE::del(int v){
    nodo* pos_ant;
    nodo* pos_del;
    if(find(v, pos_ant)){
        if(pos_ant){
            pos_del = pos_ant->next;
            pos_ant->next = pos_del->next;
            delete pos_del;
        } else{
            pos_del = head;
            head = pos_del->next;
            delete pos_del;
        }
    }
}

LE::~LE(){
    while(head){
        del(head->valor);
    }
}

void split(nodo*& p, nodo*& q, nodo*& r){
    nodo* ult_q;
    nodo* ult_r;
    cout << "Iniciando Split" << endl;
    for(;p;p=p->next){
        if(p->valor%2==0){
            if(!q){
                q=p;
                ult_q=p;
            }else{
                ult_q->next=p;
                ult_q=p;
            }
        }else{
            if(!r){
                r=p;
                ult_r=p;
            }else{
                ult_r->next=p;
                ult_r=p;
            }
        }
    }
}
int main(){

    LE listaP;
    LE listaQ;
    LE listaR;

    listaP.add(1);
    listaP.add(2);
    listaP.add(3);
    listaP.add(4);
    listaP.add(5);
    listaP.add(6);
    listaP.add(7);
    listaP.add(8);
    listaP.add(9);
    listaP.add(10);
    listaP.add(11);
    listaP.add(12);
    listaP.add(13);
    listaP.add(14);

    listaP.print();
    listaQ.print();
    listaR.print();

    split(listaP.head, listaQ.head, listaR.head);
    
    listaP.print();
    listaQ.print();
    listaR.print();
    
    return 0;
}