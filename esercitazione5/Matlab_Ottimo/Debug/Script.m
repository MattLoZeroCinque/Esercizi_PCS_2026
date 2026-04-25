% Si definisce il vettore delle dimensioni N
N = [4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192];

% Si indicano i tempi riscontrati sul terminale in secondi
T_bubble    = [9.436e-08, 3.4543e-07, 1.38869e-06, 5.71921e-06, 2.09704e-05, 6.41866e-05, 0.000232818, 0.000904851, 0.00355795, 0.0141058, 0.0589417, 0.24936];
T_insertion = [5.883e-08, 1.8627e-07, 6.6701e-07, 1.46753e-06, 4.66964e-06, 1.52648e-05, 5.99418e-05, 0.000211651, 0.000789326, 0.00308779, 0.0124344, 0.0501633];
T_selection = [9.429e-08, 3.2007e-07, 1.01126e-06, 3.13111e-06, 9.94493e-06, 3.08743e-05, 9.80935e-05, 0.000363039, 0.00139247, 0.00542462, 0.0209619, 0.0979737];
T_std_sort  = [1.414e-07, 3.090e-07, 7.5348e-07, 2.0873e-06, 4.82066e-06, 1.34844e-05, 2.25848e-05, 4.87643e-05, 0.000115946, 0.000247592, 0.000516553, 0.00142165];
T_merge     = [4.1353e-07, 1.0407e-06, 2.94006e-06, 6.02249e-06, 1.27357e-05, 2.78881e-05, 6.22233e-05, 0.000116382, 0.000261596, 0.000555354, 0.00116233, 0.00280386];
T_quick     = [8.576e-08, 2.6488e-07, 7.0181e-07, 1.61302e-06, 3.91812e-06, 8.98022e-06, 1.85101e-05, 4.13699e-05, 9.54345e-05, 0.000220054, 0.000470746, 0.00110829];
T_new_quick = [5.665e-08, 1.758e-07, 4.8674e-07, 1.60029e-06, 3.39588e-06, 8.14502e-06, 1.68529e-05, 3.81798e-05, 8.57339e-05, 0.000197286, 0.000436079, 0.00103914];

% Si crea il grafico
figure;
loglog(N, T_bubble, '-o', 'LineWidth', 2); hold on;
loglog(N, T_insertion, '-s', 'LineWidth', 2);
loglog(N, T_selection, '-d', 'LineWidth', 2);
loglog(N, T_std_sort, '-x', 'LineWidth', 2);
loglog(N, T_merge, '-^', 'LineWidth', 2);
loglog(N, T_quick, '-v', 'LineWidth', 2);
loglog(N, T_new_quick, '-*', 'LineWidth', 2, 'Color', 'r');

% Formattazione estetica
grid on;
xlabel('Dimensione del vettore (N)');
ylabel('Tempo di esecuzione (secondi)');
title('Confronto Algoritmi di Ordinamento (Modalità Debug)');
legend('Bubble Sort', 'Insertion Sort', 'Selection Sort', 'std::sort', 'Merge Sort', 'Quick Sort', 'New Quick Sort', 'Location', 'northwest');