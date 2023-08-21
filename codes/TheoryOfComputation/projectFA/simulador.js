// Importa o módulo 'fs' (File System) para manipulação de arquivos
const fs = require('fs');

// Função para carregar o autômato a partir de um arquivo JSON
function carregarAutomato(caminhoArquivo) {
  // Lê o conteúdo do arquivo e armazena como uma string
  const dadosAutomato = fs.readFileSync(caminhoArquivo, 'utf8');
  
  // Faz o parse da string JSON para criar o objeto automato
  return JSON.parse(dadosAutomato);
}

// Função para carregar os testes de entrada a partir de um arquivo CSV
function carregarEntradasDeTeste(caminhoArquivo) {
  // Lê o conteúdo do arquivo e armazena como uma string
  const dadosEntradasTeste = fs.readFileSync(caminhoArquivo, 'utf8');
  
  // Divide a string em linhas e mapeia cada linha para um objeto entrada/esperado
  const entradasTeste = dadosEntradasTeste.split('\n').map(linha => {
    const [entrada, esperado] = linha.trim().split(';');
    return { entrada, esperado: parseInt(esperado) };
  });
  
  return entradasTeste;
}

// Função para simular o fecho epsilon do autômato a partir de um estado
function fechoEpsilon(automato, estado) {
  const fecho = new Set([estado]); // Conjunto para armazenar estados no fecho epsilon
  const fila = [estado]; // Fila para percorrer estados

  while (fila.length > 0) {
    const estadoAtual = fila.pop(); // Pega o próximo estado da fila
    for (const transicao of automato.transitions) {
      if (transicao.from === estadoAtual && transicao.read === null) {
        const estadoDestino = transicao.to; // Estado alcançável por movimento vazio
        if (!fecho.has(estadoDestino)) {
          fecho.add(estadoDestino); // Adiciona ao fecho
          fila.push(estadoDestino); // Adiciona à fila para explorar mais estados
        }
      }
    }
  }

  return fecho; // Retorna o fecho epsilon
}

// Função para simular o autômato para um teste de entrada
function simularAutomato(automato, entradaTeste) {
  const tempoInicio = process.hrtime(); // Captura o momento de início da simulação

  let estadosAtuais = fechoEpsilon(automato, automato.initial);

  for (const simbolo of entradaTeste) {
    const proximosEstados = new Set();
    for (const estado of estadosAtuais) {
      for (const transicao of automato.transitions) {
        if (transicao.from === estado && (transicao.read === simbolo || transicao.read === null)) {
          proximosEstados.add(transicao.to); // Adiciona estado alcançável por transição
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

// Função principal
function principal(arquivoAutomato, arquivoEntradaTeste, arquivoSaida) {
  const automato = carregarAutomato(arquivoAutomato);
  const entradasTeste = carregarEntradasDeTeste(arquivoEntradaTeste);

  // Mapeia os resultados de simularAutomato para um formato de saída
  const dadosSaida = entradasTeste.map(teste => {
    const resultadoTempo = simularAutomato(automato, teste.entrada);
    return `${teste.entrada};${teste.esperado};${resultadoTempo.resultado ? 1 : 0};${resultadoTempo.tempoDecorrido}`;
  });

  // Escreve os resultados no arquivo de saída
  fs.writeFileSync(arquivoSaida, `${dadosSaida.join('\n')}`);
}

// Verifica se os argumentos da linha de comando são válidos e chama a função principal
if (process.argv.length !== 5) {
  console.log('Uso: node script.js arquivoAutomato arquivoEntradaTeste arquivoSaida');
} else {
  principal(process.argv[2], process.argv[3], process.argv[4]);
}
