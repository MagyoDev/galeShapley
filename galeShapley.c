#include <stdio.h>
#include <stdbool.h>

#define N 4  

bool prefereOutro(int preferencia[], int candidato, int outroCandidato) {
    for (int i = 0; i < N; i++) {
        if (preferencia[i] == outroCandidato) {
            return false;
        }
        if (preferencia[i] == candidato) {
            return true;
        }
    }
    return false;
}

void galeShapley(int preferenciaCandidatos[N][N], int preferenciaSetores[N][N]) {
    int setorParceiro[N];
    bool candidatoOcupado[N] = {false};
    int propostasFeitas[N] = {0};
    for (int i = 0; i < N; i++) {
        setorParceiro[i] = -1;
    }
    int candidatosLivres = N;
    while (candidatosLivres > 0) {
        int candidato;
        for (candidato = 0; candidato < N; candidato++) {
            if (!candidatoOcupado[candidato]) {
                break;
            }
        }
        int setor = preferenciaCandidatos[candidato][propostasFeitas[candidato]];
        propostasFeitas[candidato]++;
        if (setorParceiro[setor] == -1) {
            setorParceiro[setor] = candidato;
            candidatoOcupado[candidato] = true;
            candidatosLivres--;
        } else {
            int candidatoAtual = setorParceiro[setor];
            if (prefereOutro(preferenciaSetores[setor], candidato, candidatoAtual)) {
                setorParceiro[setor] = candidato;
                candidatoOcupado[candidato] = true;
                candidatoOcupado[candidatoAtual] = false;
            }
        }
    }
    printf("Casamentos Estáveis (Candidato - Setor):\n");
    for (int i = 0; i < N; i++) {
        printf("Candidato %d - Setor %d\n", setorParceiro[i] + 1, i + 1);
    }
}

int main() {
    int preferenciaCandidatos[N][N];
    int preferenciaSetores[N][N];
    
    printf("Digite as preferências dos candidatos para os setores:\n");
    for (int i = 0; i < N; i++) {
        printf("Candidato %d: ", i + 1);
        for (int j = 0; j < N; j++) {
            scanf("%d", &preferenciaCandidatos[i][j]);
            preferenciaCandidatos[i][j]--;  
        }
    }
    
    printf("\nDigite as preferências dos setores para os candidatos:\n");
    for (int i = 0; i < N; i++) {
        printf("Setor %d: ", i + 1);
        for (int j = 0; j < N; j++) {
            scanf("%d", &preferenciaSetores[i][j]);
            preferenciaSetores[i][j]--;
        }
    }
    
    galeShapley(preferenciaCandidatos, preferenciaSetores);
    return 0;
}
