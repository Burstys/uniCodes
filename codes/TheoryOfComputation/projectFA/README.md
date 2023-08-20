# Descrição - Simulador de Autômatos

- O simulador consiste em 2 (duas) entradas com dados, sendo uma JSON (.aut) contendo as configurações do autômato e outra CSV (.in) contendo as entradas a serem lidas e seus respectivos resultados esperados.

# Funções utilizadas na elaboração do simulador de autômatos:

>Importando o módulo fs:
- O código começa importando o módulo fs, que é o módulo de sistema de arquivos do Node.js. Ele permite a leitura e escrita de arquivos.
````
const fs = require('fs');
````

>Definindo funções de carregamento de dados:
- carregarAutomato(caminhoArquivo): Esta função lê um arquivo JSON que contém a especificação do autômato e o converte em um objeto JavaScript usando JSON.parse.
````
function carregarAutomato(caminhoArquivo) {
  const dadosAutomato = fs.readFileSync(caminhoArquivo, 'utf8');
  return JSON.parse(dadosAutomato);
}
````
- carregarEntradasDeTeste(caminhoArquivo): Esta função lê um arquivo CSV que contém as entradas de teste e os resultados esperados, e transforma os dados em um array de objetos.
````
function carregarEntradasDeTeste(caminhoArquivo) {
  const dadosEntradasTeste = fs.readFileSync(caminhoArquivo, 'utf8');
  const entradasTeste = dadosEntradasTeste.split('\n').map(linha => {
    const [entrada, esperado] = linha.trim().split(';');
    return { entrada, esperado: parseInt(esperado) };
  });
  return entradasTeste;
}
````

>Definindo a função de cálculo do fecho epsilon:
- fechoEpsilon(automato, estado): Esta função recebe um autômato e um estado como entrada e calcula o fecho epsilon desse estado. O fecho epsilon é o conjunto de todos os estados alcançáveis a partir do estado atual através de movimentos vazios.
````
function fechoEpsilon(automato, estado) {
  const fecho = new Set([estado]); // Conjunto para armazenar os estados no fecho epsilon
  const fila = [estado]; // Fila para percorrer os estados

  while (fila.length > 0) {
    const estadoAtual = fila.pop(); // Pegar o próximo estado da fila
    for (const transicao of automato.transitions) {
      if (transicao.from === estadoAtual && transicao.read === null) {
        const estadoDestino = transicao.to; // Estado alcançável por movimento vazio
        if (!fecho.has(estadoDestino)) {
          fecho.add(estadoDestino); // Adicionar ao fecho
          fila.push(estadoDestino); // Adicionar à fila para explorar mais estados
        }
      }
    }
  }

  return fecho; // Retorna o fecho epsilon
}
````
>Definindo a função de simulação do autômato:
- simularAutomato(automato, entradaTeste): Esta função simula o autômato para uma determinada entrada de teste. Ela utiliza o conceito de fecho epsilon para calcular todos os estados alcançáveis a cada passo da entrada.
````
function simularAutomato(automato, entradaTeste) {
  let estadosAtuais = fechoEpsilon(automato, automato.initial);

  for (const simbolo of entradaTeste) {
    const proximosEstados = new Set();
    for (const estado of estadosAtuais) {
      for (const transicao of automato.transitions) {
        if (transicao.from === estado && (transicao.read === simbolo || transicao.read === null)) {
          proximosEstados.add(transicao.to); // Adicionar estado alcançável por transição
        }
      }
    }
    estadosAtuais = new Set();
    for (const estado of proximosEstados) {
      estadosAtuais = new Set([...estadosAtuais, ...fechoEpsilon(automato, estado)]);
    }
  }

  return [...estadosAtuais].some(estado => automato.final.includes(estado)); // Verificar se algum estado final foi alcançado
}
````
>Função principal:
- principal(arquivoAutomato, arquivoEntradaTeste, arquivoSaida): A função principal carrega a especificação do autômato e as entradas de teste, e executa a simulação do autômato para cada entrada. Ela também mede o tempo de execução usando new Date().getTime() para calcular o tempo em milissegundos entre o início e o fim da simulação.
````
function principal(arquivoAutomato, arquivoEntradaTeste, arquivoSaida) {
  const automato = carregarAutomato(arquivoAutomato);
  const entradasTeste = carregarEntradasDeTeste(arquivoEntradaTeste);

  const dadosSaida = entradasTeste.map(teste => {
    const tempoInicio = new Date().getTime();
    const resultado = simularAutomato(automato, teste.entrada);
    const tempoFinal = new Date().getTime();
    const tempoDecorrido = (tempoFinal - tempoInicio);
    return `${teste.entrada};${teste.esperado};${resultado ? 1 : 0};${tempoDecorrido}`;
  });

  fs.writeFileSync(arquivoSaida, `${dadosSaida.join('\n')}`);
}
````
>Chamada da função principal:
- O código verifica se o número de argumentos passados na linha de comando é igual a 5 (incluindo o próprio nome do script). Se não for, exibe uma mensagem de uso correto. Caso contrário, chama a função principal com os caminhos dos arquivos de entrada e saída fornecidos na linha de comando.
````
if (process.argv.length !== 5) {
  console.log('Uso: node script.js arquivoAutomato arquivoEntradaTeste arquivoSaida');
} else {
  principal(process.argv[2], process.argv[3], process.argv[4]);
}
````