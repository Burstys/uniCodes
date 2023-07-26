const fs = require('fs');

// Carregando o automato em um objeto
const automatoJSON = fs.readFileSync('transition.json', 'utf-8');
const automatoDefinicoes = JSON.parse(automatoJSON);

const automato = {
    estadoInicial: automatoDefinicoes.initial,
    estadoFinal: automatoDefinicoes.final,
    transicoes: automatoDefinicoes.transitions
};

const transicoes = [];

for (const transicao of automatoDefinicoes.transitions) {
    const { from, read, to } = transicao;
    transicoes.push({ from, read, to });
}

automato.transicoes = transicoes;

// Leitura das entradas do arquivo CSV
const entradas = [];

const entradasCSV = fs.readFileSync('entradas2.csv', 'utf-8');
const linhas = entradasCSV.trim().split('\n');

for (const linha of linhas) {
    const simbolos = linha.trim().split('');
    entradas.push(simbolos);
}

function processarEntradas(automato, entradas) {
    const resultados = [];

    for (const entrada of entradas) {
        const entradasCSV = entrada.join(''); // Transforma o array em uma string
        const resultadoEsperado = entrada[entrada.length - 1]; // Último elemento é o resultado esperado

        // Inicializa o estado atual como o estado inicial do autômato
        let estadoAtual = automato.estadoInicial;

        // Inicializa o tempo de execução
        const inicioTempo = process.hrtime();

        // Percorre a cadeia de entrada
        for (const simboloAtual of entrada) {
            // Obtém as transições a partir do estado atual
            const transicoes = automato.transicoes.filter((transicao) => transicao.from === estadoAtual);

            // Verifica se existe uma transição para o símbolo atual
            const transicoesSimbolo = transicoes.find((transicao) => transicao.read === simboloAtual);

            // Verifica se existe uma transição vazia
            const transicoesVazias = transicoes.find((transicao) => transicao.read === null);

            // Verifica se há transições possíveis
            if (transicoesSimbolo || transicoesVazias) {
                // Atualiza o estado atual com base nas transições encontradas
                estadoAtual = (transicoesSimbolo && transicoesSimbolo.to) || (transicoesVazias && transicoesVazias.to);

                // Se o estado atual for indefinido, a cadeia foi rejeitada
                if (estadoAtual === undefined) {
                    resultados.push({ entrada: entradasCSV, resultadoEsperado, resultadoObtido: 'rejeita', tempoExecucao: calcularTempoExecucao(inicioTempo) });
                    break;
                }
            } else {
                // Se não houver transições possíveis, a cadeia foi rejeitada
                resultados.push({ entrada: entradasCSV, resultadoEsperado, resultadoObtido: 'rejeita', tempoExecucao: calcularTempoExecucao(inicioTempo) });
                break;
            }
        }

        // Se a cadeia foi percorrida completamente e o estado atual está entre os estados finais, a cadeia é aceita
        if (estadoAtual !== undefined && automato.estadoFinal.includes(estadoAtual)) {
            resultados.push({ entrada: entradasCSV, resultadoEsperado, resultadoObtido: 'aceita', tempoExecucao: calcularTempoExecucao(inicioTempo) });
        } else if (estadoAtual !== undefined) {
            // Se a cadeia foi percorrida completamente, mas o estado atual não está entre os estados finais, a cadeia é rejeitada
            resultados.push({ entrada: entradasCSV, resultadoEsperado, resultadoObtido: 'rejeita', tempoExecucao: 0 });
        }
    }

    return resultados;
}

function calcularTempoExecucao(inicioTempo) {
    const fimTempo = process.hrtime(inicioTempo);
    return fimTempo[0] * 1000 + fimTempo[1] / 1000000; // Tempo de execução em milissegundos
}

const resultado = processarEntradas(automato, entradas);
const resultadoTXT = resultado
    .map(({ entrada, resultadoEsperado, resultadoObtido, tempoExecucao }) => `${entrada}, ${resultadoEsperado}, ${resultadoObtido}, ${tempoExecucao}`)
    .join('\n');

fs.writeFileSync('resultadoTXT', resultadoTXT);
