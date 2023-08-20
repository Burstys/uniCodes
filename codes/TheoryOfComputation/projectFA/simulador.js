const fs = require('fs');

// Carregar o autômato a partir do arquivo JSON
function carregarAutomato(caminhoArquivo) {
  const dadosAutomato = fs.readFileSync(caminhoArquivo, 'utf8');
  return JSON.parse(dadosAutomato);
}

// Carregar os testes de entrada a partir do arquivo CSV
function carregarEntradasDeTeste(caminhoArquivo) {
  const dadosEntradasTeste = fs.readFileSync(caminhoArquivo, 'utf8');
  const entradasTeste = dadosEntradasTeste.split('\n').map(linha => {
    const [entrada, esperado] = linha.trim().split(';');
    return { entrada, esperado: parseInt(esperado) };
  });
  return entradasTeste;
}

// Simular o autômato utilizando o movimento vazio
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

// Simular o autômato para um teste de entrada
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

// Função principal
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

// Chamada da função principal
if (process.argv.length !== 5) {
  console.log('Uso: node script.js arquivoAutomato arquivoEntradaTeste arquivoSaida');
} else {
  principal(process.argv[2], process.argv[3], process.argv[4]);
}
