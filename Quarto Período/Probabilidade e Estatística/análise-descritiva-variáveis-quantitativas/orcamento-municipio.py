# Os dados representam a porcentagem do orçamento gasto com pessoal para 50 pequenos municípios de certa região.

# (a) comente a distribuição dos dados quanto ao centro, dispersão e forma;
# (b) com base em sua análise, e sabendo que na região considerada existem, ao todo, 200 municípios, em quantos deles você acha que o
# gasto com pessoal é maior que 70% do orçamento?
# (c) em outra região, sabe-se que o gasto médio com pessoal é de 65% e o desvio padrão é de 20%. Qual das duas regiões é mais homogênea
# em relação a essa variável? Por quê?


import numpy as np
import matplotlib.pyplot as plt

data = [69.5, 71.6, 73.0, 68.9, 68.9, 70.0, 72.6, 66.2, 68.1, 72.4, 67.6, 68.2, 72.1,
73.2, 67.6, 69.7, 71.0, 69.4, 71.5, 73.8, 69.6, 69.6, 68.2, 69.9, 68.0, 70.2,
71.4, 70.7, 69.7, 71.0, 66, 70.3, 71.7, 69.2, 69.8, 68.4, 69.5, 70.8, 72.2,
69.4, 67.1, 69.0, 66.3, 69.2, 71.7, 65.6, 69.6, 70.1, 69.9, 70.5]

# NumPy array
array = np.array(data)

# Tabela dos 5 valores - min Q1 md Q3 max
tabela = np.percentile(array, [0, 25, 50, 75, 100])

# Centro e Dispersão
print("Média:", array.mean())
print("Desvio Padrão:", array.std())
print("Mínimo:", tabela[0])
print("Q1:", tabela[1])
print("Mediana:", tabela[2]) 
print("Q3:", tabela[3])
print("Máximo:", tabela[4])

# Forma
plt.figure(figsize=(12, 5))
plt.hist(data, bins=[65, 66, 67, 68, 69, 70, 71, 72, 73], edgecolor='black', alpha=0.7)
plt.title('Histograma da Porcentagem de gasto com pessoal')
plt.xlabel('Porcentagem de gasto')
plt.ylabel('Frequência')
plt.show()

maior70 = (array > 70).sum()
print(maior70) # 20 de 50 -> 80 de 200, se a amostra for representativa