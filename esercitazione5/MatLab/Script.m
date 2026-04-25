% Si definisce il vettore delle dimensioni N
N = [4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192];

% Si indicano i tempi riscontrati sul terminale in secondi
T_bubble    = [8.21e-08, 3.5854e-07, 1.61654e-06, 4.49189e-06, 1.74862e-05, 5.44157e-05, 0.000201478, 0.000740246, 0.00308678, 0.0121701, 0.0519215, 0.222578];
T_insertion = [5.481e-08, 1.7098e-07, 6.0037e-07, 1.33725e-06, 4.235e-06, 1.68564e-05, 5.45659e-05, 0.000192553, 0.000754652, 0.00314852, 0.0121377, 0.0483705];
T_selection = [8.63e-08, 2.8619e-07, 1.29247e-06, 3.10042e-06, 8.53574e-06, 2.87021e-05, 9.58118e-05, 0.000384316, 0.00136032, 0.00518467, 0.0211587, 0.0838484];
T_std_sort  = [1.4763e-07, 3.0399e-07, 9.7496e-07, 2.0893e-06, 4.74288e-06, 1.10752e-05, 2.2661e-05, 9.18917e-05, 0.00012857, 0.000248517, 0.000569605, 0.00118676];
T_merge     = [3.9272e-07, 1.42148e-06, 2.33133e-06, 5.26368e-06, 1.15769e-05, 2.38369e-05, 4.7632e-05, 0.000135619, 0.00022819, 0.000469818, 0.000950141, 0.00201374];
T_quick     = [8.363e-08, 3.4353e-07, 7.2805e-07, 1.49571e-06, 3.49544e-06, 8.41625e-06, 1.68848e-05, 6.30769e-05, 8.71772e-05, 0.000193447, 0.000431407, 0.000935501];

% Si crea il grafico
figure;
loglog(N, T_bubble, '-o', 'LineWidth', 2); hold on;
loglog(N, T_insertion, '-s', 'LineWidth', 2);
loglog(N, T_selection, '-d', 'LineWidth', 2);
loglog(N, T_std_sort, '-x', 'LineWidth', 2);
loglog(N, T_merge, '-^', 'LineWidth', 2);
loglog(N, T_quick, '-v', 'LineWidth', 2);

% Ho inserito una formattazione estetica per una migliore comprensione,
% consigliato e realizzato tramite l'uso dell'IA!
grid on;
xlabel('Dimensione del vettore (N)');
ylabel('Tempo di esecuzione (secondi)');
title('Confronto Algoritmi di Ordinamento');
legend('Bubble Sort', 'Insertion Sort', 'Selection Sort', 'std::sort', 'Merge Sort', 'Quick Sort', 'Location', 'northwest');