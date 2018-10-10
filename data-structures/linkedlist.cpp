
struct node_t {
	int elemento;
	node_t *proximo;
	node_t *anterior;
};
class Listaencadeada{
    private:
        int _n_elementos;
        node_t* _inicio:
        node_t* _fim;
    public:
        Listaencadeada();
        ~Listaencadeada();
        void isere_elemento(int n);//fim
        void insere_primeiro(int n);//inicio
        int get_iesimo(int n);
        void remover_elemento(); //fim
        void remover_primeiro(); //inicio
        void inserir_iesimo(int n, int i);

        void remover_iesimo(int i);
        int tamanho();
};

Listaencadeada::Listaencadeada(){
    this->_inicio = nullptr;
    this->_fim = nullptr;
    this->_n_elementos = 0;
}
Listaencadeada::~Listaencadeada(){
    node_t* atual = _inicio;
    node_t* anterior = nullptr;
    while (atual != nullptr)
    {
        anterior = atual;
        atual = atual->proximo;
        delete anterior;
    }
    delete atual;
    this->_n_elementos = 0;
}
void Listaencadeada::insere_elemento(int n){
    node_t* novo = new node_t();
    novo->elemento = n;
    if(this->_fim == nullptr){
        this->_fim = novo;
        this->_inicio = novo;
        novo->proximo = nullptr;
        novo->anterior = nullptr;
    }else{
        this->_fim->proximo = novo;
        novo->anterior = this->_fim;
        novo->proximo = nullptr;
        this->_fim = novo;
    }
    this->_n_elementos++;
}//fim
void Listaencadeada::insere_primeiro(int n){
    node_t* novo = new node_t();
    novo->elemento = n;
    if(this->_inicio == nullptr){
        this->_inicio = novo;
        this->_fim = novo;
        novo->proximo = nullptr;
        novo->proximo = nullptr;
    }else{
        this->_inicio->anterior = novo;
        novo->proximo = this->_inicio;
        this->_inicio = novo;
    }
    this->_n_elementos++;
}//inicio
int Listaencadeada::get_iesimo(int n){
    node_t* aux = this->_inicio;
    for(int i = 0; i < n; i++){
        aux = aux->proximo;
    }
    return aux->elemento;
}
void Listaencadeada::remover_elemento() {
    node_t* aux = this->_fim;
    this->_fim->anterior->proximo = nullptr;
    this->_fim = this->_fim->anterior;
    this->_n_elementos--;
    delete aux;
}//fim
void Listaencadeada::remover_primeiro(){
    node_t* aux = this->_inicio;
    this->_inicio->proximo->anterior = nullptr;
    this->_inicio = this->_inicio->proximo;
    this->_n_elementos--;
    delete aux;
} //inicio
void Listaencadeada::inserir_iesimo(int n, int i){
    node_t* novo = new node_t();
    novo->elemento = n;
    node_t* now = this->_inicio;
    node_t* prev = nullptr;
    for(int s = 0; s < i; s++){
        prev = now;
        now = now->proximo;
    }
    if(now->anterior == nullptr){
        novo->proximo = this->_inicio;
        novo->anterior = nullptr;
        this->_inicio->anterior = novo;
        this->_inicio = novo;
        this->_n_elementos++;
    }else if(now->proximo == nullptr){
        novo->anterior = this->_fim;
        novo->proximo = nullptr;
        this->_fim->proximo = novo;
        this->_fim = novo;
        this->_n_elementos++;
    }else{
        novo->anterior = prev;
        novo->proximo = now;
        prev->proximo = novo;
        now->anterior = novo;
        this->_n_elementos++;
    }
}
void Listaencadeada::remover_iesimo(int i){
    if(i >= this->_n_elementos){
        return;
    }
    node_t* atual = this->_inicio;
    for(int j=0; j<i;j++){
        atual = atual->proximo;
    }
    if(atual->proximo == nullptr){//fim
        if(atual->anterior == nullptr){
            this->_fim = nullptr;
            this->_inicio = nullptr;
            this->_n_elementos--;
        }else{
            this->_fim = atual->anterior;
            this->_fim->proximo = nullptr;
            this->_n_elementos--;
        }
    }else if(atual == this->_inicio){
            atual->proximo->anterior = nullptr;
            this->_inicio = atual->proximo;
            this->_n_elementos--;
    }else{
            atual->anterior->proximo = atual->proximo;
            atual->proximo->anterior = atual->anterior;
            this->_n_elementos--;
        }
        delete atual;
    }
int Listaencadeada::tamanho(){
    return this->_n_elementos;
}
