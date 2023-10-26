import pandas as pd
import matplotlib.pyplot as plt

# Função para realizar a análise e plotagem de um histograma
def analyze_and_plot(df, area_name, price_limit, y_limit, bin_width):
    print(f"-- CASAS DA ÁREA {area_name.upper()} --")
    
    print("Preço:")
    mean_price = df['VALOR DA CASA'].mean()
    std_dev = df['VALOR DA CASA'].std()
    coef_var = (std_dev / mean_price) * 100

    print(f"Média: {mean_price:.2f}")
    print(f"Desvio Padrão: {std_dev:.2f}")
    print(f"Coeficiente de Variação: {coef_var:.2f}%")
    print(df['VALOR DA CASA'].describe().loc[['min', '25%', '50%', '75%', 'max']])

    bins = range(0, price_limit + bin_width, bin_width)
    df.hist(column='VALOR DA CASA', bins=bins)
    plt.ylim(0, y_limit)
    plt.title(f'Histograma do Valor da Casa em Área {area_name}')
    plt.xlabel('Valor da Casa')
    plt.ylabel('Frequência')
    plt.show()

# Nomes das áreas
areas = ['Central', 'Leste', 'Sul', 'Norte', 'Oeste']

# Coletar os dados de todas as áreas
data_dict = {}

# Primeira parte: análise com todos os valores
print("-- ANÁLISE GERAL --")

for area_name in areas:
    df = pd.read_excel('Analise_mercado_imobiliário.xlsx', sheet_name=f'BASE DE DADOS ({area_name.upper()})')
    analyze_and_plot(df, area_name, 2000000, 100, 250000)
    data_dict[area_name] = df['VALOR DA CASA']

# Segunda parte: análise com valores filtrados
print("-- ANÁLISE FILTRADA POR PREÇO MÁXIMO E QUANTIDADE DE DORMITÓRIOS --")

for area_name in areas:
    df = pd.read_excel('Analise_mercado_imobiliário.xlsx', sheet_name=f'BASE DE DADOS ({area_name.upper()})')
    df_limitado = df[(df['VALOR DA CASA'] <= 350000) & (df['NÚMERO DE QUARTOS'] == 3)]
    analyze_and_plot(df_limitado, area_name, 350000, 25, 50000)
    data_dict[area_name] = df_limitado['VALOR DA CASA']

# Criar um boxplot com todos os dados coletados
plt.boxplot(data_dict.values(), labels=data_dict.keys())
plt.title('Boxplot dos Valores das Casas em Todas as Áreas')
plt.xlabel('Áreas')
plt.ylabel('Valor da Casa')
plt.show()
