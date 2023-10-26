# Os diâmetros de uma peça, medidos em 30 peças diferentes foram manufaturados pela máquina A e os 30 restantes foram manufaturados
# pela máquina B. Ele tem os valores apresentados na tabela dada. Construa uma tabela de distribuição de frequências e um
# histograma. Comente os gráficos, comparando os histogramas obtidos para as máquinas A e B. Faça o resumo estatístico. Que informação o
# box plot que compara Maquina A com B traz nessa situação?

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# dados
data = {
    'Máquina A': [88.24, 87.58, 87.99, 87.89, 88.04, 88.14, 88.1, 88.07, 87.83, 87.77, 87.85, 88.19, 88.39, 87.9, 87.69, 88.18, 87.96, 87.96, 87.93, 88.26, 87.72, 87.59, 88.09, 88.3, 88.12, 88.22, 87.82, 88.01, 88.03, 88.09],
    'Máquina B': [87.80, 88.18, 88.13, 87.92, 88.22, 88.06, 88.15, 88.28, 88.08, 88.04, 88.30, 88.14, 88.14, 87.70, 88.25, 88.30, 88.09, 87.91, 88.03, 88.14, 88.18, 87.98, 87.79, 87.63, 87.82, 87.95, 88.04, 88.14, 88.19, 87.96]
}
df = pd.DataFrame(data)

# Tabela de Resumo estatístico:
# Cálculos para máquina A
data_sizeA = len(df['Máquina A'])
medianA = df['Máquina A'].median()
meanA = df['Máquina A'].mean()
stdevA = df['Máquina A'].std()
varA = df['Máquina A'].var()
cvA = (stdevA / meanA) * 100
maxA = df['Máquina A'].max()
minA = df['Máquina A'].min()
ampA = maxA - minA
quartilA = df['Máquina A'].describe().loc[['25%', '75%']]

# Cálculos para máquina B
data_sizeB = len(df['Máquina B'])
medianB = df['Máquina B'].median()
meanB = df['Máquina B'].mean()
stdevB = df['Máquina B'].std()
varB = df['Máquina B'].var()
cvB = (stdevB / meanB) * 100
maxB = df['Máquina B'].max()
minB = df['Máquina B'].min()
ampB = maxB - minB
quartilB = df['Máquina B'].describe().loc[['25%', '75%']]

tabela = {
    'Estatística': ['Tamanho', 'Mediana', 'Média', 'Desvio Padrão', 'Variância', 'Coeficiente de Variação',
                     'Mínimo', 'Máximo', 'Amplitude', 'Q1', 'Q3'],
    'Máquina A': [data_sizeA, medianA, meanA, stdevA, varA, cvA, minA, maxA, ampA, quartilA[0], quartilA[1]],
    'Máquina B': [data_sizeB, medianB, meanB, stdevB, varB, cvB, minB, maxB, ampB, quartilB[0], quartilB[1]]
}

tabela = pd.DataFrame(tabela)

print(tabela)

# Histograma

minTotal = min(minA, minB)
maxTotal = max(maxA, maxB)

bins = np.arange(int(minTotal), int(maxTotal), 0.05)
df.hist(column='Máquina A', bins=7)
# plt.ylim(0, y_limit)
plt.title('Histograma do Diametro das Peças produzidas pela Máquina A')
plt.xlabel('Diametro')
plt.ylabel('Frequência')
plt.show()

df.hist(column='Máquina B', bins=7)
# plt.ylim(0, y_limit)
plt.title('Histograma do Diametro das Peças produzidas pela Máquina B')
plt.xlabel('Diametro')
plt.ylabel('Frequência')
plt.show()
    
# Criar um boxplot com todos os dados coletados
data_dict = {}
data_dict['A'] = df['Máquina A']
data_dict['B'] = df['Máquina B']

plt.boxplot(data_dict.values(), labels=data_dict.keys())
plt.title('Boxplot dos Diametros das Peças')
plt.xlabel('Máquinas')
plt.ylabel('Diametro')
plt.show()