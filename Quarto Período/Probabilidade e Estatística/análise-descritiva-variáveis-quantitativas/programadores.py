# Um cientista de computação está investigando a utilidade de duas diferentes linguagens de programação na melhoria das tarefas
# computacionais. Dois grupos de doze programadores com mesmo nível de experiência com ambas as linguagens foram selecionados por
# sorteio e codificaram uma função padrão em uma das linguagens. O tempo em minutos foi registrado, sendo os dados mostrados a seguir:
# L-1 17 16 21 14 18 24 16 14 21 23 13 18
# L-2 18 14 19 11 23 21 10 13 19 24 15 20
# Faça uma análise comparativa baseada em cálculos de estatísticas descritivas, histogramas e box-plot

import numpy as np
import matplotlib.pyplot as plt

L1_data = [17, 16, 21, 14, 18, 24, 16, 14, 21, 23, 13, 18]
L2_data = [18, 14, 19, 11, 23, 21, 10, 13, 19, 24, 15, 20]

# NumPy arrays
L1 = np.array(L1_data)
L2 = np.array(L2_data)

# Tabela dos 5 valores - min Q1 md Q3 max
tabela_L1 = np.percentile(L1, [0, 25, 50, 75, 100])
tabela_L2 = np.percentile(L2, [0, 25, 50, 75, 100])

print("Linguagem 1:")
print("Média:", L1.mean())
print("Desvio Padrão:", L1.std())
print("Mínimo:", tabela_L1[0])
print("Q1:", tabela_L1[1])
print("Mediana:", tabela_L1[2])
print("Q3:", tabela_L1[3])
print("Máximo:", tabela_L1[4])

print("Linguagem 2:")
print("Média:", L2.mean())
print("Desvio Padrão:", L2.std())
print("Mínimo:", tabela_L2[0])
print("Q1:", tabela_L2[1])
print("Mediana:", tabela_L2[2])
print("Q3:", tabela_L2[3])
print("Máximo:", tabela_L2[4])

# Histogramas
bins = np.linspace(min(min(L1), min(L2)), max(max(L1), max(L2)), 8) 

plt.figure(figsize=(12, 5))
plt.subplot(1, 2, 1)
plt.hist(L1, bins=bins, edgecolor='black', alpha=0.7)
plt.title('Histograma da Linguagem 1')
plt.xlabel('Tempo levado')
plt.ylabel('Frequência')

plt.subplot(1, 2, 2)
plt.hist(L2, bins=bins, edgecolor='black', alpha=0.7)
plt.title('Histograma da Linguagem 2')
plt.xlabel('Tempo levado')
plt.ylabel('Frequência')

plt.tight_layout()
plt.show()

# Box plot
data = [L1_data, L2_data]
fig, ax = plt.subplots()
ax.boxplot(data)
ax.set_xticklabels(['L-1', 'L-2'])
plt.title('Boxplot das Linguagens')
plt.show()