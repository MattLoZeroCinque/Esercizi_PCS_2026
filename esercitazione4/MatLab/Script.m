% Si definisce il vettore delle dimensioni N
N = [4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192];

% Si indicano i tempi riscontrati sul terminale in secondi
T_bubble    = [2.8e-07, 6.2e-07, 1.497e-06, 5.574e-06, 1.8848e-05, 6.8657e-05, 0.000274535, 0.00114463, 0.0039231, 0.0151137, 0.0596443, 0.253262];
T_insertion = [1.5e-07, 4.08e-07, 6.45e-07, 1.763e-06, 5.069e-06, 1.598e-05, 9.4302e-05, 0.000196383, 0.000851053, 0.00274243, 0.0115369, 0.0443598];
T_selection = [2.2e-07, 5.28e-07, 1.198e-06, 3.568e-06, 1.1018e-05, 4.187e-05, 0.000163351, 0.000570564, 0.0020164, 0.0075549, 0.028905, 0.113063];
T_std_sort  = [1.5e-07, 3.01e-07, 5.21e-07, 9.53e-07, 2.155e-06, 4.881e-06, 1.127e-05, 2.502e-05, 5.5891e-05, 0.000127242, 0.00028247, 0.00062408];

% Si crea il grafico
figure;
loglog(N, T_bubble, '-o', 'LineWidth', 2); hold on;
loglog(N, T_insertion, '-s', 'LineWidth', 2);
loglog(N, T_selection, '-d', 'LineWidth', 2);
loglog(N, T_std_sort, '-x', 'LineWidth', 2);

% Ho inserito una formattazione estetica per una migliore comrpensione,
% consigliato e realizzato tramite l'uso dell'IA!
grid on;
xlabel('Dimensione del vettore (N)');
ylabel('Tempo di esecuzione (secondi)');
title('Confronto Algoritmi di Ordinamento');
legend('Bubble Sort', 'Insertion Sort', 'Selection Sort', 'std::sort', 'Location', 'northwest');