# Um fabricante de molas está interessado em implementar um sistema de controle da qualidade para monitorar seu processo de produção.
# Como parte desse sistema de qualidade, foi decidido registrar o número de molas fora de conformidade, em cada batelada de produção, de
# tamanho igual a 50. Durante a produção, 40 bateladas de dados foram coletadas referentes à produção dos turnos 1 e 2.

# (a) Identifique se existem outliers ; (b) Construa box-plots e histogramas comparativos (use 5 intervalos de classe)
# (c) Que tipo de informação o cálculo dos quartis contêm? (c) Comparando as medidas de dispersão, o que você conclui? (d) Fazendo uma
# análise descritiva geral dos dados qual é o resultado da comparação dos dois turnos?

import numpy as np
import matplotlib.pyplot as plt

T1_data = [9, 12, 6, 9, 7, 14, 12, 4, 6, 7, 8, 5, 9, 7, 8, 11, 3, 6, 7, 7, 11, 4, 4, 8, 7, 5, 6, 4, 5, 8, 19, 9, 18, 12, 11, 17, 15, 17, 13, 13]
T2_data = [10, 5, 9, 8, 10, 11, 10, 7, 7, 13, 11, 8, 6, 4, 2, 15, 13, 8, 8, 7, 5, 11, 9, 7, 9, 21, 3, 6, 8, 7, 18, 10, 4, 8, 7, 5, 6, 4, 15, 8]

# NumPy arrays
T1 = np.array(T1_data)
T2 = np.array(T2_data)

T1_Q1 = np.percentile(T1, [25])
T1_Q3 = np.percentile(T1, [75])
T2_Q1 = np.percentile(T2, [25])
T2_Q3 = np.percentile(T2, [75])
print("T1: Q1 - ", T1_Q1, " e Q3 - ", T1_Q3)
print("T2: Q1 - ", T2_Q1, " e Q3 - ", T2_Q3)

# Histogramas
bins = np.linspace(min(min(T1), min(T2)), max(max(T1), max(T2)), 6) 

plt.figure(figsize=(12, 5))
plt.subplot(1, 2, 1)
plt.hist(T1, bins=bins, edgecolor='black', alpha=0.7)
plt.title('Histograma do Turno 1')
plt.xlabel('Molas com defeito')
plt.ylabel('Frequência')

plt.subplot(1, 2, 2)
plt.hist(T2, bins=bins, edgecolor='black', alpha=0.7)
plt.title('Histograma do Turno 2')
plt.xlabel('Molas com defeito')
plt.ylabel('Frequência')

plt.tight_layout()
plt.show()

# Box plot
data = [T1_data, T2_data]
fig, ax = plt.subplots()
ax.boxplot(data)
ax.set_xticklabels(['T-1', 'T-2'])
plt.title('Boxplot dos Turnos')
plt.show()

# Medidas de dispersão
print("Turno 1:")
print("Média:", T1.mean())
print("Desvio Padrão:", T1.std())
print("Coef variancia:", T1.std()/T1.mean())
print("IQ:", T1_Q3-T1_Q1)
print("Amplitude:", max(T1) - min(T1))

print("Turno 2:")
print("Média:", T2.mean())
print("Desvio Padrão:", T2.std())
print("Coef variancia:", T2.std()/T2.mean())
print("IQ:", T2_Q3-T2_Q1)
print("Amplitude:", max(T2) - min(T2))