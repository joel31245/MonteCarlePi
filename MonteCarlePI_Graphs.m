x = csvread('doubleDigitsAccuracy.csv');

double = csvread('doubleIterations.csv');
single = csvread('singleIterations.csv');

figure(1);
hold on;
set( gca, 'Yscale', 'log');
plot(x,double);
plot(x,single);
legend('Double Precision','Single Precision');
xlabel('Number of Digits to be Accurate');
ylabel('Number of Iterations Required for Accuracy');
title('Monte-Carlo PI Approximations');