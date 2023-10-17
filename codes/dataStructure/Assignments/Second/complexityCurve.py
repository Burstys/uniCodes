import numpy as np
import matplotlib.pyplot as plt

x = [5, 10, 15, 20, 25, 30, 35, 40, 45, 50]
y = [0.0477, 0.20063, 0.449567, 0.804533, 1.248233, 1.802, 2.442133, 3.2188, 4.039667, 4.9769]
desvio = [0.000702, 0.002125, 0.003617, 0.00802, 0.010543, 0.016501, 0.013691, 0.065898, 0.31214, 0.027693]

curve = np.polyfit(x, y, 2)
poly = np.poly1d(curve)
desvio_padrao = np.std(desvio)
print(poly)

plt.figure(figsize=(10, 6))
plt.plot(x, y, label='Complexidade da Função de Ordenação')
plt.scatter(x, y, c="black")
plt.fill_between(x, np.array(y) - desvio_padrao, np.array(y) + desvio_padrao, color='lightblue', alpha=0.3, label='Desvio Padrão')
plt.xlabel('Tamanho da Entrada (x1000)')
plt.ylabel('Tempo de Execução (s)')
plt.title('Tempo de Execução x Tamanho da Entrada')
plt.legend()
plt.grid(True)
plt.show()


