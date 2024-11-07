#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    // Initialisation d'un grand tableau pour simuler une charge de travail
    const int N = 1000000;
    std::vector<int> array(N, 1); // Crée un tableau avec des valeurs de 1
    int sum = 0;

    // Mesurer le temps avant le calcul
    double start_time = omp_get_wtime();

    // Début de la région parallèle
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; ++i) {
        sum += array[i];
    }

    // Mesurer le temps après le calcul
    double end_time = omp_get_wtime();

    // Résultats
    std::cout << "La somme est: " << sum << std::endl;
    std::cout << "Temps d'exécution avec OpenMP: " << (end_time - start_time) << " secondes" << std::endl;

    return 0;
}

