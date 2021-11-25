//declaração dos vetores a serem usados
int main() {
    int vetor[] = {78, 1, 289, 294, 999};
    int X = sizeof(vetor) / sizeof(vetor[0]);
    radixsort(vetor, X);
    return 0;
}

int numero(int vetor[], int X) {
    int variavel = vetor[0];
    int i;
    for (i = 1; i < X; i++)
        if (vetor[i] > variavel)
            variavel = vetor[i];
    return variavel;
}
// função para classificar s vetores comparado pelo valor de N
void radixsort(int vetor[], int X) {
    int n = numero(vetor, X);
 
    int cla;
    for (cla = 1; n / cla > 0; cla *= 10)
        countSort(vetor, X, cla);
}
//classifica itens em chaves num intervalo determinado, calcula a
//saída usando uma função determinada
 void countSort(int vetor[], int X, int saida) {
    int sai[X]; 
    int i, count[10] = { 0 };
 
    // formulas para realizar a separação em ordem
    for (i = 0; i < X; i++)
        count[(vetor[i] / saida) % 10]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // mostrar a ordem dos vetores na saída
    for (i = X - 1; i >= 0; i--) {
        sai[count[(vetor[i] / saida) % 10] - 1] = vetor[i];
        count[(vetor[i] / saida) % 10]--;
    }
 
    for (i = 0; i < X; i++)
        vetor[i] = sai[i];
}
