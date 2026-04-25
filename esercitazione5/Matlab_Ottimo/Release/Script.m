% Si definisce il vettore delle dimensioni N
N = [4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192];

% Si indicano i tempi riscontrati sul terminale in secondi
T_bubble    = [2.2582e-07, 1.3601e-07, 5.9015e-07, 2.48618e-06, 8.08148e-06, 3.1836e-05, 9.90378e-05, 0.000394257, 0.00152586, 0.00579307, 0.0225132, 0.0918685];
T_insertion = [2.312e-08, 6.888e-08, 1.6662e-07, 6.1145e-07, 1.06997e-06, 2.74389e-06, 7.85971e-06, 2.31343e-05, 9.36808e-05, 0.0003205, 0.00128542, 0.00513792];
T_selection = [2.632e-08, 1.0529e-07, 3.4509e-07, 1.06904e-06, 2.62565e-06, 7.35201e-06, 2.21236e-05, 7.94981e-05, 0.000215868, 0.000754535, 0.00272885, 0.010403];
T_std_sort  = [2.397e-08, 7.305e-08, 1.9735e-07, 5.5752e-07, 1.24143e-06, 3.21189e-06, 6.37401e-06, 1.31789e-05, 3.06807e-05, 9.1508e-05, 0.000139958, 0.000305135];
T_merge     = [1.0079e-07, 2.5269e-07, 7.1203e-07, 1.59391e-06, 3.30988e-06, 6.83519e-06, 1.46967e-05, 2.90558e-05, 6.89965e-05, 0.000160388, 0.000305121, 0.000629575];
T_quick     = [2.829e-08, 1.0659e-07, 3.0165e-07, 7.1767e-07, 1.37044e-06, 3.26355e-06, 6.44678e-06, 1.42377e-05, 3.76303e-05, 7.65605e-05, 0.000160596, 0.00030722];
T_new_quick = [2.358e-08, 6.827e-08, 1.8646e-07, 4.7386e-07, 1.10906e-06, 2.62245e-06, 6.87258e-06, 1.27652e-05, 2.9499e-05, 6.64443e-05, 0.000144398, 0.000298666];

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