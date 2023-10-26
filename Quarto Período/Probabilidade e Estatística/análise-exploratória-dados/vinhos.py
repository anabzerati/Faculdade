import numpy as np
import matplotlib.pyplot as plt

data = np.array([753, 751, 752, 753, 753, 752, 753, 754, 754, 752, 753, 751, 752, 750, 753, 755, 753, 756, 751, 750])

mean = np.mean(data)
median = np.median(data)
std_dev = np.std(data)

# cálculo
z_scores = (data - mean) / std_dev
print(z_scores)

# verifica se todos os valores cálculados estão no intervalo (-3, 3)
within_range = np.all(np.logical_and(z_scores >= -3, z_scores <= 3))

# histograma
plt.hist(data, bins=6, edgecolor='k')
plt.title('Histograma do Volume de Enchimento das Garrafas')
plt.xlabel('Volume (ml)')
plt.ylabel('Frequência')
plt.show()

print("Média:", mean)
print("Mediana:", median)
print("Desvio Padrão:", std_dev)

print("Valores padronizados dentro do intervalo [-3, 3]:", within_range)

if within_range:
    print("A distribuição dos dados está dentro do intervalo [-3, 3] após a padronização.")
else:
    print("A distribuição dos dados não está completamente dentro do intervalo [-3, 3] após a padronização.")

