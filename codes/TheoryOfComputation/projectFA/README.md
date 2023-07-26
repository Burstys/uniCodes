# Descrição - Simulador de Autômatos

- O simulador consiste em 2 (duas) entradas com dados, sendo uma JSON contendo as configurações do autômato e outra CSV contendo as entradas a serem lidas e seus respectivos resultados esperados.

### Para a elaboração do simulador, foram utilizadas as seguintes funções e métodos:
>fs = Módulo voltado a interação com arquivos que permite a leitura e gravação de arquivos
````
const fs = require('fs');
````
>fs.fileReadSync() = função utilizada para ler um arquivo de forma síncrona, onde a leitura completa é realizada antes de prosseguir com a execução do código
````
const automatoJSON = fs.readFileSync('transition.json', 'utf-8');
````
>JSON.parse() = função utilizada para converter em objeto JavaScript uma string do arquivo JSON
````
const automatoDefinicoes = JSON.parse(automatoJSON);
````
>automato = objeto criado para representar o autômato e armazenar as informações obtidas a partir do arquivo JSON, tendo as propriedades "estadoInicial", "estadoFinal" e "transicoes"
````
const automato = {
    estadoInicial: automatoDefinicoes.initial,
    estadoFinal: automatoDefinicoes.final,
    transicoes: automatoDefinicoes.transitions
};
````
automato.transicoes = array criado para armazenar as transições contidas no autômato, formadas por um objeto que contém os campos "from", "read" e "to"
````
const transicoes = [];

for (const transicao of automatoDefinicoes.transitions) {
    const { from, read, to } = transicao;
    transicoes.push({ from, read, to });
}

automato.transicoes = transicoes;
````
>processarEntradas() = função que recebe como parâmetros o autômato e as entradas a partir dos arquivos JSON e CSV, respectivamente, percorrendo e verificando se cada entrada é aceita ou não
````
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
                    resultados.push({ entrada: entradasCSV, resultadoEsperado, resultadoObtido: 'rejeita', tempoExecucao: 0 });
                    break;
                }
            } else {
                // Se não houver transições possíveis, a cadeia foi rejeitada
                resultados.push({ entrada: entradasCSV, resultadoEsperado, resultadoObtido: 'rejeita', tempoExecucao: 0 });
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
````
>entrada.join() = função utilizada para converter em string um array
````
const entradasCSV = entrada.join('');
````
>transicoes.find() = função usada para encontrar o primeiro elemento que satisfaz a condição de uma função callback
````
// Verifica se existe uma transição para o símbolo atual
            const transicoesSimbolo = transicoes.find((transicao) => transicao.read === simboloAtual);

            // Verifica se existe uma transição vazia
            const transicoesVazias = transicoes.find((transicao) => transicao.read === null);

//No caso, a função callback é dada por "(transicao) => transicao.read === simboloAtual/null"
````
>automato.estadoFinal.includes() = verificação dos estados finais, para conferir se o estado atual está incluso
````
if (estadoAtual !== undefined && automato.estadoFinal.includes(estadoAtual)) {
            resultados.push({ entrada: entradasCSV, resultadoEsperado, resultadoObtido: 'aceita', tempoExecucao: calcularTempoExecucao(inicioTempo) });
        } else if (estadoAtual !== undefined) {
            // Se a cadeia foi percorrida completamente, mas o estado atual não está entre os estados finais, a cadeia é rejeitada
            resultados.push({ entrada: entradasCSV, resultadoEsperado, resultadoObtido: 'rejeita', tempoExecucao: 0 });
        }
````
>calcularTempoExecucao() = função utilizada para calcular o tempo de execução em milissegundos
````
function calcularTempoExecucao(inicioTempo) {
    const fimTempo = process.hrtime(inicioTempo);
    return fimTempo[0] * 1000 + fimTempo[1] / 1000000; // Tempo de execução em milissegundos
}
````

>fs.writeFileSync() = função utilizada para gravar/escrever dados no arquivo de maneira síncrona
````
const resultado = processarEntradas(automato, entradas);
const resultadoTXT = resultado
    .map(({ entrada, resultadoEsperado, resultadoObtido, tempoExecucao }) => `${entrada}, ${resultadoEsperado}, ${resultadoObtido}, ${tempoExecucao}`)
    .join('\n');

fs.writeFileSync('resultadoTXT', resultadoTXT);
````
>.map() = método para criar um novo array a partir da leitura de cada elemento escolhido de um array existente 
````
.map(({ entrada, resultadoEsperado, resultadoObtido, tempoExecucao }) => `${entrada}, ${resultadoEsperado}, ${resultadoObtido}, ${tempoExecucao}`)
````
>.join() = implementar "\n" ao final de cada linha
````
.join('\n');
````