import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import statsmodels.api as sm

# dados
data = {
    'Coluna1': [1, 2, 3, 4, 5],
    'Coluna2': [2, 4, 1, 3, 5]
}
df = pd.DataFrame(data)

# Matriz de correlação
correlation_matrix = df.corr()
correlation = df['x'].corr(df['y'])
print(correlation_matrix)

# Análise de Regressão
X = df['Coluna1']
X = sm.add_constant(X)  # constante para o intercepto
y = df['Coluna2']

model = sm.OLS(y, X).fit()

# estatísticas do modelo
print(model.summary()) 

# gráfico de dispersão
plt.scatter(df['Coluna1'], df['Coluna2'], label='Pontos de Dados')

# reta de regressão linear
plt.plot(df['Coluna1'], model.predict(X), color='red', label='Reta de Regressão Linear')

plt.title('Gráfico de Regressão Linear')
plt.xlabel('Coluna1')
plt.ylabel('Coluna2')
plt.legend()
plt.show()

# erros
residuo = y - model.predict(X)
plt.scatter(df['Coluna1'], residuo, label='Resíduos')
plt.axhline(y=0, color='r', linestyle='--', label='Linha de Zero Resíduo')  # Adiciona uma linha de referência em zero
plt.title('Gráfico de Dispersão dos Resíduos')
plt.xlabel('Coluna1')
plt.ylabel('Resíduos')
plt.legend()
plt.show()
