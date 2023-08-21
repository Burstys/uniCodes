# Descrição - Simulador de Autômatos

- O simulador consiste em 2 (duas) entradas com dados, sendo uma JSON (.aut) contendo as configurações do autômato e outra CSV (.in) contendo as entradas a serem lidas e seus respectivos resultados esperados.

### Caminho para o respositório no GitHub: https://github.com/Burstys/uniCodes/tree/master/codes/TheoryOfComputation/projectFA

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
  const tempoInicio = process.hrtime(); // Captura o momento de início da simulação

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

  const tempoFinal = process.hrtime(tempoInicio); // Captura o tempo decorrido usando hrtime
  const tempoDecorrido = (tempoFinal[0] * 1e9 + tempoFinal[1]) / 1e6; // Converte para milissegundos

  return {
    resultado: [...estadosAtuais].some(estado => automato.final.includes(estado)),
    tempoDecorrido: tempoDecorrido
  };
}
````
>Função principal:
- principal(arquivoAutomato, arquivoEntradaTeste, arquivoSaida): A função principal carrega a especificação do autômato e as entradas de teste, e executa a simulação do autômato para cada entrada.
````
function principal(arquivoAutomato, arquivoEntradaTeste, arquivoSaida) {
  const automato = carregarAutomato(arquivoAutomato);
  const entradasTeste = carregarEntradasDeTeste(arquivoEntradaTeste);

  const dadosSaida = entradasTeste.map(teste => {
    const resultadoTempo = simularAutomato(automato, teste.entrada);
    return `${teste.entrada};${teste.esperado};${resultadoTempo.resultado ? 1 : 0};${resultadoTempo.tempoDecorrido}`;
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
>Exemplo de uso
- Com base no seguinte autômato:
````
{
    "initial": 0,
    "final" : [4,7],
    "transitions": [
      {"from": 0, "read": "a", "to": 1 },
      {"from": 1, "read": "b", "to": 3 },
      {"from": 2, "read": "a", "to": 3 },
      {"from": 3, "read": "b", "to": 4 },
      {"from": 4, "read": "a", "to": 4 },
      {"from": 7, "read": "c", "to": 1 },
      {"from": 4, "read": null, "to": 0 }
    ]
  }
````
- E nas seguintes entradas:
````
aababababbbababa;1
abb;1
aaabba;0
````
- O resultado obtido é:
````
aababababbbababa;1;0;0.0966
abb;1;1;0.0442
aaabba;0;0;0.2084
````