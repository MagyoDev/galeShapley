# Algoritmo Gale-Shapley para Emparelhamento Estável

Este projeto implementa o algoritmo de Gale-Shapley em C para encontrar um emparelhamento estável entre candidatos e setores. O algoritmo é adaptado para que cada candidato tenha uma lista de setores em ordem de preferência, e cada setor tenha uma lista de candidatos preferidos. O programa permite a entrada dessas preferências e retorna um conjunto de pares estáveis entre candidatos e setores.

## Descrição do Algoritmo

O algoritmo de Gale-Shapley é uma solução para o problema de emparelhamento estável. Em nosso caso, cada candidato propõe a um setor na sua lista de preferência, e o setor decide temporariamente aceitar ou rejeitar o candidato com base em suas próprias preferências. O processo se repete até que todos os candidatos e setores estejam emparelhados de forma estável, ou seja, sem que qualquer candidato ou setor prefira um emparelhamento diferente.

## Funcionalidades

- **Entrada de preferências**: Permite que o usuário insira preferências tanto para candidatos quanto para setores.
- **Emparelhamento estável**: Retorna uma lista de pares estáveis entre candidatos e setores.
