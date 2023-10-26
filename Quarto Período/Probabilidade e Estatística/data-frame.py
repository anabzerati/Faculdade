import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# ler planilha
df = pd.read_excel('Analise_mercado_imobiliário.xlsx', sheet_name='0. BASE DE TUDO');

#imprimir data frame
# print(df)
print(df['VALOR DA CASA'])

#média 
# print(df.mean())
print(df['VALOR DA CASA'].mean())

# desvio padrão
# print(df.std())
print(df['VALOR DA CASA'].std())

# five number summary
# print(df.describe().loc[['min', '25%', '50%', '75%', 'max']])
print(df['VALOR DA CASA'].describe().loc[['min', '25%', '50%', '75%', 'max']])

# histograma
df.hist(column='VALOR DA CASA')
plt.title('Histograma do Valor da Casa')
plt.xlabel('Valor da Casa')
plt.ylabel('Frequência')
plt.show()

bins = [0,2,4,6,8] #intervalos
plt.hist(x, color='red', edgecolor="black", bins=bins, label="X values")
plt.axvline(x=np.nanmedian(x), label="Median")
plt.xlabel("Intervals")
plt.ylabel("Frequency")
plt.title("Frequency x Values")
plt.legend(loc=2)
plt.show()

# filtrar linhas
df2 = df[(df['VALOR DA CASA'] <= 300000) & (df['NÚMERO DE QUARTOS'] == 3)]
print(df2)

# gráfico de dispersão
plt.scatter(df['Coluna1'], df['Coluna2'])
plt.title('Gráfico de Dispersão entre Coluna1 e Coluna2')
plt.xlabel('Coluna1')
plt.ylabel('Coluna2')
plt.show()