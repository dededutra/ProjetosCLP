// André Dutra da Silva
#include <stdio.h>

#define MAX_SIZE 1024
#define MAX_WORD 100
#define SIZE_POLO 50

int topStack = 0;
int top = 0;
int next = 0;
int topPolonesa = 0;
char arvoreVet[MAX_SIZE];
int pilha[MAX_WORD];
char stack[MAX_WORD];
char palavra[MAX_WORD];
char polonesaRev[SIZE_POLO];
void pushStack(int valor);
int popStack();
int readStack();
void startArv(char *arvo);
void putArv(int p);
void P2B(char *arvoreNew);
void PostOrder(char *arvo, int indice);
void Pcode();
void arv(char *arvo, int indice, int nivel);
int sizeWord(char *palavra);
void coluna();
void push(char *valor);
void pop();
char read();
char getNext();
void erro(int i);
void end(int i, char *estado, char *tran, char *p);

void Pcode()
{
    for(int i = 0; polonesaRev[i] != '\0'; i++)
    {
        switch (polonesaRev[i])
        {
            case 'a':
                printf("   \tLOD 0 3");
                break;
            case 'b':
                printf("   \tLOD 0 4");
                break;
            case 'c':
                printf("   \tLOD 0 5");
                break;
            case '1':
                printf("   \tLIT 0 1");
                break;
            case '0':
                printf("   \tLIT 0 0");
                break;
            case '+':
                printf("   \tOPR 0 2");
                break;
            case '-':
                printf("   \tOPR 0 3");
                break;
            case '*':
                printf("   \tOPR 0 4");
                break;
            case '/':
                printf("   \tOPR 0 5");
                break;
            default:
                break;
        
        }
        printf("\n");
    }
}


int main()
{
    char token;
    int i = 0;
    FILE *fp;
    char arvoreBi[MAX_SIZE];

   
    fp = fopen("input.txt", "r");
    if(fp == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return 0;
    }

    fscanf(fp, "%s", palavra);
    fclose(fp);

    startArv(arvoreVet);
    coluna();

    q0:
        end(i, "q0", "t0", "-");
        token = palavra[top];
        push("E");
        putArv(0);
        goto q1;
    q1:
        i++;
        if(token == '(' && read() == 'E')      {end(i, "q1", "t1", "p1"); pop(); push("(EXE)"); putArv(1); goto q1;}
        else if(token == '0' && read() == 'E') {end(i, "q1", "t2", "p2"); pop(); push("0"); putArv(2); goto q1;}
        else if(token == '1' && read() == 'E') {end(i, "q1", "t3", "p3"); pop(); push("1"); putArv(3); goto q1;}
        else if(token == 'a' && read() == 'E') {end(i, "q1", "t4", "p4"); pop(); push("a"); putArv(4); goto q1;}
        else if(token == 'b' && read() == 'E') {end(i, "q1", "t5", "p5"); pop(); push("b"); putArv(5); goto q1;}
        else if(token == 'c' && read() == 'E') {end(i, "q1", "t6", "p6"); pop(); push("c"); putArv(6); goto q1;}
        else if(token == '+' && read() == 'X') {end(i, "q1", "t7", "p7"); pop(); push("+"); putArv(7); goto q1;}
        else if(token == '-' && read() == 'X') {end(i, "q1", "t8", "p8"); pop(); push("-"); putArv(8); goto q1;}
        else if(token == '*' && read() == 'X') {end(i, "q1", "t9", "p9"); pop(); push("*"); putArv(9); goto q1;}
        else if(token == '/' && read() == 'X') {end(i, "q1", "t10", "p10"); pop(); push("/"); putArv(10); goto q1;}

        else if(token == 'a' && read() == 'a') {end(i, "q1", "t11", "-"); pop(); token = getNext(); goto q1;}
        else if(token == 'b' && read() == 'b') {end(i, "q1", "t12", "-"); pop(); token = getNext(); goto q1;}
        else if(token == 'c' && read() == 'c') {end(i, "q1", "t13", "-"); pop(); token = getNext(); goto q1;}
        else if(token == '0' && read() == '0') {end(i, "q1", "t14", "-"); pop(); token = getNext(); goto q1;}
        else if(token == '1' && read() == '1') {end(i, "q1", "t15", "-"); pop(); token = getNext(); goto q1;}
        else if(token == '(' && read() == '(') {end(i, "q1", "t16", "-"); pop(); token = getNext(); goto q1;}
        else if(token == ')' && read() == ')') {end(i, "q1", "t17", "-"); pop(); token = getNext(); goto q1;}
        else if(token == '+' && read() == '+') {end(i, "q1", "t18", "-"); pop(); token = getNext(); goto q1;}
        else if(token == '-' && read() == '-') {end(i, "q1", "t19", "-"); pop(); token = getNext(); goto q1;}
        else if(token == '*' && read() == '*') {end(i, "q1", "t20", "-"); pop(); token = getNext(); goto q1;}
        else if(token == '/' && read() == '/') {end(i, "q1", "t21", "-"); pop(); token = getNext(); goto q1;}
        else if(token == '\0' && top == 0)    { end(i, "q1", "-", "-"); goto end;}
        else {erro(1); return 0;}
    end:
        P2B(arvoreBi);

        PostOrder(arvoreBi, 0);
        polonesaRev[topPolonesa] = '\0';
        printf("\np-code:\n");
        Pcode();
        printf("\nNotacao Polonesa:\n%s", polonesaRev);

       

    return 0;
}


void P2B(char *arvoreNew)
{
    int p, a;

    startArv(arvoreNew);

    for(int i=MAX_SIZE; i >= 0; i--)
    {
        if(arvoreVet[i] == 'a' || arvoreVet[i] == 'b' || arvoreVet[i] == 'c' || arvoreVet[i] == '0' || arvoreVet[i] == '1')
        {
            
            p = (i-1)/5;
            arvoreNew[p] = arvoreVet[i];
            arvoreNew[i] = ' ';
            
        }
        else if(arvoreVet[i] == '+' || arvoreVet[i] == '-' || arvoreVet[i] == '*' || arvoreVet[i] == '/')
        {
            
            p = (i-1)/5;
            a = (p-1)/5;
            arvoreNew[p] = ' ';
            arvoreNew[a] = arvoreVet[i];
            arvoreNew[i] = ' ';
        }
    }
}

void pushStack(int valor)
{
    pilha[topStack++] = valor;
}

int popStack()
{
    return pilha[--topStack];
}

int readStack()
{
    return pilha[topStack-1];
}

void startArv(char *arvo)
{
    for(int i = 0; i<MAX_SIZE;i++)
        arvo[i] = ' ';
}

void putArv(int p)
{
    if(p == 0)
    {
        arvoreVet[0] = 'E';
        pushStack(0);
    }
    else if(p == 1)
    {
        int no = popStack();
        arvoreVet[5* no + 1] = '(';
        arvoreVet[5* no + 2] = 'E';
        arvoreVet[5* no + 3] = 'X';
        arvoreVet[5* no + 4] = 'E';
        arvoreVet[5* no + 5] = ')';
        pushStack(5* no + 4);
        pushStack(5* no + 3);
        pushStack(5* no + 2);
    }
    else if(p == 2)
    {
        int no = popStack();
        arvoreVet[5 * no + 1] = '0';
    }
    else if(p == 3)
    {
        int no = popStack();
        arvoreVet[5 * no + 1] = '1';
    }
    else if(p == 4)
    {
        int no = popStack();
        arvoreVet[5 * no + 1] = 'a';
    }
    else if(p == 5)
    {
        int no = popStack();
        arvoreVet[5 * no + 1] = 'b';
    }
    else if(p == 6)
    {
        int no = popStack();
        arvoreVet[5 * no + 1] = 'c';
    }
    else if(p == 7)
    {
        int no = popStack();
        arvoreVet[5 * no + 1] = '+';
    }
    else if(p == 8)
    {
        int no = popStack();
        arvoreVet[5 * no + 1] = '-';
    }
    else if(p == 9)
    {
        int no = popStack();
        arvoreVet[5 * no + 1] = '*';
    }
    else if(p == 10)
    {
        int no = popStack();
        arvoreVet[5 * no + 1] = '/';
    }
    
}


void PostOrder(char *arvo, int indice)
{
    if(arvo[indice] != ' ')
    {
        PostOrder(arvo, 5*indice+2);
        PostOrder(arvo, 5*indice+4);
        polonesaRev[topPolonesa++] = arvo[indice];
    }
}


void arv(char *arvo, int indice, int nivel) 
{
    if (indice < MAX_SIZE && arvo[indice] != ' ') 
    {
        for (int i = 0; i < nivel; i++) 
            printf("   ");

        printf("|-- %c\n", arvo[indice]);

        arv(arvo, 5 * indice + 1, nivel + 1); 
        arv(arvo, 5 * indice + 2, nivel + 1); 
        arv(arvo, 5 * indice + 3, nivel + 1); 
        arv(arvo, 5 * indice + 4, nivel + 1); 
        arv(arvo, 5 * indice + 5, nivel + 1); 
    }
}

int sizeWord(char *palavra)
{
    int tam = -1;
    for(int i = 0; palavra[i] != '\0'; i++)
        tam++;

    return tam;
}

void coluna(){
    int tamPal = sizeWord(palavra);
     printf("\n====================================================\n"); 

    printf("  i |  q  |");

    for(int i = 0; i < tamPal;i++)
    {
        if(i == tamPal/2)
            printf(".w");
    
        printf(" ");
    }

    printf("  |  t  |  p  | Stack\n");
    for(int i = 0; i < tamPal + 40; i++)
        printf("=");

}

void push(char *valor)
{
    int tam = sizeWord(valor);

    for (int i = 0; valor[i] != '\0'; i++)
    {
        stack[top] = valor[tam-i];
        top++;
    }
}

void pop()
{
    top--;
}

char read()
{
    return stack[top-1];
}

char getNext()
{
    next++;
    char token = palavra[next];
    return token;
}

void erro(int i)
{
    if(i == 1){
        printf("\n\n\tErro, palavra nao reconhecida\n");
    }
}

void end(int i, char *estado, char *tran, char *p)
{
    printf("\n");
    printf("%3d | ", i);
    printf("%3s | ", estado);

    for(int j = 0; palavra[j] != '\0'; j++)
    {
        if(j == next){
            printf(".");
        }
        printf("%c", palavra[j]);
    }

    if(palavra[next] == '\0')
        printf(".");

    printf(" | ");
    printf("%3s | ", tran);
    printf("%3s | ", p);

    if(top == 0)
        printf("vazio");
    else
        for(int j = top-1; j >= 0; j--)
            printf("%c", stack[j]);
}
